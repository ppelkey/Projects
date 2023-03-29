#include "tree.h"
using namespace std;
//Philip Pelkey, 12/7/2022, CS 163, Program 4
//This is the cpp file to implement the tree class' member functions.
//It currently has functions to construct the tree, add a node, and display all.
//I've added the retrieve function.


tree::tree()
{
	root = nullptr;
}


tree::~tree()
{
	remove_all(root);
}


void remove_all(node * root)
{
	if(!root)
		return;
	remove_all(root->left);
	remove_all(root->right);
	delete root;
	return;
}


int tree::add_term(term & a_term)
{
	return add_term(root, a_term);
}

//A function to add a term to a binary search tree.
int tree::add_term(node *& a_root, term & a_term)
{
	if(!a_root)
	{
		node * temp = new node;
		if(!temp->data.copy(a_term))
			return 0;
		temp->left = nullptr;
		temp->right = nullptr;
		a_root = temp;
		return 1;
	}
	char * root_name;
	char * term_name;
	
	a_term.get_name(root_name);
	a_root->data.get_name(term_name);
	if(strcmp(root_name, term_name) < 0)
		return add_term(a_root->left, a_term);

	return add_term(a_root->right, a_term);
}


//A wrapper function to display everything in the BST.
int tree::display_all()
{
	return display_all(root);	
}


//A function that does the work for the above one. It displays the data
//sorted alphabetically.
int tree::display_all(node * a_root)
{
	if(!a_root)
		return 1;
	display_all(a_root->left);
	a_root->data.display();
	display_all(a_root->right);
	return 1;
};

int tree::display_topic(char * a_topic)
{
	return display_topic(root, a_topic);
}


int tree::display_topic(node * root, char * a_topic)
{
	if(!root)
		return 0;
	if(root->data.is_topic(a_topic) == 0)
	{
		root->data.display();
		return 1;
	}

	if(root->data.is_topic(a_topic) > 0)
		return display_topic(root->left, a_topic);
	return display_topic(root->right, a_topic);
}

int tree::get(char * term_name, term & term_match)
{
	return get(root, term_name, term_match);
}

int tree::get(node * root, char * term_name, term & term_match)
{
	if(!root)
		return 0;
	if(root->data.is_match(term_name) == 0)
	{
		char * name;
		char * topic;
		char * definition;
		root->data.get_all(name, topic, definition);
		if(term_match.add(name, topic, definition))
			return 1;
		return 0;
	}

	if(root->data.is_match(term_name) > 0)
		return get(root->left, term_name, term_match);
	return get(root->right, term_name, term_match);
}


int tree::remove(char * term_name)
{
	return remove(root, term_name);
}


int tree::remove(node *& root, char * term_name)
{
	if(!root)
		return 0;
	if(root->data.is_match(term_name) == 0)
	{
		if(!(root->left || root->right))	//If both nodes are null
		{
			delete root;
			root = nullptr;
			return 1;
		}
		if(!root->right)
		{
			node * temp = root->left;
			delete root;
			root = temp;
			return 1;
		}

		if(!(root->left))			//Above returned false so we know left||right, so !left means right
		{
			node * temp = root->right;
			delete root;
			root = temp;
			return 1;
		}


		node * current = root->right;
		node * parent = root;
		while (current->left)
		{
			parent = current;
			current = current->left;
		}

		node * temp = current->right;
		root->data.copy(current->data);
		parent->left = temp;

		delete current;
		return 1;
	}


	if(root->data.is_match(term_name) > 0)
		return remove(root->left, term_name);
	return remove(root->right, term_name);
}


