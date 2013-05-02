#ifndef TypeQualifierNode_H_GUARD
#define TypeQualifierNode_H_GUARD

class TypeQualInfo {
	private:
	bool constness;
	bool volatileness;

	public:
	TypeQualInfo() : constness(false), volatileness(false)  {}
	bool setConstness() { constness = true; return (constness) ? false : true ;   } 
	bool setVolatileness() { volatileness = true; return (volatileness) ? false : true ;   } 
	bool isConst() { return constness; } 
	bool isVolatile() { return volatileness; } 
};

class TypeQualifierNode {
public:

	enum TypeQual { Const, Volatile };
	
	TypeQualifierNode(int tqual )
		: tqual(tqual)
	{}

	int getTypeQualitiferValue()
	{
		return tqual;
	}

	int /*TypeQual*/ tqual;
};


#endif // END TypeQualifierNode_H_GUARD

