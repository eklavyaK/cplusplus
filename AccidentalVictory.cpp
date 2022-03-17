#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,m=0,sum=0; cin>>n; vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i].first;v[i].second=i;
        }
        if(n==1){cout<<1<<'\n'<<1<<endl;continue;}
        int in = n-1;
        sort(v.begin(),v.end());
        long long front[n-1];
        front[0]=v[0].first;
        for(int i = 1; i<n-1; i++){
            front[i]=v[i].first+front[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(front[i]>=v[i+1].first){
                in=i;
            }
            else goto print;
        }
        print:
            cout<<n-in<<endl;
            vector<int> result;
            for(int i = in; i<n; i++){
                result.push_back(v[i].second+1);
            }
            sort(result.begin(),result.end());
            for(int i = 0; i<n-in; i++){
                cout<<result[i]<<" ";
            }
        finish:
            cout<<endl;
    }
    return 0;
}