#include <iostream>
#include <queue>

struct TreeNode
{
	int data;
	TreeNode* leftNode;
	TreeNode* rightNode;
};

class LinkedTree
{
public:
	LinkedTree(){}
	~LinkedTree(){}
	void Insert(int data);
	bool Search(int data);
	int GetMax();
	int GetMin();
	int GetHeight();
	void PreOrder();
	void LevelOrder();

private:
	TreeNode* m_root{nullptr};
	TreeNode* GetNode(int data);
	int GetMax(TreeNode*);
	int GetMin(TreeNode*);
	TreeNode* Insert(TreeNode* node, int data);
        bool Search(TreeNode* node, int data);
	int GetHeight(TreeNode* node);
	void PreOrder(TreeNode* node);
	void LevelOrder(TreeNode* node);
};

TreeNode* LinkedTree::GetNode(int data)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->leftNode = nullptr;
	node->rightNode = nullptr;
	return node;
}

void LinkedTree::Insert(int data)
{
	m_root = Insert(m_root, data);
}

TreeNode* LinkedTree::Insert(TreeNode* node, int data)
{
	if(node == nullptr)
	{
		return GetNode(data);
	}
	
	if(data <= node->data)
	{
		node->leftNode = Insert(node->leftNode, data);
	}
	else
	{
		node->rightNode = Insert(node->rightNode, data);
	}

	return node;
}

bool LinkedTree::Search(int data)
{
	return Search(m_root, data);
}

bool LinkedTree::Search(TreeNode* node, int data)
{
	if(node == nullptr)
	{
		return false;
	}
	else if(node->data == data)
	{
		return true;
	}
	else if(data < node->data)
	{
		return Search(node->leftNode, data);
	}
	else
	{
		return Search(node->rightNode, data);
	}
}

int LinkedTree::GetMax()
{
	if(m_root == nullptr)
	{
		std::cout << "Empty tree" << std::endl;
		return -1;
	}

	return GetMax(m_root);
}

int LinkedTree::GetMax(TreeNode* node)
{
	if(node->rightNode)
	{
		return GetMax(node->rightNode);	
	}
	
	return node->data;
}

int LinkedTree::GetMin()
{
        if(m_root == nullptr)
        {
                std::cout << "Empty tree" << std::endl;
                return -1;
        }

        return GetMin(m_root);
}

int LinkedTree::GetMin(TreeNode* node)
{
        if(node->leftNode)
        {
                return GetMin(node->leftNode);
        }

        return node->data;
}

int LinkedTree::GetHeight()
{
	return GetHeight(m_root);
}

int LinkedTree::GetHeight(TreeNode* node)
{
	if(node == nullptr)
	{
		return 0;
	}
	else if(node->leftNode == nullptr && node->rightNode == nullptr)
	{
		return 0;
	}
	else
	{
		return std::max(GetHeight(node->leftNode), GetHeight(node->rightNode))+1;
	}
}

void LinkedTree::PreOrder()
{
	std::cout << "PreOrder: ";
	PreOrder(m_root);
	std::cout<< '\n';
}

void LinkedTree::PreOrder(TreeNode* node)
{
	if(node == nullptr)
	{
		return;
	}
	
	std::cout << node->data << ' ';
	
	PreOrder(node->leftNode);
	PreOrder(node->rightNode);
}

void LinkedTree::LevelOrder()
{
	std::cout << "LevelOrder: ";
	LevelOrder(m_root);
	std::cout << '\n';
}

void LinkedTree::LevelOrder(TreeNode* node)
{
	std::queue<TreeNode*> nodeQueue;
	if(node)
	{
		nodeQueue.push(node);
	}

	while(nodeQueue.empty() == false)
	{
		TreeNode* tmp = nodeQueue.front();
		nodeQueue.pop();
		
		if(tmp->leftNode)
		{
			nodeQueue.push(tmp->leftNode);
		}

		if(tmp->rightNode)
		{
			nodeQueue.push(tmp->rightNode);
		}

		std::cout << tmp->data << ' ';
	}
}


int main()
{
	LinkedTree tree = LinkedTree();
	tree.Insert(10);
	tree.Insert(20);
	tree.Insert(15);
	tree.Insert(5);

	std::cout << "search for 5: " << (tree.Search(5) ? "found" : "not found") << std::endl;
	std::cout << "search for 25: " << (tree.Search(25) ? "found" : "not found") << std::endl;	

	std::cout << "Height: " << tree.GetHeight() << std::endl; //2

	tree.Insert(1);
	std::cout << "Height: " << tree.GetHeight() << std::endl; //2
	tree.Insert(-2);
	std::cout << "Height: " << tree.GetHeight() << std::endl; //3
	tree.Insert(15);
	std::cout << "Height: " << tree.GetHeight() << std::endl; //3
	tree.Insert(14);
	std::cout << "Height: " << tree.GetHeight() << std::endl; //4
	
	std::cout << "Min value: " << tree.GetMin() << std::endl;
        std::cout << "Max value: " << tree.GetMax() << std::endl;

	tree.PreOrder();
	tree.LevelOrder();
	return 0;
}

