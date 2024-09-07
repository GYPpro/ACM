#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define map unordered_map
#define set unordered_set

#include <map>
#include <set>
// #pragma GCC optimize(2)

#define int long long
#define FI for (int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define pii pair<int,int>
#define se second

void sort(auto &x)
{
    sort(x.begin(), x.end());
};

using namespace std;
#define MAXN ((int) 2e5)


class ors{
public:

const int mod=998244353;
vector<vector<int>> f;
pair<vector<int>,vector<int>> solve(int n,int m,string s)
{
	// int n,m;
	// cin>>n>>m;
	// //cout<<n<<' '<<m<<' '<<"ok"<<endl;
	// string s;
	// cin>>s;
	s=' '+s;
	int id=1;
	int len=s.size()-1;
	vector<int>a(n+1,-1),b(m+1,-1);
	auto cal=[&](int x)->int
	{
		//cout<<"cal:"<<"x="<<x<<endl;
		if(id>len)return -1;
		if(s[id]=='0')
		{
			id++;
			return 0;
		}
		int v=s[id]-'0';
		id++;
		if(f[x][v]>0)
		{
			return f[x][v];
		}
		else
		{
			v=v*10+s[id]-'0';
			id++;
			if(f[x][v]>0)return f[x][v];

		}
		return -1;
	};
	auto check=[&](int x)->bool
	{
		id=1;
		a[1]=x;
		//cout<<"x="<<x<<endl;
		for(int i=1;i<=m;i++)
		{
			b[i]=cal(x);
			//cout<<id<<endl;
			//cout<<"b[i]="<<b[i]<<endl;
			if(b[i]<0)return 0;
		}
		for(int i=2;i<=n;i++)
		{
			//cout<<id<<endl;
			a[i]=cal(b[1]);
			for(int j=2;j<=m;j++)
			{
				int v=a[i]*b[j];
				int ll=v>=10?2:1;
				for(int k=ll-1;k>=0;k--)
				{
					if(id+k>len||s[id+k]-'0'!=v%10)return 0;
					v/=10;
				}
				id+=ll;
			}
			//cout<<"a[i]="<<a[i]<<endl;
			if(a[i]<0)return 0;

		}
		/*if(b[1]==0)
		{
			//cout<<"Impossible"<<'\n';
			return 0;
		}*/
		
		string s1="";
		for(int i=1;i<=n;i++)
		{

			for(int j=1;j<=m;j++)
			{
				int v=a[i]*b[j];
				s1+=to_string(v);
			}
		}
	

		return s.substr(1)==s1;
	};
	for(int k=1;k<=9;k++)
	{
		if(check(k))
		{
			// for(int i=1;i<=n;i++)
			// {
			// 	cout<<a[i];
			// }
			// cout<<' ';
			// for(int i=1;i<=m;i++)
			// {
			// 	cout<<b[i];
			// }
			// cout<<'\n';
            vector<int> rta,rtb;
            for(int i = 1;i < a.size();i ++) rta.pb(a[i]);
            for(int i = 1;i < b.size();i ++) rtb.pb(b[i]);
			return{rta,rtb};
		}

	}
	// cout<<"Impossible"<<'\n';
    
	return{{},{}};

}
 ors()
{
    f.resize(114);
    for(auto &x:f) x.resize(114);
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			f[i][i*j]=j;
		}
	}
}
};

class solution
{
private:
public:
    pair<vector<int>,vector<int>> solve(int n,int m,string s)
    {
        vector<int> c;
        for(auto x:s) c.pb(x-'0');

        auto getNXT = [&](int f,int n) -> pii {
            // cout << "getnxt :" << f << " " << c[f] << " " << n << "\n"; 
            if(n < 0) return {-1,-1};
            if(f >= c.size()) return {-1,-1};
            if(n == 0) {
                if(c[f] == 0) return {0,f+1};
                else return {-1,-1};
            } else if(c[f]%n == 0) return {c[f],f+1};
            else if(f +1 >= c.size()) return {-1,-1};
            else if((c[f]*10 + c[f+1])%n == 0) return {c[f]*10 + c[f+1],f+2};
            else return {-1,-1};
        };

        // vector<int> a,b;
        vector<int> a(1);
        vector<int> b;
        auto checkline = [&](int f,int a) -> pii {
            int id = f;
            int TTL = 0;
            while(TTL < m) {
                auto rt = getNXT(id,a);
                if(rt.first == -1) return {0,-1};
                // cout << id << " " << TTL << " " << rt.first << "\n";
                if(a * b[TTL] != rt.first) return {0,-1};
                TTL ++;
                id = rt.second;
            } return {1,id};
        }; 
        auto check = [&](int a0) -> bool {
            a.clear();
            a.pb(a0);
            b.clear();
            int id = 0;
            while(b.size() < m) {
                auto rt = getNXT(id,a0);
                if(rt.first == -1) return 0;
                b.pb(rt.first/a0);
                id = rt.second;
            }
            // for(auto x:a) cout << x;cout << "\n";
            // for(auto x:b) cout << x << " ";cout << "--" << a0 << "\n";
            while(a.size() < n) {
                // cout << "--" << a.size() << " " << id << "--\n";
                auto rt = getNXT(id,b[0]);
                if(rt.first == -1) return 0;
                a.pb(b[0] == 0 ? rt.first : rt.first/b[0]);
                // cout << rt.first << " " << rt.second << "\n";
                // cout << "gnc a[" << a.size()-1 << "]: " << a[a.size()-1] << "\n";
                auto rt2 = checkline(id,a[a.size()-1]);
                // cout << "checked " << id << " " << a[a.size()-1] << " :" <<rt2.first << " " << rt2.second << "\n";
                if(rt2.first) id = rt2.second;
                else return 0;
            }
            if(id < c.size()) return 0;
            // cout << id << "\n";
            return 1;
        };
        for(int i = 1;i < 10;i++) {
            if(check(i)){
                
                return{a,b};
            }
        }
        return {{},{}};
    }
};

signed main()
{
    srand(114514);
    for(;;)
    {
        ors s1;
        solution s2;
        int n = rand()%100 + 2,m = rand()%100 + 1;
        string s;
        int MEX = n*m+rand()%(n*m-1);
        for(int i = 0;i < MEX;i ++) s.pb(rand()%10+'0');
        if(s[0] == '0') s[0] = '1';
        // vector<int> a,b;
        // for(int i = 0;i < n;i ++) a.pb(rand()%10);
        // for(int i = 0;i < m;i ++) b.pb(rand()%10);
        // if(a[0] == 0) a[0] +=1;
        // if(b[0] == 0) b[0] +=1;
        auto c2s = [](int n) -> string{
            string rt2,rt;
            if(n == 0) return "0";
            while(n){
                rt2.pb ('0' + n % 10 );
                n /= 10;
            }
            while (rt2.size())
            {
                rt.pb(rt2[rt2.size()-1]);
                rt2.pop_back();
            }
            
            return rt;
        }; 
        // for(auto x:a)
        //     for(auto y:b)
        //         s += c2s(x*y);
        vector<int> a1,b1;
        auto rt1 = s1.solve(n,m,s);
        a1 = rt1.first;
        b1 = rt1.second;
        vector<int> a2,b2;
        auto rt2 = s2.solve(n,m,s);
        a2 = rt2.first;
        b2 = rt2.second;
        string sa2;
        for(auto x:a2)
            for(auto y:b2)
                sa2 += c2s(x*y);
        string sa1;
        for(auto x:a1)
            for(auto y:b1)
                sa1 += c2s(x*y);
        auto cmp = [](string a,string b) -> bool{
            for(int i = 0;i < min(a.size(),b.size());i ++)
            {
                if(a.size() != b.size()) return 0;
                if(a[i] != b[i] && (a[i] != 0 && b[i] != 0)) return 0;
            }
            return 1;
        };
        if(cmp(sa1,sa2)) {
            cout << "rt..\n";
        } else {
            cout << n << " " << m << "\n";
            cout << s << "\n";
            // for(auto x:a) cout << x << " ";cout << "\n";
            // for(auto x:b) cout << x << " ";cout << "\n";
            cout << "---s1----\n";
            for(auto x:a1) cout << x << " ";cout << "\n";
            for(auto x:b1) cout << x << " ";cout << "\n";
            cout << sa1 << "\n";
            cout << "---s2----\n";
            for(auto x:a2) cout << x << " ";cout << "\n";
            for(auto x:b2) cout << x << " ";cout << "\n";
            cout << sa2 << "\n";
            system("pause");
        }
    }


    return 0;
}