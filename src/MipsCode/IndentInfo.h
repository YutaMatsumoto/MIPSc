
class IndentInfo {
	size_t textIndex;
	enum IndentDirection { Increment, Decrement, None };
	IndentInfo(size_t, IndentDirection);
	int getIndent();
};

std::vector<IndentInfo> iis;

