// Interactor for Probing the Disk
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include "validate_domjudge.h"

using namespace std;
using ll = long long;

#include <complex>
typedef long double ld;  // long double should have 80 bit precision in x86 architechture
typedef complex<ld> P;

typedef vector<P> VP;

int max_side = 100000;
int min_radius = 100;
int query_limit = 1024;

const ld eps = 1e-9;
ld dot(P a, P b) { return real(conj(a)*b); }
ld cross(P a, P b) { return imag(conj(a)*b); }

struct L {
  P a, b;
  L(P a, P b) : a(a), b(b) {}
  P& operator[](int i) {
    if (i == 0) return a;
    assert(i == 1);
    return b;
  }
};

struct C {
  P p; ld r;
  C(P p, ld r) : p(p), r(r) {}
};

P proj(L l, P p) {
  ld t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}
// ld dist_lp(L l, P p) { return abs(p - proj(l, p)); }
ld dist_lp2(L l, P p) {
  // Compute ||p - proj(l, p)||^2 as robust as possible.
  P p0 = p - l[0];
  P v = l[0] - l[1];
  ld v2 = norm(v);
  ld p0v = dot(p0, v);
  return norm(p0) - (p0v * p0v) / v2;
}

ld chord(L l, P p, ld r) {
  // Compute the chord length of the circle (p, r) with segment line passing a line l.
  // To verify the result is 0 or greater than that, I use __int128 type here.
  // This check excludes numerical errors.
  P p0 = p - l[0];
  P v = l[0] - l[1];
  __int128 p0_2 = (__int128)norm(p0);
  __int128 v2 = (__int128)norm(v);
  __int128 p0v = (__int128)dot(p0, v);
  __int128 d2num = p0_2 * v2 - p0v * p0v;
  __int128 r_128 = (__int128)r;

  if (d2num < r_128 * r_128 * v2) {
    // When the chord length is positive, I switch back the computation to long double to avoid contamination
    ld d2 = dist_lp2(l, p);
    ld len = sqrt(max((ld)0.0, r * r - d2)); //safely
    return len;
  } else {
    return 0;
  }
}

VP is_lc(C c, L l) {
  VP ret;
  ld len = chord(l, c.p, c.r);
  if (len > 0) {
    P nor = (l[0] - l[1]) / abs(l[0] - l[1]);

    auto add = [&](P q) {
      // note q contains numerical error
      if (dot(l[0] - q, l[1] - q) < 0 || abs(l[0] - q) < eps || abs(l[1] - q) < eps) {
        ret.push_back(q);
      }
    };

    add(proj(l, c.p) + len * nor);
    add(proj(l, c.p) - len * nor);
  }
  return ret;
}

ld common_len(L l, C c) {
  if (abs(l[0] - l[1]) < eps) {
    // avoid boundary
    return 0;
  }

  if (abs(l[0] - c.p) < c.r + eps && abs(l[1] - c.p) < c.r + eps) {
    // when the segment is totally included in the circle, return the entire length firstly
    return abs(l[1] - l[0]);
  }

  // in the following case, the segment is partially included in the circle, or the segment has no common points with the circle
  VP sp = is_lc(c, l);

  if (sp.size() == 2) {
    return abs(sp[0] - sp[1]);
  }
  else if (sp.size() == 1) {
    if (abs(l[0] - c.p) < c.r + 1e-9 && abs(l[1] - c.p) > c.r + 1e-9) {
      return abs(l[0] - sp[0]);
    }
    if (abs(l[1] - c.p) < c.r + 1e-9 && abs(l[0] - c.p) > c.r + 1e-9) {
      return abs(l[1] - sp[0]);
    }
    // Basically, the code shouldn't reach here.
    // Most likely case is when the segment is touching the circle. In this case, the return value should be zero
    return 0;
  }
  else {
    return 0;
  }
}

int main(int argc, char **argv) {
  init_io(argc, argv);

  int x, y, r;
  if (!(judge_in >> x >> y >> r)) {
    judge_error("Unable to read x, y, and r\n");
  }

  if (x - r < 0 || x + r > max_side) {
      judge_error("x and r is violating the constraint");
  }
  if (y - r < 0 || y + r > max_side) {
      judge_error("y and r is violating the constraint");
  }
  if (r < min_radius) {
      judge_error("r is too small");
  }

  int query_count = 0;
  while (true) {
    string op;
    if (!author_out.get(op)) {
      wrong_answer("query type is not given\n");
    }

    if (op == "query") {
      query_count++;
      if (query_count > query_limit) {
        wrong_answer("query limit exceeded\n");
      }

      int x1, y1, x2, y2;
      if (!author_out.get(x1)) {
        wrong_answer("x1 is not given or unable to parse as an integer\n");
      }
      if (!author_out.get(y1)) {
        wrong_answer("y1 is not given or unable to parse as an integer\n");
      }
      if (!author_out.get(x2)) {
        wrong_answer("x2 is not given or unable to parse as an integer\n");
      }
      if (!author_out.get(y2)) {
        wrong_answer("y2 is not given or unable to parse as an integer\n");
      }
      if (x1 < 0 || x1 > max_side) wrong_answer("x1 is out of range: given=%d\n", x1);
      if (y1 < 0 || y1 > max_side) wrong_answer("y1 is out of range: given=%d\n", y1);
      if (x2 < 0 || x2 > max_side) wrong_answer("x2 is out of range: given=%d\n", x2);
      if (y2 < 0 || y2 > max_side) wrong_answer("y2 is out of range: given=%d\n", y2);

      if (x1 == x2 && y1 == y2) wrong_answer("(x1, y1) != (x2, y2) must hold\n");

      ld len = common_len(L(P(x1, y1), P(x2, y2)), C(P(x, y), r));

      jprintln("%.7Lf", len);
    }
    else if (op == "answer") {
      int x_guess, y_guess, r_guess;
      if (!author_out.get(x_guess)) {
        wrong_answer("guess for x is not given or unable to parse as an integer\n");
      }
      if (!author_out.get(y_guess)) {
        wrong_answer("guess for y is not given or unable to parse as an integer\n");
      }
      if (!author_out.get(r_guess)) {
        wrong_answer("guess for r is not given or unable to parse as an integer\n");
      }

      if (x != x_guess) {
        wrong_answer("wrong guess for x is given: expected=%d, given=%d\n", x, x_guess);
      }
      if (y != y_guess) {
        wrong_answer("wrong guess for y is given: expected=%d, given=%d\n", y, y_guess);
      }
      if (r != r_guess) {
        wrong_answer("wrong guess for y is given: expected=%d, given=%d\n", r, r_guess);
      }

      accept();
    }
    else {
      wrong_answer("invalid query type: %s\n", op.c_str());
    }
  }
}
