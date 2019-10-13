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

struct sg{
	int t,x,y;
};
bool cmp(sg a,sg b){
	if(a.x < b.x) return true;
	else if(a.x == b.x){
		return (a.y>b.y);
	}
	else return false;
}

int f(sg a, sg b){
	if(a.x < b.x){
		if(a.y < b.x) return 0;
		else return a.y - b.x;
	}else{
		if(a.x > b.y) return 0;
		else return b.y - a.x;
	}
}

vector<sg> v1,v2;

int main(){
	fin;
	int n;cin>>n;char t;int x,y;
	forn(i,n){
		cin>>t>>x>>y;
		if(t == 'J') v1.pb(sg{1,x,y});
		else v2.pb(sg{0,x,y});
	}

	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);

	//for(auto a: v1) cout<<a.x<<" "<<a.y<<"\n\n";

	int i=0,j=0,mx1=0,mx2=0;
	while(i<sz(v1) || j<sz(v2)){
		if(i<sz(v1)){
			if(v1[i].y<=mx1) v1.erase(v1.begin()+i),i--;
			mx1 = max(mx1,v1[i].y);
		}
		if(j<sz(v2)){
			if(v2[j].y<=mx2) v2.erase(v2.begin()+j),j--;
			mx2 = max(mx2,v2[j].y);
		}
		i++;j++;
	}
	//for(auto a: v2) cout<<a.x<<" "<<a.y<<"\n";

	cout<<"\n"<<f(sg{1,2,5},sg{1,1,10})<<"\n";

	
	return 0;
}