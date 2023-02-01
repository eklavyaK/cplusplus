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
    set<int> st;
    for(int i=0;i<n;i++)cin>>arr[i],st.insert(arr[i]);
    if(st.size()!=n || st.count(0)){
        cout<<"YES"<<endl;
        return;
    }
    st.clear();
    for(int i=0;i<(1<<n);i++){
        int s = 0;
        for(int j=0;j<n;j++){
            if((1<<j)&i)s+=arr[j];
        }
        st.insert(s);
    }
    if(st.size()==(1<<n))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}