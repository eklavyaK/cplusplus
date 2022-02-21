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
		int n; cin>>n; vector<int> a(n),b(n);
		for(int i = 0; i<n; i++)cin>>a[i];
		for(int i = 0; i<n; i++)cin>>b[i];
		if(find(b.begin(),b.end(),1)==b.end() || find(b.begin(),b.end(),0)==b.end()){
			int detect = 0;
			for(int i = 0; i<n-1; i++) if(a[i]>a[i+1]){detect=1;break;}
			detect?cout<<"No"<<endl:cout<<"Yes"<<endl;
		}
		else cout<<"Yes"<<endl;
	}
	return 0;
}