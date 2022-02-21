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
        string s; cin>>s; int count=0, n = s.length();
        long long sum = 0l;
        for(int i = 0; i<n; i++){
            if(s[i]=='-') count--;
            else count++;
            if(count<0) {sum+=(i+1);count=0;}
        }
        cout<<sum+s.length()<<endl;
    }
    return 0;
}