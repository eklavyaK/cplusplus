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
    string s; cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 1;
        while(i+1<n && s[i]==s[i+1])i++,cnt++;
        ans = max(ans,cnt);
    }
    cout<<ans+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}