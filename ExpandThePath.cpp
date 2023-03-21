#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

string flip(string s){
    for(int i=0;i<s.size();i++){
        s[i] = s[i]=='R'?'D':'R';
    }
    return s;
}

void code(){
    int n; cin>>n;
    string s; cin>>s;
    if(s[0]=='D') s = flip(s);
    s = 'R' + s;
    int m = s.size();
    if(s==string(m,'R')){
        cout<<n<<endl;
        return;
    }
    int cnt = 0, ans = 0;
    for(int i=m-1;i>=0;i--){
        if(s[i]=='R')cnt++;
        else ans+=cnt;
    }
    int l = 0;
    for(int i=0;i<m;i++){
        if(s[i]=='D'){
            l = i-1; break;
        }
    }
    cnt = 0;
    ans+=(n-1)*l;
    for(int i=m-1;i>l;i--){
        if(s[i]=='D')cnt++;
        else ans+=cnt;
    }
    cout<<n*n-ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}