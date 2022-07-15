#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
/***************************************************MAIN PROGRAM*******************************************************/
vector<vector<char>> now;
bool solve(){
    int done[10]{};
    function<void(int,int)> compute_box=[&](int r, int c){
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(now[i][j]!='.')done[now[i][j]-'0']++;
            }
        }
    };
    function<void(int)> compute_row=[&](int row){
        for(int j=0;j<9;j++){
            if(now[row][j]!='.')done[now[row][j]-'0']++;
        }
    };
    function<void(int)> compute_col=[&](int col){
        for(int j=0;j<9;j++){
            if(now[j][col]!='.')done[now[j][col]-'0']++;
        }
    };
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(now[i][j]=='.'){
                if(i<3 && j<3)compute_box(0,0);
                else if(i<3 && j<6)compute_box(0,3);
                else if(i<3 && j<9)compute_box(0,6);
                else if(i<6 && j<3)compute_box(3,0);
                else if(i<6 && j<6)compute_box(3,3);
                else if(i<6 && j<9)compute_box(3,6);
                else if(i<9 && j<3)compute_box(6,0);
                else if(i<9 && j<6)compute_box(6,3);
                else compute_box(6,6);
                compute_col(j);
                compute_row(i);
                for(int k=1;k<10;k++){
                    if(!done[k]){
                        now[i][j] = (char)('0'+k);
                        if(solve())return true;
                        now[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &A) {
    now = A;
    if(!solve()){
        cout<<"No solution exist!!\nPlease enter a correct Sudoku."<<endl;
        exit(0);
    }
}
int main(){
    vector<string> example({"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"}); cout<<"Example input:-\n"<<endl;
    for(auto vec : example){
        for(int i=0;i<9;i++)cout<<vec[i]<<' ';cout<<endl;
    }
    cout<<endl;
    cout<<"Please enter the original numbers in Sudoku in row-column format with space between the numbers in the same row."<<endl;
    cout<<"Enter a dot (.) in case if cell is empty. Refer to the above example.\n"<<endl;
    vector<vector<char>> v(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char c; cin>>c;
            if((c-'0'<=9 && c-'0'>=1)||c=='.'){
                v[i][j] = c;
            }
            else{
                cout<<"INVALID INPUT";
                exit(0);
            }
        }
    }
    cout<<endl<<endl;
    solveSudoku(v);
    cout<<"Original Sudoku:-\n"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<v[i][j]<<((j!=8)?" | ":"");
        }
        cout<<endl;
        if(i!=8)cout<<string(33,'-')<<endl;
    }
    cout<<'\n'<<endl;
    cout<<"Solved Sudoku:-\n"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<now[i][j]<<((j!=8)?" | ":"");
        }
        cout<<endl;
        if(i!=8)cout<<string(33,'-')<<endl;
    }
    return 0;
}