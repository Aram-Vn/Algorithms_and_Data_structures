# Algorithms and Data Structures

This repository contains implementations of various sorting algorithms and data structures. The project aims to provide efficient and well-documented code for educational purposes and practical use cases.

## Table of Contents

- [Features](#features)
- [Directory Structure](#directory-structure)
- [Sorting Algorithms](#sorting-algorithms)
  - [Pre requirements for auto test](#pre-requirements-for-sorting-algorithms-test-auto-run)
  - [Manual Testing](#for-manual-testing)


## Features

- Implementations of common data structures like AVL Trees, Binary Search Trees, Graphs, and more.
- Various sorting algorithms including Bubble Sort, Quick Sort, Merge Sort, and others.
- Test cases for each data structure and sorting algorithm to ensure correctness.
- Easy-to-run test scripts for automated Sorting Algorithms testing, including measuring the time required for each sorting algorithm with the same amount of elements to see time that this or other sorting algorithms need to run with same amount of elements.

## Directory Structure

```bash
.
│
├── Data_structures
│   │
│   ├── AVL_Tree
│   │   ├── CMakeLists.txt
│   │   ├── headers
│   │   │   └── AVL_Tree.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── AVL_Tree.hpp
│   │   └── tests
│   │
│   ├── Binary_Search_Tree
│   │   ├── CMakeLists.txt
│   │   ├── headers
│   │   │   └── Binary_Search_Tree.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── Binary_Search_Tree.hpp
│   │   └── tests
│   │       ├── CMakeLists.txt
│   │       │
│   │       └── test_Binary_Search_Tree.cpp
│   │
│   ├── Graph
│   │   ├── CMakeLists.txt
│   │   ├── compile_commands.json
│   │   ├── headers
│   │   │   └── Graph.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── Graph.cpp
│   │   └── tests
│   │       ├── CMakeLists.txt
│   │       └── RB_Tree_test.cpp
│   │
│   ├── heap
│   │   ├── CMakeLists.txt
│   │   ├── headers
│   │   │   └── priority_queue.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── priority_queue.hpp
│   │   └── tests
│   │       ├── CMakeLists.txt
│   │       └── test_heap.cpp
│   │
│   ├── RB_Tree
│   │   ├── CMakeLists.txt
│   │   ├── compile_commands.json
│   │   ├── headers
│   │   │   └── RB_Tree.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── RB_Tree.hpp
│   │   └── tests
│   │       ├── CMakeLists.txt
│   │       └── RB_Tree_test.cpp
│   │
│   ├── weighted_graph_adj_list
│   │   ├── CMakeLists.txt
│   │   ├── compile_commands.json
│   │   ├── include
│   │   │   └── weighted_graph_adj_list.h
│   │   ├── main.cpp
│   │   ├── src
│   │   │   └── weighted_graph_adj_list.cpp
│   │   └── tests
│   │       ├── CMakeLists.txt
│   │       └── weighted_graph_adj_list_test.cpp
│   │
│   └── weighted_graph__matrix
│       ├── CMakeLists.txt
│       ├── compile_commands.json
│       ├── include
│       │   └── weighted_graph__matrix.h
│       ├── main.cpp
│       ├── src
│       │   └── weighted_graph__matrix.cpp
│       └── tests
│           ├── CMakeLists.txt
│           └── weighted_graph__matrix_test.cpp
│
├── Sorting_Algorithms
│   │
│   ├── include
│   │   ├── bubble_sort.h
│   │   ├── counting_sort.h
│   │   ├── heap_sort.h
│   │   ├── insertion_sort.h
│   │   ├── Linked_List_Merge_Sort.h
│   │   ├── merge_sort.h
│   │   ├── quick_sort.h
│   │   ├── selection_sort.h
│   │   └── Thread_MergeSort.h
│   │
│   ├── src
│   │   ├── 1__bubble_sort.cpp
│   │   ├── 2__insertion_sort.cpp
│   │   ├── 3__selection_sort.cpp
│   │   │
│   │   ├── 4__quick_sort
│   │   │   ├── A__quick_sort_first.cpp
│   │   │   ├── B__quick_sort_last.cpp
│   │   │   ├── C__quick_sort_medianOfThree.cpp
│   │   │   └── D__quick_sort_Random.cpp
│   │   │
│   │   ├── 5__merge_sort.cpp
│   │   ├── 6__counting_sort.cpp
│   │   ├── 7__Linked_List_Merge_Sort.cpp
│   │   ├── 8__heap_sort.cpp
│   │   └── 9__Thread_MergeSort.cpp
│   │
│   └── tests
│       ├── test_bubble_sort.cpp
│       ├── test_counting_sort.cpp
│       ├── test_heap_sort.cpp
│       ├── test_insertion_sort.cpp
│       ├── test_Linked_List_Merge_Sort.cpp
│       ├── test_merge_sort.cpp
│       ├── test_quick_sort.cpp
│       ├── test_selection_sort.cpp
│       └── test_Thread_MergeSort.cpp
│
├── README.md
├── requirements.txt
├── test_runner.py
└── test_runner.sh
```

## Sorting Algorithms

## pre requirements for Sorting Algorithms test auto run

To recreate the environment, you can run:

``` bash
python -m venv .venv
source .venv/bin/activate  # On Windows use `.venv\Scripts\activate`
pip install -r requirements.txt
```

Or if using `pipenv`:

```bash
pipenv install -r requirements.txt
```


after you can run `test_runner.py` by

```bash
./test_runner.py
#or 
python test_runner.py
```
You can choose from the following sorting algorithms to test:
<p align="center">
  <img src="https://github.com/Aram-Vn/Algorithms_and_Data_structures/assets/118690340/0b0b01bf-563d-4271-895d-c1557dc655d3" alt="Centered Image">
</p>



## for manual testing

To manually test individual sorting algorithms, you can compile and run the test files using the following

```bash
g++ <path_to_test_file > <path_to_according_src_file> -o <result_name>  -lgtest -lgtest_main -pthread
```
