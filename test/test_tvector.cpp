#include "vector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  int size = 4;
  TVector<int> v1(size);
  TVector<int> v2(size);
  for (int i = 0; i < size; i++) v1[i]=1;
  ASSERT_NO_THROW(v2=v1);
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	int size = 4;
  TVector<int> v1(size);
  TVector<int> v2(size);
  for (int i = 0; i < size; i++) v1[i]=1;
  v2=v1;
  EXPECT_EQ(v1,v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  int size = 4;
  TVector<int> v1(size);
  TVector<int> v2(size);
  for (int i = 0; i < size; i++) v1[i]=1;
  v2=v1;
  v1[0]=2;
  EXPECT_NE (v1[0],v2[0]);  
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)////////////?????????????????????????????????????????????????????
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  ASSERT_ANY_THROW(TVector<int> v(4, -1));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  int size = 4;
  TVector<int> v(size);
  for (int i = 0; i < size; i++) v[i]=1;
  ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  int size = 4;
  TVector<int> v1(size),v2(size);
  ASSERT_NO_THROW(v2=v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    int size1 = 4, size2=6;
  TVector<int> v1(size1),v2(size2);
  v2=v1;
  EXPECT_NE(size2,v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    int size1 = 4, size2 = 6;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1;
  ASSERT_NO_THROW(v2=v1);  
}

TEST(TVector, compare_equal_vectors_return_true)
{
   int size1 = 4, size2=6;
  TVector<int> v1(size1),v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1;
  v2=v1;
  EXPECT_EQ(1,(v1==v2));
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  int size = 4;
  TVector<int> v(size);
  for (int i = 0; i < size; i++) v[i]=1;
  EXPECT_EQ(1,(v==v));
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  int size1 = 4, size2 = 6;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1; 
  for (int i = 0; i < size2; i++) v2[i]=1;
  EXPECT_NE(v1,v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
  int val = 3,size = 2;
  TVector<int> v(size);
  v[0]=1;
  v[1]=3;
  ASSERT_NO_THROW(v+val);
}

TEST(TVector, can_subtract_scalar_from_vector)
{  
  int val = 3,size = 2;
  TVector<int> v(size);
  v[0]=1;
  v[1]=3;
  ASSERT_NO_THROW(v-val);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  int val = 3,size = 2;
  TVector<int> v(size);
  v[0]=1;
  v[1]=3;
  ASSERT_NO_THROW(v*val);  
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  int size = 2;
  TVector<int> v1(size), v2(size);
  v1[0]=1;
  v1[1]=3;
  v2[0]=5;
  v2[1]=6; 
  ASSERT_NO_THROW(v1+v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  int size1 = 4,size2 = 6;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1; 
  for (int i = 0; i < size2; i++) v2[i]=2;
  ASSERT_ANY_THROW(v1+v2);   
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  int size = 2;
  TVector<int> v1(size), v2(size);
  v1[0]=1;
  v1[1]=3;
  v2[0]=5;
  v2[1]=6; 
  for (int i = 0; i < size; i++) v2[i]=-(v2[i]-v1[i]);
  v1=v1-v2;
  EXPECT_EQ(v1,v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  int size1 = 4,size2 = 6;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1; 
  for (int i = 0; i < size2; i++) v2[i]=2;
  ASSERT_ANY_THROW(v1-v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  int size = 4;
  TVector<int> v1(size), v2(size);
  v1[0]=1;
  v1[1]=3;
  v2[0]=5;
  v2[1]=6;
  for (int i = 0; i < size; i++) v2[i]=v2[i]*v1[i];
  v1=v1*v2;
  EXPECT_EQ(1,(v1==v2));
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  int size1 = 4,size2 = 6;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++) v1[i]=1; 
  for (int i = 0; i < size2; i++) v2[i]=2;
  ASSERT_ANY_THROW(v1*v2);
}

