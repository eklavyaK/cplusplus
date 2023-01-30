#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n,p; cin>>n>>p;
    int arr[n]; set<int> st;
    for(int i=0;i<n;i++){
        cin>>arr[i]; st.insert(arr[i]);
    }
    int l = arr[n-1];
    for(auto i=st.rbegin();i!=st.rend();i++){
        if(*i==l-1)l--;
    }
    if(l==0){
        int now = p-1;
        while(st.count(now))now--;
        cout<<max(0,now-arr[n-1])<<endl;
        return;
    }
    int carry = 1;
    st.insert(0);
    for(int i=n-2;i>=0;i--){
        st.insert((arr[i]+carry)%p);
        carry = (arr[i]+carry)/p;
    }
    if(carry) st.insert(1);
    vector<int> z(st.rbegin(),st.rend());
    for(auto i : z) if(i==l)l--;
    cout<<p-arr[n-1]+max(0,l)<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}