#include "game.h"
#include <iostream>

Tictactoe::Tictactoe(bool _computerIsPlayerTwo, bool _playersOneMarkIsX)
{
	computerIsPlayerTwo = _computerIsPlayerTwo;

	if (_playersOneMarkIsX)
	{
		playersOneMark = 'X';
		computersMark = 'O';
	}
	else
	{
		playersOneMark = 'O';
		computersMark = 'X';
	}
}

bool Tictactoe::mark(bool _playersOneMove, int _move)
{
	if (board[_move] == 'X' || board[_move] == 'O')
		return false;

	if (_playersOneMove)
		if (playersOneMark == 'X')	board[_move] = 'X'; else board[_move] = 'O';

	if (!_playersOneMove)
		if (playersOneMark == 'X')	board[_move] = 'O'; else board[_move] = 'X';

	moveNo++;
		
	return true;
}
int Tictactoe::result(void) 
{
	int x = 1;
	int o = 2;
	
	if (playersOneMark == 'O')
	{
		x = 2;
		o = 1;
	}

	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return x;
	if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return x;
	if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return x;
	if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') return x;
	if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return x;
	if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return x;
	if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return x;
	if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return x;

	if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') return o;
	if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') return o;
	if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') return o;
	if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') return o;
	if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return o;
	if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') return o;
	if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') return o;
	if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') return o;

	for (int i = 0; i < 9; ++i)
		if (board[i] == '-')
			return 0;

	return 3;
}
char Tictactoe::at(int _position)
{
	return board[_position];
}
bool Tictactoe::isLineCompletionPossible(char _mark, int& _move)
{
	if (board[0] == _mark)
	{
		if (board[1] == _mark && board[2] == '-') { _move = 2; return true; }
		if (board[1] == '-' && board[2] == _mark) { _move = 1; return true; }
		if (board[3] == _mark && board[6] == '-') { _move = 6; return true; }
		if (board[3] == '-' && board[6] == _mark) { _move = 3; return true; }
		if (board[4] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[4] == '-' && board[8] == _mark) { _move = 4; return true; }
	}

	if (board[1] == _mark)
	{
		if (board[4] == _mark && board[7] == '-') { _move = 7; return true; }
		if (board[4] == '-' && board[7] == _mark) { _move = 4; return true; }
		if (board[0] == _mark && board[2] == '-') { _move = 2; return true; }
		if (board[0] == '-' && board[2] == _mark) { _move = 0; return true; }
	}

	if (board[2] == _mark)
	{
		if (board[4] == _mark && board[6] == '-') { _move = 6; return true; }
		if (board[4] == '-' && board[6] == _mark) { _move = 4; return true; }
		if (board[5] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[5] == '-' && board[8] == _mark) { _move = 5; return true; }
	}

	if (board[3] == _mark)
	{
		if (board[0] == _mark && board[6] == '-') { _move = 6; return true; }
		if (board[0] == '-' && board[6] == _mark) { _move = 0; return true; }
		if (board[4] == _mark && board[5] == '-') { _move = 5; return true; }
		if (board[4] == '-' && board[5] == _mark) { _move = 4; return true; }
	}

	if (board[4] == _mark)
	{
		if (board[0] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[0] == '-' && board[8] == _mark) { _move = 0; return true; }
		if (board[2] == _mark && board[6] == '-') { _move = 6; return true; }
		if (board[2] == '-' && board[6] == _mark) { _move = 2; return true; }
		if (board[1] == _mark && board[7] == '-') { _move = 7; return true; }
		if (board[1] == '-' && board[7] == _mark) { _move = 1; return true; }
		if (board[3] == _mark && board[5] == '-') { _move = 5; return true; }
		if (board[3] == '-' && board[5] == _mark) { _move = 3; return true; }
	}

	if (board[5] == _mark)
	{
		if (board[2] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[2] == '-' && board[8] == _mark) { _move = 2; return true; }
	}

	if (board[6] == _mark)
	{
		if (board[7] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[7] == '-' && board[8] == _mark) { _move = 7; return true; }
	}

	if (board[7] == _mark)
	{
		if (board[6] == _mark && board[8] == '-') { _move = 8; return true; }
		if (board[6] == '-' && board[8] == _mark) { _move = 6; return true; }
	}

	return false;
}
int Tictactoe::computerMove(char computersMark)

{
	char opponentsMark = 'X';
	if (computersMark == 'X')	opponentsMark = 'O';

	srand(time_t(NULL));

	int move = 10;
	if (!this->isLineCompletionPossible(computersMark, move))
	{
		if (this->isLineCompletionPossible(opponentsMark, move))
		{
			if (moveNo == 0)
			{
				move = 2 * (1 + rand() % 2);
			}

			if (moveNo == 1)
			{
				if (board[4] == opponentsMark)	move = 6;

				if (board[0] == opponentsMark)	move = 4;
				if (board[2] == opponentsMark)	move = 4;
				if (board[6] == opponentsMark)	move = 4;
				if (board[8] == opponentsMark)	move = 4;

				if (board[1] == opponentsMark)	move = 4;
				if (board[3] == opponentsMark)	move = 4;
				if (board[5] == opponentsMark)	move = 4;
				if (board[7] == opponentsMark)	move = 4;
			}

			if (moveNo == 2)
			{
				if (board[4] == computersMark)
				{
					if (board[1] == opponentsMark || board[3] == opponentsMark)	move = 8;
					if (board[5] == opponentsMark || board[7] == opponentsMark)	move = 0;
					if (board[0] == opponentsMark)	move = 8;
					if (board[2] == opponentsMark)	move = 6;
					if (board[6] == opponentsMark)	move = 2;
					if (board[8] == opponentsMark)	move = 0;
				}

				if (board[2] == computersMark)
				{
					if (board[4] == opponentsMark)	move = 6;
					else if (board[1] == opponentsMark)	move = 4;
					else if (board[5] == opponentsMark)	move = 4;
					else if (board[8] == opponentsMark)	move = 0;
					else
						move = 8;
				}
			}

			if (moveNo == 3)
			{
				if (board[6] == computersMark) move = 2;

				if (board[4] == computersMark)
				{
					if (board[0] == opponentsMark)
					{
						if (board[5] == opponentsMark)	move = 2;
						if (board[8] == opponentsMark)	move = 1;
						if (board[7] == opponentsMark)	move = 6;
					}

					if (board[1] == opponentsMark)
					{
						if (board[3] == opponentsMark)	move = 0;
						if (board[5] == opponentsMark)	move = 2;
						if (board[7] == opponentsMark)	move = 0;
						if (board[8] == opponentsMark)	move = 2;
						if (board[6] == opponentsMark)	move = 0;
					}

					if (board[2] == opponentsMark)
					{
						if (board[3] == opponentsMark)	move = 0;
						if (board[7] == opponentsMark)	move = 8;
						if (board[6] == opponentsMark)	move = 1;
					}

					if (board[3] == opponentsMark)
					{
						if (board[8] == opponentsMark)	move = 6;
						if (board[7] == opponentsMark)	move = 6;
						if (board[5] == opponentsMark)	move = 2;
					}

					if (board[5] == opponentsMark)
					{
						if (board[6] == opponentsMark)	move = 8;
						if (board[7] == opponentsMark)	move = 8;
					}
				}
			}

			if (moveNo == 4)
						
			{
				if (board[2] == computersMark && board[8] == computersMark)
				{
					if (board[4] == '-' && board[6] == '-' && board[7] == '-')	move = 6;
					if (board[4] == '-' && board[0] == '-' && board[1] == '-')	move = 0;
				}

				if (board[4] == computersMark && board[8] == computersMark)
				{
					if (board[2] == '-' && board[5] == '-' && board[6] == '-')	move = 2;
					if (board[2] == '-' && board[6] == '-' && board[7] == '-')	move = 6;
				}

				if (board[0] == computersMark && board[4] == computersMark)
				{
					if (board[1] == '-' && board[2] == '-' && board[6] == '-')	move = 6;
					if (board[2] == '-' && board[3] == '-' && board[6] == '-')	move = 2;
				}

				if (board[2] == computersMark && board[4] == computersMark)
				{
					if (board[0] == '-' && board[1] == '-' && board[8] == '-')	move = 0;
					if (board[0] == '-' && board[5] == '-' && board[8] == '-')	move = 8;
				}

				if (board[4] == computersMark && board[6] == computersMark)
				{
					if (board[0] == '-' && board[3] == '-' && board[8] == '-')	move = 0;
					if (board[0] == '-' && board[7] == '-' && board[8] == '-')	move = 8;
				}
			}
		}
	}

	if (move == 10)
	{
		do { move = rand() % 9; } while (board[move] != '-');
	}

	this->mark(false, move);
	return move;
	
}

Tictactoe::~Tictactoe() 
{
}