#include <iostream>
#include <vector>
#include <algorithm>

void Swap(int& a, int & b)
{
  int temp = a;
  a = b;
  b = temp;
}

// 递归版本
void HeapSort1(std::vector<int>& vec, int len, int index)
{
  int left = index * 2 + 1;
  int right = index * 2 + 2;

  int maxIdx = index;
  if(left < len && vec[left] > vec[maxIdx]) maxIdx = left;
  if(right < len && vec[right] > vec[maxIdx]) maxIdx = right;

  if(maxIdx != index)
  {
    Swap(vec[maxIdx], vec[index]);
    HeapSort1(vec, len, maxIdx);
  }
}

void Heap1(std::vector<int>& vec)
{
  int len = vec.size();
  for(int i = (len - 2) >> 1; i >= 0; --i)
  {
    HeapSort1(vec, len, i);
  }

  for(int i = len - 1; i >= 1; --i){
    Swap(vec[0], vec[i]);
    HeapSort1(vec, i, 0);
  }
}


int main()
{

  std::vector<int> vec{ 9, 3, 8, 6, 7, 2, 1, 0, 4, 5} ;
  Heap1(vec);

  for(auto e : vec){
    std::cout << e << " "; 
  }
  std::cout << std::endl;
  return 0;
}
