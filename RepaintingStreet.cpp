#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n>>k;int max = 0;
        int a[n], track[101]={0}, result = n;
        for(int i = 0; i<n; i++) {cin>>a[i]; if(track[a[i]]==0) track[a[i]]=1;}
        while(max++<100)
        {
            if(track[max]==1)
            {
                int temp_result = 0;
                for(int i = 0; i<n; i++)
                {
                    if(a[i] == max) continue;
                    temp_result++;
                    i = i + k-1;
                }
                if(result>temp_result) result = temp_result;
            }
        }
        cout<<result<<endl;
    }
}