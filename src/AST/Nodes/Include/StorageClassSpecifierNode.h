// #include "ASTNodes.h"
#ifndef STORAGECLASSSPECIFIERNODE_H_GUARD
#define STORAGECLASSSPECIFIERNODE_H_GUARD


class StorageClassSpecifierNode {
private:
	int specifier;

const char specs[5][10] = {
	"auto",
	"register",
	"static",
	"extern",
	"typedef"
};

public:

	enum StorageSpecifierKind {
		Auto = 0,  StorageSpecifierKindStart = 0,
		Register,
		Static,
		Extern,
		Typedef, StorageSpecifierKindEnd = Typedef,
	};

	StorageClassSpecifierNode(int storageSpecKind );

};
#endif
