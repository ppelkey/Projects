#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

/* Philip Pelkey, 12/g/2022, CS163 - online, Program 4
 * This header reuses the term class from Program 3. It passes the class to a new tree header,
 * which defines a tree class and node structure, both of which work with the term class.
 * I have also added a value function to return the name data's integer value.
 * I subsequently removed the "value" function and opted to rework the is_match and is_topic
 * function to return the strcmp value for their respective arguments and data members.
*/

const int SIZE = 1301;

class term
{
	public:
		term();
		~term();
		int add(char * a_name, char * a_topic, char * a_definition);
		int get_name(char *& a_name);
		int get_all(char *&the_name, char * &the_topic, char*&the_def);
		int is_match(char * a_name);
		int is_topic(char * a_topic);
		int copy(term & a_term);
		int display();
private:
		char * name;
		char * topic;
		char * definition;
};

