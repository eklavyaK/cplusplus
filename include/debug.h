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

/****************************************************DEBUG TEMPLATE*******************************************/


#define debug(...) std::cerr << ultimate_humungousaur(#__VA_ARGS__) << __printDebug(__VA_ARGS__) <<  '\n'
#define debugarr(a,n) std::cerr << "## " << #a << " => " << __printarr(a,n) << '\n'
#define min_pq(T) std::priority_queue<T,std::vector<T>,std::greater<T>>
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
template <typename T, typename V> void __print(std::pair<T,V>p){ std::cerr<<"{";__print(p.first);std::cerr<<",";__print(p.second);std::cerr<<"}"; }
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

template <typename... Args> std::string ultimate_humungousaur(const std::string &names){
    std::stringstream debugStream;
    debugStream << names;
    std::string namesString = debugStream.str();
    __stripSpaces(namesString);
    std::cerr << "## ";
    __printVariableNames(namesString);
    std::cerr << "=> ";
    return "";
}

template <typename T> std::string __printDebug(const T &value){
    __print(value); std::cerr << " "; return "";
}

template <typename T, typename... Args> std::string __printDebug(const T &value, const Args &...args){
    __print(value); std::cerr << " ";
    __printDebug(args...);
    return "";
}

/****************************************************TEMPLATE ENDS HERE*******************************************/