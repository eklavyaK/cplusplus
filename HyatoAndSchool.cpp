#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	int o = 0, e = 0;
	int arr[n];
	for(int i=0;i<n;i++){
		int k; cin>>k;
		arr[i] = k;
		if(k&1)o++;
		else e++;
	}
	if(o>=3){
		cout<<"YES"<<endl;
		int k = 3;
		for(int i=0;i<n;i++){
			if(k>0 && arr[i]&1){
				cout<<i+1<<' ';
				k--;
			}
		}
		cout<<endl;
	}
	else if(e>=2 && o>=1){
		cout<<"YES"<<endl;
		int k = 2, l =1;
		for(int i=0;i<n;i++){
			if(l>0 && arr[i]&1){
				cout<<i+1<<' ';
				l--;
			}
			else if(k>0 && arr[i]%2==0){
				cout<<i+1<<" ";
				k--;
			}
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}