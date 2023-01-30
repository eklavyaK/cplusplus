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
    int arr[n+1], ans = 0, cnt = 0;
    int next[n+1]{};
    bool f = false;
    vector<vector<int>> prev(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i+arr[i]<=n && i+arr[i]>=1)next[i] = i+arr[i],prev[i+arr[i]].push_back(i);
        else next[i] = -1;
    }
    for(int i=1;i<=n;i++){
        if(next[i]!=-1)continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front(); 
            q.pop(); cnt++;
            if(node==1) f = true;
            for(auto j : prev[node]){
                q.push(j);
            }
        }
    }
    int end = 1;
    set<int> st;
    while(true){
        st.insert(end);
        if(end+arr[end]<=n && end+arr[end]>=1 && !st.count(end+arr[end]))end = next[end];
        else  break;
    }
    set<int> s;
    function<int(int)> dfs = [&](int node){
        int tot = 1;
        s.insert(node);
        for(auto i : prev[node]){
            if(!s.count(i))tot+=dfs(i);
        }
        if(st.count(node))ans+=cnt-f*tot+n+1;
        return tot;
    };
    dfs(end);
    for(int i=1;i<=n;i++){
        if(!st.count(i) && f)ans+=2*n+1;
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}