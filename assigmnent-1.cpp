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

	////Setter member functions
	void append(const CMPT135_String &s);
	void append(const char &c);
	void append(const char *cStr); //*cStr is a null terminated char array

	////Other member functions
	int findCharIndex(const char &c) const;
	int reverseFindCharIndex(const char &c) const;
	CMPT135_String getSubString(const int &startIndex, const int &len) const;
	//bool isSubString(const CMPT135_String &s) const;
	//bool isSubString(const char *cStr) const; //*cStr is a null terminated char array
	//void reverse();
	int countChar(const char c);
	//void removeChar(const char &c);
	//void replaceChar(const char &c1, const char &c2);

	////Operator member functions
	//CMPT135_String operator + (const CMPT135_String &s) const;
	//CMPT135_String operator + (const char *cStr) const; //*cStr is a null terminated char array
	//CMPT135_String operator + (const char &c) const;
	//CMPT135_String& operator += (const CMPT135_String &s);
	//CMPT135_String& operator += (const char *cStr); //*cStr is a null terminated char array
	//CMPT135_String& operator += (const char &c);
	//bool operator == (const CMPT135_String &s) const;
	//bool operator == (const char *cStr) const; //*cStr is a null terminated char array
	//bool operator != (const CMPT135_String &s) const;
	//bool operator != (const char *cStr) const; //*cStr is a null terminated char array
	//bool operator < (const CMPT135_String &s) const;
	//bool operator < (const char *cStr) const; //*cStr is a null terminated char array
	//bool operator > (const CMPT135_String &s) const;
	//bool operator > (const char *cStr) const; //*cStr is a null terminated char array
	//bool operator <= (const CMPT135_String &s) const;
	//bool operator <= (const char *cStr) const; //*cStr is a null terminated char array
	//bool operator >= (const CMPT135_String &s) const;
	//bool operator >= (const char *cStr) const; //*cStr is a null terminated char array

	////Friend Functions (for operators)
	//friend CMPT135_String operator + (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	//friend CMPT135_String operator + (const char &c, const CMPT135_String &s);
	//friend bool operator == (const char *cStr, const CMPT135_String &s); //*cStr a null terminated char array
	//friend bool operator != (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	//friend bool operator < (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	//friend bool operator > (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	//friend bool operator <= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	//friend bool operator >= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend ostream& operator << (ostream &outputStream, const CMPT135_String &s);
	friend istream& operator >> (istream &inputStream, CMPT135_String &s);
};

int CMPT135_String::cstrlen(const char *cStr)
{
	if(cStr == nullptr)
		return 0;
	else
	{
		int len = 0;
		while(cStr[len]!='\0')
			len++;
		return len;
	}
}

CMPT135_String::CMPT135_String()
{
	buffer=nullptr;
}

CMPT135_String::CMPT135_String(const char &c)
{
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0'; 
}

CMPT135_String::CMPT135_String(const char *cStr)
{
	int length =0;
	for(int i = 0;cStr[i]!='\0';i++)
	{
		length++;
	}
	buffer = new char[length+1];
	for(int i = 0;i<length;i++)
	{
		buffer[i]=cStr[i];
	}
	buffer[length]='\0';
}

CMPT135_String::CMPT135_String(const CMPT135_String &s)
{
	if(cstrlen(s.buffer)>0)
	{
		this->buffer=new char[cstrlen(s.buffer)+1];
		for(int i =0;i<cstrlen(s.buffer);i++)
		{
			this->buffer[i]=s.buffer[i];
		}
		this->buffer[cstrlen(s.buffer)]='\0';
	}

}


int CMPT135_String::getLength() const
{
	return CMPT135_String::cstrlen(buffer);
}

CMPT135_String::~CMPT135_String()
{
	if (buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}

CMPT135_String& CMPT135_String::operator=(const CMPT135_String &s)
{
	this->~CMPT135_String();
	int length=cstrlen(s.buffer);
	
	this->buffer = new char[cstrlen(s.buffer)+1];
	for(int i =0;i<length;i++)
	{
		this->buffer[i]=s[i];

	}
	this->buffer[cstrlen(s.buffer)]='\0';
	return *this;
}

CMPT135_String& CMPT135_String::operator=(const char& c)
{
	if(this->buffer!=nullptr)
	{
		delete[] buffer;
	}
	this->buffer= new char[1];
	int len =1;
	this->buffer[0]=c;
	this->buffer[1]='\0';

	return *this;

}

CMPT135_String& CMPT135_String::operator = (const char *cStr)
{
	if(this->buffer!=nullptr)
	{
		delete[]this->buffer;
	}

	int len = cstrlen(cStr);
	this->buffer = new char[len+1];
	for(int i = 0; i< len;i++)
	{
		this->buffer[i]=cStr[i];
	}
	this->buffer[len]='\0';
	return *this;
}

char& CMPT135_String::operator[](const int &index)const
{
	if(index>=0 &&index<this->getLength())
	{
		return this->buffer[index];
	}
	else
	{
		cout<<"error out of bounds"<<endl;
		system("exit");
	}
}

void CMPT135_String:: append(const CMPT135_String &s)
{
	
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(s.buffer);
	if(len1==0)
	{
		delete[]this->buffer;
		this->buffer= new char[len2];
		this->buffer= s.buffer;
	}
	else
	{
	
	int tlen = len1+len2;

	char * temp = new char [len1+len2+1];
	for(int i =0;i<len1;i++)
	{
		temp[i]=this->buffer[i];
	}
	for(int i = len1;i<tlen;i++)
	{
		temp[i]=s.buffer[i];
	}

	delete[]this->buffer;
	this->buffer=new char[tlen];
	for(int i= 0; i<tlen;i++)
	{
		this->buffer[i]=temp[i];
	}
	this->buffer[tlen]='\0';
	}
	
}
void CMPT135_String::append(const char &c)
{
	int len=cstrlen(this->buffer);
	if(len==0)
	{
		delete[]this->buffer;
		this->buffer= new char[1];
		this->buffer[0]=c;
	}
	else
	{
		char* temp= new char [ len+2];
		for(int i = 0; i< len;i++)
		{
			temp[i]=this->buffer[i];
		}
		temp[len]=c;
		temp[len+1]='\0';
		delete[]this->buffer;
		this->buffer=new char[len+2];
		buffer=temp;

	}
	
}
void CMPT135_String::append(const char *cstr) // not correct
{
	int len1 = cstrlen(this->buffer);
	int len2 = cstrlen(cstr);
	if(len1==0)
	{
		delete[]this->buffer;
		this->buffer= new char[len2];
		for(int i = 0;i<len2;i++)
		{
			this->buffer[i]=cstr[i];
		}
		this->buffer[len2]='\0';
	}
	else
	{
	
	int tlen = len1+len2;

	char * temp = new char [tlen+2];
	for(int i =0;i<len1;i++)
	{
		temp[i]=this->buffer[i];
	}
	temp[len1]='\0';
	for(int i = len1+1;i<tlen+2;i++)
	{
		temp[i]=cstr[i];
	}

	delete[]this->buffer;
	this->buffer=new char[tlen];
	for(int i= 0; i<tlen;i++)
	{
		this->buffer[i]=temp[i];
	}
	this->buffer[tlen+1]='\0';
	}
	
}
int CMPT135_String::findCharIndex(const char & c)const
{
	int len= cstrlen(this->buffer);
	for(int i = 0; i< len;i++)
	{
		if(this->buffer[i]==c)
		{
			return i;
		}
	}
	return -1;
}

int CMPT135_String::reverseFindCharIndex(const char & c)const
{
	int len =cstrlen(this->buffer);
	int largest= -1;
	for(int i =0;i<len;i++)
	{
		if(this->buffer[i]==c)
		{
			largest= i;
		}
	}
	return largest;
}

//CMPT135_String CMPT135_String::getSubString(const int &startIndex, const int &len) const
//{
//	CMPT135_String temp;
//	int length = cstrlen(this->buffer);
//	int diff = length - startIndex;
//	if(diff<len)
//	{
//
//		temp.buffer = new char[diff];
//		int length = cstrlen(this->buffer);
//		for(int i = 0, j = 0; i < length;i++)
//		{
//			if(i==startIndex)
//			{
//				temp.buffer[j]=this->buffer[i];
//				j++;
//			
//			}
//		}
//		temp.buffer[diff]='\0';
//	}
//	else 
//	{
//		temp.buffer = new char[len];
//		int length = cstrlen(this->buffer);
//		for(int i = 0, j = 0; i < length;i++)
//		{
//			if(i==startIndex)
//			{
//				temp.buffer[j]=this->buffer[i];
//				j++;
//			
//			}
//		}
//		temp.buffer[len]='\0';
//	}
//	return temp;
//}

int CMPT135_String::countChar(const char c)
{
	int count= 0;
	int len = cstrlen(this->buffer);
	for(int i =0;i<len;i++)
	{
		if(this->buffer[i]=c)
			count++;
	}
	return count;

}

ostream&operator << (ostream &outputStream,const CMPT135_String & s)
{
	for (int i = 0; i < s.getLength(); i++)
		outputStream << s.buffer[i];
	return outputStream;
}

istream& operator>>(istream &inputStream,CMPT135_String &s)
{
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
	//
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

	////Test getSubString function
	//s1 = s3.getSubString(4, 3);
	//cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	//s1 = s3.getSubString(10, 5);
	//cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	//s1 = s3.getSubString(10, 8);
	//cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	//
	
	
	//Test countChar function
	ch = '1';
	k = s1.countChar(ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	

	system("pause");
	return 0;
}