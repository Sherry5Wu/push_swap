/*
Radix sort is a non-comparative integer sorting algorithm that sorts numbers by processing individual digits. It operates on the principle that numbers can be sorted digit by digit, from the least 
significant digit to the most significant digit (LSD Radix Sort) or vice versa (MSD Radix Sort). Here’s a detailed explanation of the LSD Radix Sort, which is the more commonly used variant:

How Radix Sort Works
Determine the Maximum Number of Digits:

Identify the number with the maximum digits in the list. This will determine the number of iterations required.
Sorting by Each Digit:

Starting from the least significant digit (rightmost digit), sort the numbers based on that digit using a stable sorting algorithm, like counting sort or bucket sort.
Move to the next significant digit and repeat the process. Continue until the most significant digit has been sorted.
Steps in LSD Radix Sort
Initialize the Data Structure:

Create an array of empty buckets (often 10 buckets for base-10 numbers).
Distribute the Numbers:

For the current digit position (starting with the least significant digit), place each number into the corresponding bucket based on the digit in that position.
Collect the Numbers:

Collect numbers from the buckets and concatenate them back into a single list, preserving the order of numbers within each bucket.
Repeat for All Digit Positions:

Repeat the distribute and collect steps for each digit position, moving from the least significant to the most significant digit.
Example
Given a list of numbers: [170, 45, 75, 90, 802, 24, 2, 66]

Step 1: Sort based on the least significant digit:

Buckets:
0: [170, 90]
1: []
2: [802, 2]
3: []
4: [24]
5: [45, 75]
6: [66]
7: []
8: []
9: []
Collected: [170, 90, 802, 2, 24, 45, 75, 66]
Step 2: Sort based on the next significant digit:

Buckets:
0: [802, 2]
1: []
2: [24]
3: []
4: [45]
5: []
6: [66]
7: [170, 75]
8: []
9: [90]
Collected: [802, 2, 24, 45, 66, 170, 75, 90]
Step 3: Sort based on the most significant digit:

Buckets:
0: [2, 24, 45, 66, 75, 90]
1: [170]
2: []
3: []
4: []
5: []
6: []
7: []
8: [802]
9: []
Collected: [2, 24, 45, 66, 75, 90, 170, 802]

Characteristics:

  Stable: Radix sort preserves the relative order of numbers with the same digit value.
  Complexity: The time complexity is O(d⋅(n + b)), wehre d is the number of digits, n is the number of elements, and 
              b is the base (for decimal numbers,b =10).
  Non-comparative: Unlike comparative sorts (e.g., quicksort, mergesort), radix sort does not compare elements directly.


Applications:

Used for sorting integers, strings, and other types of data where the ordering can be digit-based.
Particularly effective for large datasets with uniformly distributed values.
Non-comparative: Unlike comparative sorts (e.g., quicksort, mergesort), radix sort does not compare elements directly.
Applications
Used for sorting integers, strings, and other types of data where the ordering can be digit-based.
Particularly effective for large datasets with uniformly distributed values.
*/

/*
基数排序 (Radix Sort)
基数排序是一种非比较型排序算法，适用于整数排序。它通过对每位数字进行排序来实现整体排序。基数排序从最低有效位（个位）开始，将数字分配到对应的桶中，然后收集并重新分配数字，逐位排序直到最高有效位。

算法步骤
确定最大位数：
找到数组中最大数字的位数，确定排序需要多少轮。例如，对于数字 170, 45, 75, 90, 802, 24, 2, 66，最大数字是 802，它有 3 位，因此需要进行 3 轮排序。

按位数进行排序：
从最低有效位（个位）开始，对数组进行排序。使用计数排序或桶排序来排序每一位的数字。

详细步骤
准备桶：
创建 10 个桶（0 到 9），每个桶对应一个数字（0-9）。

分配桶：
遍历数组中的每个数字，根据当前位的数字，将其放入对应的桶中。例如，对于个位数，如果数字是 170，它的个位数是 0，所以将其放入桶 0 中。

收集数字：
按桶的顺序（从 0 到 9）收集数字，重新排列数组。

移动到下一位：
移动到下一位（十位、百位等），重复上述分配桶和收集数字的过程。

重复直到最高有效位：
重复上述过程，直到处理完最高有效位。
*/

#include<stdio.h>
#define MAX 20
//#define SHOWPASS
#define BASE 10

void print(int *a, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
}

void radixsort(int *a, int n) {
  int i, b[MAX], m = a[0], exp = 1;

  for (i = 1; i < n; i++) {
    if (a[i] > m) {
      m = a[i];
    }
  }

  while (m / exp > 0) {
    int bucket[BASE] = { 0 };

    for (i = 0; i < n; i++) {
      bucket[(a[i] / exp) % BASE]++;
    }

    for (i = 1; i < BASE; i++) {
      bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
      b[--bucket[(a[i] / exp) % BASE]] = a[i];
    }

    for (i = 0; i < n; i++) {
      a[i] = b[i];
    }

    exp *= BASE;

#ifdef SHOWPASS
    printf("\nPASS   : ");
    print(a, n);
#endif
  }
}

int main() {
  int arr[MAX];
  int i, n;

  printf("Enter total elements (n <= %d) : ", MAX);
  scanf("%d", &n);
  n = n < MAX ? n : MAX;

  printf("Enter %d Elements : ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nARRAY  : ");
  print(&arr[0], n);

  radixsort(&arr[0], n);

  printf("\nSORTED : ");
  print(&arr[0], n);
  printf("\n");

  return 0;
}
