#include <iostream>

const bool black = 1;
const bool red = 0;

template<typename T> struct Node
{
	T value;
	bool color;
	Node* left;
	Node* right;
	Node* parent;
};

template<typename T> class RedBlackTree
{
private:
	Node<T>* root;
	Node<T>* NIL;
public:
	RedBlackTree()
	{
		NIL = new Node<T>;
		NIL->left = NIL->parent = NIL->right = nullptr;
		NIL->color = black;
		root = NIL;
	}

	bool _color()const
	{
		return color;
	}

	Node<T>* _root()const
	{
		return root;
	}


	void left_rotate(Node<T>* current)
	{
		Node<T>* temp = current->right;
		current->right = temp->left;
		if (temp->left != NIL)
			temp->left->parent = current;
		if (current->parent != NIL)
		{
			if (current == current->parent->left)
				current->parent->left = temp;
			else
				current->parent->right = temp;
		}
		else
		{
			root = temp;
		}
		temp->left = current;
		if (current != NIL)
			current->parent = temp;
	}

	void right_rotate(Node<T> *current)
	{
		Node<T> *temp = current->left;
		current->left = temp->right;
		if (temp->right != NIL)
			temp->right->parent = current;
		if (temp != NIL)
			temp->parent = current->parent;
		if (current->parent != NIL)
		{
			if (current == current->parent->right)
				current->parent->right = temp;
			else
				current->parent->left = temp;
		}
		else
		{
			root = temp;
		}


		temp->right = current;
		if (current != NIL)
			current->parent = temp;
	}


	void insertFix(Node<T>* current)
	{
		while (current != root && current->parent->color == red)
		{
			if (current->parent == current->parent->parent->left)
			{
				Node<T>* temp = current->parent->parent->right;
				if (temp->color == red)
				{
					current->parent->color = black;
					temp->color = black;
					current->parent->parent->color = red;
					current = current->parent->parent;
				}

				else
				{
					if (current == current->parent->right)
					{
						current = current->parent;
						left_rotate(current);
					}
					current->parent->color = black;
					current->parent->parent->color = red;
					right_rotate(current->parent->parent);
				}
			}

			else
			{
				Node<T>* temp = current->parent->parent->left;
				if (temp->color == red)
				{
					current->parent->color = black;
					temp->color = black;
					current->parent->parent->color = red;
					current = current->parent->parent;
				}
				else
				{
					if (current == current->parent->left)
					{
						current = current->parent;
						right_rotate(current);
					}
					current->parent->color = black;
					current->parent->parent->color = red;
					left_rotate(current->parent->parent);
				}
			}
		}
		root->color = black;
	}


	void insert(const T& added)
	{
		Node<T>* daughter = new Node<T>;
		daughter->value = added;
		daughter->color = red;
		daughter->left = daughter->right = daughter->parent = NIL;
		Node<T>* parent = NIL;
		Node<T>* temp = root;
		if (root == NIL)
		{
			root = daughter;
			root->color = black;
			return;
		}
		while (temp != NIL)
		{

			if (daughter->value == temp->value)
				return;

			parent = temp;
			if (added < temp->value)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if (added < parent->value)
		{
			parent->left = daughter;
		}
		else
		{
			parent->right = daughter;

		}
		daughter->parent = parent;
		insertFix(daughter);
	}

	void display(const Node<T>* temp, unsigned int level)const
	{
		try
		{
			if (root == NIL)
			{
				throw 2;
			}
			if (temp != NIL)
			{
				display(temp->left, level + 1);
				for (int i = 0; i < level; i++)
					std::cout << "____";
				std::cout << "(" << temp->color << ")";
				std::cout << temp->value << "\n";
				display(temp->right, level + 1);
			}
		}
		catch (int i)
		{
			std::cout << "There is nothing to print\nError #2\n";
		}
	}

	Node<T>* search(const T& value)const
	{
		Node<T>* current = root;
		while (current != NIL)
		{
			if (value == current->value)
				return current;
			else
			{
				if (value < current->value)
					current = current->left;
				else current = current->right;
			}
		}
		return 0;
	}
};
