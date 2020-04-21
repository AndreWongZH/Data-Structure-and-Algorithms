#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;

public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };

	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
private:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	void _preOrderPrint(TreeNode<T>*);
	void _inOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	TreeNode<T>* _insert(TreeNode<T>* current, T x);

	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
    void _destroySubTree(TreeNode<T>*);
	bool _exist(TreeNode<T>*, T);
	T _searchMin(TreeNode<T>*);
	T _successor(TreeNode<T>*, T);
	T _lastParentMoveLeft(T);
	TreeNode<T>* _doRotation(TreeNode<T>*);
	int _balance(TreeNode<T>*);
	int _getHeight(TreeNode<T>*);
	int _max(int, int);
    
public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() ;
	T searchMin();
	bool exist(T x);
	T successor(T);
};

#include "BST.hpp"
