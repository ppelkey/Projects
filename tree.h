#include "term.h"

/*Philip Pelkey, 12/7/2022, CS163 - Online, Program 4 Header
 *This header takes the header for the term class from program 3, and defines a tree class
 and a node structure for the tree. The node takes a term as its data, and has pointers to left
 and right nodes. The tree class has constructor and destructor functions, along with functions to add,
 remove, retrieve, and display terms.
 */

struct node
{
	term data;
	node * left;
	node * right;
};

class tree 
{
	public:
		tree();
		~tree();
		int add_term(term & a_term);
		int display_all();
		int display_topic(char * a_topic);
		int get(char * term_name, term & term_match);
		int remove(char * term_name);
	private:
		node * root; 
		int display_all(node * a_root);
		int add_term(node *& root, term & a_term);
		int display_topic(node * root, char * a_topic);
		int get(node * root, char * term_name, term & term_match);
		int remove(node *& root, char * term_name);
};

void remove_all(node * root);
