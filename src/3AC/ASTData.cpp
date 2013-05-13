/*
 * ASTData.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#include "ASTData.h"
#include "LoadOp.h"

ASTData::ASTData() {
	// TODO Auto-generated constructor stub

	code = new std::vector< Operation* >();

}

void ASTData::removeLoadOps( std::vector< Operation* >* ops )
{

	for( unsigned int i = 0 ; i < ops->size() ; i++ )
	{

		LoadOp* j = dynamic_cast< LoadOp* >( ops->at( i ) );

		if( j )

			ops->erase( ops->begin() + i );

	}

}

