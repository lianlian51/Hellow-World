#include <iostream>
using namespace std;
#include <vector>

void SelectSort_1(vector<int> &arr)
{
  int len = arr.size();
  for(int i = 0; i < len; ++i){
    int maxPos = 0;
    for(int j = 0; j < len - i; ++j){
      if(arr[j] > arr[maxPos])
        maxPos = j;
    }
    if(maxPos != len - i - 1)
      swap(arr[maxPos], arr[len - i - 1]);
  }
}

void SelectSort_2(std::vector<int> &arr)
{
  int len = arr.size();
  int left = 0;
  int right = len - 1;
  while(left < right)
  {
    int min_pos = left;
    int max_pos = left;
    for(int i = left; i <= right; ++i){
      if(arr[min_pos] > arr[i]){
        min_pos = i;
      }
      if(arr[max_pos] < arr[i]){
        max_pos = i;
      }
    }
    if(min_pos != left)
      swap(arr[min_pos], arr[left]);
    if(max_pos == left){
      max_pos = min_pos;
    }
    if(max_pos != right)
      swap(arr[max_pos], arr[right]);
    ++left, --right;
  }
}

int main()
{
  std::vector<int> arr1{2,3,8,7,4,6,5,1,0};
  std::vector<int> arr2{2,3,8,7,4,6,5,1,0};

  SelectSort_1(arr1);
  SelectSort_2(arr2);

  for(auto e :arr1){
    std::cout << e << " ";
  }
  std::cout << std::endl;

  for(auto e :arr2){
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
