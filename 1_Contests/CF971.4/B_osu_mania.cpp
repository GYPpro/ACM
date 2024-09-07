#include <stdio.h>
void solve();
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	solve();
	}

}
void solve(){
	int n,m;
	int arr[1000];
	char s[4];
	scanf("%d",&n);
	// fflush(stdin);
	int p=n;
	while(n--){
		scanf("%s",&s);
		// fflush(stdin);
		for(int i=0;i<4;i++){
			if(s[i]=='#'){
				arr[n]=i+1;
			}
		}
	}
	for(m=0;m<p;m++){
		printf("%d ", arr[m]);
	}
	printf("\n");
	return;
}
