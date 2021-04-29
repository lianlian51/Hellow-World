#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

void BucketSort(std::vector<int>& vec)
{
  int len = vec.size();
  int Max = INT_MIN;
  int Min = INT_MAX;
  // 1.计算出最大最小值
  for(int i = 0; i < len; ++i)
  {
    if(vec[i] > Max){
      Max = vec[i];
    }
    if(vec[i] < Min){
      Min = vec[i];
    }
  }

  // 2. 计算出桶的数量
  int bucketnum = (Max - Min) / len + 1;
  std::vector<std::vector<int>> temp(bucketnum);
  
  // 3. 将元素放入桶内
  for(int i = 0; i < len; ++i)
  {
    int num = (vec[i] - Min) / bucketnum;
    temp[num].push_back(vec[i]);
  }
  // 4. 对桶内的元素进行排序
  for(int i = 0; i < bucketnum; ++i){
    sort(temp[i].begin(), temp[i].end());
  }
  // 5. 将桶中的元素赋值给原序列
  int index = 0;
  for(int i = 0; i < bucketnum; ++i)
  {
    int knum = temp[i].size();
    int j = 0;
    while(j < knum)
    {
      vec[index++] = temp[i][j++];
    }
  }
}


int main()
{
  std::vector<int> vec{18, 11, 28, 45, 23, 50};
  BucketSort(vec);
  for(auto& e : vec)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
