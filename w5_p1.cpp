//
// Created by Nonthachai Plodthong on 4/12/2022 AD.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors {
	CannotOpenFile = 1,
	BadArgumentCount = 2,
};


int main(int argc, char **argv) {
	sdds::Book library[7];
	std::fstream file("../books.txt");
	std::string record;
	std::string gl{""};
	size_t _count{0u};
	if (!file) {
		std::cerr << "Error Canot open file\n";
	} else {
		while (_count < 7 && std::getline(file, gl)) {
			if (gl[0] != '#') {
				Book _temp(gl); //this instance store in the heap
				library[_count] = _temp;
				_count++;
			}
		}
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto fixed = [&](Book &b) {
		if (b.country() == "US") {
			b.price() *= usdToCadRate;
		}
		if (b.country() == "UK") {
			b.price() *= gbpToCadRate;
		}
	};
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto &lib: library) {
		std::cout << lib;
	}
	std::cout << "-----------------------------------------\n\n";
	for (int i = 0; i < 7; ++i) {
		fixed(library[i]);
	}
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto &printUpdate: library) {
		cout << printUpdate;
	}


	return 0;
}