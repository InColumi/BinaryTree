#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

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
	int _countLeftNodes;
	int _countRightNodes;
	public:

	BinaryTree()
	{
		_root = NULL;
		int _countLeftNodes = 0;
		int _countRightNodes = 0;
	}

	void ReadFromFile(string fileName)
	{
		ifstream in;
		in.open(fileName);
		if(in.is_open() == false)
		{
			cout << "Файл не найден.\n";
		}

		string line;
		
		while(getline(in, line))
		{
			AddValue(stoi(line));
		}
		in.close();
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
		_countLeftNodes = 0;
		_countRightNodes = 0;
	}

	void ShowInfo()
	{
		CountNodes();
		if(IsSymmetrical())
		{
			cout << "Дерево является сбалансированным\n";
		}
		else
		{
			cout << "Дерево НЕ является сбалансированным\n";
		}
	}

	private:

	bool IsSymmetrical()
	{
		int differece = abs(_countLeftNodes - _countRightNodes);
		return differece == 0 || differece == 1;
	}

	void CountNodes()
	{
		CountLeftAndRightNodes(_root);
	}

	void  CountLeftNodes(Node* nodes)
	{
		if(nodes->Left != NULL)
		{
			CountLeftNodes(nodes->Left);
			++_countLeftNodes;
		}
		else if(nodes->Right != NULL)
		{
			CountLeftNodes(nodes->Right);
			++_countLeftNodes;
		}
	}

	void CountRightNodes(Node* nodes)
	{
		if(nodes->Right != NULL)
		{
			CountRightNodes(nodes->Right);
			++_countRightNodes;
		}
		else if(nodes->Left != NULL)
		{
			CountRightNodes(nodes->Left);
			++_countRightNodes;
		}
	}

	void CountLeftAndRightNodes(Node* nodes)
	{
		CountLeftNodes(nodes);
		CountRightNodes(nodes);
	}

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
	
	tree.ReadFromFile("TreeValues.txt");

	cout << "Вывод дерева в обратном порядке:\n";
	tree.ShowTreeInRevers();
	cout << "-----------------------------------------------------------" << endl;
	cout << "Вывод дерева в прямом порядке:\n";
	tree.ShowTreeInStraight();
	cout << "-----------------------------------------------------------" << endl;
	cout << "Вывод дерева в симметричном порядке:\n";
	tree.ShowTreeInSymmetrical();
	cout << "-----------------------------------------------------------" << endl;

	tree.ShowInfo();
	return 0;
}