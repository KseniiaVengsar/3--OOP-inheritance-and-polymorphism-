// 3.Methods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

class Figure {

public:
	
	virtual void fig_type() {

		std::cout << "������:" << std::endl;

	}

	virtual bool check() {
		std::cout << "����������" << std::endl;
		return true;
	}
	virtual void print_sides_count() {

		std::cout << "���������� ������: 0" << std::endl;
	}

};

void print_info(Figure* figure) {
	figure->fig_type();
	figure->check();
	figure->print_sides_count();
	
}
// /////////////////////////////////////////////////////////////////////////////////
class Triangle :public Figure {
	//����������� (������� � ���� ������������, ���������� ������ ����� 3, ����� ����� ����� 180);
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

		std::cout << "�����������:" << std::endl;

	}
	bool check() override {
		// ���������, ��� ����� ����� ����� 180 ��������
		if (A + B + C != 180) {
			std::cout << "������������" << std::endl;
			return false;
			
		}
		else {
			std::cout << "����������" << std::endl;
			return true;
		}
		

	}
	
	void print_sides_count() {
		std::cout << "���������� ������: 3" << std::endl;
		std::cout << "�������: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << std::endl;
		std::cout << "����: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
	}
};
class Right_triangle :public Triangle {
	//������������� �����������:
	
public:
	Right_triangle( int a_, int b_, int c_, int A_, int B_, int C_) :Triangle( a_, b_, c_, A_, B_, C_) {

	}
	 void fig_type() override {

		std::cout << "������������� �����������:" << std::endl;

	}
	//������������� �����������(���� C ������ ����� 90);
	 bool check() override {
		
		if (C != 90) {

			std::cout << "������������" << std::endl;
			return false;
		}	
		else {
			std::cout << "����������" << std::endl;
			return true;
		}
	}
};
class Isosceles_triangle :public Triangle {
	//�������������� �����������//�������������� ����������� (������� a � c �����, ���� A � C �����);
public:
	Isosceles_triangle(int a_, int b_, int A_, int B_) :Triangle( a_, b_, b_, A_, B_, B_) {

	}
	void fig_type() override {

		std::cout << "�������������� �����������:" << std::endl;

	}
	bool check() override {

		if (a != c && A != C) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}
	}
};
class Equilateral_triangle :public Triangle {
	//�������������� �����������//�������������� ����������� (��� ������� �����, ��� ���� ����� 60);
public:
	Equilateral_triangle( int a_, int A_) :Triangle( a_, a_, a_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "�������������� �����������:" << std::endl;

	}
	bool check() override {

		if ((a != c && a != b || c != a && c != b || b != a && b != c)&&(A != 60 || B != 60 || C != 60)) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}
	
	}
};

////////////////////////////////////////////////////////////////////////////////
class Quadrangle :public Figure {
	//��������������:��� ������������ � ��������������� ��������� ���������� � ����� ������ � �������� �����.
	//����� �� ����������� ���, ����������� � ��������������� ������ print_info ������� ������ �� ������ ������.
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
		std::cout << "���������� ������: 4" << std::endl;
		std::cout << "�������: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
		std::cout << "����: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
	}
	 void fig_type() override {

		std::cout << "��������������:" << std::endl;

	}
	//�������������� (������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360);
	bool check() override  {

		if (A + B + C + D != 360) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}
	}
};
class Rectangle :public Quadrangle {
	//�������������:������������� (������� a,c � b,d ������� �����, ��� ���� ����� 90);
public:
	Rectangle( int a_, int b_, int A_) :Quadrangle( a_, b_, a_, b_, A_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "�������������:" << std::endl;

	}
	bool check() override {

		if ((a != b && c != d)&& (A + B + C + D != 90)) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}

		
	}
};
class Square :public Quadrangle {
	//�������  (��� ������� �����, ��� ���� ����� 90);
public:
	Square( int a_, int A_) :Quadrangle( a_, a_, a_, a_, A_, A_, A_, A_) {

	}
	void fig_type() override {

		std::cout << "�������:" << std::endl;

	}
	bool check() override {
		if ((a != b && a != c && a != d || b != a && b != c && b != d || c != a && c != b && c != d)&& (A != 90 && B != 90 && C != 90 && D != 90)) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}

		
	}
};
class Parallelogram :public Quadrangle {
	//��������������
public:
	Parallelogram( int a_, int b_, int A_, int B_) :Quadrangle( a_, b_, a_, b_, A_, B_, A_, B_) {

	}
	 void fig_type() override {

		std::cout << "��������������:" << std::endl;

	}
	//�������������� (������� a,c � b,d ������� �����, ���� A,C � B,D ������� �����);
	bool check() override {

		if ((a != b && c != d)&& (A != B && C != D)) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
			return true;
		}
	}
};
class Rhombus :public Quadrangle {
	//���� - (��� ������� �����, ���� A,C � B,D ������� �����).
public:
	Rhombus( int a_, int A_, int B_) :Quadrangle( a_, a_, a_, a_, A_, B_, A_, B_) {
	}
	 void fig_type() override {

		std::cout << "����:" << std::endl;

	}
	bool check() override {
		if (A != B && C != D) {

			
			std::cout << "������������" << std::endl;
			return false;
		}
		else {
			
			std::cout << "����������" << std::endl;
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

	// ������� ������
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
