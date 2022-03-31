#include<bits/stdc++.h>
using namespace std;
//algorithm to get the all possible combinations of r characters from a string or n characters
//function format: Combination(s, c, 0, n-1, 0, r) ----> c is a char array of size r and s is the string of all n characters in it
vector<string> v;
void Combination(string s,char c[],int start, int end, int index, int r){
	if(index==r){
		v.push_back(c);
		return;
	}
	for(int i=start; i<=end&&end-i+1>=r-index; i++){
		c[index]=s[i];
		Combination(s,c,i+1,end,index+1,r);
	}
}
int main(){
	string s; int n,r; cin>>s>>r;
	n=s.size();char c[r+1]={'\0'};
	Combination(s, c, 0, n-1, 0, r);

	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<endl;
	}
}