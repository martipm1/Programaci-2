#include "ClassString.h"


//--------------------------------------------------------------
//--------------------CONSTRUCTORS------------------------------
//--------------------------------------------------------------

ClassString::ClassString()
{
	length = 1;
	string = new char[length];
	string[0] = '\0';
}

ClassString::ClassString(const char* _string, ...)
{
	length = 0;
	if (_string != NULL)
	{
		static char buff1[4096];
		va_list args;

		va_start(args, _string);
		int res = vsprintf_s(buff1, 4096, _string, args);
		va_end(args);

		if (res > 0)
		{
			length = res + 1;
			string = new char[length];
			strcpy_s(string, length, buff1);
		}
	}
}

//--------------------------------------------------------------
//--------------------OPERATORS---------------------------------
//--------------------------------------------------------------
bool ClassString::operator == (const ClassString& s) const
{
	return strcmp(s.string, string) == 0;
}

bool ClassString::operator == (const char* s) const
{
	if (s != NULL)
		return strcmp(s, string) == 0;
	return false;
}

const ClassString& ClassString::operator = (ClassString& s)
{
	if (s.Length() + 1 > length)
	{
		delete[] string;
		Alloc(s.Length() + 1);
	}
	else
		Clear();

	strcpy_s(string, length, s.string);

	return(*this);
}

const ClassString& ClassString::operator = (const char* s)
{
	if (s != NULL)
	{
		if (strlen(s) + 1 > length)
		{
			delete[] string;
			Alloc(strlen(s) + 1);
		}
		else
			Clear();
		strcpy_s(string, length, s);
	}
	else
	{
		Clear();
	}
	return(*this);
}

bool ClassString::operator != (const ClassString& s) const
{
	return strcmp(s.string, string) != 0;
}

bool ClassString::operator != (const char* s) const
{
	if (s != NULL)
		return strcmp(s, string) != 0;
	return true;
}

ClassString& ClassString::operator += (const char* s)
{
	if (s != NULL)
	{
		if (length < (strlen(s) + strlen(string)))
		{
			ClassString aux_string;
			strcpy_s(aux_string.string, length, string);
			Alloc((strlen(s) + 1) + strlen(string));
			strcpy_s(string, length, aux_string.string);
			strcat_s(string, length, s);
		}
		else
		{
			strcat_s(string, length, s);
		}
		return (*this);
	}
	else
	{
		return (*this);
	}
}

ClassString& ClassString::operator += (const ClassString& s)
{
	if (length < (strlen(s.string) + strlen(string)))
	{
		ClassString aux_string;
		strcpy_s(aux_string.string, length, string);
		Alloc((strlen(s.string) + 1) + strlen(string));
		strcpy_s(string, length, aux_string.string);
		strcat_s(string, length, s.string);
	}
	else
	{
		strcat_s(string, length, s.string);
	}
	return (*this);
}


//--------------------------------------------------------------
//-----------------------METHODS--------------------------------
//--------------------------------------------------------------
const void ClassString::Clear()
{
	delete[] string;
	string = new char[1];
}

const void ClassString::Alloc(const int i)
{
	length = i;
	string = new char[i];
}

int ClassString::Length()
{
	return strlen(string);
}

char* ClassString::getString()
{
	return string;
}

//--------------------------------------------------------------
//-----------------------DESTRUCTOR-----------------------------
//--------------------------------------------------------------
ClassString::~ClassString()
{
	delete[] string;
}