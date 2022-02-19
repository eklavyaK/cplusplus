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
        int n; cin>>n; int mod = 1000000007; long long result = n;
        for(int i = 2; i<2*n; i++) result = (result*i) % mod; cout<<result<<endl;
    }
    return 0;
}