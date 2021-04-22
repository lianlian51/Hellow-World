#include <stdio.h>

void test(int* array, int size)
{
      int begin = 0;
      int end = size - 1;

      int MaxPos = begin;
      int MinPos = begin;

      while (begin < end)
        {
              int index = begin + 1;
              while (index <= end)
                {
                     if (array[MaxPos] < array[index])
                           MaxPos = index;
                     if (array[MinPos] > array[index])
                         MinPos = index;

                      ++index;
                  
        }

              if (MaxPos != end)
                    Swap(&array[MaxPos], &array[end]);

              if (MinPos == end)
                    MinPos = MaxPos;
              //个人觉得应该直接在此遍历一下，找到最小的标记较为妥当


                if (MinPos != 0)
                    Swap(&array[MinPos], &array[0]);

              begin++;
              end--;
          
    }
}

int main()
{
  int arr[] = {4,6,7,1,2,3,9,8};
  test(arr, 8);
  for(int i = 0; i < 8; ++i){
    printf("%d ", arr[i] );
  }
  printf("\n");
}
