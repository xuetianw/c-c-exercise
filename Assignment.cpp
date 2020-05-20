#include <iostream>
using namespace std;

class CMPT135_String
{
private:
	char *buffer;	//This will be the dynamic array to hold the characters
public:
	//static member function to compute the length of null terminated char arrays
	static int cstrlen(const char *cStr); 

	//Constructors
	CMPT135_String();
	CMPT135_String(const char &c);
	CMPT135_String(const char *cStr); //*cStr is a null terminated char array
	CMPT135_String(const CMPT135_String &s);

	//Destructor
	~CMPT135_String();

	//Assignment operators
	CMPT135_String& operator = (const CMPT135_String &s);
	CMPT135_String& operator = (const char &c);
	CMPT135_String& operator = (const char *cStr); //*cStr is a null terminated char array

	//Getter member functions
	int getLength() const;
	char& operator[](const int &index) const;

	//Setter member functions
	void append(const CMPT135_String &s);
	void append(const char &c);
	void append(const char *cStr); //*cStr is a null terminated char array

	//Other member functions
	int findCharIndex(const char &c) const;
	int reverseFindCharIndex(const char &c) const;
	CMPT135_String getSubString(const int &startIndex, const int &len) const;
	bool isSubString(const CMPT135_String &s) const;
	bool isSubString(const char *cStr) const; //*cStr is a null terminated char array
	void reverse();
	int countChar(const char c);
	void removeChar(const char &c);
	void replaceChar(const char &c1, const char &c2);

	//Operator member functions
	CMPT135_String operator + (const CMPT135_String &s) const;
	CMPT135_String operator + (const char *cStr) const; //*cStr is a null terminated char array
	CMPT135_String operator + (const char &c) const;
	CMPT135_String& operator += (const CMPT135_String &s);
	CMPT135_String& operator += (const char *cStr); //*cStr is a null terminated char array
	CMPT135_String& operator += (const char &c);
	bool operator == (const CMPT135_String &s) const;
	bool operator == (const char *cStr) const; //*cStr is a null terminated char array
	bool operator != (const CMPT135_String &s) const;
	bool operator != (const char *cStr) const; //*cStr is a null terminated char array
	bool operator < (const CMPT135_String &s) const;
	bool operator < (const char *cStr) const; //*cStr is a null terminated char array
	bool operator > (const CMPT135_String &s) const;
	bool operator > (const char *cStr) const; //*cStr is a null terminated char array
	bool operator <= (const CMPT135_String &s) const;
	bool operator <= (const char *cStr) const; //*cStr is a null terminated char array
	bool operator >= (const CMPT135_String &s) const;
	bool operator >= (const char *cStr) const; //*cStr is a null terminated char array

	//Friend Functions (for operators)
	friend CMPT135_String operator + (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend CMPT135_String operator + (const char &c, const CMPT135_String &s);
	friend bool operator == (const char *cStr, const CMPT135_String &s); //*cStr a null terminated char array
	friend bool operator != (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator < (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator > (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator <= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator >= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend ostream& operator << (ostream &outputStream, const CMPT135_String &s);
	friend istream& operator >> (istream &inputStream, CMPT135_String &s);
};


/*
	provided by instructor
*/
int CMPT135_String::cstrlen(const char *cStr)
{
	if(cStr == nullptr)
		return 0;
	else
	{
		int len = 0;
		while(cStr[len] != '\0')
			len++;
		return len;
	}
}

//Constructors
/*
	provided by instructor
*/
CMPT135_String::CMPT135_String()
{
	buffer = nullptr;
}

CMPT135_String::CMPT135_String(const char &c)
{
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';
}

/*
	provided by instructor
*/
CMPT135_String::CMPT135_String(const char *cStr) //*cStr is a null terminated char array
{
/*
This function constructs a non-default CMPT135_String that contains all the printable
characters of the argument and a null character at the end.
*/
	int length = cstrlen(cStr);
	buffer = new char[length + 1];
	for(int i = 0;i < length; i++) {
		buffer[i]=cStr[i];
	}
	buffer[length]='\0';
}

CMPT135_String::CMPT135_String(const CMPT135_String &s)
{
	if(cstrlen(s.buffer)>0) {
		this->buffer = new char[cstrlen(s.buffer)+1];
		for(int i =0; i < cstrlen(s.buffer); i++) {
			this->buffer[i] = s.buffer[i];
		}
		this->buffer[cstrlen(s.buffer) + 1]='\0';
	} else {
		this->buffer = nullptr;
	}
}

//Destructor
/*
	provided by instructor
*/
CMPT135_String::~CMPT135_String()
{
	if (buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}

//Assignment operators
CMPT135_String& CMPT135_String::operator=(const CMPT135_String &s)
{
	int length = cstrlen(s.buffer);
	this->buffer = new char[length + 1];
	for(int i =0; i < length; i++){
		this->buffer[i] = s[i];
	}
	this->buffer[length] = '\0';
	return *this;
}

CMPT135_String& CMPT135_String::operator=(const char& c)
{
	if(this->buffer != nullptr) {
		delete[] buffer;
		buffer = nullptr;
	}
	this->buffer= new char[1];
	this->buffer[0] = c;
	this->buffer[1]='\0';
	return *this;
}

CMPT135_String& CMPT135_String::operator = (const char *cStr)
{
	if(this->buffer != nullptr)
	{
		delete[] (this->buffer);
		buffer = nullptr;
	}
	int len = cstrlen(cStr);
	this->buffer = new char[len+1];
	for(int i = 0; i< len; i++) {
		this->buffer[i] = cStr[i];
	}
	this->buffer[len]='\0';
	return *this;
}

/*
	provided by instructor
*/
//Getter member functions
int CMPT135_String::getLength() const
{
	return CMPT135_String::cstrlen(buffer);
}


char& CMPT135_String::operator[](const int &index)const
{
	if ((index >= 0) && (index < this->getLength())) {
		return this->buffer[index];
	}
	else {
		cout<<"error out of bounds"<<endl;
		system("exit");
	}
}



void CMPT135_String:: append(const CMPT135_String &s)
{
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(s.buffer);
	if(len1 == 0) {
		this->buffer= new char[len2];
		this->buffer= s.buffer;
	}
	else {
		int tlen = len1 + len2;
		char *temp = new char [tlen];
		for(int i =0; i < len1; i++) {
			temp[i] = this->buffer[i];
		}
		for(int i = len1; i < tlen; i++) {
			temp[i] = s.buffer[i];
		}

		delete[] (this->buffer) ;
		this->buffer = new char[tlen + 1];
		for(int i = 0; i < tlen; i++) {
			this->buffer[i] = temp[i];
		}
		this->buffer[tlen]='\0';
	}

}
void CMPT135_String::append(const char &c)
{
	int len=cstrlen(this->buffer);
	if(len == 0) {
		this->buffer = new char[1];
		this->buffer[0] = c;
	}
	else {
		char* temp= new char [len + 2];
		for(int i = 0; i < len; i++) {
			temp[i] = this->buffer[i];
		}
		temp[len] = c;
		temp[len + 1]='\0';
		delete[] (this->buffer);
		this->buffer=new char[len+2];
		buffer = temp;
	}

}
void CMPT135_String::append(const char *cstr) // not correct
{
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(cstr);
	if(len1 == 0) {
		this->buffer = new char[len2 + 1];
		for(int i = 0; i < len2; i++) {
			this->buffer[i] = cstr[i];
		}
		this->buffer[len2]='\0';
	}
	else {
		int tlen = len1 + len2;
		char *temp = new char [tlen];
		for (int i =0; i < len1; i++) {
			temp[i] = this->buffer[i];
		}
		for(int i = len1; i < tlen; i++){
			temp[i] = cstr[i - len1];
		}

		delete[](this -> buffer);
		this->buffer=new char[tlen + 1];
		for(int i= 0; i < tlen; i++) {
			this->buffer[i] = temp[i];
		}
		this->buffer[tlen]='\0';
	}

}
int CMPT135_String::findCharIndex(const char & c)const
{
	int len= cstrlen(this->buffer);
	for(int i = 0; i < len;i++)
	{
		if (this->buffer[i] == c) {
			return i;
		}
	}
	return -1;
}

int CMPT135_String::reverseFindCharIndex(const char & c)const
{
	int len = cstrlen(this->buffer);
	int largest= -1;
	for(int i =0;i < len; i++)
	{
		if(this->buffer[i]==c)
		{
			largest= i;
		}
	}
	return largest;
}


CMPT135_String CMPT135_String::getSubString(const int &startIndex, const int &length) const
{
	int input_length = cstrlen(this->buffer);
	if(startIndex >= input_length) {
		return CMPT135_String('\0');
	} else {
		if (startIndex + length < input_length) {
			char *temp = new char[length + 1];
			for (int i = startIndex; i < startIndex + length; i++) {
				temp[i - startIndex] = this->buffer[i];
			}
			temp[length] = '\0';
			return CMPT135_String(temp);
		} else {
			char *temp = new char[length + 1];
			for (int i = startIndex; i < startIndex + length; i++) {
				temp [i - startIndex] = this->buffer[i];
			}
			temp[length] = '\0';
			return CMPT135_String(temp);
		}
	}

}
bool CheckSubstring(std::string sub_string, std::string big_string){
	if(sub_string.size() > big_string.size())
		return false;

	for (int i = 0; i < big_string.size(); i++){
		int j = 0;
		// If the first characters match
		if(big_string[i] == sub_string[j]){
			int k = i;
			while (big_string[i] == sub_string[j] && j < sub_string.size()){
				j++;
				i++;
			}
			if (j == sub_string.size())
				return true;
			else // Re-initialize i to its original value
				i = k;
		}
	}
	return false;
}

bool CMPT135_String::isSubString(const CMPT135_String &s) const
{
	/*
This function tests if the calling object is a substring of the argument s.
If it is it returns true otherwise it returns false
*/
	if(getLength() > s.getLength())
		return false;

	for (int i = 0; i < s.getLength(); i++){
		int j = 0;
		// If the first characters match
		if(s[i] == buffer[j]){
			int k = i;
			while (j < getLength() && i < s.getLength() && s[i] == buffer[j] ){
				j++;
				i++;
			}
			if (j == getLength())
				return true;
			else // Re-initialize i to its original value
				i = k;
		}
	}
	return false;

//	return CheckSubstring((this->buffer), string(s.buffer));
}



bool CMPT135_String::isSubString(const char *cStr) const //*cStr is a null terminated char array
{
	/*
This function tests if the calling object is a substring of the argument null terminated
character
array. If it is it returns true otherwise it returns false
*/

	if(getLength() > cstrlen(cStr))
		return false;

	for (int i = 0; i < cstrlen(cStr); i++){
		int j = 0;
		// If the first characters match
		if(cStr[i] == buffer[j]){
			int k = i;
			while (j < getLength() && i < cstrlen(cStr) && cStr[i] == buffer[j] ){
				j++;
				i++;
			}
			if (j == getLength())
				return true;
			else // Re-initialize i to its original value
				i = k;
		}
	}
	return false;
//	return (CheckSubstring(string(this->buffer), string(cStr)));

}

void CMPT135_String::reverse()
{
	int n = this->getLength();
	for (int i = 0; i < n / 2; i++) {
		swap(this->buffer[i], this->buffer[n - i - 1]);
	}
}

int CMPT135_String::countChar(const char c)
{
	int num = 0;
	for (int i = 0; i < cstrlen(this->buffer); i++) {
		if (this -> buffer [i] == c) {
			num ++;
		}
	}
	return num;
}

void CMPT135_String::removeChar(const char &c)
{
	int numbOfOccurence = countChar(c);
	int newlength = this->getLength() - numbOfOccurence;
	char *temp = new char [newlength];
	int occurence = 0;
	for (int i = 0; i < cstrlen(this->buffer); i++) {
		if (this -> buffer [i] != c) {
			temp[i- occurence] = buffer[i];
		} else {
			occurence ++;
		}
	}
	temp[newlength] = '\0';
	this->buffer = temp;
}

void CMPT135_String::replaceChar(const char &c1, const char &c2)
{
/*
This function replaces every occurence of the argument character c1 in the calling object by
the argument character c2
*/
	for (int i = 0; i < cstrlen(this->buffer); i++) {
		if (this -> buffer [i] == c1) {
			this -> buffer [i] = c2;
		}
	}
}

//Operator member functions
CMPT135_String CMPT135_String::operator + (const CMPT135_String &s) const
{
/*
This function returns a new CMPT135_String object made up all the characters of the
calling object followed by the characters of the argument s
*/
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(s.buffer);
	int tlen = len1 + len2;
	char *temp = new char [len1 + len2 + 1];
	for(int i =0; i < len1; i++) {
		temp[i] = this->buffer[i];
	}
	for(int i = len1; i < tlen; i++) {
		temp[i] = s.buffer[i];
	}
	temp[tlen]='\0';
	return *this;
}


CMPT135_String CMPT135_String::operator + (const char *cStr) const //*cStr is a null terminated char array
{
	/*
	This function returns a new CMPT135_String object made up all the characters of the
	calling object followed by the characters of the null terminated character array argument cStr
	*/
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(cStr);
	int tlen = len1 + len2;
	char *temp = new char [len1 + len2 + 1];
	for(int i =0; i < len1; i++) {
		temp[i] = this->buffer[i];
	}
	for(int i = len1; i < tlen; i++) {
		temp[i] = cStr[i - len1];
	}
	temp[tlen]='\0';
	return CMPT135_String(temp);
}


CMPT135_String CMPT135_String::operator + (const char &c) const
{
/*
This function returns a new CMPT135_String object made up all the characters of the
calling object followed by the character argument c
*/

	int len1 = cstrlen(this->buffer);
	int tlen = len1 + 1;
	char *temp = new char [tlen + 1];
	for(int i =0; i < len1; i++) {
		temp[i] = this->buffer[i];
	}
	for(int i = len1; i < tlen; i++) {
		temp[i] = c;
	}
	temp[tlen]='\0';
	return CMPT135_String(temp);
}

CMPT135_String& CMPT135_String::operator += (const CMPT135_String &s)
{
/*
This function appends a copy of the characters of s to the calling object and then
returns the calling object
*/
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(s.buffer);
	if(len1 == 0) {
		this->buffer= new char[len2];
		this->buffer= s.buffer;
	}
	else {
		int tlen = len1 + len2;
		char *temp = new char [tlen];
		for(int i =0; i < len1; i++) {
			temp[i] = this->buffer[i];
		}
		for(int i = len1; i < tlen; i++) {
			temp[i] = s.buffer[i];
		}

		delete[] (this->buffer) ;
		this->buffer = new char[tlen + 1];
		for(int i = 0; i < tlen; i++) {
			this->buffer[i] = temp[i];
		}
		this->buffer[tlen]='\0';
	}
	return *this;
}

CMPT135_String& CMPT135_String::operator += (const char *cStr) //*cStr is a null terminated char array
{
/*
This function appends a copy of the characters of the null terminated character array cStr
to the calling object and then returns the calling object
*/
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(cStr);
	int tlen = len1 + len2;
	char *temp = new char [len1 + len2 + 1];
	for(int i =0; i < len1; i++) {
		temp[i] = this->buffer[i];
	}
	for(int i = len1; i < tlen; i++) {
		temp[i] = cStr[i - len1];
	}
	temp[tlen]='\0';
	this->buffer = temp;
	return *this;
}

CMPT135_String& CMPT135_String::operator += (const char &c)
{
/*
This function appends a copy of the character c to the calling object and then
returns the calling object
*/
	int len1 = cstrlen(this->buffer);
	int tlen = len1 + 1;
	char *temp = new char [tlen + 1];
	for(int i =0; i < len1; i++) {
		temp[i] = this->buffer[i];
	}
	temp[len1] = c;
	temp[tlen]='\0';
	this->buffer = temp;
	return *this;
}

bool CMPT135_String::operator == (const CMPT135_String &s) const
{
/*
This function tests if the calling object is equal to the argument s
NOTE:- Two CMPT135_String are equal if they have the same length and characters of the
calling object are equal to the characters of the argument s at corresponding indexes.
*/
	if (this->getLength() != s.getLength() ) {
		return false;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] != s.buffer[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator == (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is equal to the null terminated character array cStr
*/
	if (this->getLength() != cstrlen(cStr)) {
		return false;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] != cStr[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator != (const CMPT135_String &s) const
{
/*
This function tests if the calling object is not equal to the argument s
*/
	if (this->getLength() != s.getLength() ) {
		return true;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] != s.buffer[i]) {
				return true;
			}
		}
		return false;
	}
}

bool CMPT135_String::operator != (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is not equal to the null terminated character array
cStr
*/
	if (this->getLength() != cstrlen(cStr) ) {
		return true;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] != cStr[i]) {
				return true;
			}
		}
		return false;
	}
}

bool CMPT135_String::operator < (const CMPT135_String &s) const
{
/*
This function tests if the calling object is less than the argument s
NOTE:- Given two CMPT135_String objects s1 and s2, we say s1 < s2 if there
exists a valid index i such that s1[i] < s2[i]. If no such an index exists,
then we still say s1 < s2 only if length of s1 is less than length of s2.
Otherwise s1 is not less than s2.
*/

	if (this->getLength() != s.getLength() ) {
		return false;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] >= s.buffer[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator < (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is less than the null terminated character array cStr
*/
	if (this->getLength() != cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] >= cStr[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator > (const CMPT135_String &s) const
{
/*
This function tests if the calling object is greater than the argument s
*/
	if (this->getLength() != s.getLength()) {
		return (s.getLength() == 0) && (this->getLength() != 0);
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] <= s.buffer[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator > (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is greater than the null terminated character array
cStr
*/
	if (this->getLength() != cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] <= cStr[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator <= (const CMPT135_String &s) const
{
/*
This function tests if the calling object is less than or equal to the argument s
*/
	if (this->getLength() != s.getLength()) {
		return false;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] > s.buffer[i]) {
				return false;
			}
		}
		return true;
	}
}


bool CMPT135_String::operator <= (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is less than or equal to the null terminated character
array cStr
*/
	if (this->getLength() != cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] > cStr[i]) {
				return false;
			}
		}
		return true;
	}
}


bool CMPT135_String::operator >= (const CMPT135_String &s) const
{
/*
This function tests if the calling object is greater than or equal to the argument s
*/

	if (this->getLength() != s.getLength()) {
		return (s.getLength() == 0) && (this->getLength() != 0);
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (this->buffer[i] < s.buffer[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT135_String::operator >= (const char *cStr) const //*cStr is a null terminated char array
{
/*
This function tests if the calling object is greater than or equal to the null terminated
character array cStr
*/
	if (this->getLength() != cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < cstrlen(cStr); i++) {
			if (this->buffer[i] < cStr[i]) {
				return false;
			}
		}
		return true;
	}
}


//Friend Functions (for operators)
CMPT135_String operator + (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function returns a new CMPT135_String object whose characters are those of the null
terminated character array argument cStr followed by those of s
*/
	int len1 = s.getLength();
	int len2 = CMPT135_String::cstrlen(cStr);
	int tlen = len1 + len2;
	char *temp = new char [len1 + len2 + 1];
	for(int i = 0; i < len2; i++) {
		temp[i] = cStr[i];
	}
	for(int i = len2; i < tlen; i++) {
		temp[i] = s.buffer[i - len2];
	}
	temp[tlen]='\0';
	return CMPT135_String(temp);
}

CMPT135_String operator + (const char &c, const CMPT135_String &s)
{
/*
This function returns a new CMPT135_String object whose characters are that of character
argument c followed by those of s
*/
	int len1 = s.getLength();
	int tlen = len1 + 1;
	char *temp = new char [tlen + 1];
	temp[0] = c;
	for(int i = 1; i < tlen; i++) {
		temp[i] = s.buffer[i];
	}
	temp[tlen]='\0';
	return CMPT135_String(temp);
}

bool operator == (const char *cStr, const CMPT135_String &s) //*cStr a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is equal to s
*/
	int len = CMPT135_String::cstrlen(cStr);
	if(len != s.getLength()) {
		return false;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (cStr[i] != s.buffer[i]) {
				return false;
			}
		}
		return false;
	}

}

bool operator != (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is not equal to s
*/
	int len = CMPT135_String::cstrlen(cStr);
	if(len != s.getLength()) {
		return true;
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (cStr[i] != s.buffer[i]) {
				return true;
			}
		}
		return false;
	}
}

bool operator < (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is less than s
*/
	if (s.getLength() != CMPT135_String::cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < CMPT135_String::cstrlen(cStr); i++) {
			if (s.buffer[i] >= cStr[i]) {
				return false;
			}
		}
		return true;
	}
}


bool operator > (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is greater than s
*/
	if (s.getLength() != CMPT135_String::cstrlen(cStr) ) {
		return (s.getLength() == 0) && (CMPT135_String::cstrlen(cStr) != 0);
	} else {
		for (int i = 0; i < CMPT135_String::cstrlen(cStr); i++) {
			if (s.buffer[i] <= cStr[i]) {
				return false;
			}
		}
		return true;
	}
}
bool operator <= (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is less than or equal
to s
*/
	if (s.getLength() != CMPT135_String::cstrlen(cStr) ) {
		return false;
	} else {
		for (int i = 0; i < CMPT135_String::cstrlen(cStr); i++) {
			if (s.buffer[i] > cStr[i]) {
				return false;
			}
		}
		return true;
	}
}
bool operator >= (const char *cStr, const CMPT135_String &s) //*cStr is a null terminated char array
{
/*
This function tests if the null terminated character array argument cStr is greater than or
equal to s
*/
	if (s.getLength() != CMPT135_String::cstrlen(cStr) ) {
		return (s.getLength() == 0) && (CMPT135_String::cstrlen(cStr) != 0);
	} else {
		for (int i = 0; i < CMPT135_String::cstrlen(cStr); i++) {
			if (s.buffer[i] < cStr[i]) {
				return false;
			}
		}
		return true;
	}
}

ostream& operator << (ostream &outputStream, const CMPT135_String &s)
{
/*
This function prints the characters in the dynamic array member variable buffer.
This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
*/
	for (int i = 0; i < s.getLength(); i++)
		outputStream << s.buffer[i];
	return outputStream;
}
istream& operator >> (istream &inputStream, CMPT135_String &s)
{
/*
This function is designed to read ANY number of characters from the user.
Reading will stop when the user presses the Enter Key.
In order to achieve this, we will read one character at a time
until end of line character ('\n') is read.
The trouble will be where to store unknown number of characters input.
For this, we will create a char array (named buffer) of length 5.
If the array gets full as the user types characters from the keyboard, then
we will expand the size of buffer array to twice its size and continue reading.
We will keep on expanding it every time it gets full.
Finally, we will copy all characters read to s object. We will also do some
memory clean up of unnecessary allocated memory.
This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
*/
	int bufferCurrentLength = 5;
	char *buffer = new char[bufferCurrentLength];
	int length = 0;
	char c;
	while (true)
	{
		inputStream.get(c);
		if (c == '\n')
			break;
//Check if the buffer is full. If yes expand it in order
//to make room for the new character to be appended.
		if (length == bufferCurrentLength)
		{
//Allocate expanded memory space
			char *temp = new char[2*bufferCurrentLength];
			for (int i = 0; i < bufferCurrentLength; i++)
				temp[i] = buffer[i];
//Delete current buffer
			delete[] buffer;
//Point buffer to temp
			buffer = temp;
//Adjust the size of the current buffer
			bufferCurrentLength *= 2;
		}
		buffer[length++] = c;
	}
//Destruct s
	s.~CMPT135_String();
	//Now allocate the exact memory size for s and copy characters of buffer to s
	if (length > 0)
	{
		s.buffer = new char[length + 1];
		for (int i = 0; i < length; i++)
			s.buffer[i] = buffer[i];
		s.buffer[length] = '\0';
	}
//Finally delete the allocated memory for buffer
	delete[] buffer;
//Return the input stream
	return inputStream;
}

int main()
{
	//Test the cstrlen static member function'
	cout << "The length of \"Yonas\" is " << CMPT135_String::cstrlen("Yonas") << endl;
	cout << "The length of \"\" is " << CMPT135_String::cstrlen("") << endl;
	cout << "The length of nullptr is " << CMPT135_String::cstrlen(nullptr) << endl;
	cout << endl;

	//Test default constructor and getLength member functions
	CMPT135_String s1;
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	cout << endl;


	//Test non-default constructor and getLength member functions
	CMPT135_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.getLength() << endl;
	cout << endl;

	//Test non-default constructor and getLength member functions
	CMPT135_String s3 = "CMPT 135";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test copy constructor and getLength member functions
	CMPT135_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test destructor and getLength member functions
	s4.~CMPT135_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test indexing operator
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'u';
	cout << "s4[2] is " << s4[2] << endl;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test append function and getLength member functions
	s1.append(s4);
	cout << "s1 is \"" << s4 << "\" and its length is " << s1.getLength() << endl;

	//Test append function and getLength member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test append function and getLength member functions
	s3.append("201901");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test findCharIndex function
	char ch = '1';
	int k = s3.findCharIndex(ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.findCharIndex('m');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test reverseFindCharIndex function
	ch = '1';
	k = s3.reverseFindCharIndex(ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.reverseFindCharIndex('m');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test getSubString function
	s1 = s3.getSubString(10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	//Test isSubString function
	if (s1.isSubString(s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902029010190";
	if (s1.isSubString(s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902019010190";
	if (s1.isSubString(x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;

	//Test reverse function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1.reverse();
	cout << "After reversing it, s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	//Test countChar function
	ch = '1';
	k = s1.countChar(ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	//Test the removeChar function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	s1.removeChar(ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	s3.removeChar(ch);
	cout << "\"" << s3 << "\"" << endl;

	//Test replaceChar function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	s2.replaceChar('1', '5');
	cout << s2 << endl;

	//Test + operator
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	//Test += operatror
	s2 = "Test";
	cout << "s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl;
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	//Test relational operators
	s1 = "Test1";
	s2 = "";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	//Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	//Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s2) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s2) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" < s1 is " << ("Test2" < s2) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s2) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s2) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" >= s1 is " << ("Test2" >= s2) << endl;

	//Test input stream operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;

//	system("pause");
	return 0;
}