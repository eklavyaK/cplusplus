#include<bits/stdc++.h>
using namespace std;
int n,k;
bool condition(string &a, string &b)
{
    for(int i = 0; i<k; i++)
        if(a[i] != b[i]){ if(i%2==0) return a[i]<b[i]; else return a[i]>b[i]; }
    return true;
}
int main()
{
    cin>>n>>k; string s[n];
    for(int i = 0; i<n; i++) {cin>>s[i]; s[i].append(to_string(i+1));}
    sort(s,s+n,condition);
    for(int i = 0; i<n; i++) cout<<s[i].substr(k)<<" ";
    return 0;
}