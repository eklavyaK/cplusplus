#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
string s; int n;
vector<int> pos;
int get(int l, int r){
	if(r-l==1)return 0;
	else if(pos[r]==l){
		return get(l+1,r-1);
	}
	else{
		int ret = get(pos[r],r);
		r = pos[r]-3;
		while(true){
			ret = max(ret,get(pos[r],r)+1);
			if(pos[r]<=l) break;
			else r = pos[r]-3;
		}
		return ret;
	}
}
int main(){
	cin>>s;
	stack<int> q;
	n = s.size();
	pos.resize(n);
	for(int i=0;i<n;i++){
		if(s[i]=='(')q.push(i);
		else if(s[i]==')')pos[i] = q.top(), q.pop();
	}
	cout<<get(0,n-1)<<endl;
	return 0;
}