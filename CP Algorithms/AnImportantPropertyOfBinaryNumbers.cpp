/*

Binary numbers from 0 to 2^n-1 can be used to:

->Divide a collection of n numbers into two groups in all possible ways:

    for each binary number, the numbers present at position where '1' is present in binary number are grouped together and all the positions where '0' is present are grouped into another group. Each group will go through a combination which can be possible from collection.
    
->Get all the subsets of a set of n numbers

    just like above we take all the numbers present at positions where '1' is present in a binary string. If we look at all the binary strings we can see that after iterating through every binary string we could get all the possible subsets of a set.

->Getting all the possible combinations of a string or a array (nCr where r=0,1,2,3....n)

    implementation is same as getting all the subsets of a set

*/
#include<iostream>
#include<vector>
using namespace std;

int a[20];int n;

void GetAllSubsets(){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<a[j]<<' ';
        }
        cout<<endl;
    }
}
void DivideInGroupsOfTwo(){
    for(int i=0;i<(1<<n);i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<a[j]<<' ';
            else v.push_back(a[j]);
        }
        cout<<endl;
        for(auto i : v)cout<<i<<' ';
        cout<<endl<<'\n';
    }
}
int main(){ 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    GetAllSubsets();
    DivideInGroupsOfTwo();
    return 0;
}