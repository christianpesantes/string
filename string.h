
//------------------------------------------------------------------------------
//	author		:	christian pesantes
//	filename	:	string.h
//	compiler	:	borland C++ 5.5.1
//------------------------------------------------------------------------------

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <sstream>

namespace cpt
{
	//--------------------------------------------------------------------------
	//	class	:	string
	//	info	:	dynamic character array
	//--------------------------------------------------------------------------
	
	class string
	{
	private:
		
		//	data
		char * _data;			// 	allocates string
		unsigned int _size;		// 	keeps track of string size
	
	public:
	
		//	constructors
		string();					//	1 constructor : default
		string(const string &);		//	2 constructor : copy
		string(const char *);		//	3 constructor : c-string
		string(char);				//	4 constructor : character
		virtual ~string();			//	destructor
		
		//	getters
		unsigned int size() const;		//	returns size of string
		const char * c_str() const;		//	returns c-string
		
		//	tools
		void clear();			//	empties string; size becomes 0
		bool isEmpty() const;	//	returns TRUE if the string is empty
		bool find(char, unsigned int &) const;	//	finds char in string
		bool find(char) const;	//	finds char in string
		unsigned int count(char) const;	//	finds char in string
		
		//	convert
		string substr (unsigned int, unsigned int) const;	//	substring
		string toLower() const;		//	converts all characters to lower case
		string toUpper() const;		//	converts all characters to upper case
		string clone() const;		//	returns a clone of the string
		string filter() const;		//	returns a filtered clone
		string trim() const;		//	returns a filtered clone
		
		string extractHTML() const;
		
		//	operators[]
		char & operator[] (unsigned int);				// 	1 operator[]
		const char & operator[] (unsigned int) const;	// 	2 operator[]
		
		//	operators+
		string operator+ (const string &) const;	//	1 operator+ : default
		string operator+ (const char *) const;		//	2 operator+ : c-string
		string operator+ (char) const;				//	3 operator+ : character
		
		//	operators=
		string & operator= (const string &);	//	1 operator= : default
		string & operator= (const char *);		//	2 operator= : c-string
		string & operator= (char);				//	3 operator= : character
		
		//	operators+=
		string & operator+= (const string &);	//	1 operator+= : default
		string & operator+= (const char *);		//	2 operator+= : c-string
		string & operator+= (char);				//	3 operator+= : character
		
		//	compare
		bool operator> (const string &) const;			//	1 operator> : default
		bool operator> (const char *) const;			//	2 operator> : c-string
		bool operator> (char) const;					//	3 operator> : character
		bool operator< (const string &) const;			//	1 operator> : default
		bool operator< (const char *) const;			//	2 operator> : c-string
		bool operator< (char) const;					//	3 operator> : character
		bool operator>= (const string &) const;			//	1 operator>= : default
		bool operator>= (const char *) const;			//	2 operator>= : c-string
		bool operator>= (char) const;					//	3 operator>= : character
		bool operator<= (const string &) const;			//	1 operator>= : default
		bool operator<= (const char *) const;			//	2 operator>= : c-string
		bool operator<= (char) const;					//	3 operator>= : character
		bool operator== (const string &) const;			//	1 operator== : default
		bool operator== (const char *) const;			//	2 operator== : c-string
		bool operator== (char) const;					//	3 operator== : character
		bool operator!= (const string &) const;			//	1 operator!= : default
		bool operator!= (const char *) const;			//	2 operator!= : c-string
		bool operator!= (char) const;					//	3 operator!= : character
		bool isEqualTo(const string &, bool) const;		//	1 isEqualTo : default
		bool isEqualTo(const char *, bool) const;		//	2 isEqualTo : c-string
		bool isEqualTo(char, bool) const;				//	3 isEqualTo : character
		
		//	print
		void print(std::ostream &, const char *, const char *) const;	//	out
		friend std::ostream & operator<< (std::ostream &, string &);	//	out
	};
	
	//--------------------------------------------------------------------------
	//	helper functions
	//--------------------------------------------------------------------------
	
	//	char check
	bool isAlphaNum(char);	//	returns TRUE if alphanumeric
	bool isAlpha(char);		//	returns TRUE if alpha
	bool isDigit(char);		//	returns TRUE if number
	
	//	tools
	bool filter(string &);	//	filters string
		
	//	char convert
	cpt::string intToString (int);				//	converts int to string
	cpt::string uintToString (unsigned int);	//	converts uint to string
	
}

//------------------------------------------------------------------------------
//														public : constructors
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	1 constructor : default
//------------------------------------------------------------------------------
cpt::string::string()
{
	this->_size = 0;
	this->_data = 0;
}

//------------------------------------------------------------------------------
//	2 constructor : copy
//------------------------------------------------------------------------------
cpt::string::string(const cpt::string & str)
{
	if(str.isEmpty()) { this->_size = 0; this->_data = 0; return; }
	
	this->_size = str.size();
	this->_data = new char [this->_size +1];
	
	for(unsigned int i=0; i<this->_size; i++) { this->_data[i] = str._data[i]; }
	this->_data[this->_size] = '\0';
}

//------------------------------------------------------------------------------
//	3 constructor : c-string
//------------------------------------------------------------------------------
cpt::string::string(const char * str)
{
	unsigned int sz;
	for(sz=0; str[sz]!='\0'; sz++);
	
	if(sz==0) { this->_size = 0; this->_data = 0; return; }
	
	this->_size = sz;
	this->_data = new char [this->_size +1];
	
	for(unsigned int i=0; i<this->_size; i++) { this->_data[i] = str[i]; }
	this->_data[this->_size] = '\0';
}

//------------------------------------------------------------------------------
//	4 constructor : character
//------------------------------------------------------------------------------
cpt::string::string(char c)
{
	this->_size = 1;
	this->_data = new char [this->_size +1];
	
	this->_data[0] = c;
	this->_data[this->_size] = '\0';
}

//------------------------------------------------------------------------------
//	destructor
//------------------------------------------------------------------------------
cpt::string::~string()
{
	if(this->_size > 0) 
	{ 
		this->_size = 0; 
		delete [] this->_data; 
		this->_data = 0; 
	}
}


//------------------------------------------------------------------------------
//															public : getters
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	returns size of string
//------------------------------------------------------------------------------
unsigned int cpt::string::size() const
{
	return this->_size;
}

//------------------------------------------------------------------------------
//	returns c-string
//------------------------------------------------------------------------------
const char * cpt::string::c_str() const
{
	return this->_data;
}


//------------------------------------------------------------------------------
//															public : tools
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	deletes contents of string; size becomes 0
//------------------------------------------------------------------------------
void cpt::string::clear()
{
	if(this->_size > 0) { this->_size = 0; delete [] this->_data; this->_data = 0; }
}

//------------------------------------------------------------------------------
//	returns TRUE if the string is empty
//------------------------------------------------------------------------------
bool cpt::string::isEmpty() const
{
	return this->_size == 0 ? true : false;
}

//------------------------------------------------------------------------------
//	returns TRUE if the char is found and gives the index to the first match
//------------------------------------------------------------------------------
bool cpt::string::find(char c, unsigned int & index) const
{
	index = 0;
	if(this->isEmpty()) {return false; }

	for(unsigned int i=0; i<this->_size; i++) 
	{ if(this->_data[i] == c) { index = i; return true; } }

	return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool cpt::string::find(char c) const
{
	if(this->isEmpty()) {return false; }

	for(unsigned int i=0; i<this->_size; i++) 
	{ if(this->_data[i] == c) { return true; } }

	return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
unsigned int cpt::string::count(char c) const
{
	unsigned int total = 0;
	if(this->isEmpty()) {return false; }

	for(unsigned int i=0; i<this->_size; i++) 
	{ if(this->_data[i] == c) { total++; } }

	return total;
}


//------------------------------------------------------------------------------
//															public : convert
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	generates a substring from index 'start' to index 'end'
//	'start' and 'end' are inclusive
//------------------------------------------------------------------------------
cpt::string cpt::string::substr (unsigned int start, unsigned int end) const
{
	if(this->isEmpty()) { return *this; }
	
	if (start==end) { return cpt::string(this->_data[start]); }
	
	if(end >= this->_size) { end = this->_size -1; }
	if(start >= end) { start = 0; }

	cpt::string sub;

	for(unsigned int i=0; i<(end-start +1); i++) { sub += this->_data[start +i]; }
	return sub;
}

//------------------------------------------------------------------------------
//	converts all characters to lower case
//------------------------------------------------------------------------------
cpt::string cpt::string::toLower() const
{
	if(this->isEmpty()) return *this;
	
	cpt::string str(*this);

	for(unsigned int i=0; i<str.size(); i++) 
	{
		if(str[i] >= 'A' && str[i] <= 'Z') { str[i] += 32; }
	}

	return str;
}

//------------------------------------------------------------------------------
//	converts all characters to upper case
//------------------------------------------------------------------------------
cpt::string cpt::string::toUpper() const
{
	if(this->isEmpty()) return *this;
	
	cpt::string str(*this);

	for(unsigned int i=0; i<str.size(); i++) 
	{ 
		if(str[i] >= 'a' && str[i] <= 'z') { str[i] -= 32; }
	}

	return str;
}

//------------------------------------------------------------------------------
//	returns a clone of the string
//------------------------------------------------------------------------------
cpt::string cpt::string::clone() const
{
	return cpt::string(*this);
}

//------------------------------------------------------------------------------
//	filters string from alpha-numeric characters
//------------------------------------------------------------------------------
cpt::string cpt::string::filter() const
{
	cpt::string str(*this);
	
	while(!cpt::isAlpha(str[0])) 
	{
		if(str.size()==1) { str.clear(); return str; }
		str = str.substr(1, str.size()-1); 
	}		
	
	while(!cpt::isAlpha(str[str.size()-1]))
	{ 
		if(str.size()==1) { str.clear(); return str; }
		str = str.substr(0, str.size()-2); 
	}
	
	return str;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
cpt::string cpt::string::trim() const
{
	cpt::string str(*this);
	
	while(!cpt::isAlpha(str[0])) 
	{ str = str.substr(1, str.size()-1); } 
	
	while(str[str.size()-1]!=')')
	{ str = str.substr(0, str.size()-2); }
	
	return str;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
cpt::string cpt::string::extractHTML() const
{
	cpt::string str(*this);
	cpt::string link;
	
	if (this->isEmpty()) { link.clear();  return link; }
	
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	
	if(!str.find('.', i)) { link.clear(); return link; }
	
	for(unsigned int w=i; w>=0; w--)
	{
		if(str[w]=='\\' || str[w]=='/' || str[w]=='"')
		{
			j = w+1;
			break;
		}
	}
	
	if(j==0) { link.clear(); return link; }
	
	for(unsigned int w=i; w<str.size(); w++)
	{
		if(str[w]=='"')
		{
			k = w-1;
			break;
		}
	}
	
	if(k==str.size()-1) { link.clear(); return link; }
	
	link = str.substr(j, k);
	return link;
	
}

//------------------------------------------------------------------------------
//														public : operators[]
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 	1 operator[] : returns a reference to the character at a specific position
//------------------------------------------------------------------------------
char & cpt::string::operator[] (unsigned int i)
{
	if(i >= this->_size) { return this->_data[this->_size]; }
	return this->_data[i];
}

//------------------------------------------------------------------------------
// 	2 operator[] : returns a reference to the character at a specific position
//------------------------------------------------------------------------------
const char & cpt::string::operator[] (unsigned int i) const
{
	if(i >= this->_size) { return this->_data[this->_size]; }
	return this->_data[i];
}


//------------------------------------------------------------------------------
//														public : operators+
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	1 operator+ : default
//------------------------------------------------------------------------------
cpt::string cpt::string::operator+ (const cpt::string & str) const
{
	cpt::string x(*this);
	x += str;
	return x;
}

//------------------------------------------------------------------------------
//	2 operator+ : c-string
//------------------------------------------------------------------------------
cpt::string cpt::string::operator+ (const char * str) const
{
	cpt::string x(*this);
	x += str;
	return x;
}

//------------------------------------------------------------------------------
//	3 operator+ : character
//------------------------------------------------------------------------------
cpt::string cpt::string::operator+ (char c) const
{
	cpt::string x(*this);
	x += c;
	return x;
}


//------------------------------------------------------------------------------
//														public : operators=
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	1 operator= : default
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator= (const cpt::string & str)
{
	this->clear();
	
	if(str.isEmpty()) { return *this; }
	
	this->_size = str.size();
	this->_data = new char [this->_size +1];
	
	for(unsigned int i=0; i<this->_size; i++) { this->_data[i] = str[i]; }
	this->_data[this->_size] = '\0';
	
	return *this;
}

//------------------------------------------------------------------------------
//	2 operator= : c-string
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator= (const char * str)
{
	this->clear();

	unsigned int sz;
	for(sz=0; str[sz]!='\0'; sz++);
	
	if(sz==0) { return *this;}
	
	this->_size = sz;
	this->_data = new char [this->_size +1];
	
	for(unsigned int i=0; i<sz; i++) { this->_data[i] = str[i]; }
	this->_data[this->_size] = '\0';
	
	return *this;
}

//------------------------------------------------------------------------------
//	3 operator= : character
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator= (char c)
{
	this->clear();
	
	this->_size = 1;
	this->_data = new char[this->_size +1];
	
	this->_data[0] = c;
	this->_data[this->_size] = '\0';
	
	return *this;
}


//------------------------------------------------------------------------------
//														public : operators+=
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	1 operator+= : default
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator+= (const cpt::string & str)
{
	cpt::string x(*this);
	this->clear();
	
	this->_size = x.size() + str.size();
	this->_data = new char[this->_size +1];
	
	for(unsigned int i=0; i<x.size(); i++) { this->_data[i] = x[i]; }
	for(unsigned int i=0; i<str.size(); i++) { this->_data[x.size() +i] = str[i]; }
	
	this->_data[this->_size] = '\0';
	
	return *this;
}

//------------------------------------------------------------------------------
//	2 operator+= : c-string
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator+= (const char * str)
{
	cpt::string x(*this);
	this->clear();
	
	unsigned int sz;
	for(sz=0; str[sz]!='\0'; sz++);
	
	this->_size = x.size() + sz;
	this->_data = new char[this->_size +1];
	
	for(unsigned int i=0; i<x.size(); i++) { this->_data[i] = x[i]; }
	for(unsigned int i=0; i<sz; i++) { this->_data[x.size() +i] = str[i]; }
	
	this->_data[this->_size] = '\0';

	return *this;
}

//------------------------------------------------------------------------------
//	3 operator+= : character
//------------------------------------------------------------------------------
cpt::string & cpt::string::operator+= (char c)
{
	cpt::string x(*this);
	this->clear();
	
	this->_size = x.size() +1;
	this->_data = new char[this->_size +1];
	
	for(unsigned int i=0; i<x.size(); i++) { this->_data[i] = x[i]; }
	this->_data[x.size()] = c;
	
	this->_data[this->_size] = '\0';
	
	return *this;
}


//------------------------------------------------------------------------------
//															public : compare
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	1 operator> : default
//------------------------------------------------------------------------------
bool cpt::string::operator> (const cpt::string & str) const
{
	if(std::strcmp(this->c_str(), str.c_str()) > 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	2 operator> : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator> (const char * str) const
{
	if(std::strcmp(this->c_str(), str) > 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	3 operator> : character
//------------------------------------------------------------------------------
bool cpt::string::operator> (char c) const
{
	if(std::strcmp(this->c_str(), cpt::string(c).c_str()) > 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	1 operator< : default
//------------------------------------------------------------------------------
bool cpt::string::operator< (const cpt::string & str) const
{
	if(std::strcmp(this->c_str(), str.c_str()) < 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	2 operator< : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator< (const char * str) const
{
	if(std::strcmp(this->c_str(), str) < 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	3 operator< : character
//------------------------------------------------------------------------------
bool cpt::string::operator< (char c) const
{
	if(std::strcmp(this->c_str(), cpt::string(c).c_str()) < 0) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	1 operator>= : default
//------------------------------------------------------------------------------
bool cpt::string::operator>= (const cpt::string & str) const
{
	if(std::strcmp(this->c_str(), str.c_str()) > 0) { return true; }
	if(this->isEqualTo(str, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	2 operator>= : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator>= (const char * str) const
{
	if(std::strcmp(this->c_str(), str) > 0) { return true; }
	if(this->isEqualTo(str, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	3 operator>= : character
//------------------------------------------------------------------------------
bool cpt::string::operator>= (char c) const
{
	if(std::strcmp(this->c_str(), cpt::string(c).c_str()) > 0) { return true; }
	if(this->isEqualTo(c, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	1 operator<= : default
//------------------------------------------------------------------------------
bool cpt::string::operator<= (const cpt::string & str) const
{
	if(std::strcmp(this->c_str(), str.c_str()) < 0) { return true; }
	if(this->isEqualTo(str, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	2 operator<= : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator<= (const char * str) const
{
	if(std::strcmp(this->c_str(), str) < 0) { return true; }
	if(this->isEqualTo(str, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	3 operator<= : character
//------------------------------------------------------------------------------
bool cpt::string::operator<= (char c) const
{
	if(std::strcmp(this->c_str(), cpt::string(c).c_str()) < 0) { return true; }
	if(this->isEqualTo(c, true)) { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	1 operator== : default
//------------------------------------------------------------------------------
bool cpt::string::operator== (const cpt::string & str) const
{
	return this->isEqualTo(str, true);
}

//------------------------------------------------------------------------------
//	2 operator== : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator== (const char * str) const
{
	return this->isEqualTo(str, true);
}

//------------------------------------------------------------------------------
//	3 operator== : character
//------------------------------------------------------------------------------
bool cpt::string::operator== (char c) const
{
	return this->isEqualTo(c, true);
}

//------------------------------------------------------------------------------
//	1 operator!= : default
//------------------------------------------------------------------------------
bool cpt::string::operator!= (const cpt::string & str) const
{
	return !(this->isEqualTo(str, true));
}

//------------------------------------------------------------------------------
//	2 operator!= : c-string
//------------------------------------------------------------------------------
bool cpt::string::operator!= (const char * str) const
{
	return !(this->isEqualTo(str, true));
}

//------------------------------------------------------------------------------
//	3 operator!= : character
//------------------------------------------------------------------------------
bool cpt::string::operator!= (char c) const
{
	return !(this->isEqualTo(c, true));
}

//------------------------------------------------------------------------------
//	1 isEqualTo : returns TRUE if the 2 string match
//------------------------------------------------------------------------------
bool cpt::string::isEqualTo(const cpt::string & str, bool case_sensitive) const
{
	if(this->_size != str.size()) { return false; }

	if(case_sensitive)
	{
		for(unsigned int i=0; i<this->_size; i++) 
		{ if(this->_data[i] != str[i]) { return false; } }
		
		return true;
	}

	cpt::string x = this->toLower();
	cpt::string y = str.toLower();

	for(unsigned int i=0; i<x.size(); i++) 
	{ if(x[i] != y[i]) { return false; } }
	
	return true;
}

//------------------------------------------------------------------------------
//	2 isEqualTo : returns TRUE if the 2 string match
//------------------------------------------------------------------------------
bool cpt::string::isEqualTo(const char * c_str, bool case_sensitive) const
{
	cpt::string str(c_str);
	
	if(this->_size != str.size()) { return false; }

	if(case_sensitive)
	{
		for(unsigned int i=0; i<this->_size; i++) 
		{ if( this->_data[i] != str[i]) { return false; } }
		
		return true;
	}
	
	cpt::string x = this->toLower();
	cpt::string y = str.toLower();

	for(unsigned int i=0; i<x.size(); i++) 
	{ if(x[i] != y[i]) { return false; } }
	
	return true;
}

//------------------------------------------------------------------------------
//	2 isEqualTo : returns TRUE if the 2 string match
//------------------------------------------------------------------------------
bool cpt::string::isEqualTo(char c, bool case_sensitive) const
{
	if(this->_size != 1) { return false; }

	cpt::string str(c);

	if(case_sensitive)
	{
		for(unsigned int i=0; i<this->_size; i++) 
		{ if( this->_data[i] != str[i]) { return false; } }
		
		return true;
	}
	
	cpt::string x = this->toLower();
	cpt::string y = str.toLower();

	for(unsigned int i=0; i<x.size(); i++) 
	{ if(x[i] != y[i]) { return false; } }
	
	return true;
}


//------------------------------------------------------------------------------
//															public : print
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	prints the string
//------------------------------------------------------------------------------
void cpt::string::print(std::ostream & out, const char * pre, const char * post) const
{
	if(pre != 0) { out << pre; }
	out << this->c_str();
	if(post != 0) { out << post; }
}

//------------------------------------------------------------------------------
//	std::cout
//------------------------------------------------------------------------------
std::ostream & cpt::operator<< (std::ostream & out, cpt::string & str)
{
	out << str.c_str();
	return out;
}


//------------------------------------------------------------------------------
//											helper functions : char check
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	returns TRUE if alphanumeric
//------------------------------------------------------------------------------
bool cpt::isAlphaNum(char c)
{
	if(c >= '0' && c <= '9') { return true; }
	if(c >= 'A' && c <= 'Z') { return true; }
	if(c >= 'a' && c <= 'z') { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	returns TRUE if alpha
//------------------------------------------------------------------------------
bool cpt::isAlpha(char c)
{
	if(c >= 'A' && c <= 'Z') { return true; }
	if(c >= 'a' && c <= 'z') { return true; }
	return false;
}

//------------------------------------------------------------------------------
//	returns TRUE if number
//------------------------------------------------------------------------------
bool cpt::isDigit(char c)
{
	if(c >= '0' && c <= '9') { return true; }
	return false;
}


//------------------------------------------------------------------------------
//											helper functions : char convert
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	converts number to string
//------------------------------------------------------------------------------
cpt::string cpt::intToString (int num)
{
	std::ostringstream ss;
	ss << num;
	return cpt::string(ss.str().c_str());
}

//------------------------------------------------------------------------------
//	converts number to string
//------------------------------------------------------------------------------
cpt::string cpt::uintToString (unsigned int num)
{
	std::ostringstream ss;
	ss << num;
	return cpt::string(ss.str().c_str());
}

#endif