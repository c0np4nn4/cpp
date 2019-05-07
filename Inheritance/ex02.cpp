#include <iostream>
#include <string>

using namespace std;

enum Grade { FRESH = 1, SOPHOMORE, JUNIOR, SENIOR };

class Person {
	string name;
	int age;
	string address;
public:
	Person(const string& theName, int theAge = 1, const string& theAddress = "" )
		: name(theName) ,address(theAddress) { 
		this->age = theAge;
		cout << "Person of " << name << " are constructed !" << endl;
	}
		
	string getName() const { return this->name; }
	void rename(const string& theName) { name = theName; }
	int getAge() const { return this->age; }
	void increaseAge() { age++; }
	string getAddress() const { return this->address; }
	void moveTo(const string& theAddress) { address = theAddress; }
	void print() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
		cout << "주소: " << address << endl;
	}
	
	~Person() {
		cout << "Person of " << name << " are destructed !" << endl;
	}
};

class Student : public Person {
	string schoolName;
	Grade grade;
public:
	Student(const string& theName, const string& theSchoolName, 
			Grade theGrade = FRESH, const string& theAddress = "")
		: Person(theName, theGrade+20, theAddress), schoolName(theSchoolName)
		{
			this->grade = theGrade;
			cout << "Student of " << getName() << " are constructed !" << endl;
		}
		 
	string getSchoolName() const { return this->schoolName; }
	void setSchoolName(const string& theSchoolName) { this->schoolName = theSchoolName; } 
	Grade getGrade() const { return this->grade; }
	void upGrade() { grade = static_cast<Grade>( 1 + static_cast<int>(this->grade)); }
	void print() {
		Person::print();
		cout << "학교: " << schoolName << endl;
		cout << "학년: " << grade << endl;
	}
	
	~Student() {
		cout << "Student of " << getName() << " are destructed !" << endl;
	}
};

/*
int main() {
	Person p1("Brown"), p2("James");

	p1.rename("Jackson");
	p2.moveTo("Seoul");

	Student s1("Tom"), s2("Jane");
	s1.setSchoolName("KoreaUniv");
	s2.upGrade();

	s1.rename("Harrison");
	s2.increaseAge();
	
	
	s1.print();
	cout << endl;
	s2.print();
}
*/

int main(){
	Student s1("Tom", "KoreaUniv"), s2("Jane", "AmericaUniv", JUNIOR, "LA");
	s1.print();
	cout << endl;
	s2.print();
}
