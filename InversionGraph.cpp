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
        int n,m=0; cin>>n; int a[n],count=0,index=0; bool track[n+1]={false};track[0]=true;
        for(int i = 0; i<n; i++) cin>>a[i];while(track[index])index++;
        for(int i = 0; i<n-1; i++){m=max(a[i],m);track[a[i]]=true;while(track[index])index++;if(index>m)count++;}
        cout<<count+1<<endl;
    }
    return 0;
}