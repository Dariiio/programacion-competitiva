// @tag1@tag2

//link problem
#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(register int i=(a); i<(b); i++)
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

int dp[2010][2010];

int main(){
	fin;
	int t,n,a[2010];

	cin>>t;
	while(t--){
		map <int, vi> a2;
		map <int, int> a3; // k y su id entre 0 y 1999
		muno(dp);		map <int, vi> a2;


		cin>>n;
		forr(i,1,n+1){
			cin>>a[i];
			a2[a[i]].pb(i);
			if(a3[a[i]] == 0){
				a3[a[i]] = i; // asigno id a k
				dp[a3[a[i]]][i] = 1; //cuento uno en la matriz de cantidades
			}else{
				dp[a3[a[i]]][i] = dp[a3[a[i]]][a3[a[i]]] +1;
				dp[a3[a-1[i]]][a3[a[i]]]++;
			}
		}
		/*
		forn(i,2010){
			forn(j,2010){
				cout<<dp[i][j]<<" ";
			}cout<<"\n";
		}*/

		cout<<"Id de k: "<<a3[1]<<"\n";
		cout<<"dp[k][c] :"<<dp[a3[1]][4]<<"\n";

		int cnt = 0;
		for(int i = n-2;i>=0;i--){
			for(int j = n-1;j>i;j--){
				int k = 2*a[j]-a[i];
				{
					if(k == 2*a[j]-a[i] && k>0){
						//auto up = upper_bound(a2[k].begin(),a2[k].end(),j);
						//int posup = up - a2[k].begin();
						//int cant = a2[k].size()-posup;
						//cnt += cant;
						//cout<<a[i]<<" "<<a[j]<<" "<<k<<"\n";
						//cout<<a2[k][p]<<"->"<<a[a2[k][p]]<<"\n";
					}
				}
			}
		}
	cout<<cnt<<"\n";
	}
	return 0;
}
/*
3 4 5
3 4 5
3 4 5
1 5 9
1 5 9
4 5 6
4 5 6
5 5 5
8

3 4 9
3 4 9
3 4 9
4 5 2
4
*/