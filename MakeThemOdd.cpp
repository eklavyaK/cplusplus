#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,count=0; cin>>n; map<int,int> map;
        for(int i = 0; i<n; i++) {cin>>k;while(!(k%2) && !map[k]) {map[k]=1;k/=2;count++;}}
        cout<<count<<endl;
    }
    return 0;
}