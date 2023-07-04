// #ifndef ONLINE_JUDGE
// freopen("1err.txt", "w", stderr);
// #endif




const string fff="[ ",vvv="{",kkk=",",xxx=" ",zzz="}",yyy="]";
#define debug(...) ultimate_humungousaur(#__VA_ARGS__), __printDebug(__VA_ARGS__), cerr << endl
#define debugarr(a,n)cerr<<"## "<<#a<<" => "<<__printarr(a,n)<<endl
#define min_pq priority_queue<T,vector<T>,greater<T>>
void __print(signed x){cerr<<x;}
void __print(unsigned x){cerr<<x;}
void __print(signed long x){cerr<<x;}
void __print(unsigned long x){cerr<<x;}
void __print(signed long long x){cerr<<x;}
void __print(unsigned long long x){cerr<<x;}
void __print(float x){cerr<<x;}
void __print(double x){cerr<<x;}
void __print(long double x){cerr<<x;}
void __print(char x){cerr<<x;}
void __print(const char *x){cerr<<x;}
void __print(const string &x){cerr<<x;}
void __print(bool x){cerr<<x;}
template<class T>void __print(set<T>);
template<class T>void __print(vector<T>);
template<class T>void __print(queue<T>);
template<class T>void __print(stack<T>);
template<class T>void __print(multiset<T>);
template<class T,class V>void __print(map<T,V>m);
template<class T,class V>void __print(pair<T,V>p);
template<class T>void __print(vector<T>v){__print(fff);for(T i:v){__print(i);__print(xxx);} __print(yyy);}
template<class T>void __print(set<T>s){__print(fff);for(T i:s){__print(i);__print(xxx);}__print(yyy);}
template<class T>void __print(multiset<T>ms){__print(fff);for(T i:ms){__print(i);__print(xxx);} __print(yyy);}
template<class T>void __print(queue<T>q){__print(fff);while(!q.empty()){__print(q.front());q.pop();__print(xxx);}__print(yyy);}
template<class T>void __print(priority_queue<T>q){__print(fff);while(!q.empty()){__print(q.top());q.pop();__print(xxx);}__print(yyy);}
template<class T>void __print(min_pq q){__print(fff);while(!q.empty()){__print(q.top());q.pop();__print(xxx);}__print(yyy);}
template<class T>void __print(stack<T>st){__print(fff);while(!st.empty()){__print(st.top());st.pop();__print(xxx);}__print(yyy);}
template<class T,class V>void __print(pair<T,V>p){__print(vvv);__print(p.F);__print(kkk);__print(p.S);__print(zzz);}
template<class T>string __printarr(T *a,int n){__print(fff);for(int i=0;i<n;i++){__print(a[i]);__print(xxx);} __print(yyy);return "";}
template<class T,class V>void __print(map<T,V>m){__print(fff);for(auto i:m){__print(i);__print(xxx);}__print(yyy);}

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
    __print(value); cerr << " ";
}

template <typename T, typename... Args> void __printDebug(const T &value, const Args &...args){
    __print(value); cerr << " ";
    __printDebug(args...);
}