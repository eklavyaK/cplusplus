#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    vector<array<int,3>> v;
    array<int,3> curr;
    curr[0] = 23;
    curr[1] = 54;
    curr[2] = 89;
    v.push_back(curr);
    curr[0] = 9;
    curr[1] = 4;
    curr[2] = 98;
    v.push_back(curr);
    curr[0] = 23;
    curr[1] = 54;
    curr[2] = 80;
    v.push_back(curr);
    sort(v.begin(),v.end());
    for(auto i : v){
        for(auto j : i) cout<<j<<' ';
        cout<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}