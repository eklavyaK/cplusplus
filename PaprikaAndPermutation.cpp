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
        int n,k,count=0; cin>>n; int a[n+1]={0};vector<int> v;bool detect = false;
        for(int i = 1; i<=n; i++) {cin>>k; if(k<=n && !a[k]) a[k] = k; else v.emplace_back(k/2-!(k%2));}int track = 0;
        sort(v.begin(),v.end());for(int i = 1; i<=n; i++) if(!a[i]) {if(v[track++]<i) {detect = true;break;} else count++;}
        if(detect) cout<<-1<<endl; else cout<<count<<endl;
    }
    return 0;
}