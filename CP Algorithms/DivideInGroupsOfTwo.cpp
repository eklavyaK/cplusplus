#include<iostream>
#include<vector>
using namespace std;

int a[20],n;
void DivideInGroupsOfTwo(){
    for(int i=0;i<(1<<n);i++){                     //all numbers from 0 to 2^n-1
        vector<int> v;
        cout<<'(';
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<a[j]<<' ';          //generation of a group using bitmask
            else v.push_back(a[j]);
        }
        cout<<") (";
        for(auto i : v)cout<<i<<' ';
        cout<<')'<<endl;
    }
}
int main(){ 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    DivideInGroupsOfTwo();
    return 0;
}