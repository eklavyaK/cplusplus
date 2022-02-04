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
        int n,k; cin>>n; int a[n],detect = 0;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) 
        {
            detect = 1;
            for(int j = i+2; j>=2; j--) if(a[i]%j) {detect = 0;break;}
            if(detect) break;
        }
        if(detect) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}