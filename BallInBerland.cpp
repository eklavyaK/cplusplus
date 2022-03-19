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
        int a,b,k; cin>>a>>b>>k; int boys[k],girls[k];
        for(int i = 0; i<k; i++)cin>>boys[i];
        for(int i = 0; i<k; i++)cin>>girls[i];
        sort(boys,boys+k);sort(girls,girls+k);
        vector<int> vb,vg;
        for(int i = 0; i<k; i++){
            int cnt = 0;
            while(i+1<k && boys[i+1]==boys[i]){cnt++,i++;}
            if(cnt){vb.push_back(cnt+1);}
        }
        for(int i = 0; i<k; i++){
            int cnt=0;
            while(i+1<k && girls[i+1]==girls[i]){cnt++,i++;}
            if(cnt){vg.push_back(cnt+1);}
        }
        long long result = (long long)k*(k-1)/2;
        for(auto i : vb){
            result-=(long long)i*(i-1)/2;
        }
        for(auto i : vg){
            result-=(long long)i*(i-1)/2;
        }
        cout<<result<<endl;
    }
    return 0;
}