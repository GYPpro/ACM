#include <bits/stdc++.h>
#include "testlib.h"
using i64 = long long;
constexpr int N = 1e6 + 10;
int n, a[N];
i64 k, f[N];
namespace flower {
	using namespace std;
	const int N = 1e6 + 10;
	const int M = 20;
	int number_begin[N], number_end[N];
	char s[N];

	struct suffix_array_t {
		int sa[N], rank[N], rmq_l[N], rmq[M][N];
		char s[N];

		void build() {
			static int a[N], b[N], c[N], temp[N];
			s[n + 1] = 0;
			for (int i = 0; i < 26; ++i) {
				c[i] = 0;
			}
			for (int i = 1; i <= n; ++i) {
				++c[s[i] - 'a'];
			}
			for (int i = 1; i < 26; ++i) {
				c[i] += c[i - 1];
			}
			for (int i = n; i; --i) {
				sa[c[s[i] - 'a']--] = i;
			}
			rank[sa[1]] = 1;
			for (int i = 2; i <= n; ++i) {
				rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
			}
			for (int l = 1; rank[sa[n]] < n; l <<= 1) {
				for (int i = 0; i <= n; ++i) {
					c[i] = 0;
				}
				for (int i = 1; i <= n; ++i) {
					++c[b[i] = i + l > n ? 0 : rank[i + l]];
				}
				for (int i = 1; i <= n; ++i) {
					c[i] += c[i - 1];
				}
				for (int i = n; i; --i) {
					temp[c[b[i]]--] = i;
				}
				for (int i = 0; i <= n; ++i) {
					c[i] = 0;
				}
				for (int i = 1; i <= n; ++i) {
					++c[a[i] = rank[i]];
				}
				for (int i = 1; i <= n; ++i) {
					c[i] += c[i - 1];
				}
				for (int i = n; i; --i) {
					sa[c[a[temp[i]]]--] = temp[i];
				}
				rank[sa[1]] = 1;
				for (int i = 2; i <= n; ++i) {
					rank[sa[i]] = rank[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]);
				}
			}
			for (int i = 1, j = 0; i <= n; ++i) {
				for (j -= j > 0; rank[i] != 1 && s[i + j] == s[sa[rank[i] - 1] + j]; ++j);
				rmq[0][rank[i]] = j;
			}
			for (int i = 1; i < M; ++i) {
				for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
					rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
				}
			}
			for (int i = 2; i <= n; ++i) {
				rmq_l[i] = rmq_l[i >> 1] + 1;
			}
		}

		int lcp(int x, int y) {
			if (x == y) {
				return n - x + 1;
			}
			x = rank[x];
			y = rank[y];
			if (x > y) {
				swap(x, y);
			}
			++x;
			int k = rmq_l[y - x + 1];
			return min(rmq[k][x], rmq[k][y - (1 << k) + 1]);
		}
	} prefix, suffix;

	int calc() {
		for (int i = 1; i <= n; i ++) s[i] = a[i] + 'a';
		for (int i = 1; i <= n; ++i) {
			prefix.s[i] = suffix.s[n - i + 1] = s[i];
		}
		prefix.build();
		suffix.build();
		for (int i = 0; i <= n; ++i) {
			number_begin[i] = number_end[i] = 0;
		}
		for (int i = 1; i << 1 <= n; ++i) {
			for (int j = 1; j + i <= n; j += i) {
				if (s[j] == s[j + i]) {
					int l = j - min(i, suffix.lcp(n - j + 1, n - j - i + 1)), r = j + min(i, prefix.lcp(j, j + i));
					if (l + i <= r) {
						++number_begin[l + 1];
						--number_begin[r - i + 1];
						++number_end[l + (i << 1)];
						--number_end[r + i];
					}
				}
			}
		}
		int answer = 0;
		for (int i = 1; i <= n; ++i) {
			number_begin[i] += number_begin[i - 1];
			number_end[i] += number_end[i - 1];
			answer += number_begin[i];
		}
		return answer;
	}
}
int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
	n = inf.readInt(), k = inf.readInt();
	std::string s = ouf.readWord(), t = ans.readWord();
	if(s == "Yes") {
		for(int i = 1; i <= n; i ++) {
			a[i] = ouf.readInt();
		}
		if(flower::calc() == k) {
			assert(t == "Yes");
			quitf(_ok, "");
		} else {
			quitf(_wa, "");
		}
	} else {
		if(t == "Yes") {
			quitf(_wa, "");
		} else {
			quitf(_ok, "");
		}
	}
	return 0;
}

