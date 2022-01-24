#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,detect = 0; cin>>n; vector<int> v;vector<int> res(2*n+1);vector<int>print;
        for(int i = 0; i<n; i++) {cin>>k;v.emplace_back(k); res[k] = 1;}
        for(int i = 0; i<n; i++) 
        {
            if(i<n-1 && v[i]+1<=2*n && !res[v[i]+1]) {print.emplace_back(v[i]);print.emplace_back(v[i]+1);res[v[i]+1]=1;}
            else
            {
                detect = 1;
                for(int j = v[i]+1; j<=2*n; j++) if(res[j]==0) {print.emplace_back(v[i]);print.emplace_back(j);res[j]=1;detect = 0; break;}
                if(detect) break;
            }
        }
        if(find(res.begin()+1,res.end(),0) != res.end()) cout<<-1<<endl;
        else for(auto i : print) cout<<i<<" "; cout<<endl;
    }
    return 0;
}