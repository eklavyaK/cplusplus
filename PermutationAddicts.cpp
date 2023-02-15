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
    int k = n, mn = n+1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<mn) mn = min(mn,i+1), k--;
        else break;
    }
    vector<vector<int>> graph(n+2);
    int cnt[n+2]{};
    for(int i=0;i<n;i++){
        graph[arr[i]].push_back(i+1);
        cnt[arr[i]]++;
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int node){
        int next = -1;
        for(auto i : graph[node]){
            if(cnt[i])next = i;
            else ans.push_back(i);
        }
        if(next==-1)return;
        ans.push_back(next);
        dfs(next);
    };
    if(cnt[0])dfs(0);
    else dfs(n+1);
    cout<<k<<endl;
    for(auto i : ans) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}