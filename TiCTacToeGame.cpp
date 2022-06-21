#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
string p1, p2;
char c1, c2;
int cnt;
map<char,string> m;
map<string,bool> input;
vector<char> matrix(9);
void start();
void display();
void check(char c){
    cnt++;
    if((matrix[0]==matrix[1] && matrix[1]==matrix[2] && matrix[0]!=' ') ||
    (matrix[3]==matrix[4] && matrix[4]==matrix[5] && matrix[5]!=' ') ||
    (matrix[6]==matrix[7] && matrix[7]==matrix[8] && matrix[8]!=' ') ||
    (matrix[0]==matrix[3] && matrix[3]==matrix[6] && matrix[6]!=' ') ||
    (matrix[1]==matrix[4] && matrix[4]==matrix[7] && matrix[7]!=' ') ||
    (matrix[2]==matrix[5] && matrix[5]==matrix[8] && matrix[8]!=' ') ||
    (matrix[0]==matrix[4] && matrix[4]==matrix[8] && matrix[8]!=' ') ||
    (matrix[2]==matrix[4] && matrix[4]==matrix[6] && matrix[6]!=' ')){
        display();
        int k = 41+m[c].size();
        cout<<string(k,'~')<<endl;
        cout<<"!!!!!!! Congrats '"<<m[c]<<"', you have WON !!!!!!!"<<endl;
        cout<<string(k,'~')<<endl;
        cout<<endl;
        start();
    }
    if(cnt==9){
        display();
        cout<<string(26,'~')<<endl;
        cout<<"!!!!!!! Match DRAW !!!!!!!"<<endl;
        cout<<string(26,'~')<<endl;
        cout<<endl;
        start();
    }
}
void display(){
    cout<<" "<<matrix[0]<<" "<<'|'<<" "<<matrix[1]<<" "<<'|'<<" "<<matrix[2]<<"                           "<<" 1 "<<'|'<<" 2 "<<'|'<<" 3 "<<"            position"<<endl;
    cout<<"-----------                          -----------"<<endl;
    cout<<" "<<matrix[3]<<" "<<'|'<<" "<<matrix[4]<<" "<<'|'<<" "<<matrix[5]<<"                           "<<" 4 "<<'|'<<" 5 "<<'|'<<" 6 "<<"   <--------   of"<<endl;
    cout<<"-----------                          -----------"<<endl;
    cout<<" "<<matrix[6]<<" "<<'|'<<" "<<matrix[7]<<" "<<'|'<<" "<<matrix[8]<<"                           "<<" 7 "<<'|'<<" 8 "<<'|'<<" 9 "<<"            the cells"<<endl;
    cout<<endl;
}
void play(){
    string in;
    display();
    bool r = true;
    while(true){
        if(r) cout<<p1<<", it's your turn (enter a cell position):"<<endl;
        else cout<<"Enter again:"<<endl;
        cin>>in; r = false;cout<<endl;
        if(input.count(in)){
            int k = stoi(in);
            if(matrix[k-1]!=' '){
                cout<<"!! Please choose an empty cell !!"<<endl;
                continue;
            }
            matrix[k-1]=c1;
            break;
        }
        else cout<<"!!!! Invalid input !!!!"<<endl;
    }
    check(c1);
    display();
    r = true;
    while(true){
        if(r) cout<<p2<<", it's your turn (enter a cell position):"<<endl;
        else cout<<"Enter again:"<<endl;
        cin>>in; r = false;cout<<endl;
        if(input.count(in)){
            int k = stoi(in);
            if(matrix[k-1]!=' '){
                cout<<endl;
                cout<<"!! Please choose an empty cell !!"<<endl;
                continue;
            }
            matrix[k-1]=c2;
            break;
        }
        else cout<<"!!!! Invalid input !!!!"<<endl;
    }
    check(c2);
    play();
}
void start(){
    fill(matrix.begin(),matrix.end(),' ');
    while(true){
        cout<<"Press 'Y' to play, press 'N' to quit:"<<endl;
        string c; cin>>c;
        if(c == "Y" || c== "y")break;
        else if(c == "N" || c == "n")exit(0);
        else cout<<endl<<"!!!! Invalid input !!!!"<<endl<<endl;
    }
    string s;
    cout<<endl;
    getline(cin,s);
    cout<<"Name of Player 1: "; getline(cin,p1);
    cout<<endl;
    cout<<"Name of Player 2: "; getline(cin,p2);
    cout<<endl;
    while(true){
        string c;
        cout<<p1<<" Choose your symbol (x or o): ";
        cin>>c;cout<<endl;
        if(c=="X"){
            c2 = 'O'; c1 = 'X';
            cout<<p2<<"'s symbol is: O"<<endl;
        }
        else if(c == "x"){
            c2 = 'o'; c1 = 'x';
            cout<<p2<<"'s symbol is: o"<<endl;
        }
        else if(c=="O"){
            c2 = 'X'; c1 = 'O';
            cout<<p2<<"'s symbol is: X"<<endl;
        }
        else if(c == "o"){
            c2 = 'x'; c1 = 'o';
            cout<<p2<<"'s symbol is: x"<<endl;
        }
        else{
            cout<<"!!!! Invalid input !!!!"<<endl<<endl;
            continue;
        }
        break;
    }
    cout<<endl;
    m[c2]=p2;m[c1]=p1;
    cnt = 0;
    play();
}
int main(){
    for(int i=1;i<=9;i++){
        input[to_string(i)]=true;
    }
    start();
    return 0;
}