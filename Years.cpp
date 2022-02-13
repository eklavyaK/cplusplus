#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); int max=0;
    int n; cin>>n; int index=0,a[2*n]; for(int i = 0; i<n; i++) {int l, r; cin>>l;cin>>r; a[index++]=2*l;a[index++]=2*r-1;}
    sort(a,a+2*n); int count=0;for(int i = 0; i<2*n; i++) {if(a[i]%2) count--; else count++; if(count>max){max=count;index=i;}}
    cout<<a[index]/2<<" "<<max<<endl; 
    return 0;
}