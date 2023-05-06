// Copyright 2023 Eremin Aleksandr

#ifndef MODULES_MONOM_INCLUDE_MONOM_H_
#define MODULES_MONOM_INCLUDE_MONOM_H_
// ����� ��� ��������� ������

#include <iostream>

//����������� ��� ��������� ������������� ����;
enum State {
	START,
	NUMBER,
	END
};
//�������, �����, ��������, ����������;
enum LexType {
	LEX_NULL, //��� �������������� ������;

	LEX_NUMBER, //�����;
	LEX_DELIM, //�����������, ��������� �� ������������ ��������;
	LEX_VAR //����������
};
//�����������
enum LexDelims {
	LEX_DEL_NULL, //��� ������;

	LEX_DEL_ADD, //�������� +;
	LEX_DEL_SUB, //�������� -, �������� ��� �������;
	LEX_DEL_POW, //���������� � �������;
	LEX_DEL_EQUALS //���� ���������;
};

class Monom {
private: double coefficient;
	   int degreeX;
	   int degreeY;
	   int degreeZ;

public: Monom() {
	coefficient = 0;
	degreeX = 0;
	degreeY = 0;
	degreeZ = 0;
};
	  Monom(double coeff, int degX, int degY, int degZ);
	  Monom(const Monom& m);

	  double coeff() {
		  return coefficient;
	  }
	  int degree() {
		  return degreeX + degreeY + degreeZ;
	  }

	  const Monom& operator = (const Monom& _monom);
	  bool operator != (const Monom& _monom) const;
	  bool operator == (const Monom& _monom) const;

	  Monom operator + (const Monom& _monom) const;
	  Monom operator - (const Monom& _monom) const;
	  Monom operator * (const Monom& _monom) const;

	  Monom operator + (const double& _Num) const;
	  Monom operator - (const double& _Num) const;
	  Monom operator * (const double& _Num) const;
	  bool degreeEq(const Monom& _monom);
};

class Lexema {
public: int type; //��� ������� (���������, �����������, ������);
	  int index; //���������� ������ �������;
	  double value; //�������� ������� (��� �������� ��������);

	  std::string buf; //�������� ����� �������;

	  Lexema(int type = LEX_NULL, int index = LEX_NULL,
		  const std::string& buf = "",
		  double value = 0) : type(type),
		  index(index),
		  buf(buf),
		  value(value) {};
};

#endif // MODULES_MONOM_INCLUDE_MONOM_H_
