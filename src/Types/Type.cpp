/*
 * Type.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: njordan
 */

#include "Symbol.h"
#include "Type.h"
#include "ArrayType.h"
#include "PointerType.h"
#include "TypedefType.h"
#include "FunctionType.h"
#include "BuiltinType.h"

#include "TypeInfo.h"

// Type::Type( std::string id , int lineNumber , int columnNumber ) {
	// this->id = id;
	// this->lineNumber = lineNumber;
	// this->columnNumber = columnNumber;
// }

std::string Type::getTypeAsString()
{
	return "Naked Type";
}
std::string Type::toString()
{
	return getTypeAsString();
}

/*
std::string Type::getTypeAsString()
{
	switch( getType() )
	{

		case uChar:
		{
			return "unsigned char";

			break;
		}
		case uShort:
		{
			return "unsigned short";

			break;
		}
		case uInt:
		{
			return "unsigned int";

			break;
		}
		case uLong:
		{
			return "unsigned long";

			break;
		}
		case uLongLong:
		{
			return "unsigned long long";

			break;
		}
		case Char:
		{
			return "char";

			break;
		}
		case Short:
		{
			return "short";

			break;
		}
		case Int:
		{
			return "int";

			break;
		}
		case Long:
		{
			return "long";

			break;
		}
		case LongLong:
		{
			return "long long";

			break;
		}
		case Float:
		{
			return "float";

			break;
		}
		case Double:
		{
			return "double";

			break;
		}
		case Enum:
		{
			return "enum";

			break;
		}
		case Union:
		{
			return "union";

			break;
		}
		case Struct:
		{
			return "struct";

			break;
		}
		case Pointer:
		{
			return ( (PointerType*) this )->symbol->symbolType->getTypeAsString() + "*";

			break;
		}
		case Typedef:
		{
			return ( (TypedefType*) this )->redefinedType->id;

			break;
		}
		case Array:
		{
			std::string s;

			s = "";

			ArrayType* a = (ArrayType*) this;

			std::cout << "before" << std::endl;
			return a->toString();
			std::cout << "after" << std::endl;

			// s += ( (ArrayType*) this )->getElementType()->getTypeAsString();
			// for( unsigned int i = 0 ; i < ( (ArrayType*) this )->dimension && ( (ArrayType*) this )->dimension > 1 ; i++ )
			// 	s += std::string( "[" + ( (ArrayType*) this )->offsets.at(i) ) + "]";

			return s;

			break;
		}
		case Function:
		{
			std::string functionType = "";

			functionType += ( (FunctionType*) this )->returnType->getTypeAsString();

			functionType += " (";

			for( Type* i : ( (FunctionType*) this )->operands )
			{

				functionType += i->getTypeAsString() + ",";

			}

			functionType += ")";

			return functionType;

			break;
		}
		case Void:
		{
			return "void";

			break;
		}
		default:
		{
			return "ERROR";

			break;
		}

	}

	return "";

}
*/

/*
std::string Type::toString()
{
	return	getTypeAsString();
}
*/

std::string Type::getId()
{

	return id;

}


Type::Type(TypeEnum type) : type(type)
{
}

Type::~Type() 
{
	// TODO Auto-generated destructor stub
}

int Type::getType() 
{
	return type;
}
