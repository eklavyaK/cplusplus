#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n; int a[n]; bool e=false,o=false;
    for(int i = 0; i<n; i++) {cin>>a[i];if(a[i]%2)o=true;else e=true;}
    if(o&&e)sort(a,a+n);
    for(int i = 0; i<n; i++) cout<<a[i]<<" ";
    return 0;
}