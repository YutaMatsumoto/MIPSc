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

}

TranslationUnitNode::TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration, TranslationUnitNode* _translationUnit )
		: externalDeclaration( _externalDeclaration ) ,  translationUnit( _translationUnit )
{

}

std::vector< Operation* >* TranslationUnitNode::toOperations()
{

	std::vector< Operation* >* operations = new std::vector< Operation* >();

	if( externalDeclaration )
	{

		std::vector< Operation* >* temp;

		temp = externalDeclaration->toOperations();

		operations->insert( operations->end(), temp->begin() , temp->end() );

	}

	std::vector< Operation* >* temp = translationUnit->toOperations();

	operations->insert( operations->end() , temp->begin() , temp->end() );

	return operations;

}

std::string TranslationUnitNode::getNodeTypeAsString()
{

	return std::string( "translation unit" );

}

