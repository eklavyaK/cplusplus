#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;int k,e=0,o=0;
    while(tc-->0)
    {
        cin>>k;if(k%2)o++;else e++;
    } if(e && o) {cout<<2<<" "<<1<<" ";e--;o--;}while(e--)cout<<2<<" ";while(o--)cout<<1<<" ";
    return 0;
}