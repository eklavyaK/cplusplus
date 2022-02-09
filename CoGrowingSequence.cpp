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
        int n; cin>>n; long long k,res[n]; string s[n]; res[0]=0;cin>>k; s[0] = binary(k,64);
        for(int i = 1; i<n; i++) 
        {
            cin>>k; s[i] = binary(k,64); long long sum = 0;
            for(int j = 0; j<64; j++) if(s[i-1][j]=='1' && s[i][j]=='0') {sum+=(long long)pow(2,63-j); s[i][j] = '1';}
            res[i] = sum;
        }
        for(int i = 0; i<n; i++) cout<<res[i]<<" "; cout<<endl;
    }
    return 0;
}