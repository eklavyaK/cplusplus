#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,m,k,count=0; cin>>n>>m; map<int,int> map;
        for(int i = 0; i<n; i++) {cin>>k; map[k%m]++;}
        for(auto i : map)
        {
            if(i.first == 0) count++;
            else if(i.first == (float)m/2) count++;
            else if(map[m-i.first]!=0)
            { 
                abs(i.second-map[m-i.first])>1?count += abs(i.second-map[m-i.first]): count++;
                map[m-i.first] = 0;
            }
            else count+=i.second;
            map[i.first] = 0;
        }
        cout<<count<<endl;
    }
    return 0;
}