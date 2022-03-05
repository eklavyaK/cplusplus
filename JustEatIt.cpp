#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n; cin>>n; int a[n]; bool detect = false;
		for(int i = 0; i<n; i++)cin>>a[i]; long long sum = 0;
		for(int i = 0; i<n-1; i++){
			sum+=a[i];if(sum<=0){detect = true;break;}
		}
		if(detect){cout<<"NO"<<endl;continue;}sum = 0;
		for(int i=n-1;i>=1;i--){
			sum+=a[i];if(sum<=0){detect = true;break;}
		}
		detect?cout<<"NO"<<endl:cout<<"YES"<<endl;
	}
	return 0;
}