#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;


int m[650][200005];

void code(){
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i].F;
    for(int i=0;i<n;i++)cin>>arr[i].S;
    sort(arr.begin(),arr.end());
    ll ans = 0, z = sqrt(2*n)+5;
    for(int i=1;i<=z;i++){
        for(int j=1;j<=n;j++) m[i][j]=0;
    }
    for(int i=0;i<n;i++){
        int r = arr[i].S%arr[i].F;
        for(int j=0;arr[i].F-r+j*arr[i].F<=n && j<=arr[i].F;j++){
            int num = (arr[i].F-r+j*arr[i].F+arr[i].S)/arr[i].F;
            if(num<=arr[i].F && num<z) ans+=m[num][arr[i].F-r+j*arr[i].F];
        }
        if(arr[i].F<z) m[arr[i].F][arr[i].S]++;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}