// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         vector<int>colors(n);
         if(n==1){
             cout<<1<<endl;
             colors[0]=1;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else if(n==2){
             cout<<2<<endl;
             colors[0]=1;
             colors[1]=2;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else if(n==3){
             cout<<2<<endl;
             colors[0]=1;
             colors[1]=2;
             colors[2]=2;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else if(n==4){
             cout<<3<<endl;
             colors[0]=1;
             colors[1]=2;
             colors[2]=2;
             colors[3]=3;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else if(n==5){
             cout<<3<<endl;
             colors[0]=1;
             colors[1]=2;
             colors[2]=2;
             colors[3]=3;
             colors[4]=3;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else if(n==6){
             cout<<4<<endl;
             colors[0]=1;
             colors[1]=2;
             colors[2]=2;
             colors[3]=3;
             colors[4]=3;
             colors[5]=4;
             for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }else{
             int mncolor=4;
             cout<<mncolor<<endl;
             int start=1;
             for(int i=0;i<n;i++){
                 colors[i]=start;
                 start=(start%mncolor+1);
             }
              for(int i=0;i<n;i++){
                 cout<<colors[i]<<" ";
             }
             cout<<endl;
         }
     }

    return 0;
}