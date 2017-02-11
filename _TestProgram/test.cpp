#include <iostream>

using namespace std;

class Animal {
public: 
	void move() { cout << "This animal moves some way" << endl; }
	virtual void eat() { cout << "Animal ate somthing" << endl; }
	virtual void sing() { cout << "Animal sang something" << endl; }
	virtual ~Animal() {}
};

class Wolf: public Animal {
public:
	void move() { cout << "Wolf walks" << endl; }
	void eat(void) { cout << "Wolf eats meat!" << endl; }
};

int main() {
	Animal* zoo[] = {new Wolf(), new Animal()};

	for(Animal* a:zoo) {
		a->move();
		a->eat();
		a->sing();
		delete a;
	}

	return 0;
}