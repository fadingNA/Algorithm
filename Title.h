//
// Created by Nonthachai Plodthong on 7/12/2022 AD.
//

#ifndef MULTIINHERITANCE_TITLE_H
#define MULTIINHERITANCE_TITLE_H

namespace sdds{
	class Title{
		const char* name{};
		const char* valid() const{
			if(!name[0]){
				throw "Invalid Title";
			}
			return name;
		}
	public:
		Title() = default;

		Title(const char* cp) : name(cp){}
		void display() const{
			std::cout << valid() << std::endl;
		}
	};

	template<typename T>
	class SmartPointer{
		T* p {};
	public:
		explicit SmartPointer(const SmartPointer&) = delete;
		SmartPointer& operator=(const SmartPointer&) = delete;
		SmartPointer(SmartPointer&& move) noexcept{
			p = move.p;
			move.p = nullptr;
		}

		SmartPointer& operator==(SmartPointer&& moves){
			if(this != moves){
				delete p;
				p = moves.p;
				moves.p = nullptr;
			}
			return *this;
		}
		~SmartPointer(){
			delete p;
		}
		T& operator*(){
			return *p;
		}
		T* operator->(){
			return p;
		}
	};
}

#endif //MULTIINHERITANCE_TITLE_H
