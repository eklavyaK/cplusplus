function<void(int,int)> dfs = [&](int i, int j){
    //     if(i<0) return;
    //     if(s[i]=='(' && s[j]==')'){
    //         cost+=active;
    //         if(!active){
    //             i-=2;
    //             address[i+1] = j;
    //             j = address[i];
    //         }
    //         else{
    //             i--;
    //             j = address[j];
    //             active--;
    //         }
    //     }
    //     else if(s[i]==')' && s[j]==')'){
    //         address[i] = j;
    //         j = i;
    //         i--;
    //         active++;
    //     }
    //     dfs(i,j);
    // };
    // dfs(n-2,n-1);