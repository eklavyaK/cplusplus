#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
	int n,m; cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>a[i][j];
	}
	function<bool(int)> check = [&](int l){
		int c[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]<l)c[i][j] = 0;
				else c[i][j] = 1;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]) c[i][j] = c[i-1][j] + c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			set<pair<int,int>> st;
			for(int j=0;j<m;j++){
				st.insert({c[i][j],j});
				if(j>=l-1){
					int now = st.begin()->first;
					if(now>=l)return true;
					st.erase({c[i][j-l+1],j-l+1});
				}
			}
		}
		return false;
	};
	int l = 1, r = 1000;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid))l=mid+1;
		else r = mid-1;
	}
	cout<<l-1<<endl;
}