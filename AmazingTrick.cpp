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
    int pos[n+1];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        pos[k] = i;
    }
    bool f = false;
    vector<int> ans(n+1),nxt(n+1);
    iota(ans.begin(),ans.end(),0);
    function<bool()> check = [&](){
        for(int i=1;i<=n;i++){
            if(ans[i]==i||nxt[i]==i)return false;
        }
        return true;
    };
    for(int i=0;i<1000;i++){
        random_shuffle(ans.begin()+1,ans.end());
        for(int i=1;i<=n;i++){
            nxt[ans[i]] = pos[i];
        }
        if(check()){
            f = true;
            break;
        }
    }
    if(!f){
        cout<<"Impossible"<<endl;
        return;
    }
    else cout<<"Possible"<<endl;
    for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}