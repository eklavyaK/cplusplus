#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;

ll query(ll a, ll b){
	cout<<'?'<<' '<<a<<' '<<b<<endl<<flush;
	ll k; cin>>k; return k;
}

void code(){
	cout.precision(20);
	for(int i=3;i<=27;i++){
		ll f = query(1,i);
		if(f==-1){
			cout<<"! "<<i-1<<endl;
			return;
		}
		ll g = query(i,1);
		if(f!=g){
			cout<<"! "<<f+g<<endl;
			return;
		}
	}
	cout<<1e18<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t = 1; while(t--)code();
	return 0;
}