#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m; cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int value[n];
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int k = i;
        value[i] = arr[i];
        while(k+1<n && arr[k+1]>=arr[i])k++;
        st.insert({i,k});
        i = k;
    }
    function<void(int)> update = [&](int i){
        auto it = st.lower_bound({i,n});
        it--;
        auto [l,r] = *it;
        if(arr[i]>=value[l])return;
        if(l!=i){
            st.erase({l,r});
            st.insert({l,i-1});
        }
        value[i] = arr[i];
        it = st.lower_bound({i,0});
        while(true){
            if(value[it->F]<arr[i] || it==st.end()){
                st.insert({i,r});
                break;
            }
            auto itr = it; it++;
            r = itr->S;
            st.erase(*itr);
        }
    };
    while(m--){
        int k,d; cin>>k>>d;
        k--; arr[k]-=d;
        update(k);
        cout<<st.size()<<" ";
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}