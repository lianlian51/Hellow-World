#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort_1(vector<int>& arr, int len)
{
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < len - i -1; ++j){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


void BubbleSort_2(vector<int>& arr, int len)
{
  for(int i = 0; i < len; ++i){
    bool flag = true;
    for(int j = 0; j < len - i -1; ++j){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = false;
      }
    }
    if(flag)
      break;
  }
}

void BubbleSort_3(vector<int>& arr, int len)
{
  int sortBorder = len - 1;
  int lastExchangeindex = 0;
  for(int i = 0; i < len; ++i){
    bool flag = true;
    for(int j = 0; j < sortBorder; ++j){
      if(arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = false;
        lastExchangeindex = j;
      }
    }

    sortBorder = lastExchangeindex;
    if(flag)
      break;
  }
}


int main()
{
  int i = 0;
  vector<int> arr1{2,6,4,8,1,9,3,0,7};
  vector<int> arr2{2,6,4,8,1,9,3,0,7};
  vector<int> arr3{2,6,4,8,1,9,3,0,7};

  BubbleSort_1(arr1, arr1.size());
  BubbleSort_2(arr2, arr2.size());
  BubbleSort_3(arr3, arr3.size());

  int len = arr1.size();
  for(i = 0; i < len; ++i){
    printf("%d ", arr1[i]);
  }

  std::cout << std::endl;
  for( i = 0; i < len; ++i){
    printf("%d ", arr2[i]);
  }
  std::cout << std::endl;
  for(i = 0; i < len; ++i){
    printf("%d ", arr3[i]);
  }
  std::cout << std::endl;
  return 0;
}
