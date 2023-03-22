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
    vector<int> res(n+1), pos(n+1);
    for(int i=1;i<=n;i++)cin>>res[i],pos[res[i]]=i;
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> curr = res;
    sort(curr.begin(),curr.end());
    for(int i=1;i<=n;i++){
        if(curr[i]==curr[i+1]){
            cout<<"YES"<<endl;
            return;
        }
    }
    function<void(int,int,int)> rotate = [&](int i, int j, int k){
        swap(res[i],res[j]);
        swap(res[j],res[k]);
        pos[res[i]] = i;
        pos[res[j]] = j;
        pos[res[k]] = k;
    };
    for(int i=n;i>=3;i--){
        if(res[i]==i)continue;
        if(pos[i]==i-1)rotate(i-1,i-2,i);
        else rotate(pos[i],i-1,i);
    }
    if(res[1]==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}