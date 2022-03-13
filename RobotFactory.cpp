#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int r,c,t,in=1,temp=1; cin>>r>>c; 
    int a[r][c];string s[r][c];
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>t;
            s[i][j]=binary(t,4);
        }
    }
    map<int,int> v;
    for(int i = 0; i<c; i++){
        if(s[0][i][1]=='1'){
            a[0][i]=in;
            v[in++]=temp;
            temp=1;
        }
        else{
            temp++;
            a[0][i]=in;
        }
    }
    map<int,int> m;
    for(int i = 1; i<r; i++){
        for(int j = 0; j<c; j++){
            if(s[i][j][0]=='0' && s[i][j][3]=='0'){
                if(a[i][j-1]==a[i-1][j]){
                    v[a[i][j-1]]++;
                    int k = a[i-1][j];
                    while(m[k])k=m[k];
                    a[i][j]=k;
                }
                else if(a[i][j-1]!=a[i-1][j]){
                    int k = a[i][j-1];
                    int l = a[i-1][j];
                    while(m[k])k=m[k];
                    while(m[l])l=m[l];
                    if(l==k){
                        a[i][j]=k;
                        v[a[i][j]]++;
                    }
                    if(l<k){
                        a[i][j]=l;
                        v[a[i][j]]+=(1+v[k]);
                        m[k]=l;
                        v.erase(k);
                    }
                    if(l>k){
                        a[i][j]=k;
                        v[a[i][j]]+=(1+v[l]);
                        m[l]=k;
                        v.erase(l);
                    }
                }
            }
            else if(s[i][j][3]=='0'){
                int k=a[i][j-1];
                while(m[k])k=m[k];
                a[i][j]=k;
                v[a[i][j]]++;
            }
            else if(s[i][j][0]=='0'){
                int k=a[i-1][j];
                while(m[k])k=m[k];
                a[i][j]=k;
                v[a[i][j]]++;
            }
            else{
                v[in]++;
                a[i][j]=in++;
            }
        }
    }
    vector<int> result;
    for(auto i : v) result.push_back(i.second);
    sort(result.begin(),result.end(),greater<int>());
    for(auto i : result) cout<<i<<" ";
    return 0;
}