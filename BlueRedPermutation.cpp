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
        int n; cin>>n; int a[n],l,r,b[n+1]={0},detect=0,countr=0,countb=0;
        for(int i = 0; i<n; i++) cin>>a[i];string s; cin>>s;
        for(int i = 0; i<n; i++) {if(s[i]=='B') countb++; else countr++;}r=n-countr+1;l=countb;
        for(int i = 0; i<n; i++) 
        {
            if(s[i]=='B') 
            {
                if(a[i]>=l)b[l--]=1;
                else{int k = a[i]; while(k>0 && b[k])k--;if(k<=0) detect = 1;else b[k]=1;}
                while(l>0 && b[l])l--;
            }
            else
            {
                if(a[i]<=r)b[r++]=1;
                else{int k = a[i]; while(k<=n && b[k])k++;if(k>=n+1) detect = 1;else b[k]=1;}
                while(r<=n && b[r])r++;
            }
            if(detect) break;
        }
        if(detect) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}