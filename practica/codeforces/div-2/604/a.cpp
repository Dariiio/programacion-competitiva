// @tag1@tag2

//link problem
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define muno(v) memset(v,-1,sizeof(v))
#define pb push_back
#define fs first
#define sn second
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
#define dpr(v) cout << #v"=" << v << endl //;)
#define dpra(a,n) { forn(i,(n)) cout << (a)[i] << (i==(n)-1?'\n':' '); }
#define dprv(vec) dpra(vec,sz(vec))
#define all(s) s.begin(),s.end()
#define fin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main(){
	fin;
	int t;string s;
	cin>>t;
	while(t--){
		cin>>s;
		for(int i = 1;i<sz(s)-1;i++){
			if(s[i]=='?'){
				if(s[i-1]=='a'){
					if(s[i+1]=='?' || s[i+1] == 'c')
						s[i] = 'b';
					else
						s[i] = 'c';
				}
				if(s[i-1]=='b'){
					if(s[i+1]=='?' || s[i+1] == 'c')
						s[i] = 'a';
					else
						s[i] = 'c';
				}
				if(s[i-1]=='c'){
					if(s[i+1]=='?' || s[i+1] == 'b')
						s[i] = 'a';
					else
						s[i] = 'b';
				}
			}else if(s[i]==s[i-1]){
				s = "-1";
				break;
			}
		}
		cout<<s<<"\n";


	}



	return 0;
}