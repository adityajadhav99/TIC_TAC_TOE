#include<iostream>
using namespace std;

int N = 3;
char board[3][3];
char player[2] = {'X' , 'O'};
char winner;

void show_config(void){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j==0)
            {
                cout<<"  "<<board[i][j]<<"  ";
            }
            else{
                  cout<<"|  "<<board[i][j]<<"  ";// 5 characters printed 2 spaces,1 char,2 spaces

            }
        }
        if (i==2)
        {
            break;
        }
        else{
            cout<<"\n-----------------\n";
        }
    }   
}


bool checkWindir(int dir,char player){
    int  s,t;
    for (int i = 0; i < N; i++)
    {   int count =0;
        for (int j = 0; j < N; j++)
        {
            switch (dir)
            {
            case 1:
                s = i; t = j;
                break;
            case 2:
                s = j; t = i;
                break;
            case 3:
                s = j; t = j;
                break;
            case 4:
                s = j; t = N-j-1;
                break;
            default:
                break;
            }
            if (board[s][t] == player)
            {
                count++;
            }
            if(count == N)
            {
                return true;
            }
        }    
    }
    return false;
}

bool checkWin(){
    for (int dir = 1;dir<5;dir++){
        for(int p = 0; p<2 ; p++){
            if(checkWindir(dir,player[p])){
                winner = player[p];
                return true; 
            }
        }
    }
    return false;
}

bool checkLegal(int i, int j){
    if (i>3 || i<1 || j>3 || j<1)
    {
        return false;
    }
    if (board[i-1][j-1] == 0)
    {
        return true;
    }
    return false;
}

void putSymbol(int i, int j, char C){
    board[i-1][j-1] = C;
}

bool checkDraw(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }
   return true; 
}

int main(){
    string PLAYERS[2];
    cout<<"WELCOME TO THE TIC-TAC-TOE COMPETITION !!!!!!!!\nBelow you will see a board and you have to tell where you want to place the sign.\nThe first one to complete his sign in a row or column or a diagonal will win!!!"<<endl;
    cout<<"Player 1, Please enter your name : "; cin>>PLAYERS[0];
    cout<<"Player 2, Please enter your name : "; cin>>PLAYERS[1];
    
   int p = 0;
   int i , j;
    while (checkWin() != 1)
    {
        cout<<"\n";
        show_config();
        cout<<"\n"<<PLAYERS[p]<<"'s move : ";
        cin>>i>>j;
        if(checkLegal(i,j) == 0){
            continue;
        }
        putSymbol(i,j,player[p]);
        if (checkDraw() == 1)
        {
            show_config();
            cout<<"\n:(  The match has been DRAWN."<<endl;
            break;
        }
        
        p = (p+1)%2;
    }


    if (winner == 'X')
    {
        show_config();
        cout<<"\n"<<PLAYERS[0]<<" has won. Congrats!!!!!"<<endl;
    }
    if (winner == 'O')
    {
        show_config();
        cout<<"\n"<<PLAYERS[1]<<" has won. Congrats!!!!!"<<endl;
    }
    

    return 0;
}
