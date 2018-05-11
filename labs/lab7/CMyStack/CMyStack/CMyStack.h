#pragma once
#include "stdafx.h"

template <typename T>
class CStack
{
public:
	CStack() = default;

	CStack(CStack<T> const& stack)
	{
		CopyNodes(stack);
	}

	CStack(CStack<T> && cloneStack)
	{
		m_top = cloneStack.m_top;
		m_stackSize = cloneStack.m_stackSize;
		cloneStack.m_top = nullptr;
		cloneStack.m_stackSize = 0;
	}

	void Push(T const& element)
	{
		auto newNode = std::make_shared<Node>(element, m_top);
		m_top = newNode;
		m_stackSize++;
	}

	T GetTop() const
	{
		if (Empty())
		{
			throw logic_error("Imposible return content from empty stack");
		}
		return m_top->content;
	}

	void Pop()
	{
		if (!Empty())
		{
			m_top->content.~T();
			m_top = m_top->next;
			m_stackSize--;
		}
	}

	CStack<T>& operator=(CStack<T> const& cloneStack)
	{
		if (this != &cloneStack)
		{
			Clear();
			CopyNodes(cloneStack);
		}
		return *this;
	}

	CStack<T>& operator=(CStack<T> && moveStack)
	{
		if (this != &moveStack)
		{
			m_stackSize = moveStack.m_stackSize;
			m_top = moveStack.m_top;
			moveStack.m_top = nullptr;
			moveStack.m_stackSize = 0;
		}
		return *this;
	}

	bool Empty() const
	{
		return (m_stackSize == 0);
	}

	void Clear()
	{
		while (!Empty())
		{
			m_top->content.~T();
			Pop();
		}
	}

	~CStack()
	{
		Clear();
	}

private:
	struct Node
	{
		Node(T const& value, shared_ptr<Node> const& nextNode) :content(value), next(nextNode)
		{
		}
		T content;
		shared_ptr<Node> next = nullptr;
	};

	void CopyNodes(CStack<T> const& stack)
	{
		if (!stack.Empty())
		{
			shared_ptr<Node> pCopiedNode = stack.m_top;
			m_top = make_shared<Node>(*pCopiedNode);
			auto pPasteNode = m_top;
			pPasteNode->content = pCopiedNode->content;
			while (pCopiedNode->next != nullptr)
			{
				pPasteNode->next = make_shared<Node>(*pCopiedNode->next);
				pCopiedNode = pCopiedNode->next;
				pPasteNode = pPasteNode->next;
			}
			m_stackSize = stack.m_stackSize;
		}
	}

	size_t m_stackSize = 0;
	shared_ptr<Node> m_top = nullptr;
};