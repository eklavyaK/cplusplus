#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
	string s = "3141592653589793238462643383279502884197169399375105820974944";
	string r; cin>>r;
	int n = r.size(),cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]==r[i])cnt++;
		else break;
	}
	cout<<cnt<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}