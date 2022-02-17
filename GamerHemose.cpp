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
        int n,h; cin>>n>>h;int a[n],c=0,d=0,count,in=0;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) if(c<a[i]){c=a[i];in=i;}
        for(int i = 0; i<n; i++) if(i!=in && d<a[i]){d=a[i];}
        count=h/(c+d); h-=(c+d)*(count);count*=2; if(h>0) {
            h-=c;count++;if(h>0)count++;
        }cout<<count<<endl;
    }
    return 0;
}