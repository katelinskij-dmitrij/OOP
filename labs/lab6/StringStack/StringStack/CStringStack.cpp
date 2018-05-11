﻿#include "stdafx.h"
#include "CStringStack.h"

CStringStack::CStringStack(CStringStack const &stack)
{
	*this = stack;
}

CStringStack::CStringStack(CStringStack &&stack)
{
	*this = move(stack);
}

CStringStack::~CStringStack()
{
	Clear();
}

void CStringStack::Push(string const &element)
{
	auto newNode = make_shared<Node>();
	newNode->value = element;
	newNode->next = m_top;
	m_top = newNode;
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw underflow_error("Can't pop element from empty stack.");
	}
	m_top = m_top->next;
	--m_size;
}

void CStringStack::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

string CStringStack::GetLastElement()const
{
	if (IsEmpty())
	{
		throw underflow_error("Can't get last element from empty stack.");
	}
	return(m_top->value);
}

size_t CStringStack::GetSize()const
{
	return(m_size);
}

bool CStringStack::IsEmpty()const
{
	return(m_size == 0);
}

CStringStack& CStringStack::operator =(CStringStack const &stack)
{
	if (this == &stack)
	{
		throw invalid_argument("Can't copy itself");
	}
	if (stack.IsEmpty())
	{
		m_top = nullptr;
	}
	else
	{
		auto currentNode = stack.m_top;
		auto newNode = make_shared<Node>();
		while (currentNode != nullptr)
		{
			newNode->next = make_shared<Node>();
			newNode = newNode->next;
			newNode->value = currentNode->value;
			currentNode = currentNode->next;
		}
		m_size = stack.GetSize();
	}
	return *this;
}

CStringStack &CStringStack::operator=(CStringStack &&stack)
{
	if (this != &stack)
	{
		m_top = stack.m_top;
		m_size = stack.GetSize();

		stack.m_top = nullptr;
		stack.m_size = 0;
	}
	return *this;
}

bool CStringStack::operator ==(CStringStack const &stack)const
{
	if (GetSize() != stack.GetSize())
	{
		return false;
	}
	auto firstÑurrentNode = m_top;
	auto secondCurrentNode = stack.m_top;
	while (firstÑurrentNode != nullptr)
	{
		if (firstÑurrentNode->value != secondCurrentNode->value)
		{
			return false;
		}
		firstÑurrentNode = firstÑurrentNode->next;
		secondCurrentNode = secondCurrentNode->next;
	}
	return true;
}

bool CStringStack::operator !=(CStringStack const &stack)const
{
	return !(*this == stack);
}