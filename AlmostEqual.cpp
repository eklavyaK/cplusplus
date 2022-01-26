#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n; if(n%2==0) {cout<<"NO"<<endl;exit(0);}cout<<"YES"<<endl;int track = 1;cout<<track<<" ";
    for(int i = 1; i<n; i++) {if(i%2){track+=3;cout<<track++<<" ";} else cout<<track<<" ";}track = -1;
    for(int i = 1; i<=n; i++) {if(i%2){track+=3;cout<<track++<<" ";} else cout<<track<<" ";}
    return 0;
}