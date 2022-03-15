#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);

    int n,m1,m2,l,r; cin>>n>>m1>>m2; 
    vector<vector<int>> va(n+1),vb(n+1);
    while(m1--){cin>>l>>r;va[r].push_back(l);va[l].push_back(r);}
    while(m2--){cin>>l>>r;vb[r].push_back(l);vb[l].push_back(r);}
    int cnta[n+1]={0},cntb[n+1]={0},track = 1;
    for(int i = 1; i<=n; i++){
        if(!cnta[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int k = q.front();q.pop();
                cnta[k]=track;
                for(int j = 0; j<va[k].size(); j++){
                    if(!cnta[va[k][j]]){
                        q.push(va[k][j]);
                    }
                }
            }
            track++;
        }
    }
    track = 1;
    for(int i = 1; i<=n; i++){
        if(!cntb[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int k = q.front();q.pop();
                cntb[k]=track;
                for(int j = 0; j<vb[k].size(); j++){
                    if(!cntb[vb[k][j]]){
                        q.push(vb[k][j]);
                    }
                }
            }
            track++;
        }
    }
    vector<pair<int,int>> v;map<int,bool> pa,pb;
    int index = 0; bool detect = true;
    pa[cnta[1]]=true;
    pb[cntb[1]]=true;
    for(int i = 1; i<=n; i++){
        for(int j = 1+i; j<=n; j++){
            if(pa[cnta[i]]!=pa[cnta[j]] && pb[cntb[i]]!=pb[cntb[j]]){
                v.push_back(make_pair(i,j));
                pa[cnta[i]]=true;
                pa[cnta[j]]=true;
                pb[cntb[i]]=true;
                pb[cntb[j]]=true;
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto i : v)cout<<i.first<<" "<<i.second<<endl;

    return 0;
}