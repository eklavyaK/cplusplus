#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;string a[63]; for(int i = 0; i<63; i++) a[i] = to_string((long long)pow(2,i));
    while(tc--) 
    {
        string s; cin>>s; int res[63];
        for(int j = 0; j<63; j++){int count = 0;
        for(int i = 0; i<s.size(); i++){if(count<a[j].size()){if(s[i]==a[j][count])count++;} else break;} res[j]=a[j].size()-2*count+s.size();}
        cout<<*min_element(res,res+63)<<endl;
    }
    return 0;
}