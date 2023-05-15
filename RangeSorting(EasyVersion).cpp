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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int f[n]{}, ans = 0;
    for(int i=0;i<n;i++){
        stack<int> st;
        int mn = arr[i];
        st.push(arr[i]);
        for(int j=i-1;j>=0;j--){
            mn = min(mn,arr[j]);
            while(!st.empty() && arr[j]>st.top()) st.pop();
            st.push(mn);
            f[i]+=(i-j+1-st.size());
        }
        ans+=f[i];
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}