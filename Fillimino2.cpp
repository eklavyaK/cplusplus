#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n; cin>>n; int a[n];
    for(int i = 1; i<=n; i++)cin>>a[i];
    int v[n+1][n+1];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            v[i][j]=0;
        }
    }
    for(int i = 1; i<=n; i++){
        v[i][i]=a[i];int cnt=a[i]-1,r=i,c=i;
        while(cnt>0){
            if(c-1>=1 && v[r][c-1]==0){
                v[r][c-1]=a[i];
                int k = 1;c--;cnt--;
                while(cnt>0 && v[r-k][c]==0){
                    v[r-k][c]=a[i];k++;
                }
            }
            else if(r+1<=n && v[r+1][c]==0){
                v[r+1][c]=a[i];r++;cnt--;
            }
            else{cout<<-1<<endl;exit(0);}
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}