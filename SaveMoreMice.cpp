#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k; cin>>n>>k; int r,count=0;
        long long sum = 0;map<int,int> d;
        while(k--){cin>>r;d[n-r]++;}
        for(auto i : d){
            if((long long)i.second*i.first+sum<=n-1){sum+=(long long)i.second*i.first;count+=i.second;}
            else {count+=(n-1-sum)/i.first;break;}
        }
        cout<<count<<endl;
    }
    return 0;
}