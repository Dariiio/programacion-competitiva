#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t,n;cin>>t;
    string p,ans;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>p; 
		//int sc=1,ec=1;
		
		for(int i=0;i<(int)p.size();i++){
			if(p[i]=='S') p[i]='E';
			else if(p[i]=='E') p[i]='S';
		}
		
		cout<<"Case #"<<tc<<": "<<p<<"\n";
		
		
	}
       
    
    return 0;
}
