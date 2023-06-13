#include <iostream>

class ArrayStack
{
public:
	ArrayStack(const int &compacity);
	~ArrayStack();
	bool PushData(const int& data);
	bool PopData();
	bool GetTop(int *) const;
	void PrintOut() const;

private:
	int* m_arrStack;
	int m_iCompacity;
	int m_iTop{ -1 };
	void PrintOut(int*, int) const;
};

ArrayStack::ArrayStack(const int& compacity)
{
	m_iCompacity = compacity;
	if (m_iCompacity < 1)
	{
		m_iCompacity = 1;
	}
	m_arrStack = (int*)malloc(sizeof(int) * m_iCompacity);
}

ArrayStack::~ArrayStack()
{
	if (m_arrStack) 
	{
		free(m_arrStack);
	}
}

void ArrayStack::PrintOut() const
{
	std::cout << "ArrayStack: ";
	PrintOut(m_arrStack, m_iTop);
}

void ArrayStack::PrintOut(int* pData, int index) const
{
	if (index == -1) 
	{
		std::cout << '\n';
		return;
	}

	std::cout << pData[index] << ' ';
	PrintOut(pData, --index);
}

bool ArrayStack::GetTop(int * data) const
{
	if (m_iTop == -1) 
	{
		std::cout << "No data in stack array" << std::endl;
		return false;
	}

	*data = m_arrStack[m_iTop];
	return true;
}

bool ArrayStack::PushData(const int& data)
{
	m_iTop++;
	if (m_iTop == m_iCompacity) 
	{
		std::cout << "Reallocate memory..." << std::endl;
		if (m_arrStack) 
		{
			free(m_arrStack);
		}

		m_iCompacity *= 2;
		m_arrStack = (int*)malloc(sizeof(int) * m_iCompacity);
	}

	m_arrStack[m_iTop] = data;
	return true;
}

bool ArrayStack::PopData()
{
	if (m_iTop == -1) 
	{
		std::cout << "No data in stack array" << std::endl;
		return false;
	}

	m_iTop--;

	return true;
}

int main() 
{
	ArrayStack arrayStack(10);
	int a;

	int result = arrayStack.GetTop(&a);
	if(result) std::cout << "Top: " << a << std::endl;

	arrayStack.PopData();

	arrayStack.PushData(1);
	arrayStack.PushData(2);
	arrayStack.PushData(3);
	arrayStack.PushData(4);
	arrayStack.PushData(5);
	
	arrayStack.PrintOut();

	arrayStack.PopData();
	arrayStack.PopData();
	arrayStack.PopData();

	arrayStack.PrintOut();

	result = arrayStack.GetTop(&a);
	if (result) std::cout << "Top: " << a << std::endl;

	arrayStack.PrintOut();
}