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
        string s; cin>>s; int n = s.size(), count = 0; bool a[n]={false};
        for(int i = 0; i<n; i++) {if(i+1<n&&!a[i]&&!a[i+1]&&s[i]==s[i+1]) {count++;a[i+1]=true;}if(i+2<n&&!a[i]&&!a[i+2]&&s[i]==s[i+2]) {count++;a[i+2]=true;}}
        cout<<count<<endl;
    }
    return 0;
}