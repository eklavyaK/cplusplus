#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
void code(){
	int n,m; cin>>n>>m;
	struct node{
		node* next[11];
	};
	node* a = new node();
	vector<vector<int>> arr(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		node* now = a;
		vector<int> in(m+1);
		for(int j=1;j<=m;j++)cin>>arr[i][j],in[arr[i][j]]=j;
		for(int j=1;j<=m;j++){
			if(now->next[in[j]]){
				now = now->next[in[j]];
			}
			else{
				node* t = new node();
				now->next[in[j]] = t;
				now = now->next[in[j]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		int cnt = 0;
		node* now = a;
		for(int j=1;j<=m;j++){
			if(now->next[arr[i][j]]){
				cnt++;
				now = now->next[arr[i][j]];
			}
			else break;
		}
		cout<<cnt<<" ";
	}
	cout<<endl; a = NULL;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}