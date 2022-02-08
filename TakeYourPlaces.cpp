#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n],o=0,e=0, count=0,track=1;
        for(int i = 0; i<n; i++) {cin>>a[i];if(a[i]%2)o++;else e++;}
        if(abs(o-e)>1) {cout<<-1<<endl;continue;}
        if(o>e) {for(int i = 0; i<n; i++) if(a[i]%2==0){count=count+abs(track-i);track+=2;}}
        else if(e>o) {for(int i = 0; i<n; i++) if(a[i]%2){count=count+abs(track-i);track+=2;}}
        else {int r = 0;for(int i = 0; i<n; i++) if(a[i]%2==0){r=r+abs(track-i);track+=2;}int l=0;track=1;
        for(int i = 0; i<n; i++) if(a[i]%2){l=l+abs(track-i);track+=2;} count = min(l,r);}
        cout<<count<<endl;
    }
    return 0;
}