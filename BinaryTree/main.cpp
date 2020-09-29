#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
	public:
	int Value;
	Node* Left;
	Node* Right;

	Node()
	{
		Left = NULL;
		Right = NULL;
	}

};

class BinaryTree
{
	private:
	Node* _root;
	public:

	BinaryTree()
	{
		_root = NULL;
	}

	BinaryTree(int value)
	{
		_root = new Node;
		_root->Value = value;
	}

	void AddValue(int value)
	{
		_root = AddNode(value, _root);
	}

	void ShowInfo()
	{
		ShowTree(_root);
	}

	void DeleteTree()
	{
		DeleteNode(_root);
	}

	private:

	void DeleteNode(Node* node)
	{
		if(node != NULL)
		{
			DeleteNode(node->Left);
			DeleteNode(node->Right);
			free(node);
		}
	}

	Node* AddNode(int value, Node* tree)
	{
		if(tree == NULL)
		{
			tree = new Node;
			tree->Value = value;
		}
		else if(value < tree->Value)
		{
			tree->Left = AddNode(value, tree->Left);
		}
		else
		{
			tree->Right = AddNode(value, tree->Right);
		}
		return tree;
	}

	void ShowTree(Node* node, int level = 0)
	{
		if(node != NULL)
		{
			ShowTree(node->Left, level + 1);
			for(int i = 0; i < level; i++)
			{
				cout << "    ";
			}
			cout << node->Value << endl;
			ShowTree(node->Right, level + 1);
		}
	}
};

int main()
{
	BinaryTree tree;
	srand(time(0));
	
	for(int i = 0; i < 20; i++)
	{
		tree.AddValue(1 +rand() % 100);
	}

	tree.ShowInfo();
	return 0;
}