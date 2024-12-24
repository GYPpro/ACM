// argv に (cmd, judge_in, judge_ans, feedback_dir) が入る
// 判定対象のデータは標準入力
// feedback_dir/judgemessage.txt に判定の再の追加のコメントを書いてよい
// feedback_dir/diffposition.txt に差分の情報を書いてよいらしい
// 結果は AC=42 または WA=43

#include <iostream>
#include <fstream>

using namespace std;

const int AC = 42;
const int WA = 43;

[[noreturn]] void reportWrongAnswer(const string &msg, ostream &msgOut) {
  msgOut << msg << endl;
  exit(WA);
}

string decode(string::iterator &p, const string::iterator e,
	      int len, bool repeated, ostream &msgOut) {
  string decoded;
  while (p != e) {
    char c = *p++;
    if ('a' <= c && c <= 'z') {
      decoded += c;
      if (--len < 0) reportWrongAnswer("Decoded result is too long", msgOut);
    } else if ('2' <= c && c <= '9') {
      if (*p++ != '(') {
	reportWrongAnswer(string("Open parenthesis expected after ") + c, msgOut);
      }
      int rep = c - '0';
      string s = decode(p, e, len/rep+1, true, msgOut);
      if ((len -= rep*s.length()) < 0) {
	reportWrongAnswer("Decoded result is too long", msgOut);
      }
      do {
	decoded += s;
      } while (--rep != 0);
    } else if (c == ')') {
      if (!repeated) {
	reportWrongAnswer("Unexpected close parenthesis", msgOut);
      } else if (decoded.length() == 0) {
	reportWrongAnswer("Repetition of an empty string", msgOut);
      } else {
	return decoded;
      }
    } else {
      reportWrongAnswer(string("Unexpected character '") + c + "' found", msgOut);
    }
  }
  if (repeated) {
    reportWrongAnswer("Close parenthesis is missing", msgOut);
  } else {
    return decoded;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cerr << "Number of args (" << argc << ") is not 4" << endl;
    exit(-1);
  }
  ifstream judge_in(argv[1]);
  if (!judge_in) {
    cerr << "Cannot open judge input file (" << argv[1] << ")" << endl;
    exit(-1);
  }
  ifstream judge_ans(argv[2]);
  if (!judge_ans) {
    cerr << "Cannot open judge answer file (" << argv[2] << ")" << endl;
    exit(-1);
  }
  string message_file = string(argv[3]) + "/judgemessage.txt";
  ofstream msgOut(message_file);
  if (!msgOut) {
    cerr << "Cannot open judge message file (" << message_file << ")" << endl;
    exit(-1);
  }
  string ans;
  getline(judge_ans, ans);
  string judged;
  getline(cin, judged);
  if (judged.length() != ans.length()) {
    reportWrongAnswer("Length mismatch (maybe not optimal)", msgOut);
  }
  string::iterator b = judged.begin();
  string input;
  getline(judge_in, input);
  string decoded = decode(b, judged.end(), input.length(), false, msgOut);
  if (decoded != input) {
    reportWrongAnswer("The output does not decode to the original input", msgOut);
  }
  return AC;
}
