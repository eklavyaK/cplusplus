#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    
    int n; cin>>n;int a[n][2],count=0;
    queue<int> index; unordered_map<int,map<int,int>> v;
    int res[n][2],dist[n]={0},k=1;
    for(int i = 0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
        v[a[i][0]][a[i][1]]=i+1;
        dist[i]=400001;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<4; j++){
            if(!v[a[i][0]+dx[j]][a[i][1]+dy[j]]){
                res[i][0]=a[i][0]+dx[j];
                res[i][1]=a[i][1]+dy[j];
                dist[i]=k;
                index.push(i);
                break;
            }
        }
    }
    while(!index.empty()){
        int i = index.front();index.pop();
        for(int j = 0; j<4; j++){
            if(v[a[i][0]+dx[j]][a[i][1]+dy[j]] && dist[v[a[i][0]+dx[j]][a[i][1]+dy[j]]-1]>dist[i]+1){ 
                int in = v[a[i][0]+dx[j]][a[i][1]+dy[j]]-1;
                res[in][0]=res[i][0];res[in][1]=res[i][1];
                index.push(in);dist[in]=dist[i]+1;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}