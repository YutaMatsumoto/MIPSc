#ifndef TypeQualifierNode_H_GUARD
#define TypeQualifierNode_H_GUARD

class TypeQualifierNode {
public:

	enum TypeQual { Const, Volatile };
	
	TypeQualifierNode(int tqual )
		: tqual(tqual)
	{}

	int /*TypeQual*/ tqual;
};


#endif // END TypeQualifierNode_H_GUARD

