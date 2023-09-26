#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
/*
Little Johnny Bubbles enjoys spending hours in front of his computer playing video games. His favorite game is Bubble Strike, fast-paced bubble shooting online game for two players.

Each game is set in one of the N maps, each having different terrain configuration. First phase of each game decides on which map the game will be played. The game system randomly selects three maps and shows them to the players. For each player the combination of three maps shown can be same or different. Each player must pick one of those three maps shown to them to be discarded. The game system then randomly selects one of the maps (from whole set of available maps) that was not picked by any of the players and starts the game.

Johnny is deeply enthusiastic about the game and wants to spend some time studying maps, thus increasing chances to win games played on those maps. However, he also needs to do his homework, so he does not have time to study all the maps. That is why he asked himself the following question: "What is the minimum number of maps I have to study, so that the probability to play one of those maps is at least P
"?

Can you help Johnny find the answer for this question? You can assume Johnny's opponents do not know him, and they will randomly pick maps.
*/
void code(){
    ld n, p; cin>>n>>p;
    ld divisor = n*n*(n-1)*(n-2)/6;
    function<ld(int)> read = [&](int x){
        return x-1<2?0:(x-1)*(x-2)/6;
    };
    function<ld(int)> unread =[&](int x){
        ld a = (n-x-1<1||x<1)?0:(n-x-1)*x*(ld)0.5;
        ld b = x<2?0:(x-1)*(x-2)*(ld)0.5;
        ld c = n-x-1<2?0:(n-x-1)*(n-x-2)/(ld)6;
        return a+b+c;
    };
    function<bool(int)> check = [&](int x){
        cout<<x<<endl;
        ld a = (x<2?0:x*(x-1))*read(x)*(x-2)/(n-2);
        ld b = (n-x<1?0:n-x)*unread(x)*x/(n-1);
        ld c = (n-x<2?0:(n-x)*(n-x-1))*unread(x)*x/(n-2);
        ld d = (x<1?0:x)*read(x)*(x-1)/(n-1);
        ld e = ((n-x<1||x<1)?0:(n-x)*x)*(read(x)+unread(x))*(x-1)/(n-2);
        return (a+b+c+d+e)/divisor>=p;
    };
    int l = 0, r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}