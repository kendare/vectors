#include"Matrix.h"
#include <cstdlib>
#include"vector.h"
#include <time.h>
#include <clocale>
#include <malloc.h>
#include <vector>
#include<iostream>
#include <iomanip>
#include"header.h"
using namespace std;
int main()
{
	cout << "Sozdadim Vector 1" << "\n";
	MyVector<int> A;
	cin >> A;
	cout << "vernem vector 1" << "\n";
	cout << A << "\n";
	int K = 0;
	int arr[] = { 9,2,1,4,5,6,7 };
	int arrr[] = { 2,3,4,5,6,7,8 };
	MyVector<int> B(7, arr);//создадим два вектора одинаковой размерности для операций над ними
	MyVector<int> C(7, arrr);
	MyVector<int> D;
	cout << "slozhenie" << "\n";
	D = B + C;
	cout << D << "\n";
	cout << "umnozhenie" << "\n";
	K = B * C;
	cout << K << "\n";
	cout << "vuchitanie" << "\n";
	D = B - C;
	cout << D << "\n";
	cout << "delenie" << "\n";
	D = C / B;
	cout << D << "\n";
	cout << "Sortirovki" << "\n" << "\n";
	cout << "BubbleSort" << "\n";
	int t = clock();
	int arrrre[] = { 9,2,3,4,5,6,7 };
	MyVector<int> AH(7, arrrre);
	t = AH.BubbleSort();
	cout << "vreme sortirovki=" << t << "\n";
	cout << "otsortirovannue vector" << "\n";
	cout << AH << "\n" << "\n";
	int arrrr[] = { 9,2,1,4,5,6,3 };
	MyVector<int> U(7, arrrr);
	cout << "QuickSort" << "\n";
	int o = clock();
	o = U.QuickSort(0, B.GetRazmer() - 1);
	cout << "vreme sortirovki=" << o << "\n";
	cout << "otsortirovannue vector" << "\n";
	cout << U << "\n" << "\n";

	int arrrra[] = { 9,2,3,2,5,6,4 };
	MyVector<int> E(7, arrrra);
	cout << "InsertionSort" << "\n";
	int w = clock();
	w = E.InsertionSort();
	cout << "vreme sortirovki=" << w << "\n";
	cout << "otsortirovannue vector" << "\n";
	cout << E << "\n" << "\n";

	cout << "--------------------" << "\n";
	cout << "Matrica 1" << "\n";
	Matric<int> AB;
	cin >> AB;
	cout << "vvedeniya matrica KVADRATNUE 1" << AB << "\n";
	cout << "vvedite TOY ZHE RAZMERNOSTI Matricu!!!!";
	cout << "Matrica 2" << "\n";
	Matric<int> AC;
	cin >> AC;
	cout << "vvedeniya matrica 2" << AB << "\n";
	Matric<int> ABC;

	cout << "slozhenie" << "\n";
	ABC = AB + AC;
	cout << ABC << "\n";
	cout << "umnozhenie" << "\n";
	ABC = AB * AC;
	cout << ABC << "\n";
	cout << "vuchitanie" << "\n";
	ABC = AB - AC;
	cout << ABC << "\n";
	cout << "kolichestvo vxozhdeniy ukazannogo znacheniya" << "\n";
	cout << "Vector*Matrica" << "\n";
	int arrar[] = { 1,2,3 };
	MyVector<int> V1(3, arrar);
	Matric<int> V2;
	Matric<int> V3;
	cout << "vvedite razmernosti 1*3" << "\n";
	cin >> V2;
	V3 = V1 * V2;
	cout << V3 << "\n";
	cout << "Matrix*Vector" << "\n";
	Matric<int> VV;
	cout << "vvedite razmernost' 3*3" << "\n";
	cin >> VV;
	int arrereq[] = { 9,2,1 };
	MyVector<int> IO(3, arrereq);
	MyVector<int> I;
	I = VV * IO;
	cout << I << "\n";
	int uu;
	uu = E.Poisk(3);
	cout << uu << "\n";

	int rr;
	rr = AB.Poiskk(2);
	cout << rr << "\n";
	return 0;
}