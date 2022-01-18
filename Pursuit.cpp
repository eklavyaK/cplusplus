#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int a[n],b[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];
        sort(a,a+n);sort(b,b+n); int k = n - floor((float)n/4);
        int suma = 0, sumb = 0;
        for(int i = n-k; i<n; i++) {suma = suma + a[i]; sumb = sumb + b[i];}
        int count = 0, temp, tn = n;
        while(suma<sumb)
        {
            count++;
            suma = suma + 100;
            tn++;temp = tn - floor((float)tn/4);
            if(temp == k)
                suma = suma - a[tn-k-1]; 
            else {if(n-k-1>=0)sumb = sumb + b[n-k-1];k = temp;}
        }
        cout<<count<<endl;
    }
    return 0;
}