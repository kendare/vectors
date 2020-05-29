#pragma once
#include "Vector.h"
#include "Matrix.h"
template <class T>
MyVector<T> operator *(Matric<T>& matrix, MyVector<T>& vector)
{
	if (matrix.GetM() == vector.GetRazmer())
	{
		T* arr = new T[matrix.GetM()];//íóæíûé ìàññèâ
		T** arr_matrix = matrix.GetMatric();
		T* arr_vector = vector.GetVector();
		/*MyVector<T> result(matrix.GetN(), arr);*/
		for (int i = 0; i < matrix.GetM(); i++)
		{
			arr[i] = 0;
			for (int j = 0; j < matrix.GetN(); j++)
			{
				arr[i] = arr[i] + (arr_matrix[i][j] * arr_vector[j]);

			}
		}
		MyVector<T> result(matrix.GetN(), arr);
		delete[] arr;
		return result;
	}
	else
		throw - 1;
};

template <class T>
Matric<T> operator *(MyVector<T>& vector, Matric<T>& matrix)
{
	if (matrix.GetN() == vector.GetRazmer() && matrix.GetM() == 1)
	{
		T** arr = new T *[matrix.GetN()];
		for (int i = 0; i < vector.GetRazmer(); i++)
			arr[i] = new T[vector.GetRazmer()];

		for (int i = 0; i < vector.GetRazmer(); i++)
			for (int j = 0; j < matrix.GetN(); j++)
			{
				/* result.SetRazmernost(i, j);
				   result.s[i]=(matrix[0][j] * vector[i]);*/
				arr[i][j] = (matrix[0][j] * vector[i]);
			}
		Matric<T> result(matrix.GetN(), vector.GetRazmer(), arr);


		for (int i = 0; i < vector.GetRazmer(); i++)
			delete[] arr[i];
		delete[] arr;
		return result;
	}
	else
		throw - 1;
};
