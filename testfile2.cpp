#include<iostream>

using namespace std;

int main(){
    int n,m,c=0; cin>>n>>m; string s[n];
    for(int i = 0; i<n; i++)s[i]=string(500,'*');
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
                        a[i][j+k]<j-k
                    )
                    c++;
                    else break;
                }
            }
        }
    }
    cout<<c<<endl;
    return 0;
}