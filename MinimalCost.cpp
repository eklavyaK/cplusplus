#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    int d=0;
    while(t-->0)
    {
        int n,u,v;
   		cin>>n>>u>>v;
 
   		int a[n+4];
   		for(int i=1;i<=n;i++){
   			cin>>a[i];
   		}
 
   		int del=0;
   		for(int i=2;i<=n;i++){
   			del=max(del,abs(a[i]-a[i-1]));
   		}
 
   		if(del==0) cout<<min(u,v)+v<<endl;
   		else if(del==1) cout<<min(u,v)<<endl;
   		else cout<<0<<endl;     
    }
    return 0;
}