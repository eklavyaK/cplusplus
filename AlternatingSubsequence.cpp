#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,l=0,max=INT_MIN; cin>>n; int a[n]; long long sum=0l;
        for(int i = 0; i<n; i++) 
        {
            cin>>k; if(!l || ((l<0 && k<0) || (l>0 && k>0))) {if(max<k) max = k;l=k;}
            else {l=k;sum+=max;max=k;}
        }
        sum+=max;cout<<sum<<endl;
    }
    return 0;
}