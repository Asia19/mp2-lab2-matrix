#include "utmatrix.h"

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	pVector = new ValType[s];
	Size = s;
	StartIndex = si;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> //����������� �����������
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

template <class ValType> // ������
ValType& TVector<ValType>::operator[](int pos)
{
}

/*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (Size != v.Size) return 0;
	for (int i = 0; i < Size; i++) if (pVetor[i] != v.pVector[i]) return 0;
	return 1;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (Size != v.Size) return 1;
	for (int i = 0; i < Size; i++) if (pVetor[i] != v.pVector[i]) return 1;
	return 0;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	delete []pVector;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++) pVector[i] = v.pVector[i];
}

/*-------------------------------------------------------------------------*/

template <class ValType> // ��������� ������
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i] + val;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // ������� ������
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i] - val;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // �������� �� ������
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	for (int i = 0; i < Size; i++) pVector[i] = pVector[i]*val;
}

/*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size) throw "Error";
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i] + v.pVector[i];
	return vector;
} 

/*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size) throw "Error";
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i] - v.pVector[i];
	return vector;
} 
/*-------------------------------------------------------------------------*/

template <class ValType> // ��������� ������������
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	TVector vector(Size, StartIndex);
	for (int i = 0; i < Size; i++) vector[i] = pVector[i]*v.pVector[i];
	return vector;
} 

/*-------------------------------------------------------------------------*/


  // ����������������� �������
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);                    // �����������
	TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	bool operator==(const TMatrix &mt) const;      // ���������
	bool operator!=(const TMatrix &mt) const;      // ���������
	TMatrix& operator= (const TMatrix &mt);        // ������������
	TMatrix  operator+ (const TMatrix &mt);        // ��������
	TMatrix  operator- (const TMatrix &mt);        // ���������

												   // ���� / �����
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
} /*-------------------------------------------------------------------------*/

  // TVector �3 �2 �4 �6
  // TMatrix �2 �2 �3 �3
#endif