// ACCEPTED @graphs@implementation@dfs and similar

//https://codeforces.com/group/YjFmW2O15Q/contest/102363/submission/61568778
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

int g[2500][2500],visited[2500][2500],n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<ii> centros;

bool u_es_ok(ii u){
	if((u.fs >= n || u.fs <0) || (u.sn >= m || u.sn <0)) return false;
	else return true;
}

bool es_centro(ii v){
	if(g[v.fs][v.sn] == 1){
		bool ban = true;
		forn(i,4){
			ii u = { v.fs+dx[i], v.sn+dy[i] };
			if(u_es_ok(u) && g[u.fs][u.sn] != 1) ban = false;
		}
		return ban;
	}else return false;
}

void dfs(ii v){
	visited[v.fs][v.sn] = 1;
	forn(i,4){
		ii u = { v.fs+dx[i], v.sn+dy[i] };
		//Recorre solo los * adyacentes
		if(u_es_ok(u) && visited[u.fs][u.sn] == -1 && g[u.fs][u.sn] == 1)
			dfs(u);
	}
	if(es_centro(v)) centros.pb(v);
}

//recive un centro
bool es_cruz(ii v){
	int cntAr=0, cntAb=0, cntI=0, cntD=0;
	ii u;bool valido = true;
	//cuento para derecha e izquierda y controlo adyacencia
	while( v.sn+cntD < m && g[v.fs][v.sn+cntD]==1 && valido){
		//veo si tiene adjacentes arriba o abajo
		cntD++; //---->
		u = {v.fs+1,v.sn+cntD}; //----> Y ABAJO
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs][v.sn+cntD]==1){
			valido = false;//,cout<<"1";
			break;
		}
		u = {v.fs-1,v.sn+cntD};// ----> Y ARRIBA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs][v.sn+cntD]==1){
			valido = false;//,cout<<"2";
			break;
		}
		//cntD++;
	}
	while( v.sn-cntI >=0 && g[v.fs][v.sn-cntI]==1 && valido){
		//veo si tiene adjacentes arriba o abajo
		cntI++; //<----
		u = {v.fs +1,v.sn-cntI };//<---- y ABAJO
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs][v.sn-cntI]==1){
			valido = false;//,cout<<"3";
			break;
		}
		u= {v.fs-1,v.sn-cntI};//<----- y ARRIBA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs][v.sn-cntI]==1){
			valido = false;//,cout<<"4";
			break;
		}
		//cntI++;
	}
	
	while( v.fs+cntAb < n && g[v.fs+cntAb][v.sn]==1 && valido){
		//veo si tiene adjacentes izq o der
		cntAb++; // ABAJO
		u = {v.fs+cntAb,v.sn+1}; // ABAJO Y DERECHA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs+cntAb][v.sn]==1){
			valido = false;//,cout<<"5";
			break;
		}
		u = {v.fs+cntAb,v.sn-1}; // ABAJO E IZQUIERDA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs+cntAb][v.sn]==1){
			valido = false;//,cout<<"6";
			break;
		}
		//cntAb++;
	}
	while( v.fs-cntAr >= 0 && g[v.fs-cntAr][v.sn]==1 && valido){
		// veo si tiene adj izq o der
		cntAr++; // ARRIBA
		u = {v.fs-cntAr,v.sn+1};// ARRIBA Y DERECHA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs-cntAr][v.sn]==1){
			valido = false;//,cout<<"7";
			break;
		}
		u = {v.fs-cntAr,v.sn-1};// AARRIBA Y IZQUIERDA
		if(u_es_ok(u) && u!=v && g[u.fs][u.sn] == 1 && g[v.fs-cntAr][v.sn]==1){
			valido = false;//,cout<<"8";
			break;
		}
		//cntAr++;	
	}
		
	if(cntI == cntD && cntD==cntAr && cntAb>cntD && valido) return true;	
	else return false;
}

int main(){
	fin;
	muno(visited); // -1 
	zero(g); // 0 
	
	cin>>n>>m;char ax;
	forn(i,n)
		forn(j,m){
			cin>>ax;
			if(ax=='*') g[i][j] = 1;}
			
	//forn(i,n){
	//	forn(j,m) cout<<g[i][j]<<" ";
	//	cout<<"\n";
	//}
	forn(i,n)
		forn(j,m) if(es_centro({i,j}) && visited[i][j]!=1) dfs({i,j});//cout<<i<<" "<<j<<"\n";

	//forn(i,n){
	//	forn(j,m) if(visited[i][j] == -1) cout<<"."; else cout<<"*";
	//	cout<<"\n";
	//}
	//cout<<centros.size()<<"\n";
	//for(auto a: centros) cout<<a.fs<<" "<<a.sn<<"\n";
	int ans = 0;
	for(auto a: centros){
		if(es_cruz(a)) ans++;
	}
	cout<<ans;
	return 0;
}
/*
4 3
.*.
***
.*.
**.




*/


