#ifndef _GAME_H
#define _GAME_H

class Tictactoe
{
public:
	Tictactoe(bool _computerIsPlayerTwo, bool _playersOneMarkIsX);

	bool mark(bool _playersOneMove, int _move);
	int result(void);
	char at(int _position);
	bool isLineCompletionPossible(char _mark, int& _move);
	int computerMove(char computersMark);

	~Tictactoe();
private:
	char board[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	bool computerIsPlayerTwo;
	char playersOneMark;
	char computersMark;
	int winner = 0;
	int moveNo = 0;


};
#endif