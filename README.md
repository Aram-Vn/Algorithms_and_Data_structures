[Sorting Algorithms](#sorting-algorithms)


# Sorting Algorithms
- [Bubble sort](#bubble-sort)
- [Insertion sort](#insertion-sort)
- [Selection sort](#selection-sort)
- [Quick sort](#quick-sort)
    - first 
    - last
    - medianOfThree
    - Random
- [Merge sort](#merge-sort)
- [Counting sort](#counting-sort)


## Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Invariants
- Initialization: The list is unsorted.
- Maintenance: After each iteration, the largest unsorted element is placed at its correct position.
- Termination: The list is sorted.

### Complexity
    
Time Complexity:
- Best Case: `O(n)`  - When the array is already sorted.
- Worst Case: `O(n^2)` When the array is sorted in reverse order.
- Average Case: `O(n^2)`

Space Complexity: 
- `O(1)` - The algorithm sorts the input array in-place.
## Insertion Sort
Insertion sort is a simple sorting algorithm that builds the final sorted list one item at a time. It iterates through the input list, removing one element at a time and then finding its correct position within the sorted part of the list. It repeats this process until no unsorted elements remain.

### Invariants
- Initialization: The list is unsorted.
- Maintenance: After each iteration, the current element is inserted into its correct position within the sorted part of the list.
- Termination: The list is sorted.

### Complexity
Time Complexity:
- Best Case: `O(n)` - When the array is already sorted.
- Worst Case: `O(n^2)` - When the array is sorted in reverse order.
- Average Case: `O(n^2)`

Space Complexity: 
- `O(1)` - The algorithm sorts the input array in-place.


## Selection Sort
Selection sort is a simple sorting algorithm that divides the input list into two parts: the sorted sublist and the unsorted sublist. Initially, the sorted sublist is empty, and the unsorted sublist contains all the elements. The algorithm repeatedly finds the smallest (or largest, depending on the sorting order) element from the unsorted sublist and moves it to the end of the sorted sublist. This process continues until the unsorted sublist becomes empty.

### Invariants
- Initialization: The entire list is unsorted.
- Maintenance: After each iteration, the smallest (or largest) element from the unsorted sublist is moved to its correct position in the sorted sublist.
- Termination: The entire list is sorted.

### Complexity
Time Complexity:
- Best Case: O(n^2)
- Worst Case: O(n^2)
- Average Case: O(n^2)
Space Complexity: 
- O(1) - The algorithm sorts the input array in-place.

## Quick Sort

## Merge Sort

## Counting Sort




<!-- ## for testing 
```bash
g++ <path_to_test_file > <path_to_according_src_file> -o <result_name>  -lgtest -lgtest_main -pthread
```

## test_bubble_sort
```bash
g++ tests/test_bubble_sort.cpp src/1__bubble_sort.cpp -o bubble_sort_test -lgtest -lgtest_main
```

## test_insertion_sort
```bash
g++ tests/test_insertion_sort.cpp src/2__insertion_sort.cpp -o insertion_sort_test -lgtest -lgtest_main
```

## test_merge_sort
```bash
g++ tests/test_merge_sort.cpp src/5__merge_sort.cpp -o merge_sort_test -lgtest -lgtest_main-lgtest_main -->
```