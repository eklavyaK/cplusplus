#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n;map<int,int> map1; map<int,int> result; cin>>k;map1[k]=1;int initial = k;result[initial]++;if(n==1){cout<<0<<endl;continue;}
        for(int i = 1; i<n-1; i++) {cin>>k; if(map1[k]!=0){if(i+1-map1[k]!=1) result[k]++;} else result[k]+=2;map1[k] = i+1;}
        cin>>k; if(map1[k]!=0){if(n-map1[k]!=1) result[k]++;} else result[k]+=2;map1[k] = n-1;int end = k;
        if(initial == end) result[initial]--;else result[end]--;int min = INT_MAX;
        for(auto i : result)if(i.second<min)min=i.second;
        cout<<min<<endl;
    }
    return 0;
}