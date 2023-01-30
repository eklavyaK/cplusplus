#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	ll w,d,h; cin>>w>>d>>h;
	ll a,b,f,g; cin>>a>>b>>f>>g;
	cout<<h+min({b+g+abs(a-f),a+f+abs(b-g),2*d-b-g+abs(a-f),2*w-a-f+abs(b-g)})<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}