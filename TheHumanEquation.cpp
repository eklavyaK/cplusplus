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
    set<pair<int,int>> idx;
    set<pair<int,int>> st;
    int arr[n], cnt = 0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        int curr = arr[i];
        while(i+1<n && ((arr[i]<0 && arr[i+1]<0)||(arr[i]>=0 && arr[i+1]>=0))){
            i++; curr+=arr[i];
        }
        cnt++;
        idx.insert({cnt,abs(curr)});
        st.insert({abs(curr),cnt});
    }
    int ans = 0;
    while(!st.empty()){
        auto [mn,id] = *st.begin();
        auto l = idx.lower_bound({id,mn});
        auto r = idx.upper_bound({id,mn});
        st.erase({mn,id});
        if(l!=idx.begin() && r!=idx.end()){
            l--;
            st.erase({l->S,l->F});
            st.erase({r->S,r->F});
            int a = (l->S)+(r->S) - mn, in = l->F;
            idx.erase(*l);
            idx.erase(*r);
            idx.erase({id,mn});
            idx.insert({in,a});
            st.insert({a,in});
        }
        else if(l==idx.begin() && r==idx.end()){
            ans = mn; break;
        }
        else idx.erase(*l);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}