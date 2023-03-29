//Philip Pelkey, 12/7/2022, CS163 Program 4
//This is the term file from Program 3. The only difference is a new value function
//which returns the name's integer value. I've subsequently removed that function
//and reworked the match functions is_match and is_topic. 
#include "term.h"

using namespace std;


//A constructor function for the term class
term::term()
{
	name = nullptr;
	topic = nullptr;
	definition = nullptr;
}


//A destructor function for the class
term::~term()
{
	delete []name;
	delete[] topic;
	delete[] definition;
}


//A function to set a term's data members
int term::add(char * a_name, char * a_topic, char * a_definition)
{
	if(!(a_name && a_topic && a_definition))
		return 0;

	name = new char[strlen(a_name)];
	topic = new char[strlen(a_topic)];
	definition = new char[strlen(a_definition)];

	strcpy(name, a_name);
	strcpy(topic, a_topic);
	strcpy(definition, a_definition);
	return 1;
}


//A function to copy all data from the term and pass it to the character array arguments
int term::get_all(char *&the_name, char *& the_topic, char*&the_def)
{
	if(!(name && topic && definition))
		return 0;

	the_name = new char[strlen(name)];
	the_topic = new char[strlen(topic)];
	the_def = new char[strlen(definition)];

	strcpy(the_name, name);
	strcpy(the_topic, topic);
	strcpy(the_def, definition);
	return 1;
}	


//A function to copy only the name from a term
int term::get_name(char *& a_name)
{
	if(!(name && topic && definition))
		return 0;

	a_name = new char[strlen(name)];
	strcpy(a_name, name);
//	cout << "the get_name function is outputting this value: " << a_name << endl << endl;
	return 1;
}	


//A function to determine whether or not a term's name matches the argument character array
int term::is_match(char * a_name)
{
	return strcmp(name, a_name);
}


//Returns true if a given character array matches the term's topic data member
int term::is_topic(char * a_topic)
{
/*	if(!(topic && a_topic))
		return 0;
	if(strcmp(topic, a_topic) == 0)
		return 1;
	return 0;*/
	return strcmp(topic, a_topic);		//Made this change for the display_topic function to search the tree	
}

//A function to copy the member data from another term 
int term::copy(term & a_term)
{
	a_term.get_all(name, topic, definition);
	return 1;
}

/*
//A new function to return the integer value of the term's name
int term::value()
{
	int count{0};
	for(int i; name[i]; ++i)
		count += name[i];
	return count;
}
*/

//A function to display the member data from a term
int term::display()
{
	if(!(name && topic && definition))
		return 0;
			
	cout << "Name: " << name << "   Topic: " << topic << "   Definition: " << definition << endl << endl;
	return 1;
}
