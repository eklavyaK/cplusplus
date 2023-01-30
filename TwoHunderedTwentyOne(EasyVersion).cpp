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
	int n,q; cin>>n>>q;
	string s; cin>>s;
	int pos[n], p = 0;
	for(int i=0;i<n;i+=2){
		s[i] = s[i]=='+'?'-':'+';
	}
	for(int i=0;i<n;i++) {if(s[i]=='+')p++;pos[i] = p;}
	while(q--){
		int u,v;
		cin>>u>>v;
		u--; v--;
		if((v-u+1)%2==0){
			int k = 0;
			if(u>0) k = pos[v]-pos[u-1];
			else k = pos[v];
			if(k == (v-u+1)/2) cout<<0<<endl;
			else cout<<2<<endl;
		}
		else cout<<1<<endl;
	}
}