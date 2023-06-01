#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


void code()
{
    int n,c; cin>>n>>c;
    vector<int> arr(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    int k = st.size();
    int l = 1, r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(3*mid-2>=n) r = mid-1;
        else l = mid+1;
    }
    r++;
    cout<<max(0ll,(r-k)*c)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}