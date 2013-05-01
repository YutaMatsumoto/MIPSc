/*
 * IdTracker.cpp
 *
 *  Created on: Apr 15, 2013
 *      Author: njordan
 */

#include "IdTracker.h"

IdTracker* IdTracker::instance = 0;

IdTracker* IdTracker::getInstance()
{

	if( !instance )
	{

		instance = new IdTracker();

	}

	return instance;

}

unsigned int IdTracker::getId()
{

	return counter++;

}

IdTracker::IdTracker()
{

	counter = 0;

};

