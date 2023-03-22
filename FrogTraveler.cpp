#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int inf = 1e9;

void code(){
    int n; cin>>n;
    int a[n+1], b[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int arr[n+1], brr[n+1];
    for(int i=1;i<=n;i++){
        arr[i] = i-a[i];
        brr[i] = i+b[i];
    }
    queue<int> q;
    vector<int> ans;
    q.push(n);
    int r = n-1;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(!arr[curr]){
            ans.push_back(0);
            cout<<ans.size()<<endl;
            for(auto i : ans) cout<<i<<' ';
            cout<<endl;
            return;
        }
        int mn = n, k = 0;
        for(;r>=arr[curr];r--){
            if(arr[brr[r]]<mn){
                mn = arr[brr[r]];
                k = r;
            }
        }
        if(mn==n)break;
        else{
            q.push(brr[k]);
            ans.push_back(k);
        }   
    }
    cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}