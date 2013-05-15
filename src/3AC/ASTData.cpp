/*
 * ASTData.cpp
 *
 *  Created on: Apr 16, 2013
 *      Author: njordan
 */

#include "ASTData.h"
#include "LoadOp.h"
#include "GetAddressOp.h"

ASTData::ASTData() {
	// TODO Auto-generated constructor stub

	code = new std::vector< Operation* >();

}

void ASTData::removeLoadOps( ASTData* data )
{

	GetAddressOp* addr;

	std::vector< Operation* >* ops = data->code;

	for( unsigned int i = 0 ; i < ops->size() ; i++ )
	{

		LoadOp* j = dynamic_cast< LoadOp* >( ops->at( i ) );

		GetAddressOp* k = dynamic_cast< GetAddressOp* >( ops->at( i ) );

		if( k )

			addr = k;

		if( j )
		{

			j->op1->operandType = addr->op1->operandType;

			addr->op1 = j->op1;

			data->result = addr->op1;

			ops->erase( ops->begin() + i );

		}
	}

}

