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
        int n,k; cin>>n>>k;
        if(n/2 + n%2 >= k)
        for(int i = 1; i<=n; i++){if(i%2 && k-->0)cout<<string(i-1,'.')<<'R'<<string(n-i,'.')<<endl;else cout<<string(n,'.')<<endl;}
        else cout<<-1<<endl;
    }
    return 0;
}