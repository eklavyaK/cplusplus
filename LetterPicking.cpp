#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
vector<vector<int>> res;
string s;
int check(int l, int r){
	if(r-l==1){
		if(s[l]==s[r])return 3;
		else return 1;
	}
	if(!res[l+1][r-1])res[l+1][r-1]=check(l+1,r-1);
	if(!res[l+2][r])res[l+2][r]=check(l+2,r);
	if(!res[l][r-2])res[l][r-2]=check(l,r-2);

	if(((res[l+2][r]==1 || (res[l+2][r]==3 && s[l]<s[l+1]))&&(res[l+1][r-1]==1 || (res[l+1][r-1]==3 && s[l]<s[r])))||
	((res[l][r-2]==1||(res[l][r-2]==3 &&s[r]<s[r-1]))&&(res[l+1][r-1]==1 || (res[l+1][r-1]==3 && s[r]<s[l])))) 
	return 1;

	if(((res[l+1][r-1]==2||res[l+2][r]==2) || (res[l+1][r-1]==3 && s[l]>s[r]) || (res[l+2][r]==3 && s[l]>s[l+1])) &&
	((res[l][r-2]==2||res[l+1][r-1]==2) || (res[l+1][r-1]==3 && s[r]>s[l]) || (res[l][r-2]==3 && s[r]>s[r-1])))
	return 2;

	return 3;
}
void code(){
	cin>>s; int n = s.size();
	res = vector<vector<int>> (n,vector<int>(n));
	int k = check(0,n-1);
	if(k==1)cout<<"Alice"<<endl;
	else if(k==2)cout<<"Bob"<<endl;
	else cout<<"Draw"<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}