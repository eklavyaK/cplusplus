#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n;int a[n], count[n+2]={0};
        for(int i = 0; i<n; i++) {cin>>a[i];count[a[i]]++;} int index = 0;
        vector<int> res;
        while(index<n)
        {
            int l = 0; while(count[l])l++;
            if(l==0){for(int i = index; i<n; i++) res.emplace_back(0);break;}
            vector<int> v(l); int trackindex=0;
            for(;index<n; index++)
            {
                if(a[index]<l)v[a[index]]=1;count[a[index]]--;
                for(int j = trackindex; j<l; j++) {if(v[j]!=0)trackindex++; else break;}
                if(trackindex == l){index++; break;}
            }
            res.emplace_back(l);
        }
        cout<<res.size()<<endl;
        for(auto i : res) cout<<i<<" ";cout<<endl;
    }
    return 0;
}