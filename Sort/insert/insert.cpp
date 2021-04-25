#include <iostream>
#include <vector>

void Insert(std::vector<int>& vec)
{
  int len = vec.size();
  for(int i = 1; i < len; ++i)
  {
    int index = i;
    int key = vec[index];
    while(--index >= 0 && vec[index] > key)
    {
      vec[index + 1] = vec[index];
    }
    vec[index + 1] = key;
  }
}


int main()
{
  std::vector<int> vec{8, 5, 6, 4, 2, 15, 77, 6, 9};
  for(auto e: vec)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  Insert(vec);
  for(auto e: vec)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
