#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

template <class T>
int BinarySearchTree<T>::_max(int a, int b) {
	if (a < b)
		return b;
	return a;
}

template <class T>
int BinarySearchTree<T>::_getHeight(TreeNode<T>* node) {
	if (node == NULL) {
		return -1;
	}
	return node->_height;
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {


	if (current->_item > x)
	{
		if (current->_left) {
			current->_left = _insert(current->_left, x);
			current->_height = _max(_getHeight(current->_left), _getHeight(current->_right)) + 1;
			current = _doRotation(current);
		}
		else
		{
			current->_left = new TreeNode<T>(x);
		}
	}
	else if (x > current->_item) {
		if (current->_right) {
			current->_right = _insert(current->_right, x);
			current->_height = _max(_getHeight(current->_left), _getHeight(current->_right)) + 1;
			current = _doRotation(current);
		}
		else
		{
			current->_right = new TreeNode<T>(x);
		}
	}
	else {
		_size--;
		return current;
	}

	current->_height = _max(_getHeight(current->_left), _getHeight(current->_right)) + 1;

	return current;
}

template <class T>
int BinarySearchTree<T>::_balance(TreeNode<T>* node) {
	if (node == NULL) {
		return -1;
	}
	return _getHeight(node->_left) - _getHeight(node->_right);
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_doRotation(TreeNode<T>* node) {

	if (_balance(node) == 2 && _balance(node->_left) == 1) {
		// left unbalanced and left child heavy
		node = _rightRotation(node);
	}
	if (_balance(node) == 2 && _balance(node->_left) == -1) {
		// left unbalanced and right child heavy
		node->_left = _leftRotation(node->_left);
		node = _rightRotation(node);
	}
	if (_balance(node) == -2 && _balance(node->_right) == -1) {
		// right unbalanced and right child heavy
		node = _leftRotation(node);
	}
	if (_balance(node) == -2 && _balance(node->_right) == 1) {
		// right unbalanced and left child heavy
		node->_right = _rightRotation(node->_right);
		node = _leftRotation(node);
	}

	return node;
}

template <class T>
void BinarySearchTree<T>::insert(T x) {
	if (_root == NULL) {
		_root = new TreeNode<T>(x);
	}
	else
		_root = _insert(_root, x);

	_size++;
}

template <class T>
bool BinarySearchTree<T>::exist(T x) {
	if (_root == NULL) {
		return false;
	}
	else
		return _exist(_root, x);
}

template <class T>
bool BinarySearchTree<T>::_exist(TreeNode<T>* current, T x) {
	if (current->_item == x) {
		return true;
	}
	else if (current->_item < x) {
		if (current->_right) {
			return _exist(current->_right, x);
		}
		return false;
	}
	else if (current->_item > x) {
		if (current->_left) {
			return _exist(current->_left, x);
		}
		return false;
	}
	return false;
}

template <class T>
T BinarySearchTree<T>::searchMax() {
	TreeNode<T>* current = _root;
	
	while (current->_right) {
		current = current->_right;
	}
	return current->_item;
}

template <class T>
T BinarySearchTree<T>::searchMin() {
	return _searchMin(_root);
}

template <class T>
T BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {

	while (current->_left) {
		current = current->_left;
	}
	return current->_item;
}

template <class T>
T BinarySearchTree<T>::successor(T x)
{
	if (_root == NULL) {
		return -1;
	}
	else {
		return _successor(_root, x);
	}
}

template <class T>
T BinarySearchTree<T>::_successor(TreeNode<T>* current, T x)
{
	if (current->_item == x) {
		if (current->_right) {
			return _searchMin(current->_right);
		}
		// find the last guy who move left
		return _lastParentMoveLeft(x);
	}
	else if (current->_item > x) {
		if (current->_left) {
			return _successor(current->_left, x);
		}
		return _searchMin(current);
	}
	else if (current->_item < x) {
		if (current->_right) {
			return _successor(current->_right, x);
		}
		// find the last guy who move left
		return _lastParentMoveLeft(x);
	}
	return NULL;
}

template <class T>
T BinarySearchTree<T>::_lastParentMoveLeft(T x) {
	T leftParentItem = NULL;
	TreeNode<T>* current = _root;

	while (current->_item != x) {
		if (current->_item < x) {
			if (current->_right) {
				current = current->_right;
			}
			else {
				break;
			}
		}
		else if (current->_item > x) {
			if (current->_left) {
				leftParentItem = current->_item;
				current = current->_left;
			}
			else {
				break;
			}
		}
	}

	return leftParentItem;
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T>* rightNode = node->_right;
	TreeNode<T>* childNode = rightNode->_left;
	
	rightNode->_left = node;
	node->_right = childNode;

	rightNode->_height = _max(_getHeight(rightNode->_left), _getHeight(rightNode->_right)) + 1;
	node->_height = _max(_getHeight(node->_left), _getHeight(node->_right)) + 1;

	return rightNode;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T>* leftNode = node->_left;
	TreeNode<T>* childNode = leftNode->_right;

	leftNode->_right = node;
	node->_left = childNode;

	leftNode->_height = _max(_getHeight(leftNode->_left), _getHeight(leftNode->_right)) + 1;
	node->_height = _max(_getHeight(node->_left), _getHeight(node->_right)) + 1;
	
	return leftNode;
}

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {
	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::inOrderPrint() {
	_inOrderPrint(_root);
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	_postOrderPrint(_root);
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}



template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}


#endif
