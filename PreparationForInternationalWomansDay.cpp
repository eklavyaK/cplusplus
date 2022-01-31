#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,k,b; cin>>n>>k; map<int,int> map; long long count = 0l;
    for(int i = 0; i<n; i++) {cin>>b; map[b%k]++;}    
    for(auto i : map) 
    {
        if(i.first>k/2) break;
        else if(i.first==0) count += (i.second-i.second%2);
        else if(k%2 == 0 && i.first == k/2) count += (i.second-i.second%2);
        else if(map[k-i.first]!=0) count += (min(i.second,map[k-i.first])*2);
    }
    cout<<count<<endl;
    return 0;
}