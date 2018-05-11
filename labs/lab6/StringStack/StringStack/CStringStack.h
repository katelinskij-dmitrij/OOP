#pragma once
#include "stdafx.h"

class CStringStack
{
public:
	CStringStack() = default;
	CStringStack(CStringStack const &stack);
	CStringStack(CStringStack && stack);
	~CStringStack();
	void Push(string const & element);
	void Pop();
	void Clear();
	string GetLastElement() const;
	size_t GetSize() const;
	bool IsEmpty() const;
	CStringStack & operator=(CStringStack const & stack);
	CStringStack & operator=(CStringStack && stack);
	bool operator==(CStringStack const & stack) const;
	bool operator!=(CStringStack const & stack) const;
private:
	struct Node
	{
		string value;
		shared_ptr<Node> next = nullptr;
	};
	shared_ptr<Node> m_top = nullptr;
	size_t m_size = 0;
};