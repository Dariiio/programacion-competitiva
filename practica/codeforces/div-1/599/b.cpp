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


struct UnionFind{
	vector<int> f;
	void init(int n){f.clear();f.insert(f.begin(),n,-1);}
	int comp(int x){return (f[x]==-1?x:f[x]=comp(f[x]));}
	bool join(int i,int j){
		bool con = comp(i)==comp(j);
		if(!con) f[comp(i)] = comp(j);
		return con; 
	}
};

UnionFind uf;
int n,m;

struct Ar{int a,b,w;};
bool operator<(const Ar& a, const Ar& b) {return a.w < b.w;}
vector<Ar> E;


ll kruskal(){
	ll cost = 0;
	sort(E.begin(),E.end());
	uf.init(m);
	for(auto i:E){
		if(uf.comp(i.a) != uf.comp(i.b)){
			uf.join(i.a,i.b);
			cost += i.w;
		}
	}
	return cost;
}


int main(){
	fin;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		E.pb({a,b,1});
	}
	cout<<kruskal()<<"\n";
	 
	return 0;
	
}