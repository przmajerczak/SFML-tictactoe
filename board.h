#ifndef _BOARD_H
#define	_BOARD_H

void boardDisplay(char* board);

bool boardMark(char* board, char mark, int position);

bool boardIsWon(char* board, int& winner);

#endif
