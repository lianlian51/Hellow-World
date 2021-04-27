#include <iostream>
#include <vector>

void ShellSort(std::vector<int>& vec)
{
  int len = vec.size();
  int gap = 3;
  while(gap >= 1)
  {
    for(int i = gap; i < len; ++i)
    {
      int temp = vec[i];
      int end = i - gap;
      while(end >= 0 && vec[end] > temp)
      {
        vec[end + gap] = vec[end];
        end -= gap;
      }
      vec[end + gap] = temp;
    }
    --gap;
  }
}


int main()
{
  std::vector<int> vec{9,2,3,88,4,5,1,90};
  ShellSort(vec);
  for(int i = 0; i < (int)vec.size(); ++i)
  {
    printf("%d ", vec[i]);
  }
  printf("\n");
  return 0;
}
