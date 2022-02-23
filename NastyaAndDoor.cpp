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
		int n,k; cin>>n>>k; int a[n],count=0;vector<int> peaks;
		for(int i = 0; i<n; i++)cin>>a[i];
		for(int i = 1; i<n-1; i++)if(a[i]>a[i-1]&&a[i]>a[i+1])peaks.emplace_back(i+1);
		if(peaks.size()==1)cout<<2<<" "<<max(peaks[0]-k+2,1)<<endl;
		else if(peaks.size()==0)cout<<1<<" "<<1<<endl;
		else{
			int r=0;pair<int,int> p; p.first=2;p.second=max(peaks[0]-k+2,1);
			for(int i = 0; i<peaks.size(); i++){
				while(r+1<peaks.size()&&peaks[r+1]-peaks[i]+3<=k)r++;
				if(r-i+2>p.first){p.first=r-i+2;p.second=max(1,peaks[r]-k+2);}
			}
			cout<<p.first<<" "<<p.second<<endl;
		}
	}
	return 0;
}