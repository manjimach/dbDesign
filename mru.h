#ifndef _MRU_H
#define _MRU_H

#include "db.h"

#include "replacemt.h"
#include <vector>
#include <algorithm>

// MRU Buffer Replacement
class MRU : public Replacemt {
private:

	std::vector<int > mruVector;

	bool isEmpty();
	bool exists(int fr);

public:
	MRU();
	virtual ~MRU();

	virtual int SelectVictim();
	virtual void AddFrame(int fr);
	virtual void DeleteFrame(int fr);
};

#endif // MRU