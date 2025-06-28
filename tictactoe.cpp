#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Board{
    vector<vector<char>> grid;
    int size;

public:
    Board(int n=3):size(n){
        grid=vector<vector<char>>(n,vector<char>(n,' '));
    }
    void display(){
        cout<<"\n";
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                cout<<" "<<grid[i][j]<<" ";
                if(j<size-1) cout<<"|";
            }
            cout<<"\n";
            if(i<size-1) cout<<string(size*4-1,'-')<<"\n";
        }
        cout<<"\n";
    }

    bool makeMove(int r,int c,char sym){
        if(r<0||r>=size||c<0||c>=size||grid[r][c]!=' ') return false;
        grid[r][c]=sym;
        return true;
    }
    bool checkWin(char sym){
        for(int i=0;i<size;++i){
            if(all_of(grid[i].begin(),grid[i].end(),[=](char x){return x==sym;})) return true;
            bool col=true;
            for(int j=0;j<size;++j) if(grid[j][i]!=sym) col=false;
            if(col) return true;
        }
        bool diag1=true,diag2=true;
        for(int i=0;i<size;++i){
            if(grid[i][i]!=sym) diag1=false;
            if(grid[i][size-1-i]!=sym) diag2=false;
        }
        return diag1||diag2;
    }
    bool isFull(){
        for(auto& row:grid)
            for(char c:row)
                if(c==' ') return false;
        return true;
    }
};

class Game{
    Board b;
    char p1='X',p2='O';
public:
    void play(){
        cout<<"TIC TAC TOE\n";
        b.display();
        char turn=p1;
        while(true){
            int r,c;
            cout<<"Player "<<turn<<", enter row and column (0-based): ";
            cin>>r>>c;
            if(!b.makeMove(r,c,turn)){
                cout<<"Invalid move! Try again.\n";
                continue;
            }
            b.display();
            if(b.checkWin(turn)){
                cout<<"Player "<<turn<<" wins!\n";
                break;
            }
            if(b.isFull()){
                cout<<"It's a draw!\n";
                break;
            }
            turn=(turn==p1?p2:p1);
        }
    }
};

int main(){
    Game g;
    g.play();
    return 0;
}

