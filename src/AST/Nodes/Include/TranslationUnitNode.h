/*
 * TranslationUnitNode.h
 *
 *  Created on: Apr 13, 2013
 *      Author: njordan
 */

#ifndef TRANSLATIONUNITNODE_H_
#define TRANSLATIONUNITNODE_H_

#include "Node.h"
#include "Operation.h"
#include <vector>
#include <string>

#include "ExternalDeclarationNode.h"

class TranslationUnitNode : public Node
{

public:

	TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration );
	TranslationUnitNode( ExternalDeclarationNode* _externalDeclaration, TranslationUnitNode* _translationUnit );
	std::vector< Operation* >* toOperations();
	std::string getNodeTypeAsString();

	TranslationUnitNode* translationUnit;

	ExternalDeclarationNode* externalDeclaration;


};


#endif /* TRANSLATIONUNITNODE_H_ */
