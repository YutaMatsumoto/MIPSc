/*
 * SymbolNotFoundException.h
 *
 *  Created on: May 1, 2013
 *      Author: njordan
 */

#ifndef SYMBOLNOTFOUNDEXCEPTION_H_
#define SYMBOLNOTFOUNDEXCEPTION_H_

class SymbolNotFoundException {

public:

	std::string mesg;

	SymbolNotFoundException( std::string _mesg ) : mesg(_mesg) {}

};

#endif /* SYMBOLNOTFOUNDEXCEPTION_H_ */
