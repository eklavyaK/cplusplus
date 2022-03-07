#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s; cin>>s; int n = s.size(); 
	bool b[n];b[0]=false;char c=s[0]; int index = 0;
	for(int i = 1; i<n; i++){
		if(s[i]<=c){c = s[i];b[i]=false;index = i;}
		else if(s[i]>c)b[i]=true;
	}
	for(int i = 0; i<n; i++){
		b[i]?cout<<"Ann"<<endl:cout<<"Mike"<<endl;
	}
	return 0;
}