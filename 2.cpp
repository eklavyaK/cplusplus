#include <bits/stdc++.h>
using namespace std;

void bournVita()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

}

int reverseNum(int n) {
int num = 0;

while(n != 0) {
    num = n % 10 + num * 10;
    n = n / 10;
} 

return num;
}

bool checkPalindrome(int n) {

int revNum = reverseNum(n);
cout << n << " " << revNum << endl;
if(revNum == n) {
    return true;
}

return false;
}

void solve() {
int n;
cin >> n;

while(checkPalindrome(n) == false) {
    int revNum = reverseNum(n);
    n = n + revNum;
}

cout << n << endl;
}

int main(){

bournVita();


int t;
cin >> t;

while(t--) {
    solve();
}

return 0;
}