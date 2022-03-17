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
        int n;int a[4]; 
        cin>>n>>a[0]>>a[1]>>a[2]>>a[3];
        int m = *max_element(a,a+4);
        if(m>n-2){
            if(
                (a[0]==n && (a[1]==0 || a[3]==0)) ||
                (a[1]==n && (a[0]==0 || a[2]==0)) ||
                (a[2]==n && (a[1]==0 || a[3]==0)) ||
                (a[3]==n && (a[0]==0 || a[2]==0)) ||
                (a[0]==1 && (a[1]==n && a[3]==n)) ||
                (a[1]==1 && (a[0]==n && a[2]==n)) ||
                (a[2]==1 && (a[1]==n && a[3]==n)) ||
                (a[3]==1 && (a[0]==n && a[2]==n)) ||
                (a[0]==n-1 && (a[1]==0 && a[3]==0)) ||
                (a[1]==n-1 && (a[0]==0 && a[2]==0)) ||
                (a[2]==n-1 && (a[1]==0 && a[3]==0)) ||
                (a[3]==n-1 && (a[0]==0 && a[2]==0)) ||
                ((a[0]+a[2]<3) && (a[1]==n && a[3]==n-1)) ||
                ((a[1]+a[3]<3) && (a[0]==n-1 && a[2]==n)) ||
                ((a[0]+a[2]<3) && (a[1]==n-1 && a[3]==n)) ||
                ((a[1]+a[3]<3) && (a[0]==n && a[2]==n-1)) ||
                ((a[0]+a[2]<2) && (a[1]==n-1 && a[3]==n-1)) ||
                ((a[1]+a[3]<2) && (a[0]==n-1 && a[2]==n-1)) ||
                ((a[0]+a[2]<2) && (a[1]==n-1 && a[3]==n-1)) ||
                ((a[1]+a[3]<2) && (a[0]==n-1 && a[2]==n-1))
            ){
                cout<<"NO"<<endl; goto end;
            }
        }
        cout<<"YES"<<endl; end:;
    }
    return 0;
}