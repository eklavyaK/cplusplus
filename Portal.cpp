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
	vector<string> s(n);
	int sum[n][m], count[n][m];
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<m;j++){
			if(s[i][j]=='1')cnt++;
			if(i==0)sum[i][j] = cnt;
			else sum[i][j] = sum[i-1][j]+cnt;
			count[i][j] = cnt;
		}
	}
	int ans = 1e9, p = 1;
	for(int i=0;i<m;i++){
		for(int j=i+3;j<m;j++){
			int mx = -1e9, f[n], z = 0;
			for(int k=0;k<n;k++){
				z+=(s[k][i]=='0')+(s[k][j]=='0');
				int t = ((j-i-1)-(count[k][j-1]-count[k][i]));
				f[k] = z-t; f[k] = f[k]+(sum[k][j-1]-sum[k][i]);
				// if(i==1 && j==4){
				// 	cout<<k<<endl;
				// 	cout<<z<<' '<<t<<' '<<f[k]<<endl;
				// }
				if(k>3){
					mx = max(mx,f[k-4]);
					ans = min(ans,f[k]-mx+2*t-(s[k][i]=='0')-(s[k][j]=='0')-(count[k][j-1]-count[k][i]));
				}
			}
		}
	}
	cout<<ans<<endl;cout.flush();
}