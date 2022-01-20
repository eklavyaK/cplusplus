#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; int a[n],b[n];
        for(int i = 0; i<n; i++) {cin>>a[i]; if(a[i]==n) k=i;}
        for(int j = 0; j<n; j++) 
        {
            int max = n, count = 0, index = k;
            int l = 0, r= n-1;
            while(max != a[j])
            {
                count++;
                if(j>index) 
                { 
                    l = index+1; max = a[l]; index = l;
                    for(int i = l+1; i<=r; i++)
                        if(a[i]>max){max = a[i];index = i;}
                }
                else
                {
                    r = index-1;max = a[r]; index = r;
                    for(int i = r-1; i>=l; i--)
                        if(a[i]>max){max = a[i]; index = i;} 
                }
            }
            b[j] = count;
        }
        for(int i = 0; i<n; i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}