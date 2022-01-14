#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,m,k; cin>>n>>m>>k;
        if(m<=(long long int)n*(n-1)/2 && m>=n-1) 
        {if(k-1>2) cout<<"yes"<<endl; 
        else if(k-1==2 && m==(long long int)n*(n-1)/2) cout<<"yes"<<endl;
        else if(n==1 && m==0 && k>1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;}
        else cout<<"no"<<endl;
    }
    return 0;
}