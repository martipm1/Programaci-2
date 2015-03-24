#ifndef __STRING_H
#define __STRING_H
#include <string.h>
#include <stdarg.h>
#include <wtypes.h>
#include <iostream>

#define TMP_STRING_LENGTH 4096

class ClassString
{
private:

	char* string;
	int length;

public:

	const void Clear();

	const void Alloc(const int);

	int Length();

	const char* getString();

	//Constructors
	ClassString();

	ClassString(const char*, ...);


	//Operators
	bool operator == (const ClassString& s) const;

	bool operator == (const char* s) const;

	const ClassString& operator = (ClassString& s);

	const ClassString& operator = (const char* s);

	bool operator != (const ClassString& s) const;

	bool operator != (const char* s) const;

	ClassString& operator += (const char* s);

	ClassString& operator += (const ClassString& s);

	//Destructor
	~ClassString();

};

#endif __STRING_H