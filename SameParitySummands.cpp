#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n, k; cin>>n>>k;
        if(n<k) {cout<<"no"<<endl;continue;}
        else if(!(n%2) && !(k%2)) {cout<<"yes"<<endl;cout<<n-k+1<<" ";while(k-->1) cout<<1<<" ";}
        else if(n%2 && k%2) {cout<<"yes"<<endl;cout<<n-k+1<<" ";while(k-->1) cout<<1<<" ";}
        else if(!(n%2) && k%2 && n/2>=k) {cout<<"yes"<<endl;cout<<n-(k-1)*2<<" ";while(k-->1) cout<<2<<" ";}
        else cout<<"no";cout<<endl;
    }
    return 0;
}