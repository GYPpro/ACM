#include <stdio.h>
#include <iostream>
using namespace std;
int arr[1100][1100];
int vst[1100];
void solve();
void mergesort(int start, int end) {
    vst[start] = vst[end] = 1;
	if(arr[start-1][end-1]==1){
		return;
	}
	// printf("? %d %d\n",start,end);
    cout << "? " << start << " " << end << "\n";
	// fflush(stdout);
	int k;
	// scanf("%d",&k);
    cin >> k;
	if(k==start || k == end){
		arr[start-1][end-1]=1;	
	} else {
        // if(!vst[k]) 
        mergesort(start,k);
        mergesort(k,end);		
	}		
}
 
int main(){
	int t;
    ios::sync_with_stdio(0);
	// scanf("%d",&t);
    cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
void solve(){
	int n;
	// scanf("%d",&n);
    cin >> n; 
    for(int i = 0;i < 1010;i ++) vst[i] = 0;
	for(int i=2;i<=n;i++)
	    mergesort(1,i);
	// printf("! ");
    cout << "! ";
	// fflush(stdout);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
                // printf("%d %d ",i+1,j+1);
                cout << i+1 << " " << j+1 << " ";
                  //fflush(stdout);
                arr[i][j]=0;
			}
			
		}
	}
	// printf("\n");
    cout << "\n";
	// fflush(stdout);
}