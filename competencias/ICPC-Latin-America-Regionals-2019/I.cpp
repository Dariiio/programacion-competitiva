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

const ll M = 1e9+7;
int n,l;
vi g[2010];set<int> s;int comp[2010];
ll cnt = 0;ll cnt2[2010];

void dfs(int v){
	ll initial = cnt;
	for(auto u :g[v]){
		if(u > l){
			s.insert(u);
			cnt++;
		}
		else if(!comp[u]){
			dfs(u);
		}else{
			//cout<<"A";
			cnt = cnt + cnt2[u];
			cnt %= M;
		}
	}
	cnt2[v] = cnt - initial;
	if(cnt2[v]<0) cnt2[v] = M - cnt2[v];

	comp[v] = 1;
}

int main(){
	fin;
	cin>>n>>l;

	zero(comp);
	zero(cnt2);

	forr(i,1,l+1){
		int k;cin>>k;
		forn(j,k){
			int ax;cin>>ax;
			g[i].pb(ax);
		}
	}

	forr(i,1,l+1){cout<<i<<": ";for(auto a: g[i])cout<<a<<" ";cout<<"\n";}

	dfs(1);

	cout<<cnt%M<<" "<<sz(s)<<"\n";
	
	return 0;
}