#include <iostream>

class ArrayQueue
{
public:
	ArrayQueue(const int& compacity);
	~ArrayQueue();
	bool Dequeue();
	bool Enqueue(const int& data);
	bool Front(int* pData) const;
	bool Rear(int* pData) const;
	bool IsEmpty() const;
	void PrintOut() const;

private:
	int m_iCompacity;
	int* m_arrQueue;
	int m_iFrontIndex{ -1 };
	int m_iRearIndex{ -1 };
};

ArrayQueue::ArrayQueue(const int& compacity) 
{
	m_iCompacity = compacity;
	if (m_iCompacity < 1) 
	{
		m_iCompacity = 1;
	}

	m_arrQueue = (int*)malloc(sizeof(int) * m_iCompacity);
}

ArrayQueue::~ArrayQueue() 
{
	if (m_arrQueue) 
	{
		free(m_arrQueue);
	}
}

bool ArrayQueue::IsEmpty() const
{
	return (m_iFrontIndex == m_iRearIndex && m_iFrontIndex == -1);
}

void ArrayQueue::PrintOut() const
{
	int length = m_iRearIndex - m_iFrontIndex + 1;
	length = (length <= 0) ? length + m_iCompacity : length;
	std::cout << "Front: " << m_iFrontIndex << ", Rear: " << m_iRearIndex << ", length: " << length << ", ArrayQueue: ";
	for (int i = 0; i < length; i++) 
	{
		std::cout << m_arrQueue[(m_iFrontIndex + i) % m_iCompacity] << ' ';
	}
	std::cout << std::endl;
}

bool ArrayQueue::Enqueue(const int& data) 
{
	if ((m_iRearIndex + 1) % m_iCompacity == m_iFrontIndex) 
	{
		std::cout << "Queue is full!" << std::endl;
		std::cout << "Reallocate memory..." << std::endl;

		int* tmp = (int*)malloc(sizeof(int) * m_iCompacity * 2);
		for (int i = 0; i < m_iCompacity; i++) 
		{
			tmp[i] = m_arrQueue[(m_iFrontIndex + i) % m_iCompacity];
		}
		m_iFrontIndex = 0;
		m_iRearIndex = m_iCompacity - 1;
		m_iCompacity *= 2;

		if (m_arrQueue) 
		{
			free(m_arrQueue);
		}
		m_arrQueue = tmp;
	}

	if (IsEmpty()) 
	{
		m_iFrontIndex++;
	}

	m_iRearIndex = (m_iRearIndex + 1) % m_iCompacity;
	m_arrQueue[m_iRearIndex] = data;
	return true;
}

bool ArrayQueue::Dequeue() 
{
	if (IsEmpty()) 
	{
		std::cout << "Queue is empty!" << std::endl;
		return false;
	}

	if (m_iFrontIndex == m_iRearIndex) 
	{
		m_iFrontIndex == -1;
		m_iRearIndex == -1;
	}
	else
	{
		m_iFrontIndex = (m_iFrontIndex + 1) % m_iCompacity;
	}
	
	return true;
}

bool ArrayQueue::Front(int* pData) const
{
	if (m_iFrontIndex != -1) 
	{
		*pData = m_arrQueue[m_iFrontIndex];
		return true;
	}

	return false;
}

bool ArrayQueue::Rear(int* pData) const
{
	if (m_iRearIndex != -1)
	{
		*pData = m_arrQueue[m_iRearIndex];
		return true;
	}

	return false;
}

int main() 
{
	ArrayQueue arrayQueue(5);

	arrayQueue.Dequeue();
	arrayQueue.Enqueue(1);
	arrayQueue.Enqueue(2);
	arrayQueue.Enqueue(3);
	arrayQueue.Enqueue(4);
	arrayQueue.Enqueue(5);

	arrayQueue.PrintOut();

	arrayQueue.Enqueue(6);

	arrayQueue.PrintOut();

	arrayQueue.Dequeue();
	arrayQueue.Dequeue();
	arrayQueue.Dequeue();
	arrayQueue.Dequeue();

	arrayQueue.PrintOut();

	arrayQueue.Enqueue(7);
	arrayQueue.Enqueue(8);
	arrayQueue.Enqueue(9);
	arrayQueue.Enqueue(10);
	arrayQueue.Enqueue(11);
	arrayQueue.Enqueue(12);
	arrayQueue.Enqueue(13);
	arrayQueue.Enqueue(14);

	arrayQueue.PrintOut();

	arrayQueue.Enqueue(15);

	arrayQueue.PrintOut();
}