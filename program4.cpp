#include "tree.h"
using namespace std;
//Philip Pelkey, CS 163, Program 4, 12/7/2022
//This is a main function which is only performing
//minor tests at the moment, but is necessary for the code
//to compile. I'm currently testing the add, display, and
//retrieve functions.



int main()
{
	char name[50];
	char topic[50];
	char definition[1000];
	int menu{0};

	tree BST;
	term a_term;
	do {
		cout << "What would you like to do? You can:\n\n1) Add a new term\n2) Display a given topic\n3) Display all terms\n" <<
			"4) Retrieve a term by name\n5) Remove a term by name\n\nPlease enter the number corresponding to your choice,"
		       << "or press any other number key to quit.   ";
		cin >> menu;
		cin.ignore(100,'\n');
		cout << endl << endl;

		if(menu == 1)
		{
			cout << "What is the term's name?   ";
			cin.get(name, '\n');
			cin.ignore(100, '\n');
			cout << endl;

			cout << "What is the term's topic?   ";
			cin.get(topic, '\n');
			cin.ignore(100, '\n');
			cout << endl;

			cout << "What is the term's definition?   ";
			cin.get(definition, '\n');
			cin.ignore(2000, '\n');
			cout << endl;
	
			a_term.add(name, topic, definition);
			if(BST.add_term(a_term))
				cout << "The program has saved the term successfully.\n\n";
			else cout << "The add was unsuccessful.\n\n";
		}

		if(menu == 2)
		{
			cout << "What is the term's topic?   ";
			cin.get(topic, '\n');
			cin.ignore(100, '\n');
			cout << endl;
		
			BST.display_topic(topic);
		}

		if(menu == 3)
		{
			BST.display_all();
		}

		if(menu == 4)
		{
			term b_term;
			if(BST.get(name, b_term))
				cout << "Successfully retrieved data.\n\n";
			else
			cout << "Could not retrieve data.\n\n";
			cout << "The retrieved term is:\n" << b_term.display();
		}

		if(menu == 5)
		{
			cout << "What is the term's name?   ";
			cin.get(name, '\n');
			cin.ignore(100, '\n');
			cout << endl;

			BST.remove(name);
		}
	} while(menu >=1 && menu <= 5);


	return 0;
}
