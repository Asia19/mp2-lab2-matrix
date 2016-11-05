#include "matrix.h"


template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (Size != mt.Size) return 0;
	for (int l = 0; l < Size; l++) for (int i = 0; i < Size; i++) if (this->m[l][i] != mt.m[l][i]) return 0;
	return 1; 
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	if (Size != mt.Size) return 1;
	for (int l = 0; l < Size; l++) for (int i = 0; i < Size; i++) if (this->m[l][i] == mt.m[l][i]) return 0;
	return 1; 
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (Size != mt.Size) throw "error";
	for (int l = 0; l < Size; l++) for (int i = 0; i < Size; i++) if (m[l][i] != mt.m[l][i]) return 0;
	return *(this); 
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (Size != mt.Size) throw "error";
	TMatrix<ValType> mt2; 
	for (int l = 0; l < Size; l++) for (int i = 0; i < Size; i++) mt2.m[l][i] = m[l][i] + mt.m[l][i]);
	return mt2; 
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (Size != mt.Size) throw "error";
	TMatrix<ValType> mt2; 
	for (int l = 0; l < Size; l++) for (int i = 0; i < Size; i++) mt2.m[l][i] = m[l][i] - mt.m[l][i]);
	return mt2; 
} /*-------------------------------------------------------------------------*/

// TVector �3 �2 �4 �6
// TMatrix �2 �2 �3 �3
