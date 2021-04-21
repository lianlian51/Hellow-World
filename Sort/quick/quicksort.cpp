#include <cstdio>

int GetIndex(int* matrix, int left, int right)
{
  int middle = (right - left) >> 1;
  if(matrix[left] < matrix[right - 1]){
    if(matrix[middle] < matrix[left])
      return left;
    else if(matrix[middle] > matrix[right - 1]){
      return right - 1;
    }
    else 
      return middle;
  }
  else {
    if(matrix[middle] < matrix[right - 1])
      return right - 1;
    else if(matrix[middle] > matrix[left])
      return left;
    else 
      return middle;
  }
}

void Swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int Quick1(int* matrix, int left, int right)
{
  int start = left;
  int end = right - 1;
  int key = matrix[end];
  while(start < end)
  {
    while(start < end && matrix[start] <= key)
      ++start;
    while(start < end && matrix[end] >= key)
      --end;
    if(start < end)
      Swap(matrix[start], matrix[end]);
  }
  if(start != right - 1)
    Swap(matrix[right - 1], matrix[end]);

  return start;
}

int Quick2(int* matrix, int left, int right)
{
  int start = left; 
  int end = right - 1;
  int key = matrix[end];
  while(start < end)
  {
    while(start < end && matrix[start] <= key)
      ++start;

    if(start < end)
      matrix[end--] = matrix[start];

    while(start < end && matrix[end] >= key)
      --end;

    if(end > start)
      matrix[start++] = matrix[end];
  }
  matrix[start] = key;
  return start;
}

int Quick3(int* matrix, int left, int right)
{
  int cur = left;
  int prev = cur - 1;
  
  int i = GetIndex(matrix, left, right);
  int key = matrix[i];
  // int key = matrix[right - 1];
  while(cur < right)
  {
    if(matrix[cur] < key){
      prev = cur;
      cur++;
    }
    else 
      cur++;
    if(prev + 1 != cur){
      Swap(matrix[cur], matrix[++prev]);
    }
  }
  // 最后一次出来也要交换一次
  // 把基准值放在prev的位置
  // if(++prev != right - 1){
  if(++prev != i){
    Swap(matrix[prev], matrix[right - 1]);
  }
  return prev;
}


void Quick(int* matrix, int left, int right)
{
  if(right - left > 1)//left < right)
  {
    int middle = Quick2(matrix, left, right);
    Quick(matrix, left, middle);
    Quick(matrix, middle + 1, right);
  }
}


int main()
{
  int array[] = { 9, 3, 8, 6, 7, 2, 1, 0, 4, 5  };
  Quick(array, 0, sizeof(array) / sizeof(array[0]));
  for(int i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
