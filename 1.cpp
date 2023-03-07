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
    int arr[n+1]{}, ans[n+1]{};
    vector<int> st(n+1), pos(n+1), last(k+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        pos[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    st[0] = -1; int now[2]{};
    vector<int> cold(k+1), hot(k+1);
    for(int i=1;i<=k;i++)cin>>cold[i];
    for(int i=1;i<=k;i++)cin>>hot[i];
    for(int i=1;i<=n;i++){
        if(!pos[i]){
            ans[i] = ans[i-1]+cold[arr[i]];
            now[0] = i;
        }
        else if(now[0]==pos[i]){
            ans[i] = ans[i-1]+hot[arr[i]];
            now[0] = i;
        }
        else if(now[1]==pos[i]){
            ans[i] = ans[i-1]+hot[arr[i]];
            now[1] = i, st[i] = 1;
        }
        else{
            int gp = !st[pos[i]];
            int curr = ans[pos[i]];
            for(int j=pos[i]+1;j<i;j++){
                if(pos[j]>pos[i]) curr+=hot[arr[j]];
                else if(st[pos[j]]==gp) curr+=hot[arr[j]];
                else curr+=cold[arr[j]];
            }
            curr+=hot[arr[i]];
            if(curr<=ans[i-1]+cold[arr[i]]){
                curr = ans[pos[i]];
                for(int j=pos[i]+1;j<i;j++){
                    if(pos[j]>pos[i]) curr+=hot[arr[j]];
                    else if(st[pos[j]]==gp) curr+=hot[arr[j]];
                    else curr+=cold[arr[j]];
                    st[j] = gp; ans[j] = curr;
                    now[gp] = j;
                }
                st[i] = st[pos[i]];
                now[st[i]] = i;
                ans[i] = ans[i-1]+hot[arr[i]];
            }
            else{
                ans[i] = ans[i-1]+cold[arr[i]];
                now[0] = i;
            }
        }
    }
    cout<<ans[n]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}