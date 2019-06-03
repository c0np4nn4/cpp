#include <iostream>
#include <string>

using namespace std;

class StackException {
	const string msg ;
public:
	StackException(const string& _msg) : msg(_msg) {};
	void print() const { cout << msg << endl ; }
} ;

class CharStack {
	int size ;
	int top ;
	char* s ;
public:
	/**
		destructor, copy constructor, and assignment operator
	*/
	
	CharStack(int sz) { 	//------------------------------ constructor
		top = 0;
		s = new char[size = sz];
	}
	~CharStack() { 	//-------------------------------------- destructor
		delete s;
	}
	CharStack( CharStack& original ) {	//------------------ copy constructor
		top = original.top;
		s = new char[size = (original.size)];
		for(int i = 0; i < size; i ++) {
			s[i] = original.s[i];
		}
	}
	CharStack operator = (CharStack& data) {	//----------- assignment operator
			top = data.top;
			char* tmp = new char[size = (data.size)];
			for(int i = 0; i < size; i ++) {
				tmp[i] = data.s[i];
			}
			s = tmp;
		return data;
	}
	
	/** Improvement Specification
	
		@ void push (char c)
			if top == size:
				throw StackException("[+] ERROR : BOF has been detected");
		
		@ char pop (void)
			if top == 0:
				throw StackException("[+] ERROR : BUF has been detected");
	*/
	void push(char c) { 
		s[top++] = c;
		if (top == size) throw StackException("[+] ERROR : BOF has been detected");
	}
	
	char pop() { 
		if (top == 0) throw StackException("[+] ERROR : BUF has been detected");
		char r = s[--top];
		s[top] = '\0';
		return r ; 
	}
	void print() const {
	for ( int i = 0 ; i < top ; i ++ ) cout << s[i] ;
	cout << endl ;
	}
};


int main()
{
	CharStack stack(2);
	try {
		stack.push('a');
		stack.push('b');
		stack.push('c');
		stack.print();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.print();
	} catch ( const StackException& e ) { e.print(); }
	return 0;
}
