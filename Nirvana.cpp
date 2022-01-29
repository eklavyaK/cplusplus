#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s; cin>>s;long long product = 1l,i,temp=1l;cout.precision(20);
    if(s.length()==1){cout<<s<<endl;exit(0);} for(int i = 0; i<s.size(); i++)temp*=(s[i]-'0');
    if(s==string(s.length(),'9')){cout<<pow(9,s.length())<<endl;exit(0);}
    if(s[0]=='1') {for(int i = 0; i<s.size()-1; i++) product*=9;cout<<product<<endl;exit(0);}
    for(i = 0; i<s.length()-1; i++) 
    {if(product*(s[i]-1-'0')*pow(9,s.length()-i-1)>=max(temp,product*(s[i]-'0')*(s[i+1]-1-'0')*(long long)pow(9,s.length()-i-2))) {cout<<(product*(s[i]-1-'0')*pow(9,s.length()-i-1));exit(0);}else product*=(s[i]-'0');}
    cout<<temp<<endl;
    return 0;
}