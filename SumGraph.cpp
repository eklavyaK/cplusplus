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
    int l = 1, r = n;
    int dist[n], curr = 0;
    cout<<'+'<<' '<<n+1<<endl<<flush;
    cin>>curr;
    cout<<'+'<<' '<<n+2<<endl<<flush;
    cin>>curr;
    for(int i=1;i<=n;i++){
        if(i<=n/2) dist[(i-1)*2] = i;
        else dist[(n-i)*2+1] = i;
    }
    if(n&1) dist[n-1] = n/2+1;
    int ans1[n], ans2[n];
    int k = 0, mx = 0;
    for(int i=2;i<=n;i++){
        cout<<"? "<<1<<' '<<i<<endl<<flush;
        int d; cin>>d;
        if(d>mx) k = i, mx = max(mx,d);
    }
    ans1[k-1] = dist[0], ans2[k-1] = dist[n-1];
    for(int i=1;i<=n;i++){
        if(i==k)continue;
        cout<<"? "<<k<<' '<<i<<endl<<flush;
        int d; cin>>d;
        ans1[i-1] = dist[d];
        ans2[i-1] = dist[n-1-d];
    }
    cout<<"! ";
    for(auto i : ans1) cout<<i<<" ";
    for(auto i : ans2) cout<<i<<" ";
    cout<<endl<<flush;
    cin>>n;
}
/*
2
6
1 4 2 5 3 6
2
1 2
*/

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}