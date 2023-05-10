#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char board[9] = { '1','2','3','4','5','6','7','8','9' };
	char winner = '1';
	char player_xo='x';
	int win_options[8][3] = { 
		{0,1,2},
		{0,4,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{2,4,6},
		{3,4,5},
		{6,7,8} };
	
	bool not_win = true;
	int count_step = 0;
	while (not_win) {
		for (int i = 0; i < 3; i++)
		{
			cout << "\n|" << board[i * 3] << "|" << board[1 + i * 3] << "|" << board[2 + i * 3] << "|" << "\n";
			cout << "________\n";
		}
		if (count_step % 2 == 0) {
			player_xo = 'x';
		} else player_xo = '0';

		int player;

		cout << "Куда поставим " << player_xo << " ?\n";
		cin >> player;
		board[player - 1] = player_xo;
		count_step += 1;
		
		if (count_step >= 4) {
			for (int i = 0; i < 8; i++) 
			{
				if (board[win_options[i][0]] == board[win_options[i][1]])
					if(board[win_options[i][0]] == board[win_options[i][2]]) {
					winner = board[win_options[i][0]];
					//break;
				}
			}
		
			if (winner == 'x') {
				cout << winner << " одержал победу! ";
				not_win == false;
				break;
			}else if (winner == '0') {
				cout << winner << " одержал победу! ";
				not_win == false;
				break;
			}
			if (count_step == 9)
			{
				cout << "Ничья";
				not_win == false;
				break;
			}
		}
	}
}
