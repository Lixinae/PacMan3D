#ifndef __BOARD_POSITION_H__
#define __BOARD_POSITION_H__

#include <iostream>
#include <json/json.hpp>

using namespace std;

using json = nlohmann::json;

class BoardPosition {

public:
	
	BoardPosition(int x, int y);
	
	static BoardPosition fromJSON(const json & jsonPosition);
	
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
