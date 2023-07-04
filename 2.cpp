#include <bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#include "include/debug.h"
#define debug(...) ultimate_humungousaur(#__VA_ARGS__), __printDebug(__VA_ARGS__), cerr << endl

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

template <typename... Args> void ultimate_humungousaur(const std::string &names){
    std::stringstream debugStream;
    debugStream << names;
    std::string namesString = debugStream.str();
    __stripSpaces(namesString);
    std::cerr << "## ";
    __printVariableNames(namesString);
    std::cerr << "=> ";
}

template <typename T> void __printDebug(const T &value){
    __print(value);
    __print(xxx);
}

template <typename T, typename... Args> void __printDebug(const T &value, const Args &...args){
    __print(value);
    cerr << " ";
    __printDebug(args...);
}

void code(int TC)
{
    int a = 2343;
    string b = "afd";
    char c = 'c';
    bool f = 1;
    long double l = 3.14;
    debug(a, b, c);
    debug(a, b, c, f, l);
    set<int> st{a,34,34,3,5,3451};
    vector<int> v({23,23,908,489,34});
    priority_queue<set<int>> pq;
    pq.push(st);
    debug(pq);
    debug(v);
    debug(st);
    debug(false);
    debug(2343223432.23432) ;
    debug(23439);
    debug(23,4,23,4);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cerr.tie(0);
    cerr.tie(0);
    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++)
        code(TC);
    return 0;
}