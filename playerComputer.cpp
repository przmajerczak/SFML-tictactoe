#include <iostream>

#include "board.h"

using namespace std;

bool playerComputerCompleteLine(char* board, char mark, int& move)
{
	//funkcja sprawdza, czy jest (true, false) możliwość "dobicia" przeciwnika
	//jeśli tak, move to numer miejsca, w które należy wsadzić znak aby wygrać
	//jeśli nie, move zostaje niezmienione
	
	if (board[0] == mark)
	{
		if (board[1] == mark && board[2] == '-') { move = 2; return true; }
		if (board[1] == '-' && board[2] == mark) { move = 1; return true; }
		if (board[3] == mark && board[6] == '-') { move = 6; return true; }
		if (board[3] == '-' && board[6] == mark) { move = 3; return true; }
		if (board[4] == mark && board[8] == '-') { move = 8; return true; }
		if (board[4] == '-' && board[8] == mark) { move = 4; return true; }
	}

	if (board[1] == mark)
	{
		if (board[4] == mark && board[7] == '-') { move = 7; return true; }
		if (board[4] == '-' && board[7] == mark) { move = 4; return true; }
		if (board[0] == mark && board[2] == '-') { move = 2; return true; }
		if (board[0] == '-' && board[2] == mark) { move = 0; return true; }
	}

	if (board[2] == mark)
	{
		if (board[4] == mark && board[6] == '-') { move = 6; return true; }
		if (board[4] == '-' && board[6] == mark) { move = 4; return true; }
		if (board[5] == mark && board[8] == '-') { move = 8; return true; }
		if (board[5] == '-' && board[8] == mark) { move = 5; return true; }
	}

	if (board[3] == mark)
	{
		if (board[0] == mark && board[6] == '-') { move = 6; return true; }
		if (board[0] == '-' && board[6] == mark) { move = 0; return true; }
		if (board[4] == mark && board[5] == '-') { move = 5; return true; }
		if (board[4] == '-' && board[5] == mark) { move = 4; return true; }
	}

	if (board[4] == mark)
	{
		if (board[0] == mark && board[8] == '-') { move = 8; return true; }
		if (board[0] == '-' && board[8] == mark) { move = 0; return true; }
		if (board[2] == mark && board[6] == '-') { move = 6; return true; }
		if (board[2] == '-' && board[6] == mark) { move = 2; return true; }
		if (board[1] == mark && board[7] == '-') { move = 7; return true; }
		if (board[1] == '-' && board[7] == mark) { move = 1; return true; }
		if (board[3] == mark && board[5] == '-') { move = 5; return true; }
		if (board[3] == '-' && board[5] == mark) { move = 3; return true; }
	}

	if (board[5] == mark)
	{
		if (board[2] == mark && board[8] == '-') { move = 8; return true; }
		if (board[2] == '-' && board[8] == mark) { move = 2; return true; }
	}

	if (board[6] == mark)
	{
		if (board[7] == mark && board[8] == '-') { move = 8; return true; }
		if (board[7] == '-' && board[8] == mark) { move = 7; return true; }
	}

	if (board[7] == mark)
	{
		if (board[6] == mark && board[8] == '-') { move = 8; return true; }
		if (board[6] == '-' && board[8] == mark) { move = 6; return true; }
	}
	
	return false;
}

void playerComputerMove(char* board, char computersMark, int moveNo)

{
	char opponentsMark = 'X';
	if (computersMark == 'X')	opponentsMark = 'O';

	srand(time_t(NULL));

	int move = 10;
	if (!playerComputerCompleteLine(board, computersMark, move))
	{
		if (!playerComputerCompleteLine(board, opponentsMark, move))
		{
			if (moveNo == 0)
			{
				move = 2 * (1 + rand() % 2); //2 lub 4 - prawy górny róg lub środek
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

			if (moveNo == 3)	//to tym przypadku uzupelnianie i losowosc zawsze sobie poradzi
			{
				if (board[6] == computersMark) move = 2;

				if (board[4] == computersMark)	//tutaj rozpisałem wszystkie mozliwe opcje uwzględniając, co ma możliwość być na planszy w takim momencie
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

			if (moveNo == 4) //to jest moment na pułapki. jeśli algorytm uzupełniający trójki niczego tu nie znajdzie
								//to oznacza, że trzeba pułapkę zastawić, bo i tak wróg nie zdąży już nas uprzedzić
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
		//awaryjne biedalosowanie
		/*for (int i = 0; i < 9; ++i)
			if (board[i] == '-')
			{
				move = i;
				break;
			}*/
		do { move = rand() % 9; } while (board[move] != '-');
	}

	boardMark(board, computersMark, move);
}
