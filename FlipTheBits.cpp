#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n, detect = 0; cin>>n; string a,b; cin>>a>>b;
        if(n%2 && a[n-1]!=b[n-1]) {cout<<"no"<<endl; continue;}
        n = n-n%2;
        int count_0 = 0, count_1 = 0, k = 1;
        for(int i = 0; i<n; i++) if(a[i]=='0') count_0++; count_1 = n - count_0;
        for(int i = n-1; i>0; i-=2)
        {
            if(count_0==count_1)
            {
                if(k)
                {
                    if(a[i]!=a[i-1] && b[i] != b[i-1]) 
                    {if(a[i]!=b[i]){k=!k; int temp = count_0; count_0 = count_1; count_1 = temp;} count_0--; count_1--;}
                    else if(a[i]==a[i-1] && b[i]==b[i-1])
                    {if(a[i]!=b[i]){k=!k;int temp = count_0; count_0 = count_1; count_1 = temp;if(b[i]=='0')count_0-=2;else count_1-=2;} else if(a[i]=='0') count_0-=2; else count_1-=2;}
                    else {detect = 1; break;}
                }
                else
                {
                    if(a[i]!=a[i-1] && b[i] != b[i-1]) 
                    {if(a[i]==b[i]){k=!k; int temp = count_0; count_0 = count_1; count_1 = temp;} count_0--; count_1--;}
                    else if(a[i]==a[i-1] && b[i]==b[i-1])
                    {if(a[i]==b[i]){k=!k;int temp = count_0; count_0 = count_1; count_1 = temp;if(b[i]=='0')count_0-=2;else count_1-=2;} else if(a[i]=='1') count_0-=2; else count_1-=2;}
                    else {detect = 1; break;} 
                }
            }
            else 
            {
                if(k && (a[i]!=b[i] || a[i-1]!=b[i-1])) {detect = 1; break;}
                else if(!k && (a[i]==b[i] || a[i-1]==b[i-1])) {detect = 1; break;}
                else if(a[i]!=a[i-1]){ count_1--; count_0--;}
                else if(k && a[i]=='0') count_0-=2;
                else if(!k && a[i]=='1') count_0-=2;
                else count_1-=2 ;
            }
        } 
        if(detect) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}