#include "db.h"
#include "replacemt.h"
#include "mru.h"

MRU::MRU() 
{
	this->mruVector; 
}

//--------------------------------------------------------------------
/* Destructor for MRU
	Input: None
	Output: None
*/
//--------------------------------------------------------------------
MRU::~MRU() 
{
	this->mruVector.clear();
}

//--------------------------------------------------------------------
/* Checks if the MRU is empty or not
	Input: None
	Output: None
*/
//--------------------------------------------------------------------
bool MRU::isEmpty() 
{
	return this->mruVector.empty();
}

//--------------------------------------------------------------------
/* Checks if frame exists inside the MRU or not
	false otherwise
	Input: frame
	Output: bool
*/
//--------------------------------------------------------------------
bool MRU::exists(int fr)
{
	return std::find(this->mruVector.begin(), this->mruVector.end(), fr) != this->mruVector.end();
}

//--------------------------------------------------------------------
/* Selects a frame to have contents replaced 
	Returns -1 if MRU is empty
	Input: None
	Output: int (frame no.)
*/
//--------------------------------------------------------------------
int MRU::SelectVictim()
{
	if(this->isEmpty()) {
		return -1;
	}

	// remove tail of vector
	int frameNum = this->mruVector.at(this->mruVector.size()-1);
	this->mruVector.pop_back();
	return frameNum;

}

//--------------------------------------------------------------------
/* Adds a frame to the MRU
	Input: Frame number to add
	Output: None
*/
//--------------------------------------------------------------------
void MRU::AddFrame(int fr)
{
	// add frame to end of vector
	this->mruVector.push_back(fr);
}

//--------------------------------------------------------------------
/* Removes the first frame whose value is equal to fr from MRU
	Does nothing if frame not found
	Input: Frame number to remove
	Output: None
*/
//--------------------------------------------------------------------
void MRU::DeleteFrame(int fr)
{
	std::vector<int >::iterator pos = std::find(this->mruVector.begin(), this->mruVector.end(), fr);

		if(pos != this->mruVector.end()) {
		this->mruVector.erase(pos);
	}

}