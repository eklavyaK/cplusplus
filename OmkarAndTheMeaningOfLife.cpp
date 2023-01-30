#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
int query(vector<int> q){
	cout<<"? ";
	for(int i=1;i<n;i++)cout<<q[i]<<" ";
	cout<<q[n]<<endl<<flush;
	int k; cin>>k; return k;
}
void code(){
	cin>>n;
	vector<int> st;
	for(int i=2;i<=n;i++){
		vector<int> s(n+1,i);
		s[n] = 1;
		int now = query(s);
		if(now)k++,st.push_back(now);
		else break;
	}
	vector<int> ans(n+1);
	ans[n] = k+1;
	for(auto i : st){
		ans[i] = k--;
	}
	k = ans[n]+1;
	for(int i=2;i<=n-ans[n]+1;i++){
		vector<int> s(n+1,1);
		s[n] = i;
		ans[query(s)]=k++;
	}
	cout<<"! ";
	for(int i=1;i<n;i++)cout<<ans[i]<<" ";
	cout<<ans[n]<<endl<<flush;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t=1; while(t--)code();
	return 0;
}