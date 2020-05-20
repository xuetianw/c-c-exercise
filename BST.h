#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;

// Point class for Q2
class Point
{
public:
	int x;
	int y;
	Point() : x(0), y(0) {};
	Point(int _x, int _y) : x(_x), y(_y) {};
};

// Node class for BST (Q1)
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

// BST class for Q1
class BST
{
public:
	// Constructors
	BST();
	~BST();

	// Mutators
	void insert(int value);
	bool remove(int value);

	// Accessors
	bool find(int value) const;
	int q1();

private:
	Node * root;

	Node* findNode(int value, Node* & parent) const;
	Node* getSuccessor(Node* target, Node* & sParent) const;
	
	// Q1 METHOD HEADER HERE
    int maxDepth(Node* root);
};

// Q1 METHOD DEFINITION HERE

int BST:: maxDepth(Node* root) {
    if (root == nullptr) return -1;
    else {
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return 1 + std::max(left_height, right_height);
    }
}

// Q1 - CHANGE METHOD TO RETURN CALL TO YOUR METHOD
int BST::q1()
{
	return -1;
}

// Q2 HELPER FUNCTIONS HERE (if any)

// this is an strucure which implements the
// operator overlading
struct CompareHeight {
    bool operator()(Point const& p1, Point const& p2) {
        return !(p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
    }
};

// Q2 COMPLETE THE FUNCTION DEFINITION BELOW
// PRE: pts is non-empty
// PARAM: names = input array to q2 function
//        n = size of names, should be set to size of result
// POST: returns an array of Names as per description of q2
vector<Point> q2(const vector<Point> & pts) 
{
    std::priority_queue<Point, vector<Point>, CompareHeight> pqueue;

    for (Point point : pts) {
        pqueue.push(point);
    }

    vector<Point> result;
    while (!pqueue.empty()) {
        Point point =  pqueue.top();
        result.push_back(point);
//        std:: cout <<"x :" << point.x << "y :" << point.y << std::endl;
        pqueue.pop();
    }

	return result;
}

// DO NOT CHANGE ANYTHING BELOW THIS COMMENT
// BST Method Defintions -----------------------------------------------
// Default Constructor
// PRE:
// POST: root set to NULL
BST::BST()
{
	root = nullptr;
}

// De-allocates dynamic memory associated with tree
// PRE:
// POST: Value is inserted, in order, in tree
BST::~BST()
{
	// NOT IMPLEMENTED
	//cout << "... calling destructor ..." << endl;
}

// Insert value in tree maintaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: value is inserted, in order, in tree
void BST::insert(int value)
{
	Node* newNode = new Node(value);
	Node* parent = root;
	Node* next = root;

	// Set new root if tree is empty
	if (root == nullptr) {
		root = newNode;
	}
	else {
		// Find parent of new node
		while (next != nullptr) {
			parent = next;
			if (value < parent->data) {
				next = parent->left;
			}
			else {
				next = parent->right;
			}
		}
		// Insert new node
		if (value < parent->data) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
}

// Remove value from tree maintaining bst property
// PRE:
// PARAM: value = value to be removed
// POST: Removes value from tree, returns true if found, false otherwise
bool BST::remove(int value)
{
	// Find node to remove
	Node* parent = nullptr;
	Node* target = findNode(value, parent);
	//cout << "target: " << target->data << ", parent: " << parent->data << endl;

	if (target == nullptr) {
		return false;
	}

	// Target has one or no children
	if (target->left == nullptr || target->right == nullptr) {
		// Identify child
		Node* child = target->left;
		if (target->left == nullptr) {
			child = target->right; // may be null
		}
		// Attach child to parent or make child new root
		if (parent != nullptr) {
			if (target == parent->left) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {
			// target is root
			//cout << "removed root (child)" << endl;
			root = child;
		}
	}
	// Target has two children
	else {
		// Find successor
		Node* sParent = nullptr;
		Node* successor = getSuccessor(target, sParent);
		//cout << endl << "successor: " << successor->data << ", sp: " << sParent->data;

		// Attach target's L child to successor
		successor->left = target->left;
		// Attach successor to target's parent or make successor new root
		if (parent != nullptr) {
			if (target == parent->left) {
				parent->left = successor;
			}
			else {
				parent->right = successor;
			}
		}
		else {
			// target is root
			//cout << "removed root (successor)" << endl;
			root = successor;
		}

		// Case where successor is not target's R child
		if (successor != target->right) {
			// Replace successor's parent's L child with successor's R subtree
			sParent->left = successor->right;
			// Make successor's R subtree target's R subtree
			successor->right = target->right;
		}
	}

	delete target;
	return true;
}

// Searches tree for target
// PRE:
// PARAM: target = value to be found
// POST: Returns true iff target is in tree
bool BST::find(int value) const
{
	Node* parent = nullptr;
	return findNode(value, parent) != nullptr;
}

// Helper Methods ----------------------------

// Used by find and remove
// PARAM: target = value to be found
//        parent = parent of target
// POST: returns node containing target or null if value is not in tree
Node* BST::findNode(int value, Node* & parent) const
{
	Node* p = root;
	parent = nullptr;
	while (p != nullptr) {
		if (value == p->data) {
			return p;
		}
		parent = p;
		if (value < p->data) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}

	return p;
}

// Used by remove
// PRE: target has a successor
// PARAM: target - node to find the successor of
//        sParent - parent of successor
// POST: Returns the successor of target, sets successor's parent
Node* BST::getSuccessor(Node* target, Node* & sParent) const
{
	// Successor is the left most node of the right sub-tree
	Node* p = target->right;
	sParent = target;

	while (p->left != nullptr) {
		sParent = p;
		p = p->left;
	}
	return p;
}