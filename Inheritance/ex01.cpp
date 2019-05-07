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
		: name(theName) { this->age = theAge; this->address = theAddress; }
	string getName() const { return this->name; }
	void rename(const string& theName) : name(theName) { }
	int getAge() const { return this->age; }
	void increaseAge() { age++; }
	string getAddress() const { return this->address; }
	void moveTo(const string& theAddress) { address = theAddress; }
};

class Student : public Person {
	string schoolName;
	Grade grade;
public:
	Student(const string& theName, Grade theGrade = FRESH)
		: Person(theName) { this->grade = theGrade; }
	string getSchoolName() const { return this->schoolName; }
	void setSchoolName(const string& theSchoolName) { this->schoolName = theSchoolName; } 
	Grade getGrade() const { return this->grade; }
	void upGrade() { grade++; }
};

int main() {
	Person p1("Brown"), p2("James");

	p1.rename("Jackson");
	p2.moveTo("Seoul");

	Student s1("Tom"), s2("Jane");
	s1.setSchoolName("한국대학교");
	s2.upGrade();

	s1.rename("Harrison");
	s2.increaseAge();
}
