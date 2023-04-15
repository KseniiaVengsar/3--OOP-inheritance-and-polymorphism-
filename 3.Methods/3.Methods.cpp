// 3.Methods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

class Figure {

public:
	
	virtual void fig_type() {

		std::cout << "Фигура:" << std::endl;

	}

	virtual bool check() {
		std::cout << "Правильная" << std::endl;
		return true;
	}
	virtual void print_sides_count() {

		std::cout << "Количество сторон: 0" << std::endl;
	}

};

void print_info(Figure* figure) {
	figure->fig_type();
	figure->check();
	figure->print_sides_count();
	
}
// /////////////////////////////////////////////////////////////////////////////////
class Triangle :public Figure {
	//треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
protected:
	int a; int b; int c;
	int A; int B; int C;
	
public:

	Triangle( int a_, int b_, int c_, int A_, int B_, int C_) :Figure() {
		a = a_;
		b = b_;
		c = c_;
		A = A_;
		B = B_;
		C = C_;
	}

	void fig_type() override {

		std::cout << "треугольник:" << std::endl;

	}
	bool check() override {
		// Проверяем, что сумма углов равна 180 градусов
		if (A + B + C != 180) {
			std::cout << "Неправильная" << std::endl;
			return false;
			
		}
		else {
			std::cout << "Правильная" << std::endl;
			return true;
		}
		

	}
	
	void print_sides_count() {
		std::cout << "Количество сторон: 3" << std::endl;
		std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
		std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
	}
};
class Right_triangle :public Triangle {
	//Прямоугольный треугольник:
	
public:
	Right_triangle( int a_, int b_, int c_, int A_, int B_, int C_) :Triangle( a_, b_, c_, A_, B_, C_) {

	}
	 void fig_type() override {

		std::cout << "Прямоугольный треугольник:" << std::endl;

	}
	//прямоугольный треугольник(угол C всегда равен 90);
	 bool check() override {
		
		if (C != 90) {

			std::cout << "Неправильная" << std::endl;
			return false;
		}	
		else {
			std::cout << "Правильная" << std::endl;
			return true;
		}
	}
};
class Isosceles_triangle :public Triangle {
	//Равнобедренный треугольник//равнобедренный треугольник (стороны a и c равны, углы A и C равны);
public:
	Isosceles_triangle(int a_, int b_, int A_, int B_) :Triangle( a_, b_, b_, A_, B_, B_) {

	}
	void fig_type() override {

		std::cout << "Равнобедренный треугольник:" << std::endl;

	}
	bool check() override {

		if (a != c && A != C) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}
	}
};
class Equilateral_triangle :public Triangle {
	//Равносторонний треугольник//равносторонний треугольник (все стороны равны, все углы равны 60);
public:
	Equilateral_triangle( int a_, int A_) :Triangle( a_, a_, a_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "Равносторонний треугольник:" << std::endl;

	}
	bool check() override {

		if ((a != c && a != b || c != a && c != b || b != a && b != c)&&(A != 60 || B != 60 || C != 60)) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}
	
	}
};

////////////////////////////////////////////////////////////////////////////////
class Quadrangle :public Figure {
	//Четырёхугольник:Для треугольника и четырёхугольника добавится информация о длине сторон и величине углов.
	//Чтобы не дублировать код, используйте в переопределении метода print_info базовую версию из класса фигуры.
protected:
	int a; int b; int c; int d;
	int A; int B; int C; int D;
public:
	Quadrangle(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) :Figure() {
		a = a_;
		b = b_;
		c = c_;
		d = d_;
		A = A_;
		B = B_;
		C = C_;
		D = D_;
	}
	void print_sides_count() {
		std::cout << "Количество сторон: 4" << std::endl;
		std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
		std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
	}
	 void fig_type() override {

		std::cout << "Четырёхугольник:" << std::endl;

	}
	//четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
	bool check() override  {

		if (A + B + C + D != 360) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}
	}
};
class Rectangle :public Quadrangle {
	//Прямоугольник:прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
public:
	Rectangle( int a_, int b_, int A_) :Quadrangle( a_, b_, a_, b_, A_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "Прямоугольник:" << std::endl;

	}
	bool check() override {

		if ((a != b && c != d)&& (A + B + C + D != 90)) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}

		
	}
};
class Square :public Quadrangle {
	//Квадрат  (все стороны равны, все углы равны 90);
public:
	Square( int a_, int A_) :Quadrangle( a_, a_, a_, a_, A_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "Квадрат:" << std::endl;

	}
	bool check() override {
		if ((a != b && a != c && a != d || b != a && b != c && b != d || c != a && c != b && c != d)&& (A != 90 && B != 90 && C != 90 && D != 90)) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}

		
	}
};
class Parallelogram :public Quadrangle {
	//Параллелограмм
public:
	Parallelogram( int a_, int b_, int A_, int B_) :Quadrangle( a_, b_, a_, b_, A_, B_, A_, B_) {

	}
	 void fig_type() override {

		std::cout << "Параллелограмм:" << std::endl;

	}
	//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
	bool check() override {

		if ((a != b && c != d)&& (A != B && C != D)) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}
	}
};
class Rhombus :public Quadrangle {
	//Ромб - (все стороны равны, углы A,C и B,D попарно равны).
public:
	Rhombus( int a_, int A_, int B_) :Quadrangle( a_, a_, a_, a_, A_, B_, A_, B_) {
	}
	 void fig_type() override {

		std::cout << "Ромб:" << std::endl;

	}
	bool check() override {
		if (A != B && C != D) {

			
			std::cout << "Неправильная" << std::endl;
			return false;
		}
		else {
			
			std::cout << "Правильная" << std::endl;
			return true;
		}
	}
};

////////////////////////////////////////////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "RU");

	Figure* figure = new Figure();
	print_info(figure);
	std::cout << std::endl;

	Triangle* triangle = new Triangle( 1, 2, 3, 4, 5, 6);
	print_info(triangle);
	std::cout << std::endl;

	Right_triangle* right_triangle = new Right_triangle( 1, 2, 3, 4, 5, 6);
	print_info(right_triangle);
	std::cout << std::endl;

	Isosceles_triangle* isosceles_triangle = new Isosceles_triangle(1, 2, 3, 4);
	print_info(isosceles_triangle);
	std::cout << std::endl;

	Equilateral_triangle* equilateral_triangle = new Equilateral_triangle( 1, 2);
	print_info(equilateral_triangle);
	std::cout << std::endl;

	Quadrangle* quadrangle = new Quadrangle( 1, 2, 3, 4, 5, 6, 7, 8);
	print_info(quadrangle);
	std::cout << std::endl;

	Rectangle* rectangle = new Rectangle( 1, 2, 3);
	print_info(rectangle);
	std::cout << std::endl;

	Square* square = new Square(1, 2);
	print_info(square);
	std::cout << std::endl;

	Parallelogram* parallelogram = new Parallelogram( 1, 2, 3, 4);
	print_info(parallelogram);
	std::cout << std::endl;

	// Очистка памяти
	//delete figure;
	delete triangle;
	delete right_triangle;
	delete isosceles_triangle;
	delete equilateral_triangle;
	delete quadrangle;
	delete rectangle;
	delete square;
	delete parallelogram;

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
