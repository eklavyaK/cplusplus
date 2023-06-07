#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int k; cin>>k;
    string s; cin>>s;
    int n = s.size();
    for(int i=0;i<k;i++){
        int cnt = 0, l = 0, mx = 0, lf = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else cnt--;
            if(!cnt){
                if(i-l+1>mx) mx = i-l+1, lf = l;;
                l = i+1;
            }
        }
        if(mx==2) continue;
        s = s.substr(0,lf)+"()"+s.substr(lf+1,mx-2)+s.substr(lf+mx);
    }
    int cost = 0, active = 0;
    int address[n];
    iota(address,address+n,1);
    function<void(int,int)> dfs = [&](int i, int j){
        if(i<0) return;
        if(s[i]=='(' && s[j]==')'){
            cost+=active;
            if(!active){
                i-=2;
                address[i+1] = j;
                j = address[i];
            }
            else{
                i--;
                j = address[j];
                active--;
            }
        }
        else if(s[i]==')' && s[j]==')'){
            address[i] = j;
            j = i;
            i--;
            active++;
        }
        dfs(i,j);
    };
    dfs(n-2,n-1);
    cout<<cost<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}