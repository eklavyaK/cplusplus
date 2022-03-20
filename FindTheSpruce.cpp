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
        int n,m,c=0; cin>>n>>m; string s[n];
        for(int i = 0; i<n; i++)cin>>s[i];
        int a[n][m];
        for(int i = 0; i<n; i++){
            int dot=-1;
            for(int j = 0; j<m; j++){
                if(s[i][j]=='.')dot=j;
                a[i][j]=dot;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(s[i][j]=='*'){
                    for(int k = 0; i+k<n; k++){
                        if(
                            j-k>=0 && j+k<m && 
                            a[i+k][j+k]<j-k
                        )
                        c++;
                        else break;
                    }
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}