//
// Created by Nonthachai Plodthong on 7/12/2022 AD.
//

#include "push_back.h"

using namespace std;


#define c "Porrutai"
#define DEBUG (cout << "Debug : " << __DATE__   << " : " << __FILE_NAME__ << " : " <<  __LINE__  << "\n")
#define DEBUG2(c) (cout << "Debug : " << c <<   "\n")
#define col 5
class Student{
private:
public:
	Student(){
	DEBUG;
	}
	~Student(){
	DEBUG;
    }
};

namespace sdds{
	int main_debug(){
		const char* name = "Nonthachai";
		Student non;
		DEBUG2(name);
		main_array();
		return 0;
	}
	int main_array(){
		int colum, row;
		int** entity; // dynamic dimension
		//int static_array[5][10]; // static dimension
		std::cout << "Number of Row : ";
		std::cin >> row;
		std::cout << "Number of Column : ";
		std::cin >> colum;

		unique_ptr<int**> entity2(new int**[row]);
		entity = new int*[row]; // make row first;

		for(int i = 0 ; i < row ; ++i){
			entity[i] = new int[colum]; // for element of row i << make column
		}
		for(int i = 0 ; i < row; ++i){
			for(int j = 0 ; j < colum; ++j){
				entity[i][j] = (i + 1) * (j + 1);
			}
		}

		std::cout << '\n';
		for(int i = 0 ; i < row ; ++i){
			for(int j = 0 ; j < colum ; ++j){
				cout << " " << entity[i][j] << " ";
				//cout << '\n';
				//cout << " " << entity2 << " ";
			}
			cout << "\n";
		}


		for(int j = 0 ; j < colum ; ++j){
			delete[] entity[j]; // delete each row;
			}
			delete[] entity; // delete row;
		{
			cout << '\n';
			int rows{};
			int (*array)[col];
			cout << "Number of rows : ";
			cin >> rows;

			array = new int [rows][col];// allocate array
			for(int i = 0 ; i < rows ; ++i){
				for(int j = 0 ; j < col ; ++j){
					array[i][j] = (i + 1) * (j + 1);
				}
				std::cout << '\n';
			}
			for(int i = 0; i < col ; ++i){
				cout << "\t" << i + 1;
			}
			cout << '\n';
			for(int i = 0 ; i < rows ; ++i){
				cout << "\t" << i +1;
				for(int j = 0 ; j < col ; ++j){
					cout << '\t' << array[i][j];
				}
				cout << '\n';
			}
			delete[] array;
		}
		{
			try{
				int ok{};
				cin >> ok;
				if(ok == 10){
					throw "Test Throw";
				}
			}catch(int& ok){
				cout << "number of ok : " << ok << "\n";
			}catch(const char* msg){
				cout << "Catch const char* : " << msg << "\n";
			}
		}
		return 0;
	}
/*
 * Ragged Array = are commonly used  to store sets of string. A ragged is an array address. Each element of the  array holds
 * an address. The data stored at each address may be different size
 *
 * RAGGED ARRAY = commonly use for STRING,  the size maybe different size
 * char *name[] = { "Marg", "Jeremy", "Christopher", "Homer" };*/

}