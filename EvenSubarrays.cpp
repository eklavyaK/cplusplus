#include<bits/stdc++.h>
using namespace std;
int m;
vector<int> store;
void compute(int len){
	int i = 0;
	store.clear();
	while(i*i<len){
		store.push_back(i*i);
		i++;
	}
	m = store.size();
}
void codeforce(){
	int n; cin>>n; int a[n];
	for(int i = 0; i<n; i++)cin>>a[i];
	int len = 1, now = 0; long long cnt = 0;
	for(int i=0;i<=18;i++){
		if((1<<i)&n) len = 1<<(i+1);
	}
	compute(len);
	vector<long long> st(len);
	for(int i=0;i<n;i++){
		now = now^a[i];
		int k = sqrt(now);
		if(k*k==now)cnt++;
		for(int j=0;j<m;j++){
			cnt+=st[store[j]^now];
		}
		st[now]++;
	}
	cout<<((long long)n*(n+1)/2-cnt)<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t;
	while(t--){
		codeforce();
	}
}