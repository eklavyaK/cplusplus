#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; vector<int> v;
        for(int i = 0; i<n; i++) {cin>>k; v.emplace_back(k-i-1);}
        sort(v.begin(),v.end()); k = v[0]; int count = 0; long long int sum = 0l;
        for(int i = 0; i<v.size();i++) {if(k==v[i]) count++; else {sum = sum + (long long int)count*(count - 1)/2; count = 0; k = v[i];i--;}}
        sum = sum + (long long int)count*(count - 1)/2;
        cout<<sum<<endl;
    }
    return 0;
}