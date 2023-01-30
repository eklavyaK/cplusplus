#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	int arr[n], index[n+1]{};
	for(int i=0;i<n;i++){
		cin>>arr[i];
		index[arr[i]]=i;
	}
	int l = 0, r = 0, x = 0, y = 0;
	if(n%2){
		l = r =  index[n/2+1];
		x = n/2; y = n/2+2;
	}
	else{
		l = index[n/2];
		r = index[n/2+1];
		x = n/2-1; y = n/2+2;
		if(r<l){
			cout<<n/2<<endl;
			return;
		}
	}
	while(x>0 && y<=n){
		if(index[x]>l || index[y]<r || index[x]>index[y]){
			cout<<x<<endl;
			return;
		}
		else{
			l=index[x]; r = index[y];
			x--;y++;
		}
	}
	cout<<0<<endl;
}	

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}