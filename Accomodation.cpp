#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int n,m;
int mx(string s){
    int cnt = 0, ans = 0;
    vector<bool> done(m);
    for(int i=0;i<m-1;i++){
        if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==0) cnt++,done[i]=done[i+1]=1;
        else if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==1) cnt++,done[i]=done[i+1]=1,ans++;
    }
    for(int i=0;i<m-1 && cnt<m/4;i++){
        if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==2) cnt++,done[i]=done[i+1]=1,ans++;
    }
    for(int i=0;i<m;i++){
        if(!done[i] && s[i]=='1') ans++;
    }
    return ans;
}
int mn(string s){
    int cnt = 0, ans = 0;
    vector<bool> done(m);
    for(int i=0;i<m-1 && cnt<m/4;i++){
        if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==2) cnt++,done[i]=done[i+1]=1,ans++;
    }
    for(int i=0;i<m-1 && cnt<m/4;i++){
        if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==1) cnt++,done[i]=done[i+1]=1,ans++;
    }
    for(int i=0;i<m-1 && cnt<m/4;i++){
        if(!done[i] && !done[i+1] && s[i]+s[i+1]-2*'0'==0) cnt++,done[i]=done[i+1]=1;
    }
    for(int i=0;i<m;i++){
        if(!done[i] && s[i]=='1') ans++;
    }
    return ans;
}
void code(){
    cin>>n>>m;
    int ansmn = 0, ansmx = 0;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(s==string(m,'0'))continue;
        ansmx+=mx(s);
        ansmn+=mn(s);
    }
    cout<<ansmn<<' '<<ansmx<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}