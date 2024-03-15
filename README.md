# Sorting_algorithms

## for testing 
```bash
g++ <path_to_test_file > <path_to_according_src_file> -o <result_name>  -lgtest -lgtest_main -pthread
```

## test_bubble_sort
```bash
g++ tests/test_bubble_sort.cpp src/1__bubble_sort.cpp -o test_bubble_sort -lgtest -lgtest_main
```

## test_insertion_sort
```bash
g++ tests/test_insertion_sort.cpp src/2__insertion_sort.cpp -o insertion_sort -lgtest -lgtest_main
```