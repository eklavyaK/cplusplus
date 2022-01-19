#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,detect = 0; cin>>n; int a[2*n];
    for(int i = 0; i<2*n; i++) cin>>a[i];
    if(n%2==0)
    {
        for(int i = 0; i<n-2; i+=2) 
            if(a[i]+2 != a[i+2] && a[i+n]+2 != a[i+n+2]) {detect = 1; break;}
        if(detect) cout<<-1<<endl;
        else if(a[0]-a[n]== n && a[0]-a[1]<0) cout<<1<<endl;
        else if(a[0]-a[n]== -n && a[0]-a[1]<0) cout<<0<<endl;
        else if(a[0]-a[n]== n && a[0]-a[1]>0) cout<<2<<endl;
        else if(a[0]-a[n]== -n && a[0]-a[1]>0) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        int temp = a[0];
        int i = 1,count = 0;
        while(true)
        {
            if(temp == i) break;
            else if(i%2) i++;
            else i--;
            count++;
            if(temp == i) break;
            else if(i<=n) i += n;
            else i-=n;
            count++;
        }
        if(count<=n)
        for(int j = 1; j<n*2; j++)
        {
            i = j+1;
            for(int k = 1; k<=count; k++) 
            {
                if(k%2) {if(i%2) i++; else i--;}
                else {if(i<=n) i += n; else i-=n;}
            }
            if(i!=a[j]){detect = 1; break;}
        }
        else{count = 2*n-count;
        for(int j = 1; j<n*2; j++)
        {
            i = j+1;
            for(int k = 1; k<=count; k++) 
            {
                if(k%2==0) {if(i%2) i++; else i--;}
                else {if(i<=n) i += n; else i-=n;}
            }
            if(i!=a[j]){detect = 1; break;}
        }}
        if(detect) cout<<-1<<endl;
        else cout<<count<<endl;
    }
    return 0;
}