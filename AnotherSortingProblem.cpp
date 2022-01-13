#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k; cin>>n>>k; string s[n];
    vector<int> v(n); iota(v.begin(),v.end(),0);
    for(int i = 0; i<n; i++) cin>>s[i];
    sort(v.begin(),v.end(),[&](int a,int b){ string &r = s[a]; string &t = s[b];
        for(int i = 0; i<k; i++)
            if(r[i] != t[i]) {if(i%2==1) return r[i]>t[i]; else return r[i]<t[i];} return true;});
    for(int i = 0; i<n; i++) cout<<v[i]+1<<" ";
    return 0;
}