#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n], b[n]; long long cost=0l; bool track=true;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i]; 
        for(int i = 0; i<n-1; i++) for(int j = i+1; j<n; j++) cost+=pow(a[i]+a[j],2);
        for(int i = 0; i<n-1; i++) for(int j = i+1; j<n; j++) cost+=pow(b[i]+b[j],2);
        while(track)
        {
            track=false;
            for(int k = 0; k<n; k++) 
            {
                long long temp;temp = a[k];a[k]=b[k];b[k]=temp;temp=0l;
                for(int i = 0; i<n-1; i++) for(int j = i+1; j<n; j++) temp+=pow(a[i]+a[j],2);
                for(int i = 0; i<n-1; i++) for(int j = i+1; j<n; j++) temp+=pow(b[i]+b[j],2);
                if(temp<cost){cost=temp;track=true;break;} if(cost==temp) continue;
                temp = a[k];a[k]=b[k];b[k]=temp;
            }
        }
        for(int i = 0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
        for(int i = 0; i<n; i++) cout<<b[i]<<" ";cout<<endl;
        cout<<cost<<endl;
    }
    return 0;
}