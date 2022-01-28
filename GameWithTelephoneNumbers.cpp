#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s; cin>>n>>s; vector<int> v;int count=0;
    for(int i = 0; i<s.length()-10; i++) if(s[i]=='8')count++;
    if(count<=(s.size()-10)/2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}