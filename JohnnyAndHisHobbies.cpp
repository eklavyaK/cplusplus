#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; vector<int> v; vector<int> res;
        if(n%2) {cout<<-1<<endl; string s; getline(cin,s);cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue;}
        for(int i = 0; i<n; i++) {cin>>k;v.emplace_back(k);}
        for(int i = 1; i<n; i++) 
        {
            int k = v[0]^v[i];
            int detect = 1;
            for(int j = 1; j<n; j++) if(find(v.begin(),v.end(),v[j]^k)==v.end()) {detect = 0; break;}
            if(detect) res.emplace_back(k);
        }
        if(!res.empty())cout<<*min_element(res.begin(),res.end())<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}