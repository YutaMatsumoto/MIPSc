/*
 * IdTracker.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef IDTRACKER_H_
#define IDTRACKER_H_

class IdTracker {

public:

	inline static unsigned int getId()
	{

		return counter++;

	}

private:

	static unsigned int counter;

	inline IdTracker()
	{

		counter = 0;

	};

	IdTracker(IdTracker const&);       // Don't Implement

	void operator=(IdTracker const&); // Don't implement

};

#endif /* IDTRACKER_H_ */
