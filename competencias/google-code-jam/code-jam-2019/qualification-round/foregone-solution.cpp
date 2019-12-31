#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;cin>>t;
    string n,nn="";
    
    
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        nn="";
        int i=0;
        while(i<(int)n.size()){
			while(n[i] == '4' && i<(int)n.size()){
				n[i] = '3';
				nn.push_back('1');
				i++;
			}
			while(n[i]!='4' && i<(int)n.size()){
				nn.push_back('0');
				i++;
			}
		}
		cout<<"Case #"<<tc<<": "<<n<<" "<<nn<<"\n";
        
	}
       
    
    return 0;
}
