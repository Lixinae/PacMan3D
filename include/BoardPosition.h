#ifndef __BOARD_POSITION_H__
#define __BOARD_POSITION_H__

#include <iostream>

using namespace std;

class BoardPosition {

public:
	
	BoardPosition(int x, int y);
	
	int getX() const;
	int getY() const;
	
	bool operator==(const BoardPosition & other) const;
	bool operator!=(const BoardPosition & other) const;
	bool operator<(const BoardPosition & other) const;
	bool operator>(const BoardPosition & other) const;
	bool operator<=(const BoardPosition & other) const;
	bool operator>=(const BoardPosition & other) const;
	
	friend ostream & operator<<(ostream & os, BoardPosition position);
	
private:
	
	int _x;
	int _y;

};

#endif
