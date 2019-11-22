#include <iostream>
using namespace std;

void boardDisplay(char* board)
{
	for (int x = 0; x < 9; ++x)
	{
		cout << *(board + x);
		if (x % 3 == 2)
			cout << endl;
	}
}

bool boardMark(char* board, char mark, int position)
{
	// zwraca false, jeśli dana pozycja jest zajęta
	// jeśli nie jest zajęta, wstawia tam podany symbol i zwraca true
	if (board[position] == 'X' || board[position] == 'O')
		return false;
	board[position] = mark;
	return true;
}

bool boardIsWon(char* board, int& winner)
{
	//10 - wygrana X, 20 - wygrana O

	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') { winner = 10; return true; }
	if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') { winner = 10; return true; }
	if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') { winner = 10; return true; }
	if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') { winner = 10; return true; }
	if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') { winner = 10; return true; }
	if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') { winner = 10; return true; }
	if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') { winner = 10; return true; }
	if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') { winner = 10; return true; }

	if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') { winner = 20; return true; }
	if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') { winner = 20; return true; }
	if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') { winner = 20; return true; }
	if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') { winner = 20; return true; }
	if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') { winner = 20; return true; }
	if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') { winner = 20; return true; }
	if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') { winner = 20; return true; }
	if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') { winner = 20; return true; }

	return false;
}