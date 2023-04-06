#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int m; cin>>m;
    vector<int> rem(m+5);
    vector<vector<int>> arr(2,vector<int>(m+2));
    for(int j=0;j<2;j++)
        for(int i=1;i<=m;i++)cin>>arr[j][i],arr[j][i]++;
    arr[0][1]--;
    for(int i=m;i>=1;i--){
        if(i&1) rem[i] = max({arr[0][i]+1+(m-i)*2,arr[1][i],arr[0][i+1]+(m-i-1)*2+2,arr[1][i+1]+1,rem[i+2]+2});
        else rem[i] = max({arr[1][i]+1+(m-i)*2,arr[0][i],arr[1][i+1]+(m-i-1)*2+2,arr[0][i+1]+1,rem[i+2]+2});
    }
    int ans = rem[1], curr = arr[1][1];
    for(int i=1;i<=m;i++){
        ans = min(ans,max(curr+(m-i)*2,rem[i+1]));
        if((i+1)&1) curr = max({curr+2,arr[0][i+1]+1,arr[1][i+1]});
        else curr = max({curr+2,arr[1][i+1]+1,arr[0][i+1]});
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}