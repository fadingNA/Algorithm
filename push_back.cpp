//
// Created by Nonthachai Plodthong on 5/12/2022 AD.
//

#include "push_back.h"
#include <list>
#include <future>
#include <thread>
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;


void display(const char* c){
	shared_ptr<sdds::Title> p(new sdds::Title(c));
	p->display();
}

void dis(const char* cok){
	auto* tmp = new sdds::Title(cok);
	try{
		tmp->display();
	}catch(...){
		//delete tmp;
		throw;
	}
	delete tmp;
}
void DoWork(promise<double> &ok) {
	ok.set_value(30.99);
}

void task(double val) {
	cout << "this is " << val << endl;
}

double doWok(double x) {
	return x * 2;
}

double get() {
	return 12.34;
}

int main() {
	sdds::main_vehicle();
	const char *nameDemo[] = {"Non","Aom","Urai","Kosol" , ""};

	for(auto print : nameDemo){
		try{
			display(print);
			dis(print);
		}catch(const char* msg){
			std::cerr << "Throw invalid name : " << msg << "\n";
		}
	}



	sdds::main_debug();
	promise<double> p;
	future<double> f = p.get_future();
	thread okk(DoWork, std::ref(p));
	std::cout << "Value = " << f.get() << '\n';
	okk.join();
	packaged_task<double(double)> ok(doWok);
	future<double> res = ok.get_future();
	ok(10);
	double r = res.get();
	//thread so = (thread &&) (std::move(ok));
	cout << "<" << r << ">\n";

	//so.join();

	future<double> f1;
	future<double> f2;
	//f2 = async(get);

	sdds::List<int> lst;


	sdds::List<double> doubleTest;
	sdds::List<double> doubleTest2;
	sdds::List<double> doubleTest3;


//	unique_ptr<sdds::List<double>> unique(new sdds::List<double>);
//
//	unique->push_back(50.50);



	std::list<double> okok;
	//okok = std::sort(okok.begin(),okok.end()); // cannot use std:;sort
	sdds::List<int> lst2;
	doubleTest.push_back(203.2);
	okok.push_back(203.2);
	okok.push_back(203.2);
	okok.push_back(19.2);
	okok.push_back(19.2);
	okok.push_back(50.2);
	okok.pop_front();
	doubleTest.push_back(203.2);
	doubleTest.push_back(19.2);
	doubleTest.push_back(19.2);
	doubleTest.push_back(50.2);
	doubleTest.pop_back();


	for (auto print: doubleTest) {
		cout << "<" << print << ">";
	}

	doubleTest2 = doubleTest;

	doubleTest2.push_back(20.2);
	doubleTest3 = doubleTest2;
	std::cout << '\n';
	for (auto print: doubleTest) {
		cout << "<" << print << ">";
	}
	std::cout << '\n';
	for (auto print: doubleTest3) {
		cout << "<" << print << ">";
	}
	cout << '\n';
	for (auto print2: okok) {
		cout << "<" << print2 << ">";
	}

	std::cout << doubleTest.size() << '\n';
	list<string> original(5, "Non");
	original.assign({"Non", "ok", "today", "Not Die"});
	list<std::reference_wrapper<string>> reference(original.begin(), original.end());
	original.emplace_back("Will get job offer soon!");
	for_each(reference.begin(), reference.end(), [](const string &ok) {
		cout << "<" << ok << ">\n";
	});
	transform(reference.begin(), reference.end(), original.begin(), [](string &ko) {
		if (ko == "Non") {
			ko = "aom";
		} else if (ko == "Non will get All A from Seneca College") {
			ko = "Best Student\n";
		} else {
			ko = "Non will get All A from Seneca College\n";
		}
		return ko;
	});
	for_each(original.begin(), original.end(), [](const string &ok) {
		cout << "<" << ok << ">\n";
	});
	doubleTest.push_back(30);
	auto resule = find_if(doubleTest.begin(),doubleTest.end(),[](double& val) mutable -> int{
		return val == 30 ;
	});
	vector<double> vect(5,20.3);

	//auto cnt = std::count(vect.begin(),vect.end(),5);

	//doubleTest.sort();

	cout << *resule <<'\n';
}
//	l	cout << "<" << print << ">";        st2.push_back(30);
//	l}                                       st2.push_back(40);
//	lst2.push_back(14);
//	lst2.push_back(14);

//	for (auto &list: lst) {
//	std::cout << "[" << list << "]\n";
//	}
//	std::for_each(lst.begin(), lst.end(), [](const int &k) {
//		std::cout << "<" << k << ">\n";
//	});



//	for(auto& ok : lst){
//		std::cout << "<" << ok << ">\n";
//	}


