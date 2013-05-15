#include "Symbol.h"
#include "MipsCode.h"
#include "BuiltinType.h"
#include "SymbolLocation.h"
#include "MipsCode.h"
#include "DescriptorTable.h"


#include "AddOp.h"
#include "AssignOp.h"
#include "/tmp/mips-tmp/src/3AC/Operations/BranchEqualOp.h"
#include "BranchZeroOp.h"
// #include "CallOp.h"
#include "ConditionalStoreOp.h"
#include "GetAddressOp.h"
#include "LoadOp.h"
// #include "MipsConversionError.h"
#include "MultOp.h"
// #include "RestoreStackOp.h"
// #include "ReturnOp.h"
// #include "ShiftOp.h"
#include "StoreOp.h"
#include "UnconditionalJumpOp.h"

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

void brancheq_op()
{

	Symbol* s1= new Symbol( std::string( "t1" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* s2= new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);

	std::string labelstring = "A";
	unsigned int id = 1;
	Label* label = new Label(labelstring, id);

	BranchEqualOp beop( label, s1, s2 );

	beop.produceMips();

	MipsCode::getInstance().dump();

	MipsCode::getInstance().clear();

}

// class BranchZeroOp;

// void branchzero_op()
// {
// 	Symbol* s1= new Symbol( std::string( "t1" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
// 	std::string labelstring = "A";
// 	unsigned int id = 1;
// 	Label* label = new Label(labelstring, id);

// 	BranchZeroOp beop( label, s1 );

// 	beop.produceMips();

// 	MipsCode::getInstance().dump();

// 	MipsCode::getInstance().clear();
// }


void conditional_store_op()
{


	Symbol* s1= new Symbol( std::string( "t1" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* s2= new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* s3= new Symbol( std::string( "t3" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);

	// inline ConditionalStoreOp( Operand* destination , Operand* first ,
	// Operand* second , RelationalExpressionNode::RelationalExpressionType
	// _type )

	ConditionalStoreOp cstore1(s1, s2, s3, RelationalExpressionNode::Less    ) ;
	ConditionalStoreOp cstore2(s1, s2, s3, RelationalExpressionNode::Greater);
	ConditionalStoreOp cstore3(s1, s2, s3, RelationalExpressionNode::LessEqual );
	ConditionalStoreOp cstore4(s1, s2, s3, RelationalExpressionNode::GreaterEqual);

	cstore1.produceMips();
	cstore2.produceMips();
	cstore3.produceMips();
	cstore4.produceMips();

	MipsCode::getInstance().dump();

	MipsCode::getInstance().clear();
}

void get_addres_op()
{

	Symbol* s1= new Symbol( std::string( "t1" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* s2= new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);

	GetAddressOp gaop(s1,s2);
	
	gaop.produceMips();	

	MipsCode::getInstance().dump();

	MipsCode::getInstance().clear();
}

void mult_op() 
{
	Symbol* o1 = new Symbol( std::string( "t1000" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o2 = new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o3 = new Symbol( std::string( "t3" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );
	Symbol* o4 = new Symbol( std::string( "t4" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o5 = new Symbol( std::string( "t5" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);
	Symbol* o6 = new Symbol( std::string( "t6" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP );

	DescriptorTable::getInstance().setDebug();

	MultOp addOp(o3, o2, o1, MultiplicativeExpressionNode::Multiply);
	MultOp addOp2(o6, o5, o4, MultiplicativeExpressionNode::Divide);

	addOp.produceMips();
	addOp2.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

void load_op()
{
	Symbol* o1 = new Symbol( std::string( "t1000" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o2 = new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);

	LoadOp lop(o1,o2);

	lop.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

void store_op()
{
	Symbol* o1 = new Symbol( std::string( "t1000" ) , *new SymbolLocation() , new Type( Type::Int) , Symbol::ITEMP);
	Symbol* o2 = new Symbol( std::string( "t2" ) , *new SymbolLocation() , new Type( Type::Int ) , Symbol::ITEMP);

	StoreOp sop(o1,o2);

	sop.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

void unconditional_jump_op()
{
	std::string labelstring = "A";
	unsigned int id = 1;
	Label* label = new Label(labelstring, id);

	UnconditionalJumpOp jop(label);	

	jop.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

void label_op()
{
	Label label("IM_A_LABEL", 1);

	label.produceMips();

	MipsCode::getInstance().dump();
	MipsCode::getInstance().clear();
}

int main()
{

	// addop();
	// assignop();
	// brancheq_op();	
	// branchzero_op();

	// conditional_store_op();
	// get_addres_op();
	// mult_op();
	// load_op();
	// store_op();
	// unconditional_jump_op();
	label_op();
	
}
