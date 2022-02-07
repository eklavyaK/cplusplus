#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    string a[32]; for(int i = 0; i<32; i++) a[i]=to_string(pow(2,i));
    while(tc-->0)
    {
        int n,k,e=2,o=1; cin>>n>>k;if(!(n%2) || k==1)
        {
            cout<<"YES"<<endl;
            for(int i = 1; i<=n; i++) 
            {if(i%2) for(int i = 0; i<k; i++) {cout<<o<<" ";o+=2;}
            else for(int i = 0; i<k; i++) {cout<<e<<" ";e+=2;}
            cout<<endl;}
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}