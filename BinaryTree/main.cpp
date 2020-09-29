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

	void ShowTreeInSymmetrical()
	{
		PrintSymmetrical(_root);
	}

	void ShowTreeInStraight()
	{
		PrintStraight(_root);
	}

	void ShowTreeInRevers()
	{
		PrintRevers(_root);
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
	
	void PrintSymmetrical(Node* node, int level = 0)
	{
		if(node)
		{
			PrintSymmetrical(node->Left, level + 1);
			ShowNode(level, node->Value);
			PrintSymmetrical(node->Right, level + 1);
		}
	}

	void PrintStraight(Node* node, int level = 0)
	{
		if(node)
		{
			ShowNode(level, node->Value);
			PrintStraight(node->Left, level + 1);
			PrintStraight(node->Right, level + 1);
		}
	}

	void PrintRevers(Node* node, int level = 0)
	{
		if(node)
		{
			PrintRevers(node->Left, level + 1);
			PrintRevers(node->Right, level + 1);
			ShowNode(level, node->Value);
		}
	}

	void ShowNode(int level, int value)
	{
		for(int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << value << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	BinaryTree tree;
	srand(time(0));
	
	for(int i = 0; i < 20; i++)
	{
		tree.AddValue(1 +rand() % 100);
	}
	cout << "Вывод дерева в обратном порядке:\n";
	tree.ShowTreeInRevers();
	cout << "-----------------------------------------------------------" << endl;
	cout << "Вывод дерева в прямом порядке:\n";
	tree.ShowTreeInStraight();
	cout << "-----------------------------------------------------------" << endl;
	cout << "Вывод дерева в симметричном порядке:\n";
	tree.ShowTreeInSymmetrical();
	cout << "-----------------------------------------------------------" << endl;
	return 0;
}