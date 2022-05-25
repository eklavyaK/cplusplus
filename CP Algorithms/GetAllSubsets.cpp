#include<iostream>
#include<vector>
using namespace std;

int a[20],n;

void GetAllSubsets(){
    for(int i=0;i<(1<<n);i++){                     //all numbers from 0 to 2^n-1
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<a[j]<<' ';          //generation of subset using bitmask
        }
        cout<<endl;
    }
}
int main(){ 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    GetAllSubsets();
    return 0;
}