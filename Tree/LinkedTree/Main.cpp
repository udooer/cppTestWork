#include <iostream>

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

private:
	TreeNode* m_root{nullptr};
	TreeNode* GetNode(int data);
	int GetMax(TreeNode*);
	int GetMin(TreeNode*);
	TreeNode* Insert(TreeNode* node, int data);
        bool Search(TreeNode* node, int data);
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


int main()
{
	LinkedTree tree = LinkedTree();
	tree.Insert(10);
	tree.Insert(20);
	tree.Insert(15);
	tree.Insert(5);

	std::cout << "search for 5: " << (tree.Search(5) ? "found" : "not found") << std::endl;
	std::cout << "search for 25: " << (tree.Search(25) ? "found" : "not found") << std::endl;	
	
	std::cout << "Min value: " << tree.GetMin() << std::endl;
	std::cout << "Max value: " << tree.GetMax() << std::endl;
	return 0;
}

