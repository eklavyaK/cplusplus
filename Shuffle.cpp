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
		int n,x,m; cin>>n>>x>>m;
		int lf=x,rf=x;
		while(m--){
			int l,r;cin>>l>>r;
			if((l>=lf&&l<=rf)||(r<=rf&&r>=lf)||(l<=lf&&r>=rf)){
				lf=min(lf,l);rf=max(rf,r);
			}
		}
		cout<<rf-lf+1<<endl;
	}
	return 0;
}