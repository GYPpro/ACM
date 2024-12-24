#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//using ord_setl = tree<int, null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update>;
#define fi first
#define se second
#define x first
#define y second
#define int long long
#define all(x) x.begin(),x.end()
using pii = pair<int,int>;
using ld = long double;
//using pii;

const ld EPS = 1e-10;
	int r;

int dot(pii a,pii b) {
	return a.x * b.x + a.y * b.y;
}

int cross(pii a,pii b) {
	return a.x*b.y - a.y*b.x;
}

int cross(pii p1,pii p2,pii p0) {
	return cross({p1.x-p0.x,p1.y-p0.y},{p2.x-p0.x,p2.y-p0.y});
}

int dot(pii p1,pii p2,pii p0) {
	return dot({p1.x-p0.x,p1.y-p0.y},{p2.x-p0.x,p2.y-p0.y});
}
template<typename T>
T pw(T xx){
	return xx * xx;
}

ld abs(pii a) {
	return sqrtl(pw(a.x)+pw(a.y));
}

ld rc(pii a,pii b) {
	ld v = abs(cross(a,b));
	return abs(atan2l(v,dot(a,b)));
}

template<typename T>
bool eq(T a,T b) {
	if(fabs(a-b) <= EPS) return 1;
	else return 0;
}

int cer(pii a,pii b) {
	return (a.y + b.y) * abs(a.x - b.x);
}

int ctr(array<pii,3> ds){
//	sort(all(ds),[](pii a,pii b){
//		return a.y < b.y;
//	});
	pii d1 = ds[0],d2 = ds[1];
	pii d3 = ds[2];
	return abs(cross(d1,d2,d3));
	// cout << "cac:\n";
	// cout << "d1:" << d1.x << " " << d1.y << "\n";
	// cout << "d2:" << d2.x << " " << d2.y << "\n";
	// cout << "d3:" << d3.x << " " << d3.y << "\n";
	return abs(cer(d1,d3)+cer(d2,d3)-cer(d1,d2));
}

ld dis(pii a,pii b) {
	return sqrtl(pw(a.x-b.x)+pw(a.y-b.y));
}


ld p2l(pii p,pii a,pii b) {
	ld ans = cross(p,a,b);
	return abs(ans)/dis(a,b);
}

template<typename T>
int sign(T x) {
	if(fabs(x) < EPS) return 0;
	return x < 0 ? -1 : 1;
}

ld p2s(pii a,pii b,pii o){
	pii v = {a.x-b.x,a.y-b.y};
	if(sign(dot(o,a,b))== -1){
		return dis(o,a);
	} else if(sign(dot(o,b,a)) == -1) {
		return dis(o,b);
	}
	return p2l(o,a,b);
}

bool check(pii d1,pii d2,pii d3,pii d0) {
	pii v1 = {d3.x-d1.x,d3.y-d1.y},
		v2 = {d0.x-d1.x,d0.y-d1.y},
		v3 = {d2.x-d1.x,d2.y-d1.y};
	// cout << "checking:\n";
	// cout << "d1:" << d1.x << " " << d1.y << "\n";
	// cout << "d2:" << d2.x << " " << d2.y << "\n";
	// cout << "d3:" << d3.x << " " << d3.y << "\n";
	// cout << "d0:" << d0.x << " " << d0.y << "\n";
	// cout << "v1:" << v1.x << " " << v1.y << "\n";
	// cout << "v2:" << v2.x << " " << v2.y << "\n";
	// cout << "v3:" << v3.x << " " << v3.y << "\n";
	if(d1.x == d2.x && d1.y == d2.y){
        // cout << "accepted\n";
        return 1;
    }
    // cout << p2s(d1,d3,d0) << "|";
	// cout << rc(v1,v2) << " " << rc(v1,v3) << " " << rc(v2,v3) << "\n";
	if(eq(rc(v1,v2),rc(v1,v3)+rc(v2,v3)) && (p2s(d1,d3,d0) > r || eq(p2s(d1,d3,d0),(ld)r) ) ){
        // cout << "accepted\n";
        return 1;
    }
	else{
        // cout << "rejected\n";
        return 0;
    }
}

void solve(){
	int n;
	cin >> n;
	vector<pii> dots;
	pii d0;
	cin >> d0.x >> d0.y >> r;
	for(int i = 0;i < n;i ++)
	{
		int u,v;
		cin >> u >> v;
		dots.push_back({u,v});
	}
	int tic = 0;
	int ans = 0;
	int cur = 0;
	int e = 0,f = 0;
	auto nx = [&](int f) -> int {
		return (f+1)%n;
	};
	auto push = [&]() -> void {
		cur += ctr({dots[e],dots[f],dots[nx(f)]});
		// cout << "update:" <<  ctr({dots[e],dots[f],dots[nx(f)]}) << "\n";
		f ++;	
		f %= n;
	};
	auto pull = [&]() -> void {
		cur -= ctr({dots[e],dots[nx(e)],dots[f]});
		// cout << "update:-" << ctr({dots[e],dots[nx(e)],dots[f]}) << "\n";
		e ++;	
		e %= n;
	};
	while(++tic < n*3)
	{
			auto op = [](pii a) {
				cout << "<" << a.x << " " << a.y << ">";
			};
			// cout << "nxf:" << nx(f) << ":";op(dots[nx(f)]);
			// cout << "\nnxe:" << nx(e) << ":";op(dots[nx(e)]);
			// cout << "\nf:" << f << ":";op(dots[f]);
			// cout << "\ne:" << e << ":";op(dots[e]);
			// cout << "\n" << check(dots[e],dots[nx(f)],dots[nx(e)],d0) << " " << p2s(dots[nx(f)],dots[e],d0) << "\n";
		while(
			!check(dots[e],dots[nx(f)],dots[nx(e)],d0) || 
			p2s(dots[nx(f)],dots[e],d0) < (ld)r-(1e-9)
		) {
			pull();
			// system("pause");
			// cout << "nxf:" << nx(f) << ":";op(dots[nx(f)]);
			// cout << "\nnxe:" << nx(e) << ":";op(dots[nx(e)]);
			// cout << "\nf:" << f << ":";op(dots[f]);
			// cout << "\ne:" << e << ":";op(dots[e]);
			// // cout << "\n" << check(dots[e],dots[nx(f)],dots[nx(e)],d0) << " " << p2s(dots[nx(f)],dots[e],d0) << "\n";
		}
		push();
		// cout << "ans:" << ans << "\n";
		ans = max(ans,cur);
	}
	cout << ans << "\n";
}
/*
3
5
1 1 1
0 0
1 0
5 0
3 3
0 5
6
2 4 1
2 0
4 0
6 3
4 6
2 6
0 3
4
3 3 1
3 0
6 3
3 6
0 3

1
6
2 4 1
2 0
4 0
6 3
4 6
2 6
0 3
*/
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*nxf:1:<50 0>
nxe:1:<50 0>
f:0:<0 0>
e:0:<0 0>
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
update:0
ans:0
nxf:2:<100 0>
nxe:1:<50 0>
f:1:<50 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
update:0
ans:0
nxf:3:<100 10>
nxe:1:<50 0>
f:2:<100 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
1 4.47767
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
update:1000
ans:0
nxf:4:<23 10>
nxe:1:<50 0>
f:3:<100 10>
e:0:<0 0>
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
1 2.59172
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
update:770
ans:1000
nxf:5:<0 10>
nxe:1:<50 0>
f:4:<23 10>
e:0:<0 0>
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
0 5
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
update:-500
nxf:5:<0 10>
nxe:2:<100 0>
f:4:<23 10>
e:1:<50 0>
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
1 3.92232
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
update:230
ans:1770
nxf:0:<0 0>
nxe:2:<100 0>
f:5:<0 10>
e:1:<50 0>
checking:
d1:50 0
d2:0 0
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 0
95.1315|3.03094 3.14159 0.110657
rejected
0 5
checking:
d1:50 0
d2:0 0
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 0
95.1315|3.03094 3.14159 0.110657
rejected
update:-500
nxf:0:<0 0>
nxe:3:<100 10>
f:5:<0 10>
e:2:<100 0>
checking:
d1:100 0
d2:0 0
d3:100 10
d0:5 5
v1:0 10
v2:-95 5
v3:-100 0
95|1.51821 1.5708 0.0525831
rejected
0 5
checking:
d1:100 0
d2:0 0
d3:100 10
d0:5 5
v1:0 10
v2:-95 5
v3:-100 0
95|1.51821 1.5708 0.0525831
rejected
update:-1000
nxf:0:<0 0>
nxe:4:<23 10>
f:5:<0 10>
e:3:<100 10>
checking:
d1:100 10
d2:0 0
d3:23 10
d0:5 5
v1:-77 0
v2:-95 -5
v3:-100 -10
95.1315|0.0525831 0.0996687 0.0470856
rejected
0 4.47767
checking:
d1:100 10
d2:0 0
d3:23 10
d0:5 5
v1:-77 0
v2:-95 -5
v3:-100 -10
95.1315|0.0525831 0.0996687 0.0470856
rejected
update:-0
nxf:0:<0 0>
nxe:5:<0 10>
f:5:<0 10>
e:4:<23 10>
checking:
d1:23 10
d2:0 0
d3:0 10
d0:5 5
v1:-23 0
v2:-18 -5
v3:-23 -10
5|0.270947 0.410127 0.13918
rejected
0 2.59172
checking:
d1:23 10
d2:0 0
d3:0 10
d0:5 5
v1:-23 0
v2:-18 -5
v3:-23 -10
5|0.270947 0.410127 0.13918
rejected
update:-0
nxf:0:<0 0>
nxe:0:<0 0>
f:5:<0 10>
e:5:<0 10>
checking:
d1:0 10
d2:0 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:0 -10
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 10
d2:0 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:0 -10
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:1:<50 0>
nxe:0:<0 0>
f:0:<0 0>
e:5:<0 10>
checking:
d1:0 10
d2:50 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:50 -10
5|0.785398 1.3734 0.588003
rejected
0 3.92232
checking:
d1:0 10
d2:50 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:50 -10
5|0.785398 1.3734 0.588003
rejected
update:-0
nxf:1:<50 0>
nxe:1:<50 0>
f:0:<0 0>
e:0:<0 0>
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:2:<100 0>
nxe:1:<50 0>
f:1:<50 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:3:<100 10>
nxe:1:<50 0>
f:2:<100 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
1 4.47767
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
update:1000
ans:1770
nxf:4:<23 10>
nxe:1:<50 0>
f:3:<100 10>
e:0:<0 0>
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
1 2.59172
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
update:770
ans:1770
nxf:5:<0 10>
nxe:1:<50 0>
f:4:<23 10>
e:0:<0 0>
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
0 5
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
update:-500
nxf:5:<0 10>
nxe:2:<100 0>
f:4:<23 10>
e:1:<50 0>
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
1 3.92232
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
update:230
ans:1770
nxf:0:<0 0>
nxe:2:<100 0>
f:5:<0 10>
e:1:<50 0>
checking:
d1:50 0
d2:0 0
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 0
95.1315|3.03094 3.14159 0.110657
rejected
0 5
checking:
d1:50 0
d2:0 0
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 0
95.1315|3.03094 3.14159 0.110657
rejected
update:-500
nxf:0:<0 0>
nxe:3:<100 10>
f:5:<0 10>
e:2:<100 0>
checking:
d1:100 0
d2:0 0
d3:100 10
d0:5 5
v1:0 10
v2:-95 5
v3:-100 0
95|1.51821 1.5708 0.0525831
rejected
0 5
checking:
d1:100 0
d2:0 0
d3:100 10
d0:5 5
v1:0 10
v2:-95 5
v3:-100 0
95|1.51821 1.5708 0.0525831
rejected
update:-1000
nxf:0:<0 0>
nxe:4:<23 10>
f:5:<0 10>
e:3:<100 10>
checking:
d1:100 10
d2:0 0
d3:23 10
d0:5 5
v1:-77 0
v2:-95 -5
v3:-100 -10
95.1315|0.0525831 0.0996687 0.0470856
rejected
0 4.47767
checking:
d1:100 10
d2:0 0
d3:23 10
d0:5 5
v1:-77 0
v2:-95 -5
v3:-100 -10
95.1315|0.0525831 0.0996687 0.0470856
rejected
update:-0
nxf:0:<0 0>
nxe:5:<0 10>
f:5:<0 10>
e:4:<23 10>
checking:
d1:23 10
d2:0 0
d3:0 10
d0:5 5
v1:-23 0
v2:-18 -5
v3:-23 -10
5|0.270947 0.410127 0.13918
rejected
0 2.59172
checking:
d1:23 10
d2:0 0
d3:0 10
d0:5 5
v1:-23 0
v2:-18 -5
v3:-23 -10
5|0.270947 0.410127 0.13918
rejected
update:-0
nxf:0:<0 0>
nxe:0:<0 0>
f:5:<0 10>
e:5:<0 10>
checking:
d1:0 10
d2:0 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:0 -10
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 10
d2:0 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:0 -10
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:1:<50 0>
nxe:0:<0 0>
f:0:<0 0>
e:5:<0 10>
checking:
d1:0 10
d2:50 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:50 -10
5|0.785398 1.3734 0.588003
rejected
0 3.92232
checking:
d1:0 10
d2:50 0
d3:0 0
d0:5 5
v1:0 -10
v2:5 -5
v3:50 -10
5|0.785398 1.3734 0.588003
rejected
update:-0
nxf:1:<50 0>
nxe:1:<50 0>
f:0:<0 0>
e:0:<0 0>
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:50 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:50 0
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:2:<100 0>
nxe:1:<50 0>
f:1:<50 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
1 5
checking:
d1:0 0
d2:100 0
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 0
5|0.785398 0 0.785398
accepted
update:0
ans:1770
nxf:3:<100 10>
nxe:1:<50 0>
f:2:<100 0>
e:0:<0 0>
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
1 4.47767
checking:
d1:0 0
d2:100 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:100 10
5|0.785398 0.0996687 0.68573
accepted
update:1000
ans:1770
nxf:4:<23 10>
nxe:1:<50 0>
f:3:<100 10>
e:0:<0 0>
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
1 2.59172
checking:
d1:0 0
d2:23 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:23 10
5|0.785398 0.410127 0.375271
accepted
update:770
ans:1770
nxf:5:<0 10>
nxe:1:<50 0>
f:4:<23 10>
e:0:<0 0>
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
0 5
checking:
d1:0 0
d2:0 10
d3:50 0
d0:5 5
v1:50 0
v2:5 5
v3:0 10
5|0.785398 1.5708 0.785398
rejected
update:-500
nxf:5:<0 10>
nxe:2:<100 0>
f:4:<23 10>
e:1:<50 0>
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
1 3.92232
checking:
d1:50 0
d2:0 10
d3:100 0
d0:5 5
v1:50 0
v2:-45 5
v3:-50 10
95.1315|3.03094 2.9442 0.0867383
accepted
update:230
ans:1770
1770

*/