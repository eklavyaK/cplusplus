#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
 
 
 
void code(int t){
	int n; cin>>n;
	if(n&1){
		cout<<-1<<endl;
	}
	else{
		int x = n/2, y = 3*n/2;
		if((x^y)==n){
			cout<<x<<' '<<y<<endl;
		}
		else cout<<-1<<endl;
	}
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code(t);
	return 0;
}