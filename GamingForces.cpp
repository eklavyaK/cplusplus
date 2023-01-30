#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n;cin>>n;
	int cnt = 0;
	for(int i=0;i<n;i++){
		int k; cin>>k;
		if(k==1)cnt++;
	}
	cout<<cnt/2+cnt%2+n-cnt<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}