#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==0){cout<<1<<endl;return;}
	int ans = a+2*min(b,c);
	if(a>=abs(b-c)+d) ans+=abs(b-c)+d;
	else ans += a+1;
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}