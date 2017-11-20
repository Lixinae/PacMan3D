#ifndef __BONUS_H__
#define __BONUS_H__

class Bonus {

public:

	virtual void apply(Pacman pacman) = 0;
	
	virtual ~Bonus() {
		
	};

};

#endif
