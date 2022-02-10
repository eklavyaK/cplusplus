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
        int n,w,track=0; cin>>n>>w; int a[n]; vector<int> v(20);
        for(int i = 0; i<n; i++) {cin>>a[i]; int r = 0;while(pow(2,r)!=a[i]) r++;v[r]++;}
        while(true)
        {
            bool check = true;for(int i = 19; i>=0; i--) if(v[i]) {check = false;break;} 
            if(check) break; track++;int temp = w;
            for(int i = 19; i>=0; i--) {while(v[i] && pow(2,i)<=temp) {v[i]--;temp-=pow(2,i);}}
        }cout<<track<<endl;
    }
    return 0;
}