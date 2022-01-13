#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n,k;cin>>n; int a[150001]; bool track[150001] = {false};
        int result = n;
        for(int i = 0; i<n; i++) 
        {
            cin>>k;
            if(track[k] == 1)
            {
                if(i - a[k]<result) result = i - a[k];
                a[k] = i;
            }
            else {track[k] = 1; a[k] = i;}
        } 
        if(result == n) cout<<-1<<endl;
        else cout<<(n-result)<<endl; 
    }
  return 0;
}