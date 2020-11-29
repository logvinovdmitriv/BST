#pragma once
#include <iostream>

using namespace std;

template <typename T>
class BST
{
private:
	class Node
	{
	public:
		
		T data=T();
		Node* pLeft=nullptr;
		Node* pRight=nullptr;
	};
	Node* Root=nullptr;
	int size = NULL;
	void insertNode(Node* current, Node* nodeForInsert);
	bool isExistNode(Node* current, T& data);
	void printNode(Node* current);
	void removeNode(Node* current, T& data);
	void removeLeafs(Node* current);
	
public:
	bool isExist(T data);
	void insert(T data);
	void remove(T data);
	void printTree();
	void clear();
	int Size();
	~BST();
};

template<typename T>
inline BST<T>::~BST()
{
	clear();
}

template<typename T>
inline void BST<T>::insert(T data)
{
	Node* nodeForInsert = new Node;
	nodeForInsert->data = data;
	auto current = Root;
	if (Root == nullptr)
	{
		Root = nodeForInsert;
	}
	insertNode(current, nodeForInsert);
	size++;
}


template<typename T>
inline void BST<T>::printTree()
{
	if (size > 0)
	{
		printNode(Root);
	}
	else
	{
		cout << "Tree is empty"<<endl;
	}
	
}

template<typename T>
inline void BST<T>::clear()
{
	removeLeafs(Root);
	Root = nullptr;
}

template<typename T>
inline int BST<T>::Size()
{
	return size;
}



template<typename T>
inline void BST<T>::removeLeafs(Node* current)
{
	if (current == nullptr) return;

	/* first delete both subtrees */
	removeLeafs(current->pLeft);
	removeLeafs(current->pRight);

	/* then delete the node */
//	cout << "\n Deleting node: " << current->data;
	delete current;
	size--;
}


template<typename T>
inline void BST<T>::printNode(Node* current)
{
	if (current != nullptr)
	{
		cout << current->data << "\t";
		printNode(current->pLeft);
		printNode(current->pRight);
		
	};
}
template<typename T>
inline void BST<T>::remove(T data)
{
	removeNode(Root, data);
}

template<typename T>
inline void BST<T>::removeNode(Node* current, T& data)
{
	if (Root->data == data)
	{
		auto oldRoot = Root;
		Root = Root->pLeft;
		insertNode(Root, oldRoot->pRight);
		delete oldRoot;
		size--;
		current = Root;
		return;
	};
	if (current->pLeft != nullptr)
	{
		if (current->pLeft->data == data)
		{
			auto forDelete = current->pLeft;
			if (forDelete->pLeft != nullptr)
			{
				insertNode(Root, forDelete->pLeft);
			};
			if (forDelete->pRight != nullptr)
			{
				insertNode(Root, forDelete->pRight);
			}
			delete forDelete;
			size--;
			current->pLeft = nullptr;
			return;
			
		};
	}
	
	if (current->pRight != nullptr)
	{
		if (current->pRight->data == data)
		{
			auto forDelete = current->pRight;
			if (forDelete->pLeft != nullptr)
			{
				insertNode(Root, forDelete->pLeft);
			};
			if (forDelete->pRight != nullptr)
			{
				insertNode(Root, forDelete->pRight);
			}
			delete forDelete;
			size--;
			current->pRight = nullptr;
			return;
		};
	}
	if (current->data > data)
	{
		removeNode(current->pLeft, data);
	};
	if (current->data < data)
	{
		removeNode(current->pRight, data);
	};
}


template<typename T>
inline void BST<T>::insertNode(Node* current, Node* nodeForInsert)
{
	if (current == nullptr)
	{
		current = nodeForInsert;
	};
	
	if (nodeForInsert != nullptr)
	{
		if (nodeForInsert->data < current->data)
		{
			if (current->pLeft == nullptr)
			{
				current->pLeft = nodeForInsert;
			}
			else
			{
				insertNode(current->pLeft, nodeForInsert);
			}

		};
		if (nodeForInsert->data > current->data)
		{
			if (current->pRight == nullptr)
			{
				current->pRight = nodeForInsert;
			}
			else
			{
				insertNode(current->pRight, nodeForInsert);
			}

		};
		
			if (nodeForInsert->data == current->data)
			{
				current->data = nodeForInsert->data;
			};
		
	}
}

template<typename T>
inline bool BST<T>::isExist(T data)
{
	return isExistNode(Root, data);
};


template<typename T>
inline bool BST<T>::isExistNode(Node* current, T& data)
{
	if (current->data == data)
	{
		return true;
	};
	isExistNode(current->pLeft, data);
	isExistNode(current->pRight, data);
	return false;
};


















//
//template <class T>
//class BST
//{
//public:
//	struct Node
//	{
//		T value;
//		Node* left;
//		Node* right;
//	};
//	Node* root;
//	void insert(Node*&, Node*&);
//	void destroySubTree(Node*);
//	void deleteNode(T, Node*&);
//	void makeDeletion(Node*&);
//	/*void displayInOrder(Node*);
//	void displayPreOrder(Node*);
//	void displayPostOrder(Node*);*/
//	int countNodes(Node*&);
//public:
//	BST() // Constructor
//	{
//		root = nullptr;
//	}
//	~BST() // Destructor
//	{
//		destroySubTree(root);
//	}
//	void insertNode(T);
//	bool searchNode(T);
//	void remove(T);
//	/*void displayInOrder()
//	{
//		displayInOrder(root);
//	}
//	void displayPreOrder()
//	{
//		displayPreOrder(root);
//	}
//	void displayPostOrder()
//	{
//		displayPostOrder(root);
//	}*/
//	int numNodes();
//};
//
//
////*************************************************************
//// insert accepts a Node pointer and a pointer to a node. The function inserts the *
//// node into the tree pointed to by the Node pointer. This function is called recursively. *
////*************************************************************
//template <class T>
//void BST<T>::insert(Node*& nodePtr, Node*& newNode)
//{
//	if (nodePtr == nullptr)
//	{
//		// Insert the node.
//		nodePtr = newNode;
//	}
//	else if (newNode->value < nodePtr->value)
//	{
//		// Search the left branch
//		insert(nodePtr->left, newNode);
//	}
//	else
//	{
//		// Search the right branch
//		insert(nodePtr->right, newNode);
//	}
//}
////**********************************************************
//// insertNode creates a new node to hold num as its value, *
//// and passes it to the insert function. *
////**********************************************************
//template <class T>
//void BST<T>::insertNode(T num)
//{
//	Node* newNode = bullptr; // Pointer to a new node.
//	// Create a new node and store num in it.
//	newNode = new Node;
//	newNode->value = num;
//	newNode->left = newNode->right = nullptr;
//	// Insert the node.
//	insert(root, newNode);
//}
////***************************************************
//
//
//// destroySubTree is called by the destructor. It *
//// deletes all nodes in the tree. *
////***************************************************
//template <class T>
//void BST<T>::destroySubTree(Node* nodePtr)
//{
//	if (nodePtr->left)
//	{
//		destroySubTree(nodePtr->left);
//	}
//	if (nodePtr->right)
//	{
//		destroySubTree(nodePtr->right);
//	}
//	delete nodePtr;
//}
////***************************************************
//// searchNode determines if a value is present in the tree. If so, *
//// the function returns true. Otherwise, it returns false. *
////***************************************************
//template <class T>
//bool BST<T>::searchNode(T num)
//{
//	bool status = false;
//	Node* nodePtr = root;
//	while (nodePtr)
//	{
//		if (nodePtr->value == num)
//		{
//			status = true;
//		}
//		else if (num < nodePtr->value)
//		{
//			nodePtr = nodePtr->left;
//		}
//		else
//		{
//			nodePtr = nodePtr->right;
//
//		}
//	}
//	return status;
//}
////**********************************************
//// remove calls deleteNode to delete the *
//// node whose value member is the same as num. *
////**********************************************
//template <class T>
//void BST<T>::remove(T num)
//{
//	deleteNode(num, root);
//}
////********************************************
//// deleteNode deletes the node whose value *
//// member is the same as num. *
////********************************************
//template <class T>
//void BST<T>::deleteNode(T num, Node*& nodePtr)
//{
//	if (num < nodePtr->value)
//	{
//		deleteNode(num, nodePtr->left);
//	}
//	else if (num > nodePtr->value)
//	{
//		deleteNode(num, nodePtr->right);
//	}
//	else
//	{
//		makeDeletion(nodePtr);
//	}
//}
////***********************************************************
//// makeDeletion takes a reference to a pointer to the node that is to be deleted. *
//// The node is removed and the branches of the tree below the node are reattached. *
////***********************************************************
//template <class T>
//void BST<T>::makeDeletion(Node*& nodePtr)
//{
//
//
//	// Temporary pointer, used in reattaching the left subtree.
//	Node* tempNodePtr = nullptr;
//	if (nodePtr == nullptr)
//	{
//		cout << "Cannot delete empty node.\n";
//	}
//	else if (nodePtr->right == nullptr)
//	{
//		tempNodePtr = nodePtr;
//		nodePtr = nodePtr->left; // Reattach the left child
//		delete tempNodePtr;
//	}
//	else if (nodePtr->left == nullptr)
//	{
//		tempNodePtr = nodePtr;
//		nodePtr = nodePtr->right; // Reattach the right child
//		delete tempNodePtr;
//	}
//	// If the node has two children.
//	else
//	{
//		// Move one node the right.
//		tempNodePtr = nodePtr->right;
//		// Go to the end left node.
//		while (tempNodePtr->left)
//		{
//			tempNodePtr = tempNodePtr->left;
//		}
//		// Reattach the left subtree.
//		tempNodePtr->left = nodePtr->left;
//		tempNodePtr = nodePtr;
//		// Reattach the right subtree.
//		nodePtr = nodePtr->right;
//		delete tempNodePtr;
//	}
//
//	cout << "\n\nNow deleting " << nodePtr->value << " from the tree...." << endl;
//}
////****************************************************************
//
//// The displayInOrder member function displays the values *
//// in the subtree pointed to by nodePtr, via inorder traversal. *
////****************************************************************
//template <class T>
//void BST<T>::displayInOrder(Node* nodePtr)
//{
//	if (nodePtr)
//	{
//		displayInOrder(nodePtr->left);
//		cout << nodePtr->value << " ";
//		displayInOrder(nodePtr->right);
//	}
//}
////****************************************************************
//// The displayPreOrder member function displays the values *
//// in the subtree pointed to by nodePtr, via preorder traversal. *
////****************************************************************
//template <class T>
//void BST<T>::displayPreOrder(Node* nodePtr)
//{
//	if (nodePtr)
//	{
//		cout << nodePtr->value << " ";
//		displayPreOrder(nodePtr->left);
//		displayPreOrder(nodePtr->right);
//	}
//}
////****************************************************************
//// The displayPostOrder member function displays the values *
//// in the subtree pointed to by nodePtr, via postorder traversal.*
////****************************************************************
//template <class T>
//void BST<T>::displayPostOrder(Node* nodePtr)
//{
//	if (nodePtr)
//	{
//		displayPostOrder(nodePtr->left);
//		displayPostOrder(nodePtr->right);
//		cout << nodePtr->value << " ";
//	}
//
//}
////****************************************************************
//// The numNodes function returns the number of nodes in the tree.*
////****************************************************************
//template <class T>
//int BST<T>::numNodes()
//{
//	return countNodes(root);
//}
////****************************************************************
//// The countNodes function uses recursion to count the nodes in the tree.
//// This function is called by the public member function numNodes.
////****************************************************************
//template <class T>
//int BST<T>::countNodes(Node*& nodePtr)
//{
//	int count;
//	if (nodePtr == nullptr)
//	{
//		count = 0;
//	}
//	else
//	{
//		count = 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
//	}
//	return count;
//};

