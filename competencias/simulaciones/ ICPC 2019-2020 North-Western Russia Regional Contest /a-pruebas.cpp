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
	int t,n,a[2010];
	cin>>t;
	while(t--){
		cin>>n;
		forn(i,n) cin>>a[i];

		int cnt = 0;
		forn(i,n){
			forr(j,i,n){
				forr(k,j,n){
					if(i != j && j!=k && k!=i){
						if((a[j]-a[i]==a[k]-a[j]))
							cnt++,cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";
					}
				}
			}
		}
		cout<<cnt<<"\n";
		cnt = 0;

	}


	return 0;
}