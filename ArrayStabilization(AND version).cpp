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
	int n,d; cin>>n>>d;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int done[n]{}, mx = 0;
	for(int i=0;i<n;i++){
		if(done[i]) continue;
		else done[i] = 1;
		vector<int> v; bool f = 1;
		int k = i, initial = a[i];
		if(!initial)f = 0;
		v.push_back(a[k]);
		while(true){
			if(k+d>=n) k = d-n+k;
			else k = k+d;
			if(!done[k]){
				v.push_back(a[k]);
				if(f){
					initial+=a[k];
					if(!a[k])f = 0;
				}
				done[k] = 1;
			}
			else break;
		}
		int m = v.size(), now = 0, check = 1;
		for(int j=0;j<m;j++){
			if(v[j]){
				now++;
				mx = max(mx,now);
			}
			else now = 0;
			check=check&v[j];
		}
		if(v[m-1])mx = max(mx,now+initial);
		if(check){
			cout<<-1<<endl;
			return;
		}
	}
	cout<<mx<<endl;
}