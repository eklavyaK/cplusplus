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
    vector<char> v;
    for(int i=0;i<n;i++){
        v.push_back(s[i]);
        int k = i;
        while(i+1<n && s[i+1]!=s[k])i++;
        i++;
    }
    for(auto i : v) cout<<i;
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}