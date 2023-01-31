//
// Created by Nonthachai Plodthong on 7/12/2022 AD.
//
#include <iostream>
//#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

using namespace std;

class Engine {
	string m_name{};
public:
	//Engine() = default;

	Engine(const std::string &n) : m_name(n) {
		cout << "Calling Engine Constructor\n";
	}

	~Engine() {
		cout << "Calling Engine Destructor\n";
	}

	void display() const {
		cout << "[" << m_name;
	}
};

class Vehicle : public Engine {
	string type{};
	string name{};
public:
	Vehicle() : Engine("M-700") {
		type = "Honda";
		cout << "Calling Vehicle Constructor\n";
	}

	~Vehicle() {
		cout << "Calling Vehicle Destructor\n";
	}

	void display() const {
		Engine::display();
		cout << " | " << "the type is :  " << " | " << type << "]  \n";
	}
};

class Engineer : public Engine {
	double m_sal{};
public:
	Engineer() : Engine("Nonthachai") {
		m_sal = 100;
		cout << "Calling Engineer Constructor\n";
	}

	~Engineer() {
		cout << "Calling Engineer Destructor\n";
	}

	void display() const {
		Engine::display();
		cout << " - " << "have salary " << " : <" << m_sal << "> k / year] \n";
	}
};

class Government : public Vehicle, public Engineer {
public:
	Government(string name)  { cout << "Calling Government Constructor\n"; }

	~Government() { cout << "Calling Government Destuctor\n"; }

	void display() const {
		Engineer::display();
		Vehicle::display();
	}
};


int main() {
	Government gv("Non");
	gv.display();
	std::vector<int> v = {1, 2, 3, 4}, p(4);

	std::partial_sum(v.begin(), v.end(), p.begin());

	for (auto i : p)
		std::cout << i << std::endl;

	std::partial_sum(v.begin(), v.end(), p.begin(),
	                 std::multiplies<int>());

	for (auto i : p)
		std::cout << i <<  std::endl;
	return 0;
}

/*01011001 11001101 11101011 11100010
 00000000 00000000 00001111 00000000
 01011001 11001101 11101111 11100010*/
