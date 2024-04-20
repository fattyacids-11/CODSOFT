#include<iostream>
#include<string>
using namespace std;

int main()
{
	char board[3][3] = {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '}
	};
	
	
	const char player1 = 'x';
	const char player2 = 'o';
	char currentplayer = player1;
	char winner = ' ';
	bool playagain = true;
	
	
	while (playagain){
	int r = -1;
	int c = -1;
	for(int i =0;i<9 ;i++)
	{
	cout<<"  |  |  "<<endl;
	cout<<" "<<board[0][0]<<"| "<<board[0][1]<<"| "<<board[0][2]<<endl;
	cout<<"__|__|__"<<endl;
	cout<<"  |  |  "<<endl;
	cout<<" "<<board[1][0]<<"| "<<board[1][1]<<"| "<<board[1][2]<<endl;
	cout<<"__|__|__"<<endl;
	cout<<"  |  |  "<<endl;
	cout<<" "<<board[2][0]<<"| "<<board[2][1]<<"| "<<board[2][2]<<endl;
	cout<<"  |  |  "<<endl;
	
	if(winner != ' ')
	{
		break;
	}	
	cout<<"curent player is"<< currentplayer<<endl;
	while(true){
		cout<<"enter r c from 0-2 for row and column: "<<endl;
	cin>>r>>c;
	if (r < 0 ||r > 2 ||c < 0 ||c > 2)
	{
		cout<<"invalid input try again"<<endl;
	}
	else if(board[r][c]!= ' ')
	{
		cout<<"tile is full try again"<<endl;
	}
	else{
		break;
	}
	r=-1;
	c=-1;
	cin.clear();
	cin.ignore(10000 , '\n');
	}
	
	board[r][c]= currentplayer;
	currentplayer = (currentplayer == player1) ? player2 : player1;
	for(int r= 0 ; r <3 ;r++)
	{
		if (board[r][0] != ' ' && board[r][0]==board[r][1] && board[r][2]){
			winner = board[r][0];
			break;
		}
	}
	
	for (int c=0 ; c< 3; c++)
	{
		if(board[0][c] != ' ' && board[0][c]== board[1][c] == board[2][c])
		{
			winner = board[0][c];
			break;
		}
	}
	if (board[0][0]!= ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		winner = board[0][0];
	}
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		winner = board[0][2];
	}	
}
	
	if (winner != ' '){
		cout<<"player "<< winner<<" is the winner"<<endl;
	}
	else{
		cout<<"tie!!! "<<endl;
	}
	
	cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        cin >> playagain;
        if (playagain) {
            // Reset the game board and winner status for the new game
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    board[i][j] = ' ';
                }
            }
            winner = ' ';
            currentplayer = player1;
        }
    }
	cout << "Thank you for playing!" << endl;
    return 0;
}
