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
        int n; cin>>n; vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++) 
        {
            int k,temp,l; cin>>k; cin>>l; v[i].first=++l;l++;
            for(int j = 1; j<k; j++) {cin>>temp; if(temp>=l) {v[i].first=temp+1-j; l=temp+2;} else l++;}
            v[i].second=l;;
        }
        sort(v.begin(),v.end());int result = v[0].first; long long sum = v[0].second;
        for(int i = 1; i<n; i++) {if(v[i].first>sum) {result+=(v[i].first-sum);sum=v[i].second;}else sum+=(v[i].second-v[i].first);}cout<<result<<endl;
    }
    return 0;
}