#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int k,i = 1, temp, detect = 0;cin>>k; temp = k;
        if(k==1){cout<<n+1<<" "; for(int j = 1; j<=n; j++) cout<<j<<" ";cout<<endl;cin.ignore(numeric_limits<streamsize>::max(), '\n');continue;}
        for(; i<n; i++) {cin>>k; if(k==1 && temp == 0){detect = 1;cin.ignore(numeric_limits<streamsize>::max(), '\n');break;} else {temp = k;}}
        if(detect == 1 || k == 0) for(int j = 1; j<=n; j++) {cout<<j<<" ";if(j==i) cout<<n+1<<" ";}
        else cout<<-1;
        cout<<endl;
    }
    return 0;
}