#include <iostream>
#include <vector>

void MergeSort(std::vector<int>& vec, int left, int mid, int right, std::vector<int>& temp)
{
  int start1 = left, end1 = mid; 
  int start2 = mid, end2 = right;
  int index = left;
  while(start1 < end1 && start2 < end2)
  {
    if(vec[start1] < vec[start2])
    {
      temp[index++] = vec[start1++];
    }
    else 
    {
      temp[index++] = vec[start2++];
    }
  }

  while(start1 < end1)
  {
    temp[index++] = vec[start1++];
  }
  while(start2 < end2)
  {
    temp[index++] = vec[start2++];
  }


  for(int i = left; i < right; ++i)
  {
    vec[i] = temp[i];
  }
}


void Merge(std::vector<int>& vec, int left, int right, std::vector<int>& temp)
{
  int mid = left + ((right - left) >> 1);
  if(right - left > 1)
  {
    Merge(vec, left, mid, temp);
    Merge(vec, mid, right, temp);
    MergeSort(vec, left, mid, right, temp);
  }
}


int main()
{

  std::vector<int> vec{9, 3, 1, 7, 4, 0,5,8,2,3};
  std::vector<int> temp(vec.size());
  Merge(vec, 0, vec.size(), temp);
  for(auto& e : vec)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  return 0;
}
