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
        int n,index,num=0; cin>>n; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 1; i<=n; i++) 
        {
            if(a[i-1]==i)cout<<i<<" ";
            else {num=i;index=i-1;break;}
        }
        if(num) {
            int start = index;
            for(int i = num; i<n; i++) if(a[i]==num) {index=i;break;}
            for(int i = index; i>=start; i--) cout<<a[i]<<" ";
            for(int i = index+1; i<n; i++) cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}