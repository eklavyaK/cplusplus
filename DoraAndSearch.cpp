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
    int l = 0, r = n-1;
    while(l<r){
        if(arr[l]==*st.rbegin()||arr[l]==*st.begin()){
            st.erase(arr[l]); l++;
        }
        else if(arr[r]==*st.rbegin()||arr[r]==*st.begin()){
            st.erase(arr[r]); r--;
        }
        else{
            cout<<l+1<<' '<<r+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}