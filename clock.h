#ifndef _CLOCK_H
#define _CLOCK_H

#include "db.h"

#include "replacemt.h"
#include "frame.h"

#include <vector>
#include <algorithm>


// Clock Buffer Replacement
class Clock : public Replacemt {
private:

	std::vector<int > clockVector;
	
	std::vector<int> refbit;
	
	//int i;
	std::vector<int>::iterator i;
	
	bool isEmpty();
	bool exists(int fr);

public:
	Clock();
	virtual ~Clock();

	virtual int SelectVictim();
	virtual void AddFrame(int fr);
	virtual void DeleteFrame(int fr);
};

#endif // Clock