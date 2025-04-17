#include <iostream>
//задание 1
class A{
	public:
		void virtual print_class() = 0;
	
};
void A::print_class(){std::cout<<"default b\n";}

class B : public A{
	public:
		//void virtual print_class(){ std::cout<<"class b\n";}
		void virtual print_class(){ return A::print_class();}
	
};

class C : public B{
	public:
		void virtual print_class(){ std::cout<<"class c\n";}
	
};

void DemoPolymorphism(A &class_a){
	class_a.print_class();
}

//задание 2
class Base_circle{
	protected:
		float m_r;
		float m_PI = 3.14f;
		float result;
		virtual void circleMath(float r) = 0;
	public:
		Base_circle(float r) : m_r(r) {}
		float getResult(){
			circleMath(m_r);
			return result;
		}
		
};

class CalcLength : public Base_circle{
	private:
		virtual void circleMath(float r){
			m_r = r;
			result = 2*m_r*m_PI;
		}
	public:
		CalcLength(float m): Base_circle(m) {}
};

class CalcArea : public Base_circle{
	private:
		virtual void circleMath(float r){
			m_r = r;
			result = m_r*m_r*m_PI;
		}
	public:
		CalcArea(float m) : Base_circle(m) {}
};
class CalcVolume : public Base_circle{
	private:
		virtual void circleMath(float r){
			m_r = r;
			result = (4/3)*m_PI*m_r*m_r*m_r;
		}
	public:
		CalcVolume(float m) : Base_circle(m) {}
};
		
void showResult( Base_circle &circle){
	std::cout<<"Result circle operation = "<<circle.getResult()<<"\n";
}

int main(){
	std::cout<<"hello\n";
	C c;
	A *ptr_interfaceA = &c;
	DemoPolymorphism(*ptr_interfaceA);
	B b;
	ptr_interfaceA = &b;
	DemoPolymorphism(*ptr_interfaceA);
	ptr_interfaceA = nullptr;
	
	float r;
	int op;
	std::cout<<"введите радиус круга: \n";
	std::cin>>r;

	do{
		std::cout<<"выберите действие длина окружности - 1, площадь - 2, объём - 3: \n";
		std::cin>>op;
	}while(op < 1 || op > 3);
	Base_circle *base = nullptr;
	switch(op){
		case 1: {CalcLength l(r); base = &l; break;}
		case 2: {CalcArea ar(r); base = &ar; break;}
		case 3: {CalcVolume vol(r); base = &vol; break;}
	}
	showResult(*base);//разыменовали т.к. передаём по ссылке
	return 0;
}
