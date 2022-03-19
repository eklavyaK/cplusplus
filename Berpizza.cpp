#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
map<int,queue<int>> m;
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    int k, cnt = 0,track = 0;
    vector<int> v;
    while(tc-->0){
        cin>>k;
        if(k==1){
            cnt++;cin>>k;
            m[k].push(cnt);
            v.push_back(k);
        }
        else if(k==2){
            for(; track<cnt; track++){
                if(!m[v[track]].empty()){
                    cout<<m[v[track]].front()<<" ";
                    m[v[track]].pop();track++;
                    break;
                }
            }
        }
        else{
            map<int,queue<int>>::iterator it = --m.end();
            while(true){
                if(!it->second.empty()){
                    cout<<it->second.front()<<" ";
                    it->second.pop();
                    break;
                }
                else{
                    int t = it->first;it--;
                    m.erase(t);
                }
            }
        }
    }
    return 0;
}