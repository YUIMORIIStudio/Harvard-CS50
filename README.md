# ⛺️ CS50x_2023_Harvard
This course teaches you how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web development. Languages include C, Python, SQL, and JavaScript plus CSS and HTML. Problem sets inspired by real-world domains of biology, cryptography, finance, forensics, and gaming. Designed for concentrators and non-concentrators alike, with or without prior programming experience. 68% of CS50 students have never taken CS before.

Enroll here: [CS50x](https://cs50.harvard.edu/x/2023/)
Instructor: [David J. Malan](https://cs.harvard.edu/malan/) 

# Notes📝 & Project🚀

## ⛳[Week-0]()  `[Theme: Basics of Programming]`

## Project: 

  - [Scratch Project](https://scratch.mit.edu/projects/)
>  Computer science is not so much about programming as it is about problem solving
## ⛳[Week-1](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1) `[Theme: Basics of C, Greedy Algorithm, Cryptography]`

## Project: 

  - Lab
    - [Population](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1/Submission%20/population)
  - Problem set
    - Mario
      - [Mario-less](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1/Submission%20/mario-less)
      - [Mario-more](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1/Submission%20/mario-more)
    - [cash](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1/Submission%20/cash)
    - [credit](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_1/Submission /credit)

## ⛳[Week-2](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/lecture_2)`[Theme: Arrays, Cryptography, Encryption]`

##      project

- Lab
  - [scrabble](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/scrabble)
- Problem set
  - [readability](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/readability)
  - [substitution](https://github.com/itsyuimorii/Harvard-CS50/tree/main/lecture_2/Submission/substitution)

# ⛳[Week-3]() `[Theme: Algorithms, Graph Theory Basics]`

## Project

  - Lab
    - [Sort]( )
  - Problem set
    - [Plurality]( )
    - [Runoff💥]( )

## [Running Time](https://cs50.harvard.edu/x/2023/notes/3/#running-time)

>  *running time* involves an analysis using *big O* notation. Take a look at the following graph:

- It’s the shape of the curve that shows the efficiency of an algorithm. Some common running times we may see are:
  - O(n2)
  - O(nlog⁡n)
  - O(n)
  - O(log⁡n)
  - O(1)

- Of the running times above, O(n2) is considered the worst running time, O(1) is the fastest.
- Linear search was of order O(n) because it could take *n* steps in the worst case to run.
- Binary search was of order O(log⁡n) because it would take fewer and fewer steps to run even in the worst case.
- Programmers are interested in both the worst case, or *upper bound*, and the best case, or *lower bound*.
- The Ω symbol is used to denote the best case of an algorithm, such as Ω(log⁡n).
- The Θ symbol is used to denote where the upper bound and lower bound are the same, where the best case and the worst case running times are the same.

## [Linear and Binary Search](https://cs50.harvard.edu/x/2023/notes/3/#linear-and-binary-search)

### Linear search 

Linear search sequentially checks every item in a list.

This has a time complexity of O(n) and Ω(1).

```c
int main(void)
{
  int numbers[] = {4,6,8,2,7,5,0};

  for (int i = 0; i < 7; i++)
  {
    if (numbers[i] == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```

### Binary Search

Binary search repeatedly divides in half the part of a list that could contain an item, until the possible locations is narrowed down to just one.

This has a time complexity of O(log n) and Ω(1).



## Structs

Using `typefed` and the `struct` keyword, C can create a datatype that is combination of other datatypes. This could be useful for storing key value pairs.

```c
typedef struct
{
  string name;
  string number;
}
person;
```

Phone numbers should be represented using strings not ints since they can have non-numeric characters in them.

```c
typedef struct
{
  string name;
  string number;
}
person;

int main(void)
{
  person people[2];

  people[0].name = "Brian";
  people[0].number = "+1-617-495-1000";

  people[1].name = "David";
  people[1].number = "+1-949-468-2750";

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(names[i].name, "David") == 0)
    {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```

##   [Sorting](https://cs50.harvard.edu/x/2023/notes/3/#sorting)

- *sorting* is the act of taking an unsorted list of values and transforming this list into a sorted one.

- When a list is sorted, searching that list is far less taxing on the computer. Recall that we can use binary search on a sorted list, but not on an unsorted one.

- It turns out that there are many different types of sort algorithms.

- *Selection sort* is one such search algorithm.
### Merge Sort 

  - In merge sort, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order. 
  
  - This algorithm is a very typical application of the Divide and Conquer method.
  
  - Merge sort leverages something called recursion touch on in more detail in a future video.

  - Order of (n Log n) (Worse case scenario - unsorted array)

- Omega (n log n)  (Best case scenario - sorted array)

   ![img](https://www.runoob.com/wp-content/uploads/2019/03/mergeSort.gif)

  - In pseudocode: 
    - Sort the left half of the array (assuming n >1)
    
    - Sort the right half of the array (assuming n>1)
    
    - Merge the two halves together
    
      
    
    ```java
    public class MergeSort implements IArraySort {
    
        @Override
        public int[] sort(int[] sourceArray) throws Exception {
            // 对 arr 进行拷贝，不改变参数内容
            int[] arr = Arrays.copyOf(sourceArray, sourceArray.length);
    
            if (arr.length < 2) {
                return arr;
            }
            int middle = (int) Math.floor(arr.length / 2);
    
            int[] left = Arrays.copyOfRange(arr, 0, middle);
            int[] right = Arrays.copyOfRange(arr, middle, arr.length);
    
            return merge(sort(left), sort(right));
        }
    
        protected int[] merge(int[] left, int[] right) {
            int[] result = new int[left.length + right.length];
            int i = 0;
            while (left.length > 0 && right.length > 0) {
                if (left[0] <= right[0]) {
                    result[i++] = left[0];
                    left = Arrays.copyOfRange(left, 1, left.length);
                } else {
                    result[i++] = right[0];
                    right = Arrays.copyOfRange(right, 1, right.length);
                }
            }
    
            while (left.length > 0) {
                result[i++] = left[0];
                left = Arrays.copyOfRange(left, 1, left.length);
            }
    
            while (right.length > 0) {
                result[i++] = right[0];
                right = Arrays.copyOfRange(right, 1, right.length);
            }
    
            return result;
        }
    
    }
    ```
    
    > ### Algorithm steps
    >
    > 1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
    > 2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置；
    > 3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
    > 4. 重复步骤 3 直到某一指针达到序列尾；
    > 5. 将另一序列剩下的所有元素直接复制到合并序列尾。

### Selection Sort

> Selection sort loops over a list, finding the smallest unsorted item and swapping it with the leftmost unsorted item until all items have been sorted. It is relatively inefficient.
>
> 选择排序是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。

> It has a time complexity of O(n2) and Ω(n2).

- Oder of n2 (Worse case scenario - unsorted array)

- Omega n2 (Best case scenario - sorted array)

 ![img](https://www.runoob.com/wp-content/uploads/2019/03/selectionSort.gif)

 ```java
  public class SelectionSort implements IArraySort {
  
      @Override
      public int[] sort(int[] sourceArray) throws Exception {
          int[] arr = Arrays.copyOf(sourceArray, sourceArray.length);
  
          // 总共要经过 N-1 轮比较
          for (int i = 0; i < arr.length - 1; i++) {
              int min = i;
  
              // 每轮需要比较的次数 N-i
              for (int j = i + 1; j < arr.length; j++) {
                  if (arr[j] < arr[min]) {
                      // 记录目前能找到的最小值元素的下标
                      min = j;
                  }
              }
  
              // 将找到的最小值和i位置所在的值进行交换
              if (i != min) {
                  int tmp = arr[i];
                  arr[i] = arr[min];
                  arr[min] = tmp;
              }
  
          }
          return arr;
      }
  }
 ```

 > ### Algorithm steps
 >
 > First find the smallest (large) element in the unsorted sequence and store it at the beginning of the sorted sequence.
 >
 > Then find the smallest (large) element from the remaining unsorted elements and put it at the end of the sorted sequence.
 >
 > Repeat the second step until all elements are sorted.

### Bubble Sort

> Bubble sort loops over a list, compares two adjacent elements and swaps them if they are in the wrong order. The loop is repeated until the list is sorted. The largest values bubble up to the end of the list.
>
> It has a time complexity of O(n2) and Ω(n).  

- Oder of n2 (Worse case scenario - unsorted array)
- Omega n (Best case scenario - sorted array)

```java
public class BubbleSort implements IArraySort {

    @Override
    public int[] sort(int[] sourceArray) throws Exception {
 
        int[] arr = Arrays.copyOf(sourceArray, sourceArray.length);

        for (int i = 1; i < arr.length; i++) {
 
            boolean flag = true;

            for (int j = 0; j < arr.length - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;

                    flag = false;
                }
            }

            if (flag) {
                break;
            }
        }
        return arr;
    }
}
```



![img](https://www.runoob.com/wp-content/uploads/2019/03/bubbleSort.gif)

> ### Algorithm steps
>
> Compare the adjacent elements. If the first is larger than the second, swap them both.
>
> Do the same for each pair of adjacent elements, from the first pair at the beginning to the last pair at the end. After this step is done, the last element will be the largest number.
>
> Repeat the above steps for all elements except the last one.
>
> Keep repeating the above steps for fewer and fewer elements at a time until there are no more pairs of numbers to compare.

## [Recursion](https://cs50.harvard.edu/x/2023/notes/3/#recursion)

# ⛳[Week-4]() `[Theme: Memory organization, Pointers⚠, Image filters, File manipulation & Data Recovery]`

## [Hexadecimal](https://cs50.harvard.edu/x/2023/shorts/hexadecimal/)

The hexadecimal system, aka base16 , is a much more concise way to express the data on a computer’s system.

```bash
0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
```
Hexadecimal makes this mapping easy because a group of four binary digits (bits) is able has 16 different combinations, and each of those combinations maps to a single hexadecimal digit.

## [Pointers](https://cs50.harvard.edu/x/2023/shorts/pointers/)

Pointers provide an alternative way to pass data between functions.

## [Defining Custom Types](https://cs50.harvard.edu/x/2023/shorts/defining_custom_types/)

## [Dynamic Memory Allocation](https://cs50.harvard.edu/x/2023/shorts/dynamic_memory_allocation/)

## [Call Stacks](https://cs50.harvard.edu/x/2023/shorts/call_stacks/)

## [File Pointers](https://cs50.harvard.edu/x/2023/shorts/file_pointers/)

## Custom Types

  - Lab

    - 💥[volumn](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/Week04/Submission/volume)
  - Problem set

    - [filter-less](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/Week04/Submission/fliter-less)
    - [recover](https://github.com/itsyuimorii/CS50x_2023_Harvard/tree/main/Week04/Submission/recover)

# ⛳[Week-5]( ) `[Theme: Data Structures⚠]`

## [Data Structures](https://cs50.harvard.edu/x/2023/shorts/data_structures/)

## [Structures](https://cs50.harvard.edu/x/2023/shorts/structures/)

## [Singly-Linked Lists](https://cs50.harvard.edu/x/2023/shorts/singly_linked_lists/)

## [Doubly-Linked Lists](https://cs50.harvard.edu/x/2023/shorts/doubly_linked_lists/)

## [Hash Tables](https://cs50.harvard.edu/x/2023/shorts/hash_tables/)

## [Tries](https://cs50.harvard.edu/x/2023/shorts/tries/)

## [Queues](https://cs50.harvard.edu/x/2023/shorts/queues/)

## [Stacks](https://cs50.harvard.edu/x/2023/shorts/stacks/)

  - Lab
    - 
  - Problem set
    - 💥

# ⛳[Week-6]( ) `[Theme: Basics of Python, Forensics, Probability]`

  - Lab
    - 
  - Problem set
    - 
    - 
      - 
      - 
    - 

# ⛳[Week-7]() `[Theme: SQLite, Database querying, Crime Investigation]`

  - Lab
    - 
  - Problem set
    - 
    - 💥

# ⛳[Week-8]() `[Theme: Basics of HTML, CSS, Javascript, DOM]`

  - Lab
    - 
  - Problem set
    - 

# ⛳[Week-9]() `[Theme: Flask, Python revisited, Jinja, Equity Markets(Stocks)]`

  - Lab
    - 
  - Problem set
    - 
