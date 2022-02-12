#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n;
    if(n%2){n=n/2+1; cout<<2*n*(n+1)<<endl;}
    else{n=n/2+1; cout<<n*n<<endl;}
    return 0;
}