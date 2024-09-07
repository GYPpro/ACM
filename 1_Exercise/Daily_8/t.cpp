#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
#define ll long long
#define int long long

double p=acos(-1.0);
void solve(){
	int n;
	// scanf("%lld",&n);
    cin >> n;
	double ans = 0;
	if(n%2==0){
		ans=(1.0/tan(p/(2*n)));
	}
	else{
		ans=2*sin((3*p)/(4*n));
	}
	// printf("%.12lf\n",ans);
    cout << format("{:.12f}\n",ans);
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t=1;
	// scanf("%lld",&t);
    cin >> t;
	while(t--) solve();
	return 0;
}

// /Invocation failed [COMPILATION_ERROR]
// Can't compile file:
// program.cpp: In function 'void solve()':
// program.cpp:14:34: warning: conversion from 'long long int' to 'double' may change value [-Wconversion]
//    14 |                 ans=(1.0/tan(p/(2*n)));
//       |                                ~~^~~
// program.cpp:17:35: warning: conversion from 'long long int' to 'double' may change value [-Wconversion]
//    17 |                 ans=2*sin((3*p)/(4*n));
//       |                                 ~~^~~
// In file included from C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/bits/chrono_io.h:39,
//                  from C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/chrono:3330,
//                  from C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/x86_64-w64-mingw32/bits/stdc++.h:172,
//                  from program.cpp:1:
// program.cpp:20:19:   in 'constexpr' expansion of 'std::basic_format_string<char, double&>("{:.12lf}\012")'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:3672:19:   in 'constexpr' expansion of '__scanner.std::__format::_Checking_scanner<char, double>::<anonymous>.std::__format::_Scanner<char>::_M_scan()'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:3482:30:   in 'constexpr' expansion of '((std::__format::_Scanner<char>*)this)->std::__format::_Scanner<char>::_M_on_replacement_field()'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:3534:15:   in 'constexpr' expansion of '((std::__format::_Scanner<char>*)this)->std::__format::_Scanner<char>::_M_format_arg(__id)'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:3610:33:   in 'constexpr' expansion of '((std::__format::_Checking_scanner<char, double>*)this)->std::__format::_Checking_scanner<char, double>::_M_parse_format_spec<double>(__id)'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:3624:40:   in 'constexpr' expansion of '__f.std::formatter<double, char>::parse(((std::__format::_Checking_scanner<char, double>*)this)->std::__format::_Checking_scanner<char, double>::<anonymous>.std::__format::_Scanner<char>::_M_pc)'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:2025:26:   in 'constexpr' expansion of '((std::formatter<double, char>*)this)->std::formatter<double, char>::_M_f.std::__format::__formatter_fp<char>::parse((* & __pc))'
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:1410:48: error: call to non-'constexpr' function 'void std::__format::__failed_to_parse_format_spec()'
//  1410 |         __format::__failed_to_parse_format_spec();
//       |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~
// C:/Programs/gcc13-64-winlibs/include/c++/13.2.0/format:185:3: note: 'void std::__format::__failed_to_parse_format_spec()' declared here
//   185 |   __failed_to_parse_format_spec()
//       |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// =====
// Used: 0 ms, 0 KB