#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn='x';
bool draw=false;
void display_board(void)
{

    system("cls");
    cout<<"\n\n\tT I C K -- T A C -- T O E --  G A M E"<<endl;
    cout<<"\tFOR TWO PLAYER "<<endl;
    cout<<"\t\t ____________________________"<<endl;
    cout<<"\t\t|        |          |        |"<<endl;
    cout<<"\t\t|   "<<board[0][0]<<"    |   "<<board[0][1]<<"      |   "<<board[0][2]<<"    |"<<endl;
    cout<<"\t\t|________|__________|________|"<<endl;
    cout<<"\t\t|        |          |        |"<<endl;
    cout<<"\t\t|   "<<board[1][0]<<"    |   "<<board[1][1]<<"      |   "<<board[1][2]<<"    |"<<endl;
    cout<<"\t\t|________|__________|________|"<<endl;
    cout<<"\t\t|        |          |        |"<<endl;
    cout<<"\t\t|   "<<board[2][0]<<"    |   "<<board[2][1]<<"      |   "<<board[2][2]<<"    |"<<endl;
    cout<<"\t\t|________|__________|________|"<<endl;
}
void player_turn(void)
{
    if(turn=='x')
    {
        cout<<"\tPlayer-1 turn[x] (selete box) : ";
    }
    else if(turn=='o')
    {
        cout<<"\tPlayer-2 turn[o] (selete box) : ";
    }

    cin>>choice;

    switch(choice)
    {
        case 1:row=0; column=0; break;
        case 2:row=0; column=1; break;
        case 3:row=0; column=2; break;
        case 4:row=1; column=0; break;
        case 5:row=1; column=1; break;
        case 6:row=1; column=2; break;
        case 7:row=2; column=0; break;
        case 8:row=2; column=1; break;
        case 9:row=2; column=2; break;
        default:
        cout<<"\tInvalid move"<<endl;
        break;
    }

    if(turn=='x' && board[row][column]!='x' && board[row][column]!='o')
    {
        board[row][column]='x';
        turn='o';
    }
    else if(turn=='o' && board[row][column]!='o' && board[row][column]!='x')
    {
        board[row][column]='o';
        turn='x';
    }
    else
    {
        cout<<"\tbox is already filled!\n please chooes another!!"<<endl;
        player_turn();
    }
    display_board();
}
bool game_over(void)
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return false;
        }
    }

    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] &&  board[0][2]==board[2][0])
    {
        return false;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] !='x' && board[i][j]!='o')
            {
                return true;
            }
        }
    }   
}
int main()
{
    while (game_over())
    {
        display_board();
        player_turn();
        game_over();
    }
    if(turn=='x' && draw==false)
    {
        cout<<"\tCongratulations!player with [o] has won the game"<<endl;
    }
    else if(turn=='o' && draw==false)
    {
        cout<<"\tCongratulations!player with [x] has won the game"<<endl;
    }
    else 
    {
        cout<<"\t GAME-DRAW "<<endl;
    }
    return 0;
}