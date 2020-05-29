#pragma once
#include <iostream>
#include <clocale>
#include <iomanip>
#include"Matrix.h"

using namespace std;
template <class Vector>
class MyVector
{
protected:
	int razmer;
	Vector* massiv;
public:
	MyVector();
	MyVector(int r, Vector* A);
	MyVector(MyVector& B);
	~MyVector();
	Vector* GetVector();
	int GetRazmer();
	void SetVector(Vector* C);
	void SetRazmer(int e);
	MyVector<Vector> operator=(const MyVector<Vector>& other);
	bool operator ==(const MyVector<Vector>& other);
	Vector operator [](const int i);
	MyVector<Vector> operator + (const MyVector& other);
	MyVector<Vector> operator-(const MyVector<Vector>& other);
	Vector operator*(const MyVector<Vector>& other);
	MyVector<Vector> operator /(MyVector<Vector>& other);
	template <class Vector>
	friend ostream& operator<<(ostream& os, const MyVector<Vector>& vec);
	template <class Vector>
	friend istream& operator>>(istream& in, MyVector<Vector>& vec);
	//clock_t BubbleSort(MyVector<Vector>& other);
	clock_t BubbleSort();
	clock_t InsertionSort();
	clock_t QuickSort(int first, int last);
	int Poisk(Vector a);//количество вхождений указанного значени€
};


template<class Vector>
MyVector<Vector>::MyVector(int r, Vector*A)
{
	massiv = nullptr;
	try {
		if (r > 0)
		{
			razmer = r;
			massiv = new Vector[razmer];
			for (int i = 0; i < razmer; i++)
			{
				massiv[i] = A[i];
			}
		}
		else throw 1;
	}
	catch (int i)
	{
		cout << "oshibka vvoda dannux, massiv=0" << "\n";
		exit(0);
	}
}

template<class Vector>
MyVector<Vector>::MyVector(MyVector& B)
{
	massiv = nullptr;
	razmer = B.GetRazmer();
	massiv = new Vector[razmer];
	for (int i = 0; i < razmer; i++)
	{
		massiv[i] = B.massiv[i];
	}
}

template<class Vector>
Vector* MyVector<Vector>::GetVector()
{
	return massiv;
}

template<class Vector>
int MyVector<Vector>::GetRazmer()
{
	return razmer;
}

template<class Vector>
void MyVector<Vector>::SetVector(Vector* C)
{
	int i = strlen(C);
	if (massiv != 0)
	{
		massiv = 0;
		delete[] massiv;
	}
	size = i;
	massiv = new Vector[size];
	for (int k = 0; k < i; k++)
	{
		massiv[k] = C[k];
	}
}

template<class Vector>
MyVector<Vector>::MyVector()
{
	razmer = 1;
	massiv = new Vector[1];
	Vector a = 0;
	massiv[0] = a;
}

template<class Vector>
MyVector<Vector>::~MyVector()
{
	if (massiv != 0)
	{
		massiv = 0;
		delete[] massiv;
	}
	razmer = 0;
}
template<class Vector>
MyVector<Vector> MyVector<Vector>::operator=(const MyVector<Vector>& other)
{
	if (*this == other)
		return *this;
	delete[] massiv;
	this->razmer = other.razmer;
	massiv = new Vector[razmer];
	for (int i = 0; i < razmer; i++)
		massiv[i] = other.massiv[i];
	return *this;
}

template<class Vector>
bool MyVector<Vector>::operator==(const MyVector<Vector>& other)
{
	int k = 0;
	if (razmer == other.razmer)
	{
		for (int i = 0; i < razmer; i++)
		{
			if (massiv[i] == other.massiv[i])
			{
				k = k + 1;
			}
		}
		if (k == razmer)
		{
			return true;
		}
		else return false;
	}
	else
		return false;
}
template<class Vector>
Vector MyVector<Vector>::operator[](const int i)
{
	return massiv[i];
}

template<class Vector>
MyVector<Vector> MyVector<Vector>::operator + (const MyVector& other)
{
	if (razmer == other.razmer)
	{
		MyVector<Vector> vector(razmer, other.massiv);
		for (int i = 0; i < razmer; i++)
			vector.massiv[i] = massiv[i] + other.massiv[i];
		return vector;
	}
	else
		throw - 1;
}

template<class Vector>
void MyVector<Vector>::SetRazmer(int e)
{
	razmer = e;
}

template<class Vector>
MyVector<Vector> MyVector<Vector>::operator-(const MyVector<Vector>& other)
{
	if (razmer == other.razmer)
	{
		MyVector<Vector> vector(razmer, other.massiv);
		for (int i = 0; i < razmer; i++)
			vector.massiv[i] = massiv[i] - other.massiv[i];
		return vector;
	}
	else
		throw - 1;
}

template<class Vector>
Vector MyVector<Vector>::operator *(const MyVector<Vector>& other)
{
	Vector res = 0;
	if (razmer == other.razmer)
	{
		for (int i = 0; i < razmer; i++)
			res = res + (massiv[i] * other.massiv[i]);
		return res;
	}
	else
		throw - 1;
}

template<class Vector>
MyVector<Vector> MyVector<Vector>::operator /(MyVector<Vector>& other)
{

	if (razmer != other.GetRazmer())throw length_error("Nepravilnue dannue");
	MyVector<Vector> K;
	K = *this;
	for (int i = 0; i < razmer; i++)
	{
		if (K.massiv[i] != 0)
		{
			K.massiv[i] = K.massiv[i] / other.massiv[i];
		}

	}
	return K;

}

template<class Vector>
ostream& operator<<(ostream& os, const MyVector<Vector>& vec)
{
	os << "(";
	for (int i = 0; i < vec.razmer; i++)
	{
		os << vec.massiv[i];
		if (i < vec.razmer - 1)
			os << " ";
	}
	os << ")^T";
	return os;
}

template<class Vector>
istream& operator>>(istream& in, MyVector<Vector>& vec)
{
	cout << "Enter size" << "\n";
	in >> vec.razmer;
	Vector* mas;
	mas = new Vector[vec.razmer];
	for (int i = 0; i < vec.razmer; i++)
	{
		cout << "[" << i << "]" << "\n";
		in >> mas[i];
	}
	MyVector<Vector> V(vec.razmer, mas);
	vec = V;
	mas = 0;
	delete[] mas;
	return in;
}
template<class Vector>
clock_t MyVector<Vector>::BubbleSort()
{
	clock_t start, finish;
	start = clock();
	Vector tmp = 0;
	int i, j = 0;
	start = clock();
	for (int i = 0; i < razmer; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (massiv[j] > massiv[j + 1])
			{
				tmp = massiv[j];
				massiv[j] = massiv[j + 1];
				massiv[j + 1] = tmp;
			}
		}
	}
	finish = clock();
	return (finish - start);
}
template<class Vector>
int MyVector<Vector>::Poisk(Vector a)//количество вхождений указанного значени€
{
	int kol = 0;
	for (int i = 0; i < razmer; i++)
	{
		if (massiv[i] == a)
		{
			kol = kol + 1;
		}
	}
	return kol;
}

template<class Vector>
clock_t MyVector<Vector>::InsertionSort()
{
	int k = 0;
	clock_t start, finish;
	start = clock();
	Vector tmp;

	for (int i = 1; i < razmer; i++)
	{
		tmp = massiv[i];
		k = i - 1;
		while (k >= 0 && massiv[k] > tmp)
		{
			massiv[k + 1] = massiv[k];
			k = k - 1;
		}
		massiv[k + 1] = tmp;
	}
	finish = clock();
	return (finish - start);
}

template<class Vector>
clock_t MyVector<Vector>::QuickSort(int first, int last)
{
	clock_t t1, t2, t3;
	t1 = clock();
	int i = first, j = last;
	Vector tmp;
	Vector x = massiv[(first + last) / 2];

	do {
		while (massiv[i] < x)
			i++;
		while (massiv[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = massiv[i];
				massiv[i] = massiv[j];
				massiv[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		t3 = QuickSort(i, last);
	if (first < j)
		t3 = QuickSort(first, j);
	t2 = clock();
	return t2 - t1;
}