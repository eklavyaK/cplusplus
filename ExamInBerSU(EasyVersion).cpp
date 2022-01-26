#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m,sum=0; cin>>n>>m;int a[n];
    for(int i = 0; i<n; i++) 
    {
        cin>>a[i];sum += a[i];
        if(sum>m)
        {
            vector<int> v(i); int temp = 0,count=0;
            while(sum-temp>m){count++;int max = 0,index = 0;for(int j = 0; j<i; j++) if(max<a[j] && !v[j]){index = j;max=a[j];}temp+=max;v[index]=1;}
            cout<<count<<" ";
        }
        else cout<<0<<" ";
    }
    return 0;
}