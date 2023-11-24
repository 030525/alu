/*
*   description : binary code convert
*   start  date : 11/24/2023
*   finish date : 11/24/2023
*
*/

#ifndef _binary_h_
#define _binary_h_
#include <stdexcept>
#include <deque>
#include <string>
using namespace std;

string origin_to_opposite(const string & code);
string origin_to_complement(const string & code);
string opposite_to_origin(const string & code);
string opposite_to_complement(const string & code);
string complement_to_opposite(const string & code);
string complement_to_origin(const string & code);

string negative_complement(const string & code,bool & OF);

int origin_to_value(const string & code);
int opposite_to_value(const string & code);
int complement_to_value(const string & code);

#endif