#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc; cin>>tc;
	while(tc--){
		int n,k; cin>>n>>k; int m=n;
		if(k>=n){cout<<1<<endl;continue;}
		for(int i = 2; i<=min(100000,k); i++)if(n%i==0){if(n/i<=k)m=min(m,i);else m=min(m,n/i);}
		cout<<m<<endl;
	}
	return 0;
}