#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n>>k; 
        if(n%2){ n = (n-1)/2; cout<<n<<" "<<n<<" "<<1<<endl;}
        else {if(n/2%2){n=n/2-1; cout<<n<<" "<<n<<" "<<2<<endl;} else {cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;}}
    }
    return 0;
}