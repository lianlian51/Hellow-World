#include <iostream>

void CountSort(int* nums, int length)
{
  if(nums == NULL || length <= 0)
    return;
  // 1.找最大的值
  int n = nums[0];
  for(int i = 0; i < length; ++i)
  {
    if(nums[i] > n)
    {
      n = nums[i];
    }
  }

  // 2.将数字放在temp中
  int* temp = new int[n + 1];
  for(int i = 0; i < length; ++i){
    ++temp[nums[i]];
  }

  // 3.将数字回写到nums中
  int index = 0;
  for(int i = 0; i < n + 1; ++i)
  {
    while(temp[i] > 0)
    {
      nums[index++] = i;
      --temp[i];
    }
  }
}

int main()
{
  int nums[] = {5,5,2,2,4,3,6,5,3,2,5};
  CountSort(nums, sizeof(nums)/sizeof(nums[0]));
  for(auto& e: nums){
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
