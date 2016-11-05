#include "vector.h"

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	pVector = new ValType[s];
	Size = s;
	StartIndex = si;
	for (int i = 0; i < Size; i++) pVector[i]=0;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++) pVector[i] = ValType[i];

}

/*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[]pVector;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
}

/*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (Size != v.Size) return 0;
	for (int i = 0; i < Size; i++) if (pVetor[i] != v.pVector[i]) return 0;
	return 1;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (Size != v.Size) return 1;
	for (int i = 0; i < Size; i++) if (pVetor[i] != v.pVector[i]) return 1;
	return 0;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (Size != v.Size) 
	{
		Size = v.Size;
		delete []pVector;
		pVector = new ValType[Size];
	}
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++) pVector[i] = v.pVector[i];
	return *(this);
}

/*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i] + val;
	return this;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i] - val;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i]*val;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size) throw "Error";
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i] + v.pVector[i];
	return vector;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size) throw "Error";
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i] - v.pVector[i];
	return vector;
} 
/*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i]*v.pVector[i];
	return vector;
} 

/*-------------------------------------------------------------------------*/

