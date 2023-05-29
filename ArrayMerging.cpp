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
    map<int,int> a,b;
    int arr[n],brr[n];
    set<int> st;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];
    for(int i=0;i<n;i++){
        int cnt = 1;
        st.insert(arr[i]);
        while(i+1<n && arr[i+1]==arr[i]) i++,cnt++;
        a[arr[i]] = max(a[arr[i]],cnt);
    }
    for(int i=0;i<n;i++){
        int cnt = 1;
        st.insert(brr[i]);
        while(i+1<n && brr[i+1]==brr[i]) i++,cnt++;
        b[brr[i]] = max(cnt,b[brr[i]]);
    }
    int ans = 0;
    for(auto i : st){
        ans = max(ans,a[i]+b[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}