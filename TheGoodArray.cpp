#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    int ans = 0;
    for(int i=1;i<n;i++){
        ans = max(ans,(ll)(ceil((ld)i/k)+ceil((ld)(n-i)/k)));
    }
    cout<<max(ans,(ll)ceil((ld)n/k))<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}