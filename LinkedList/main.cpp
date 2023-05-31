#include <iostream>

struct LinkedNode 
{
	int data;
	LinkedNode* next;
};

class LinkedList 
{
private:
	LinkedNode* m_pHead{ nullptr };
	int m_iLength{ 0 };

public:
	void Print() const;
	void Print(LinkedNode *node) const;
	// position zero-based
	void Insert(int data, int position = 0);
	void Reverse();
	void Reverse(LinkedNode *nodeToLink, LinkedNode *currentNode);
};

void LinkedList::Print() const
{
	Print(m_pHead);
}

void LinkedList::Print(LinkedNode *node) const
{
	if (node == nullptr) 
	{
		std::cout << '\n';
		return;
	}
	std::cout << node->data << " ";
	
	Print(node->next);
}

void LinkedList::Insert(int data, int position) 
{
	if (position < 0 || position > m_iLength) 
	{
		std::cout << "Insertion failed, position = " << position << ", length = " << m_iLength << std::endl;
		return;
	}

	LinkedNode* tmp = new LinkedNode();
	tmp->data = data;
	tmp->next = nullptr;

	if (position == 0) 
	{
		tmp->next = m_pHead;
		m_pHead = tmp;
		m_iLength++;
		return;
	}

	LinkedNode* formalHead = m_pHead;
	for (int i = 0; i < position - 1; i++) 
	{
		formalHead = formalHead->next;
	}

	tmp->next = formalHead->next;
	formalHead->next = tmp;
	m_iLength++;
}

void LinkedList::Reverse() 
{
	Reverse(nullptr, m_pHead);
}

void LinkedList::Reverse(LinkedNode *nodeToLink, LinkedNode *currentNode) 
{
	if (currentNode == nullptr) 
	{
		return;
	}

	LinkedNode* tmp = currentNode->next;
	currentNode->next = nodeToLink;

	if (tmp == nullptr) 
	{
		m_pHead = currentNode;
	}
	else 
	{
		Reverse(currentNode, tmp);
	}
}

int main()
{
	LinkedList ll = LinkedList();
	ll.Insert(1, 1);
	ll.Insert(2);
	ll.Insert(3, 1);
	ll.Insert(4, 1);

	ll.Print();

	ll.Reverse();

	ll.Print();

	ll.Reverse();

	ll.Print();
}
