#include "matrix.h"


template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	for (int i = 0; i < s; i++)
		pVector[i] = TVector<ValType>(s-i,i);
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
	return TVector<TVector<ValType>>::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
  return TVector<TVector<ValType>>::operator!=(mt);
}/*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (this != & mt)
	{
		if (Size != mt.Size)
		{
			delete []pVector;
			pVector = new TVector <ValType> [mt.Size];
		}
		Size=mt.SIze;
		StartIndex=mt.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i]=mt.pVector [i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/

// TVector �3 �2 �4 �6
// TMatrix �2 �2 �3 �3
