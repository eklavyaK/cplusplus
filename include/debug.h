// #ifndef ONLINE_JUDGE
// freopen("1err.txt", "w", stderr);
// #endif




const string fff="[ ",vvv="{",kkk=",",xxx=" ",zzz="}",yyy="]";
#define debug(x)cerr<<"=> "<<#x<<xxx<<ultimate_humungousaur(x)<<endl
#define debugvar(x)cerr<<"=> "<<ultimate_humungousaur(x)<<endl
#define debugarr(x,n)cerr<<"=> "<<#x<<xxx<<ultimate_humungousaur(x,n)<<endl
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
template<class T>void __print(T *a,int n){__print(fff);for(int i=0;i<n;i++){__print(a[i]);__print(xxx);} __print(yyy);}
template<class T,class V>void __print(map<T,V>m){__print(fff);for(auto i:m){__print(i);__print(xxx);}__print(yyy);}
template<typename T> string ultimate_humungousaur(T x){__print(x); return "";}
template<typename T> string ultimate_humungousaur(T x, int n){__print(x,n); return "";}