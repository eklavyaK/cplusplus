#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int n,m;
bool check(int x,vector<int> a){
    int st = 0, en = n-1;
    while(x!=0 && st<=en){
        if(st<n && a[st]<=x){
            st++; a[en]+=x;
            x--; en--;
        }
        else st++;
    }
    return x==0;
};

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        set<int> row,col;
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            row.insert(x);
            col.insert(y);
        }
        if(row.size()==n && col.size()==n)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}