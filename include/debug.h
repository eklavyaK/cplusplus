/***********************************************************
 * Save the template in a *.h file
 * Include the macros below in your cplusplus file at the top (not above <bits/stdc++.h>)
 * Don't forget to replace the "include/debug.h" with the path of the *.h file
 * Also you must include all the STL structures used debug file. Best way for this is to directly include <bits/stdc++.h>


#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif

***************************************************************/

/**************************************************************
 * If you want separate console for stderr, then include this code in the main function
 

#ifndef ONLINE_JUDGE
freopen("1err.txt", "w", stderr);
#endif

***************************************************************/

/********************************************************************
 * WARNING: This debug file doesn't work for all the data structures
 * NOTE: It works for all the primitive data types (most probably). It works for normal set, map, pair, vector, queue, priority_queue(max and min), deque, multiset and array.
 * NOTE: If normal definitions of these datastructures is changed while declaration then it might not work
  *******************************************************************/

/**************************************************** DEBUG TEMPLATE *******************************************/


#define debug(...) std::cerr << "## " << humungousaur(#__VA_ARGS__) << "=> " << ultimate_humungousaur(__VA_ARGS__) <<  '\n'
#define debugarr(a,n) std::cerr << "## " << #a << " => " << __printarr(a,n) << '\n'
#define min_pq(T) std::priority_queue<T,std::vector<T>,std::greater<T>>

void __print(__int128 x){ std::cerr << (int) x; }
void __print(signed x){ std::cerr<<x; }
void __print(unsigned x){ std::cerr<<x; }
void __print(signed long x){ std::cerr<<x; }
void __print(unsigned long x){ std::cerr<<x; }
void __print(signed long long x){ std::cerr<<x; }
void __print(unsigned long long x){ std::cerr<<x; }
void __print(float x){ std::cerr<<x; }
void __print(double x){ std::cerr<<x; }
void __print(long double x){ std::cerr<<x; }
void __print(char x){ std::cerr<<"\'"<<x<<"\'"; }
void __print(const char *x){ std::cerr<<"\""<<x<<"\""; }
void __print(const std::string &x){ std::cerr<<"\""<<x<<"\""; }
void __print(bool x){ std::cerr<<x; }
template <typename T> void __print(std::set<T>);
template <typename T> void __print(std::vector<T>);
template <typename T> void __print(std::queue<T>);
template <typename T> void __print(std::deque<T>);
template <typename T> void __print(std::stack<T>);
template <typename T> void __print(std::multiset<T>);
template <typename T> void __print(std::priority_queue<T>q);
template <typename T> void __print(min_pq(T) q);
template <typename T, typename V> void __print(std::map<T,V>m);
template <typename T, typename V> void __print(std::pair<T,V>p);
template <typename T> void __print(std::vector<T>v){ std::cerr<<"[ ";for(T i:v){__print(i);std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(std::set<T>s){ std::cerr<<"[ ";for(T i:s){__print(i);std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(std::multiset<T>ms){ std::cerr<<"[ ";for(T i:ms){__print(i);std::cerr<<" ";} std::cerr<<"]"; }
template <typename T> void __print(std::queue<T>q){ std::cerr<<"[ ";while(!q.empty()){__print(q.front());q.pop();std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(std::deque<T>q){ std::cerr<<"[ ";while(!q.empty()){__print(q.front());q.pop_front();std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(std::priority_queue<T>q){ std::cerr<<"[ ";while(!q.empty()){__print(q.top());q.pop();std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(min_pq(T) q){ std::cerr<<"[ ";while(!q.empty()){__print(q.top());q.pop();std::cerr<<" ";}std::cerr<<"]"; }
template <typename T> void __print(std::stack<T>st){ std::cerr<<"[ ";while(!st.empty()){__print(st.top());st.pop();std::cerr<<" ";}std::cerr<<"]"; }
template <typename T, typename V> void __print(std::pair<T,V>p){ std::cerr<<"{";__print(p.first);std::cerr<<", ";__print(p.second);std::cerr<<"}"; }
template <typename T>std::string __printarr(T *a,int n){ std::cerr<<"[ ";for(int i=0;i<n;i++){__print(a[i]);std::cerr<<" ";} std::cerr<<"]";return ""; }
template <typename T, typename V> void __print(std::map<T,V>m){ std::cerr<<"[ ";for(auto i:m){__print(i);std::cerr<<" ";}std::cerr<<"]"; }

void __stripSpaces(std::string &str){
    size_t pos = 0;
    while ((pos = str.find(" ", pos)) != std::string::npos){
        str.erase(pos, 1);
    }
}

template <typename... Args> void __printVariableNames(const std::string &names){
    std::istringstream iss(names);
    std::string name;
    while (std::getline(iss, name, ',')){
        std::cerr << name << " ";
    }
}

template <typename... Args> std::string humungousaur(const std::string &names){
    std::stringstream debugStream;
    debugStream << names;
    std::string namesString = debugStream.str();
    __stripSpaces(namesString);
    __printVariableNames(namesString);
    return "";
}

template <typename T> std::string ultimate_humungousaur(const T &value){
    __print(value); std::cerr << " "; 
    return "";
}

template <typename T, typename... Args> std::string ultimate_humungousaur(const T &value, const Args &...args){
    __print(value); std::cerr << " ";
    ultimate_humungousaur(args...);
    return "";
}

/**************************************************** TEMPLATE ENDS HERE *******************************************/

/**************************************************** SAMPLE TESTER CODE *******************************************

#include<bits/stdc++.h>
#include "include/debug.h"
signed main(){
    int a = 10;
    std::string b = "w3r32";
    char c = '2';
    std::vector<std::string> v({"aef","wef"});
    std::set<int> st{23,23,432,234,2};
    std::vector<std::pair<int,int>> z({{3,234},{34,34}});
    long double d = 234.2399;
    long long e = 2343234239834;
    debug(a,b,c,d,e);
    debug(st);
    debug(v);
    debug(z);
    debug(10);
    debug(false);
    debug('c');
    debug(2343.23432);
    debug("wdef");
    debug(203982844902839023);
    std::deque<std::map<std::string,int>> q;
    std::map<std::string,int> m;
    m["w23432"] = 2323;
    m["223432"] = a;
    m["oiion"] = 90;
    q.push_front(m);
    int arr[10]{};
    debugarr(arr,10);
    std::priority_queue<std::pair<int,std::string>,std::vector<std::pair<int,std::string>>,std::greater<std::pair<int,std::string>>> pq;
    pq.push({2342,"ok"});
    pq.push({889,"ok"});
    pq.push({54645,"ok"});
    debug(pq);
    std::priority_queue<std::pair<int,std::string>> spq;
    spq.push({2342,"ok"});
    spq.push({889,"ok"});
    spq.push({54645,"ok"});
    debug(spq);
    std::multiset<long double> ms;
    for(int i=0;i<10;i++)ms.insert(rand()%19989);
    debug(ms);
    std::stack<char> stk;
    for(int i=0;i<26;i++) stk.push(65+i);
    debug(stk);
    debug(ms,spq,pq,m,d,e,a,b,c,e,v,st,stk);   //debugging all!!
    return 0;
}

************************* TEST OUTPUT *******************************

## a b c d e => 10 "w3r32" '2' 234.24 2343234239834 
## st => [ 2 23 234 432 ]
## v => [ "aef" "wef" ]
## z => [ {3, 234} {34, 34} ] 
## 10 => 10
## false => 0
## 'c' => 'c'
## "wdef" => "wdef"
## 203982844902839023 => 203982844902839023
## arr => [ 0 0 0 0 0 0 0 0 0 0 ]
## pq => [ {889, "ok"} {2342, "ok"} {54645, "ok"} ]
## spq => [ {54645, "ok"} {2342, "ok"} {889, "ok"} ]
## ms => [ 41 4475 6334 6511 6973 9369 11478 15724 18467 19169 ]
## stk => [ 'Z' 'Y' 'X' 'W' 'V' 'U' 'T' 'S' 'R' 'Q' 'P' 'O' 'N' 'M' 'L' 'K' 'J' 'I' 'H' 'G' 'F' 'E' 'D' 'C' 'B' 'A' ]
## ms spq pq m d e a b c e v st stk => [ 41 4475 6334 6511 6973 9369 11478 15724 18467 19169 ] [ {54645, "ok"} {2342, "ok"} {889, "ok"} ] [ {889, "ok"} {2342, "ok"} {54645, "ok"} ] [ {"223432", 10} {"oiion", 90} {"w23432", 2323} ] 234.24 2343234239834 10 "w3r32" '2' 2343234239834 [ "aef" "wef" ] [ 2 23 234 432 ] [ 'Z' 'Y' 'X' 'W' 'V' 'U' 'T' 'S' 'R' 'Q' 'P' 'O' 'N' 'M' 'L' 'K' 'J' 'I' 'H' 'G' 'F' 'E' 'D' 'C' 'B' 'A' ]

***************************************************************************************************************/