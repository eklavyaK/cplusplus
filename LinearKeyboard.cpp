#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;while(t--)
{
string s, r; cin>>s>>r; int result = 0;
for(int i=1; i<r.size();i++)
if(r[i]!=r[i-1]) result+=abs((int)(s.find(r[i])-s.find(r[i-1])));
cout<<result<<endl;
}
}