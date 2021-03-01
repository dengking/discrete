#if !defined MATRIX_H
#define MATRIX_H

enum Error_code{success,fail};

class Matrix
{
public:
	Matrix(int m,int n);
	Matrix(Matrix &x);
	void clrMatrix();
	void operator=(Matrix &x);
	void read();
	Matrix transform();
    Matrix operator+(Matrix &x);
	Matrix operator-(Matrix &x);//�����������ֱ��ͨ���ӷ����
	Matrix operator*(Matrix &x);
	void printMatrix();
	void swapRows(int i,int j);
private:
	int row;
	int col;
	double *tab;//������Ϊtab
};
#endif