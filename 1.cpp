#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin>>t;
	while(t--){
	    int n,k;  cin>>n>>k;
        int a[n], b[n], ans = 0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<pair<int,int>> curr(n);
        for(int i=0;i<n;i++)curr[i] = {a[i]+b[i],i};
        sort(curr.begin(),curr.end());
        for(auto i : curr) cout<<i.first<<endl;
        for(int i=0;i<n;i++){
            if(k-curr[i].first>=0)k-=curr[i].first,ans++;
            else{
                for(int j=0;j<n;j++){
                    if(j<i && k+curr[j].first-curr[i].first-a[curr[j].second]>=0){
                        ans++;break;
                    }
                    else if(j>=i && k-a[curr[j].second]>=0){
                        ans++;break;
                    }
                }
                break;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}