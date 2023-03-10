#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    vector<int> brr(n);
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        cin>>arr[i].F;
        cin>>brr[i];
        arr[i].S = i;
        st.insert({brr[i],i});
    }
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    int mx = -1e18-5, ans = 1e9+5;
    st.insert({1e18+5,0});
    st.insert({-1e18-5,0});
    for(int i=0;i<n;i++){
        int now = abs(arr[i].F-mx);
        st.erase({brr[arr[i].S],arr[i].S});
        auto it = st.lower_bound({arr[i].F,0});
        now = min(now,abs(max(it->first,mx)-arr[i].F));
        it--;
        now = min(now,abs(max(it->first,mx)-arr[i].F));
        ans = min(ans,now);
        mx = max(mx,brr[arr[i].S]);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}