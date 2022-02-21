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
        int n; cin>>n; string s; cin>>s; int a[n], count=0; vector<int> v;
        for(int i = 0; i<n; i++) {if(s[i]=='1')a[i]=1;else a[i]=0;}
        string r; cin>>r;for(int i = n-1; i>=0; i--) if(a[i]!=(r[i]-'0')){
            if(a[0]!=a[i]){
                v.emplace_back(1);v.emplace_back(i+1);
                count+=2;for(int j = (i-1)/2; j>=1; j--) 
                {int temp = !a[i-j];a[i-j]=!a[j];a[j]=temp;}
                if(i%2==0) a[i/2]=!a[i/2];
            }
            else{
                count++;v.emplace_back(i+1);
                for(int j = 0; j<(i+1)/2; j++) 
                {int temp = !a[i-j];a[i-j]=!a[j];a[j]=temp;}
                if(i%2==0) a[i/2]=!a[i/2];
            }
        }
        cout<<count<<" ";for(auto i : v)cout<<i<<" ";cout<<endl;
    }
    return 0;
}