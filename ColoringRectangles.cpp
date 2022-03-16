#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,m; cin>>n>>m;
        if(n>=3 && m>=3){
            int k = (n/3)*m;
            k+=(n%3)*(m/3);
            if(n%3 == 1 && m%3==1){
                k++;
            }
            else{
                k+=(n%3)*(m%3)/2;
            }
            cout<<k<<endl;
        }
        else if(n==2 && m>=3){
            int k = (m/3)*2;
            k+=(m%3);
            cout<<k<<endl;
        }
        else if(m==2 && n>=3){
            int k = (n/3)*2;
            k+=(n%3);
            cout<<k<<endl;
        }
        else if(n==2 && m==2){
            cout<<2<<endl;
        }
        else{
            int k = (n*m)/3 + ((n*m)%3!=0);
            cout<<k<<endl;
        }
    }
    return 0;
}