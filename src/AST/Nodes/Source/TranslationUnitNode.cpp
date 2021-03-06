/*
 * TranslationUnitNode.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */


#include "TranslationUnitNode.h"

TranslationUnitNode::TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration )
	: externalDeclaration( _externalDeclaration )
{
	nodeData = toOperations();
}

TranslationUnitNode::TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration, TranslationUnitNode* _translationUnit )
		: externalDeclaration( _externalDeclaration ) ,  translationUnit( _translationUnit )
{
	nodeData = toOperations();
}

ASTData* TranslationUnitNode::toOperations()
{

	ASTData* data = new ASTData();

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	ASTData* externalData = externalDeclaration->nodeData;

	operations->insert( operations->end(), externalData->code->begin() , externalData->code->end() );

	if( translationUnit )
	{

		ASTData* transData = translationUnit->toOperations();

		operations->insert( operations->end() , transData->code->begin() , transData->code->end() );

	}

	data->code = operations;

	return data;

}

std::string TranslationUnitNode::getNodeTypeAsString()
{

	return std::string( "translation unit" );

}

