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
        int a,b,c; cin>>a>>b>>c;
        if(c%2){
            if(b%2){
                if(a%2) cout<<0<<endl;
                else cout<<1<<endl;
            }
            else{
                if(a%2) cout<<0<<endl;
                else cout<<1<<endl;
            }
        }
        else{
            if(b%2){
                if(a%2) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else{
                if(a%2) cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}