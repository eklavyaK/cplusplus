#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    ll n,q,l,r;
	cin>>n>>q;
	vector<ll>a(n+1),sum(n+1),xo(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		xo[i]=xo[i-1]^a[i];
	}
	cin>>l>>r;
	ll ans=sum[n]-xo[n],ll,rr=1;
	for(ll=1;ll<=n;ll++){
		if(rr<ll) rr=ll;
		while(rr<=n&&(sum[rr]-sum[ll-1])-(xo[rr]^xo[ll-1])<ans) rr++;
		if(rr>n) break;
		if(rr-ll<r-l){
			r=rr;l=ll;
		}
	}
	cout<<l<<' '<<r<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}