#include <iostream>
using namespace std;

//FRACTION - (�����) ��������� ������� �����

class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
public: //������ ������, � ��� ��������� get/set ������

	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

							//Constructors - ���� ����� get/set �������
	Fraction() //��� ���� ������������� ������� ��� ������������ �� ���������. �������������
	{
		//����� ��� �������� ����� ����
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		//single-argument constructor - ����������� � ����� ����������
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		//� ����� ��������� ������� ����� ��� ������ ��������
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//OPERATOR

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		this->integer += other.integer;
		this->numerator += other.numerator;
		this->denominator += other.denominator;
		return *this;
	}
	ostream& operator << (ostream& os, const Point& obj)
	{
		os << obj.get_integer() << "\t" << obj.get_numerator() << "\t" << obj.get_denominator();
		return os;
	}

	istream& operator >> (istream& is, Point& obj)
	{
		int integer, numerator, denominator;
		is >> integer >> numerator >> denominator;
		obj.set_integer(integer);
		obj.set_numerator(numerator);
		obj.set_denominator(denominator);
		return is;
	}
	//Methods
	void to_proper()
	{
		//��������� ����� � ���������� - �������� ����� �����:
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//��������� ����� � ������������ - ����������� ����� ����� � ���������
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{
		//��������� �����
		numerator += integer * denominator;
		integer = 0;
		while(numerator !=0)
		numerator = denominator;
	}
	void print()
	{
		//5;
		//1/2;
		//2(3/4);
		if (integer)cout << integer; //���� ���� ����� ����� - ������� �� �� �����
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};



//#define CONSTRUCTROS_CHECK

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //����� ����� ���������� ����������� �� ��������� (default constructor) ������ ��� �������� �� ������
	A.print();
	Fraction B = 5; //����� ��������� ����������� � ����� ���������� Single-argument
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(14, 4);
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
	A.reduce();
	A.print();
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction buffer;
	buffer.set_integer(left.get_integer() + right.get_integer());
	buffer.set_numerator(left.get_numerator() + right.get_numerator());
	buffer.set_denominator(left.get_denominator() + right.get_denominator());
	return buffer;
}