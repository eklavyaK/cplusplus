#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,detect; cin>>n; string s[n];vector<int> v(30);
        for(int i = 0; i<n; i++) {cin>>k;s[i] = binary(k,30);}
        for(int i = 0; i<n; i++) for(int j = 0; j<30; j++) if(s[i][j]=='1')v[j]++;cout<<1<<" ";
        for(int i = 2; i<=n; i++) {detect = 1;for(int j = 0; j<30; j++) if(v[j]%i) detect = 0;if(detect)cout<<i<<" ";}
        cout<<endl;
    }
    return 0;
}