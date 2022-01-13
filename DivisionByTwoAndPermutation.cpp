#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n,detect = 1; cin>>n;int a[n], track[n] = {0};
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = n; i>=2; i--)
        {
            detect = 0;
            for(int j = 0; j<n; j++)
            {
                if(track[j] == 1) continue;
                int k = a[j];
                while(k>=i)
                {
                    if(k==i)detect = 1;
                    k=k/2;
                }
                if(detect == 1) {track[j] = 1; break;}
            }
            if(detect == 0) break;
        }
        if(detect == 1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}