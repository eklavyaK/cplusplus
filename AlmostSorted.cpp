#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k = 0; cin>>n>>k;
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),1);
    string s = bitset<61>(k-1).to_string();
    for(int i=0;i<61;i++){
        if(s[60-i]=='0')continue;
        int z = i;
        while(s[60-i]=='1')i++;
        if(n-i-1<0){
            cout<<-1<<endl;
            return;
        }
        sort(ans.begin()+n-i-1,ans.begin()+n-z,greater<int>());
    }
    for(auto i : ans)cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}