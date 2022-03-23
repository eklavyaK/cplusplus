#include<bits/stdc++.h>
using namespace std;
//algorithm to get the all possible combinations of r elements from the the group of n elements
//function format: Combination(arr, c, 0, n-1, 0, r) ----> c is a vector of size r and arr is vector of all n elements in it
vector<vector<int>> v;
void Combination(vector<int> arr,vector<int> c,int start, int end, int index, int r){
   if(index==r){
      v.push_back(c);
      return;
   }
   for(int i=start; i<=end&&end-i+1>=r-index; i++){
      c[index]=arr[i];
      Combination(arr,c,i+1,end,index+1,r);
   }
}
int main(){
   int n,r; cin>>n>>r;
   vector<int> arr(n),c(r);
   
   for(int i=0;i<n;i++){
      arr[i]=i+1;
   } 
   
   Combination(arr, c, 0, n-1, 0, r);

   for(int i = 0; i<v.size(); i++){
      for(int j = 0; j<v[i].size(); j++)cout<<v[i][j]<<" "; cout<<endl;
   }
}