#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
#define pb push_back

int main(){
    int r,c;
    cin >> r >> c;
    int n,m;
    cin >> n >> m;
    m /= 2;
    vector<vector<int>> rtl(r+1,vector<int>(c+1));
    for(int i = 0;i < n;i ++)
    {
        int x,y,c;
        cin >> x >> y >> c;
		        x --,y --; 
        rtl[x][y] = c;
    }
     for(auto x:rtl)
 		{
 			for(auto y:x)
 			cout << y << " ";
 			cout << "\n";
 		} 
    vector<vector<int>> sumr(r+c,vector<int>(1)),suml(r+c,vector<int>(1));

    for(int i = 0;i < r+c;i ++)
    {
        int x = max(0,i - c),y = max(0,c-i);
        while(x < r && y < c)
        {
             cout << "suml:add" << x << " " << y << ": "<<suml[i][suml[i].size()-1]<<" to"<< rtl[x][y]<<" at"<<i << "\n";
            
            suml[i].pb(suml[i][suml[i].size()-1] + rtl[x][y]);
            x++;
            y++;
        }
    }
    for(int i = 0;i < r+c;i ++)
    {
        int x = max(0,i-c),y = min(c-1,i);
        while(x < r && y >= 0)
        {
             cout << "sumr:add" << x << " " << y << " at"<<i << "\n";
            sumr[i].pb(sumr[i][sumr[i].size()-1] + rtl[x][y]);
            x++;
            y--;
        }
    }
     for(auto x:suml)
         {for(auto y:x)
             cout << y <<" ";
         cout << "\n";
          }
 		     cout << "suml  sumr\n";
     for(auto x:sumr)
         {for(auto y:x)
             cout << y <<" ";
         cout << "\n";
          }
    
    
    auto getl = [&](int x,int y,int l) -> int{
        int idx = y - x;
        if(idx <= 0) idx = -idx + c;
        else idx +=1;
        if(idx >= suml.size()) return 0;
//         while(y < 0 || x < 0){
//             y ++;
//             x ++;
//             l --;
//         }
        int tmpmn = 0;
        return suml[idx][min(max(0,min(x,y)+l+1),(int)suml[idx].size()-1)] - suml[idx][min((int)suml[idx].size()-1,max(0,min(x,y)))];
    };
    auto getr = [&](int x,int y,int l) -> int{
        int idx = x + y + 1;
        if(idx >= sumr.size()) return 0;
//         int tmpmn = 0;
//         if(y < 0 || x < 0)
//             tmpmn = min(y,x);
//         y -= tmpmn;
//         x -= tmpmn;
//         l += tmpmn;
        return sumr[idx][min(max(0,min(c-y-1,x))+ l+1,(int)sumr[idx].size()-1)] - sumr[idx][min((int)suml[idx].size()-1,max(0,max(c-y-1,x-1)))];
//         return sumr[idx][min(x,y)+l+1] - sumr[idx][min(x,y)];
    };
    int anstl = 0;
    int maxans = 0;
    int cursum = 0;
    int strsum = 0;
    for(int j = 0;j < c;j ++)
        for(int i = 0;i + j <= m && i < r;i ++)
            strsum += rtl[i][j];
    for(int j = 0;j < c;j ++)
    {
        cursum = strsum;
        for(int i = 0;i < r;i ++){
        	cout << "rg:" << i << " " << j << " cu:" << cursum << "\n";
            if(cursum > maxans){
                anstl = 1;
                maxans = cursum;
            } else if(cursum == maxans){ anstl ++;}
            cout << "getl at" << i+1 << " " << j-m << " " << m << ":" <<getl(i+1,j-m,m) << "\n";
            cursum += getl(i+1,j-m,m);
            cout << "getr at" << i+1 << " " << j+m << " " << m-1 << ":" << getr(i+1,j+m,m-1) << "\n";
            cursum += getr(i+1,j+m,m-1);
            cout << "getl- at" << i-m << " " << j << " " << m << ":" << getl(i-m,j,m) << "\n";
            cursum -= getl(i-m,j,m);
            cout << "getr- at" << i-m+1 << " " << j-1 << " " << m-1 << ":" << getr(i-m+1,j-1,m-1) << "\n";
            cursum -= getr(i-m+1,j-1,m-1);
        }
        if(cursum > maxans){
            anstl = 0;
            maxans = cursum;
        } else if(cursum == maxans) anstl ++;
            
        strsum -= getl(0,j-m,m+1);
        strsum += getr(0,j+m+1,m+1);
    }
    cout << maxans << " " << anstl << "\n";
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}


/*2 2
4 1
1 1 1
1 2 1
2 1 1
2 2 1
*/