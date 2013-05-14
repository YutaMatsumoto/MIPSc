#ifndef REGISTER_H_GUARD
#define REGISTER_H_GUARD
#include <string>
#include "RegisterAllocationCommon.h"

class Register {
public:

	Register(RegisterNumber rNumber);

	RegisterNumber getRegisterNumber() const;

	virtual std::string toString() const;

protected:

	std::string prefix() const;

private:

	RegisterNumber rNumber;
};

// ---------------------------------------------------------------------------

class FloatRegister : public Register {
	virtual std::string toString() const;
};

// ---------------------------------------------------------------------------

/* If needed to do $t1 instead of plain $7
*/
class IntegerRegister : public Register {
};

// ---------------------------------------------------------------------------

#endif
