#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int st[512][512];

void code(){
    int n; cin>>n;
    for(int i=0;i<512;i++)st[i][0] = 1;
    for(int j=0;j<n;j++){
        int k; cin>>k;
        if(k==0)continue;
        vector<int> c;
        for(int i=0;i<512;i++){
            if(st[k-1][i])st[k][i] = 1;
            if(st[k-1][i]&&!st[k-1][i^k])st[k][i^k] = 1,c.push_back(i^k);
        }
        for(auto i : c){
            int now = k;
            while(now+1<512){
                now++;
                if(!st[now][i])st[now][i] = 1;
                else break;
            }
        }
    }
    cout<<count(st[511],st[511]+512,1)<<endl;
    for(int i=0;i<512;i++)if(st[511][i])cout<<i<<" ";cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}