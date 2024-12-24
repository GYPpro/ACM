#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;

char c[12][12],d[12][12];
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    
    for(int i=1;i<=9;++i){
    	for(int j=1;j<=9;++j){
    		c[i][j]=inf.readChar();
    	}
    	inf.readEoln();
    }
    
    bool ok=0;
    for(int i=1;i<=9;++i){
    	string s;
    	s=ouf.readToken();
    	if(s.size()!=9){
    		quitf(_wa, ".");
    	}
    	for(int j=1;j<=9;++j){
    		d[i][j]=s[j-1];
    		if(d[i][j]!='*'&&d[i][j]!=c[i][j]){
    			quitf(_wa, ".");
    		}
    		if(d[i][j]!='*')ok=1;
    	}
    }
    
    if(!ok){
    	quitf(_wa, ".");
    }
    
    for(int i=1;i<=9;++i){
    	for(int j=1;j<=9;++j)if(d[i][j]!='*'){
    		int cnt=0;
    		for(int I=max(1,i-1);I<=min(9,i+1);++I){
    			for(int J=max(1,j-1);J<=min(9,j+1);++J)if(d[I][J]=='*')++cnt;
    		}
    		if(cnt!=(int)(c[i][j]-48)){
    			quitf(_wa, ".");
    		}
    	}
    }
    quitf(_ok, ".");
}

