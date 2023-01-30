#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
void display(int k){
	cout<<"! "<<k<<endl<<flush;
}
int query(int k){
	cout<<"- "<<k<<endl<<flush;
	cin>>k; return k;
}
void code(){
	int n; cin>>n;
	int ans = 0, now = 0;
	while(true){
		if(n==0){
			display(ans);
			break;
		}
		else{
			int bits = query(now+1);
			ans+=(1<<(bits-n+1));
			now = (1<<(bits-n+1))-1;
			n--;
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}