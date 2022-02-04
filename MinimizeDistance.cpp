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
        int n,k,t,max=0; cin>>n>>k; vector<int> neg(1),pos(1);long long sum = 0l; bool p = true;
        for(int i = 0; i<n; i++) {cin>>t;if(abs(t)>max) {if(t<0) p = false; else p = true;max=abs(t);}if(t<0) neg.emplace_back(t); else if(t>0) pos.emplace_back(t);}
        sort(neg.begin(),neg.end());sort(pos.begin(),pos.end());
        if(p)
        {
            for(int i = pos.size()-1-k; i>=0; i-=k) sum+=pos[i]*2;
            for(int i = 0; i<neg.size(); i+=k) sum+=abs(neg[i]*2);
            if(pos.size()>0)sum+=pos[pos.size()-1];
        }
        else
        {
            for(int i = k; i<neg.size(); i+=k) sum+=abs(neg[i]*2);
            for(int i = pos.size()-1; i>=0; i-=k) sum+=pos[i]*2;
            sum+=abs(neg[0]);
        }
        cout<<sum<<endl;
    }
    return 0;
}