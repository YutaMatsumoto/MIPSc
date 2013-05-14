#include "Symbol.h"
#include "MipsCode.h"
#include "BuiltinType.h"
#include "SymbolLocation.h"
#include "MipsCode.h"
#include "DescriptorTable.h"

#include "AddOp.h"
#include "AssignOp.h"

void addop()
{
	Symbol* o1 = new Symbol( std::string( "t1000" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o2 = new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o3 = new Symbol( std::string( "t3" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );
	Symbol* o4 = new Symbol( std::string( "t4" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o5 = new Symbol( std::string( "t5" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o6 = new Symbol( std::string( "t6" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );
	Symbol* o7 = new Symbol( std::string( "t7" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o8 = new Symbol( std::string( "t8" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o9 = new Symbol( std::string( "t9" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );
	Symbol* o10= new Symbol( std::string( "t10" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o11= new Symbol( std::string( "t11" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o12= new Symbol( std::string( "t12" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );

	DescriptorTable::getInstance().setDebug();

	AddOp addOp(o3, o2, o1, AdditiveExpressionNode::Subtract );
	AddOp addOp2(o6, o5, o4, AdditiveExpressionNode::Add );
	AddOp addOp3(o9, o8, o7, AdditiveExpressionNode::Subtract );
	AddOp addOp4(o12, o11, o10, AdditiveExpressionNode::Add );

	addOp.produceMips();
	addOp2.produceMips();
	addOp3.produceMips();
	addOp4.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

// Load Immediate
void assignop()
{
	// Symbol* dest =

	Symbol* dst = new Symbol( std::string( "t1" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* src = new Symbol( std::string( "2" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);

	AssignOp aop(dst, src, AssignmentOperatorNode::Assign);

	aop.produceMips();

	MipsCode::getInstance().dump();

	MipsCode::getInstance().clear();
}

int main()
{
	addop();
	assignop();
}


