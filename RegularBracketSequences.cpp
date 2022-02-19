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
        int n; cin>>n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                cout<<'('<<')';
            }
            for(int j = i; j<n; j++){
                cout<<'(';
            }
            for(int j = i; j<n; j++){
                cout<<')';
            }
            cout<<endl;
        }
    }
    return 0;
}