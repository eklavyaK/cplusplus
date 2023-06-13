#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
using namespace std;

void func(long long t = 0, char c = '`'){
    if(c!='`'){
        cout<<c<<endl;
    }
    else cout<<t<<endl;
}

void code(){
    int arr[10]{};
    func(2);
    func('A');
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);code();
    return 0;
}