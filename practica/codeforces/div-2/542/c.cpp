// @dfs and similar

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

int n,a1,b1,a2,b2,vst[10000][10000];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
string g[1000];

bool val(int a,int b){
	if (a<0 || b<0 || a>=n || b>=n)
		return false;
	else
		return true;
}

void dfs(int x,int y){
	vst[x][y] = 1;
	forn(i,4){
		int ux = x +dx[i], uy = y +dy[i];
		if(val(ux,uy) && vst[ux][uy]==0 && g[ux][uy] != 0)
			dfs(ux,uy);
	}
	cout<<x<<" "<<y<<"\n";
}


int main(){
	fin;
	zero(vst);
	cin>>n>>a1>>b1>>a2>>b2;
	forn(i,n) cin>>g[i];
	/*
	forn(i,n){
		forn(j,n) cout<<g[i][j];
		cout<<"\n";	
	}
	*/
	dfs(1,1);
	

	return 0;
}