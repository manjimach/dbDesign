#include "db.h"
#include "replacemt.h"
#include "clock.h"

//--------------------------------------------------------------------
/* Constructor for Clock
	Input: None
	Output: None
*/
//--------------------------------------------------------------------
Clock::Clock() 
{
	this->clockVector; 
}

//--------------------------------------------------------------------
/* Destructor for Clock
	Input: None
	Output: None
*/
//--------------------------------------------------------------------
Clock::~Clock() 
{
	this->clockVector.clear();
}

//--------------------------------------------------------------------
/* Returns true if Clock is empty
	Input: None
	Output: None
*/
//--------------------------------------------------------------------
bool Clock::isEmpty() 
{
	return this->clockVector.empty();
}

//--------------------------------------------------------------------
/* Returns true if frame exists inside the Clock
	false otherwise
	Input: frame
	Output: bool
*/
//--------------------------------------------------------------------
bool Clock::exists(int fr)
{
	return std::find(this->clockVector.begin(), this->clockVector.end(), fr) != this->clockVector.end();
}

//--------------------------------------------------------------------
/* Selects a frame to have contents replaced 
	Returns -1 if Clock is empty
	Input: None
	Output: int (frameNumber)
*/
//--------------------------------------------------------------------
int Clock::SelectVictim()
{
	if(this->isEmpty()) {
		return -1;
	}

	// remove from vector where refbit is 0
	for (i = clockVector.begin(); i < clockVector.end(); i++){
		if((this->refbit.at(*i))== 0){
			int frameNum = this->clockVector.at(*i);
			return frameNum;
		}
		else if((this->refbit.at(*i))== 1){
			this->refbit.at(*i) = 0;
		}
	}
	
}

//--------------------------------------------------------------------
/* Add a frame to the Clock
	Input: Frame number to add
	Output: None
*/
//--------------------------------------------------------------------
void Clock::AddFrame(int fr)
{
	// add frame to the vector
	this->clockVector.push_back(fr);
	// set refbit = 1
	this->refbit.push_back(1);
}

//--------------------------------------------------------------------
/* Removes the first frame whose value is equal to fr from Clock
	Does nothing if frame not found
	Input: Frame number to remove
	Output: None
*/
//--------------------------------------------------------------------
void Clock::DeleteFrame(int fr)
{
	std::vector<int >::iterator pos = std::find(this->clockVector.begin(), this->clockVector.end(), fr);

	if(pos != this->clockVector.end()) {
		this->clockVector.erase(pos);
	}

}