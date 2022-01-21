#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,x,y; cin>>n>>x>>y; int count = n,d=1;
        if(n==2){cout<<x<<" "<<y<<endl; continue;}
        while(d<y-x){if((y-x)%d==0) {if((y-x)/d-1<=n-2) break; else d++;} else d++;}
        n = n-2 - (y-x)/d+1;
        while(x-n*d<=0) n--;int a = x-n*d;
        for(int i = 0; i<count; i++) cout<<a + i*d<<" ";cout<<endl;
    }
    return 0;
}