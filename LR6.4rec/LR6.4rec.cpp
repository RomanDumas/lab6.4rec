#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;							// ������� ���, ��� �� ������ ��'����� � ������ ���������� ����
// ������������



double MinElement(double*& b, int n, double t, int i);					//���� �������� �������� t(�������� � �����) 
int MinIndex(double*& b, int n, double mint, int index, int i);	//���� ������ �������� t
void Print(double*& b, int n, int i);					//�������� �� ����� �����
void createArr(double*& b, int n, int i);				//��������� ������� ����� � ������� (-10;10)
double negativeLeftElement(double*& b, int n, int N, int i);		//���� ����� ��'���� t ����
double SumBetweenElements(double*& b, int firstElementIndex, int secondElementIndex, double sum);	//����� ���� �� ����� ���������� � �����, �� ��������� ��
void changeArr(double*& b, int n);	//����� �����
void findElement(double*& b, int n, int i, int k, double x, int& r, int n2);	//���� �������� �������/��������
void shiftElements(double*& b, int k, int n2, int& r);

int main() {
	int n, firstNegativeElementIndex, secondNegativeElementIndex;
	double minIndex, minElement, firstNegativeElement, secondNegativeElement, sumBetweenElements, sum = 0, t;
	cout << "1.1---------------------------------------------" << endl;
	cout << "n -> ? ";cin >> n;
	double* b = new double[n];
	srand((unsigned)time(NULL));

	createArr(b, n, 0);
	cout << "array: " << endl;
	Print(b, n, 0);
	t = b[0];
	minElement = MinElement(b, n, t, 0);				//����� ���������� �������� � �����
	minIndex = MinIndex(b, n, minElement, 0, 0);	//����� ���� �� ����������� ��������� �������
	cout << endl
		<< "min element:" << endl << minElement << endl
		<< "min element index: " << endl << (int)minIndex << endl << endl;
	cout << "1.2---------------------------------------------" << endl;

	firstNegativeElement = negativeLeftElement(b, n, 0, 0);
	firstNegativeElementIndex = MinIndex(b, n, firstNegativeElement, 0, 0);
	cout << "first negative element " << firstNegativeElement << endl;
	cout << "first negative element index " << firstNegativeElementIndex << endl << endl;

	secondNegativeElement = negativeLeftElement(b, n, firstNegativeElementIndex + 1, 0);
	secondNegativeElementIndex = MinIndex(b, n, secondNegativeElement, 0, 0);
	cout << "second negative element " << secondNegativeElement << endl;
	cout << "second negative element index " << secondNegativeElementIndex << endl << endl;

	sumBetweenElements = SumBetweenElements(b, firstNegativeElementIndex, secondNegativeElementIndex, sum);
	cout << "sum between first and second negative elements " << sumBetweenElements << endl;

	cout << "2-----------------------------------------------" << endl;
	changeArr(b, n);
	cout << "array: " << endl;
	Print(b, n, 0);
	return 0;
}
void changeArr(double*& b, int n) {
	double x=0;
	int k = 0, l = 0, j = 0, i = 0, r = 0, n2;
	n2 = 0;	//�� ���� �� ��� ���������� ��������
	findElement(b, n, i, k, x, r, n2);
	return;
}
void findElement(double*& b, int n, int i, int k, double x, int &r, int n2) {	
	r = 0;
	if (i >= n)
		return;
	else {
		if (abs(b[i]) < 1) {
			x = b[i];
			k = i;
			shiftElements(b, k, n2, r);
			b[n2++] = x;
		}
	}
	return findElement(b, n, i+1, k, x, r, n2);
}
void shiftElements(double*& b, int k, int n2, int &r) {
	if (k < n2) {
		r = 1;
		return;
	}
	b[k] = b[k-1];
	return shiftElements(b, k - 1, n2, r);
}
double SumBetweenElements(double*& b, int firstElementIndex, int secondElementIndex, double sum) {
	if (firstElementIndex + 1 >= secondElementIndex) 
		return sum;
	else if(firstElementIndex + 1 < secondElementIndex)
		sum += b[firstElementIndex + 1];
	return SumBetweenElements(b, firstElementIndex + 1, secondElementIndex, sum);
}

double negativeLeftElement(double*& b, int n, int N, int i) { //N �� ��������� n;
	i = N;
	if (i > N)
		return b[i];
	else if (b[i] >= 0)
		;
	else if (b[i] < 0)
		return b[i];
	return negativeLeftElement(b, n, N+1, i);
}

double MinElement(double*& b, int n, double t, int i) {
	if (i >= n)
		return t;
	else if (t > b[i + 1])
		t = b[i + 1];
	else if (t < b[i + 1]) {
			t = t;
		}
	return MinElement(b, n, t, i + 1);
}

int MinIndex(double*& b, int n, double mint, int index, int i) {
	if (i >= n)
		return index;
	else if (mint == b[i])
		return index;
	index++;
	return MinIndex(b, n, mint, index, i + 1);
}

void Print(double*& b, int n, int i) {
	if (i >= n)
		return;
	cout << fixed;
	cout << setw(3) << setprecision(4) << " " << b[i];
	return Print(b, n, i + 1);
}
void createArr(double*& b, int n, int i) {
	double x;
	if (i >= n)
		return;
	double r = -5 + (double)rand() * 10 / RAND_MAX;	//������� ���������� ����� �� -5 �� 5
	b[i] = r;
	return createArr(b, n, i + 1);
}
