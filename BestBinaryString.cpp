#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    string s; cin>>s;
    int n = s.size();
    int ans = 0;
    char last = '0';
    for(int i=0;i<n;i++){
        if(s[i]=='?') s[i]=last;
        last = s[i];
    }
    cout<<s<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}