// =================================================================
// File: bst.h
// Author: Luis Angel Zavala Robles
// Date: 31/Oct/2020
// 					Modified from:
// 						https://github.com/Manchas2k4/tc1031/blob/master/15_bst/bst.h
// =================================================================
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef unsigned int uint;

template <class T> class BST;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	T value;
	int key;
	Node *left, *right;

	Node(T);
	Node(T, Node<T>*, Node<T>*);

	bool find(T);
	void add(T);


	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), key(1), left(NULL), right(NULL) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
bool Node<T>::find(T val){
	if (val == value) {
		key = key + 1;
		return true;
	} else if (val < value) {
		return (left != NULL && left->find(val));
	} else {
		return (right != NULL && right->find(val));
	}
}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != NULL) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != NULL) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	bool empty() const;
	void add(T);
	string mostAccessed() const;
};


template <class T>
BST<T>::BST() : root(NULL) {}

template <class T>
bool BST<T>::empty() const {
	return (root == NULL);
}


template<class T>
void BST<T>::add(T val) {
	if (!empty()) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}


template <class T>
string BST<T>:: mostAccessed() const {		// Complejidad O(n)
	vector<Node<T>*> aux;
	queue<Node<T>*> lista;
	stringstream result;
	lista.push(root);

	while(lista.empty() == false){

		if( (lista.front()->left) != NULL){
			lista.push(lista.front()->left);
		}

		if( (lista.front()->right) != NULL){
			lista.push(lista.front()->right);
		}

		if(lista.front()->key > 1){
			aux.push_back(lista.front());
		}
		lista.pop();
	}

	sort(aux.begin(), aux.end(),
          [](auto &a, auto &b){ return a->key >= b->key; });
	

	for(int i=0; i<5; i++){
		result << aux[i]->value << " : Accesado " <<aux[i]->key << " veces" <<endl;
	}
	return result.str();
}



#endif /* BST_H */
