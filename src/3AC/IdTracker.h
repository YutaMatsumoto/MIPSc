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

	static IdTracker* getInstance();

	unsigned int getId();

private:

	static IdTracker* instance;

	unsigned int counter;

	IdTracker();

	IdTracker(IdTracker const&);       // Don't Implement

	void operator=(IdTracker const&); // Don't implement

};

#endif /* IDTRACKER_H_ */
