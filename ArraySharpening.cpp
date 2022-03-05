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
		int n; cin>>n; int a[n], cnt1=0, cnt2=0;
		for(int i = 0; i<n; i++)cin>>a[i];
		for(int i = 0; i<n; i++){
			if(a[i]>=cnt1) cnt1++;
			else break;
		}
		for(int i = n-1; i>=0; i--){
			if(a[i]>=cnt2) cnt2++;
			else break;
		}
		if((cnt1+cnt2==n && a[cnt1-1]!=a[n-cnt2]) || cnt1+cnt2>n) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}