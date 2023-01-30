#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	int curr = 0, ans = n;
	set<int> st; st.insert(0);
	for(int i=0;i<n;i++){
		int k; cin>>k; curr^=k;
		if(st.count(curr)) ans--,st.clear();
		st.insert(curr);
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}