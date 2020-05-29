#pragma once
#include<iostream>
using namespace std;

template<class M>
class Matric
{
private:
	void MemorySize(int width, int length)//выделение памяти
	{
		massiv = new M *[m];
		for (int i = 0; i < width; i++) this->massiv[i] = new M[length];
	}
protected:
	int m;//строки
	int n;//столбцы
	M** massiv;
public:
	Matric();
	Matric(int a, int b);//пустая матрица нужной размерности
	Matric(int c, int d, M** arr);
	Matric(const Matric<M>& other);
	~Matric();
	M** GetMatric();//массив матрицы
	int GetM();// узнать количество строк
	int GetN();//узнать количество столбцов
	void SetRazmernost(int width, int length);//установить размерность
	void SetMatric(M** e);//переписать значение полей в матрице уже созданной размерности
	Matric<M> operator=(const Matric<M>& other);
	bool operator ==(const Matric<M>& other);
	M*& operator [](const int i);
	Matric<M> operator+(const Matric<M>& other);
	Matric<M> operator-(const Matric<M>& other);
	Matric<M> operator*(const Matric<M>& other);
	template<class M>
	friend ostream& operator<<(ostream& os, const Matric<M>& mat);
	template<class M>
	friend istream& operator>>(istream& in, Matric<M>& mat);
	int Poiskk(M a);//количество вхождений указанного значения
};

template<class M>
Matric<M>::Matric()
{
	m = 1;
	n = 1;
	MemorySize(m, n);
	massiv[0][0] = 0;
}
template<class M>
Matric<M>::Matric(int a, int b)//пустая матрица нужной размерности
{
	m = a;
	n = b;
	MemorySize(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			massiv[i][j] = 0;
		}
	}
}

template<class M>
Matric<M>::Matric(int c, int d, M** arr)
{
	m = c;
	n = d;
	MemorySize(c, d);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			massiv[i][j] = arr[i][j];
}

template<class M>
Matric<M>::Matric(const Matric<M>& other)
{
	m = other.n;
	n = other.m;
	MemorySize(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			massiv[i][j] = other.massiv[i][j];
}

template<class M>
Matric<M>::~Matric()
{
	if (massiv != 0)
	{
		for (int i = 0; i < m; i++)
		{
			massiv[i] = 0;
			delete[] massiv[i];
		}
		massiv = 0;
		delete[] massiv;
		n = 0;
		m = 0;
	}
}
template<class M>
int Matric<M>::Poiskk(M a)//количество вхождений указанного значения
{
	int kol = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (massiv[i][j] == a)
			{
				kol = kol + 1;
			}
		}
	}
	return kol;
}

template<class M>
int Matric<M>::GetM()
{
	return m;
}

template<class M>
int Matric<M>::GetN()
{
	return n;
}

template<class M>
M** Matric<M>::GetMatric()
{
	return massiv;
}

template<class M>
void Matric<M>::SetRazmernost(int width, int length)//установить размерность
{
	m = width;
	n = length;
}

template<class M>
void Matric<M>::SetMatric(M** e)//переписать значение полей в матрице уже созданной размерности
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			massiv[i][j] = e[i][j];//переписываем массив новых значений
}

template<class M>
Matric<M> Matric<M>::operator=(const Matric<M>& other)
{
	if (*this == other)
		return *this;
	for (int i = 0; i < m; i++)//удаляем старый массив, чтобы можно было присваивать матрицу другой размерности
	{
		massiv[i] = 0;
		delete[] massiv[i];
	}
	delete[] massiv;
	massiv = 0;
	m = other.m;
	n = other.n;
	MemorySize(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			massiv[i][j] = other.massiv[i][j];
		}
	}
	return *this;
}

template<class M>
M*& Matric<M>::operator [](const int i)
{
	return massiv[i];
}

template<class M>
bool Matric<M>::operator==(const Matric<M>& other)
{
	if (m == other.m && n == other.n)
	{

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (massiv[i][j] != other.massiv[i][j])
					return false;
		return true;
	}
	else
		return false;
}

template<class M>
Matric<M> Matric<M>::operator+(const Matric<M>& other)
{
	if (n == other.n && m == other.m)
	{
		Matric<M> F(m, n, other.massiv);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				F.massiv[i][j] = other.massiv[i][j] + massiv[i][j];
			}
		}
		return F;
	}
	else
		throw - 1;
}

template<class M>
Matric<M> Matric<M>::operator-(const Matric<M>& other)
{
	if (n == other.n && m == other.m)
	{
		Matric<M> F(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				F.massiv[i][j] = massiv[i][j] - other.massiv[i][j];
		return F;
	}
	else
		throw - 1;
}

template<class M>
Matric<M> Matric<M>::operator*(const Matric<M>& other)
{
	if (n == other.m)
	{
		Matric<M> mat(m, (other.n));//сделали пустой массив нужной размерности
		for (int i = 0; i < mat.m; i++)
			for (int j = 0; j < mat.n; j++)
			{
				mat.massiv[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					mat.massiv[i][j] = mat.massiv[i][j] + (massiv[i][k] * other.massiv[k][j]);
				}
			}
		return mat;
	}
	else
		throw - 1;

}

template<class M>
ostream& operator<<(ostream& os, const Matric<M>& mat)
{
	cout << "\n";
	for (int i = 0; i < mat.m; i++)
	{
		if (i > 0) os << endl;
		os << "|";
		for (int j = 0; j < mat.n; j++)
			os << mat.massiv[i][j] << " ";
		os << "|";
	}
	return os;
}

template<class M>
istream& operator>>(istream& in, Matric<M>& mat)
{
	if ((mat.GetM() != 0) || (mat.GetN() != 0))
	{
		for (int i = 0; i < mat.m; i++)
			delete[] mat.massiv[i];
		delete[] mat.massiv;
	}
	cout << "Enter razmer" << "\n";
	cout << "m = " << "\n";
	in >> mat.m;
	cout << "n = " << "\n";
	in >> mat.n;
	mat.MemorySize(mat.m, mat.n);
	for (int i = 0; i < mat.m; i++)
	{
		cout << "Enter " << i + 1 << " line" << "\n";
		for (int j = 0; j < mat.n; j++)
			in >> mat.massiv[i][j];
	}
	return in;
}