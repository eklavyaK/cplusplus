#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int pre[100],f[100];
void str(){
    f[1] = f[2] = 1;
    int a = 1, b = 1;
    pre[1] = 1, pre[2] = 2;
    for(int i=3;i<100;i++){
        pre[i] = pre[i-1]+(a+b);
        b=(a+b),a = (b-a),f[i] = b;
        if(pre[i]>1e11)break;
    }
}

void code(){
    int n; cin>>n;
    vector<int> arr(n+1);
    int sum = 0, ch = 0;
    for(int i=1;i<=n;i++)cin>>arr[i], sum+=arr[i];
    for(int i=1;i<100;i++){
        if(pre[i]!=sum) continue;
        ch = i; break;
    }
    if(!ch){
        cout<<"NO"<<endl;
        return;
    }
    int vis[100]{};
    bool done = false;
    arr[0] = 1e18;
    sort(arr.begin(),arr.end(),greater<int>());
    function<bool(int,int)> dfs = [&](int i, int j){
        if(i==n+1) return true;
        if(j==0) return false;
        if(vis[j]||vis[j+1]==i){
            if(arr[i]>f[j])return false;
            return dfs(i,j-1);
        }
        if(arr[i]<f[j])return dfs(i,j-1);
        arr[i]-=f[j], vis[j] = i;
        if(!arr[i]){
            if(dfs(i+1,ch))return true;
            vis[j] = 0, arr[i]+=f[j];
            return dfs(i,j-1);
        }
        if(dfs(i,j-1)) return true;
        vis[j] = 0, arr[i]+=f[j];
        return dfs(i,j-1);
    };
    if(dfs(1,ch))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    str();
    int t; cin>>t; while(t--)code();
    return 0;
}