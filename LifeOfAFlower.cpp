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
        int n,k,l,h=1;cin>>n>>k;l=k;if(k)h=2;
        for(int i = 1; i<n; i++) {cin>>k;if(k){if(l)h+=5;else h++;} else if(!l){h=-1;cin.ignore(numeric_limits<streamsize>::max(), '\n');break;}l=k;}
        cout<<h<<endl;
    }
    return 0;
}