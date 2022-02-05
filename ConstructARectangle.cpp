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
        int a[3]; for(int i = 0; i<3; i++) cin>>a[i];sort(a,a+3);
        if(a[2]-a[0]==a[1] || (a[0]==a[1] && !(a[2]%2)) || (a[2]==a[1] && !(a[0]%2)))cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}