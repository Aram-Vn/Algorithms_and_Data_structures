#!/usr/bin/env python3

import subprocess

def test_bubble_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_bubble_sort.cpp', 'Sorting_Algorithms/src/1__bubble_sort.cpp', '-o', 'bubble_sort_test', '-lgtest', '-lgtest_main'])
    print("\n**********bubble_sort_test**********\n")
    subprocess.run(['./bubble_sort_test'])
    subprocess.run(['rm', 'bubble_sort_test'])

def test_insertion_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_insertion_sort.cpp', 'Sorting_Algorithms/src/2__insertion_sort.cpp', '-o', 'insertion_sort_test', '-lgtest', '-lgtest_main'])
    print("\n**********insertion_sort_test**********\n")
    subprocess.run(['./insertion_sort_test'])
    subprocess.run(['rm', 'insertion_sort_test'])

def test_merge_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_merge_sort.cpp', 'Sorting_Algorithms/src/5__merge_sort.cpp', '-o', 'merge_sort_test', '-lgtest', '-lgtest_main'])
    print("\n**********merge_sort_test**********\n")
    subprocess.run(['./merge_sort_test'])
    subprocess.run(['rm', 'merge_sort_test'])

def test_quick_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_quick_sort.cpp', 'Sorting_Algorithms/src/4__quic_sort.cpp', '-o', 'quick_sort_test', '-lgtest', '-lgtest_main'])
    print("\n**********quick_sort_test**********\n")
    subprocess.run(['./quick_sort_test'])
    subprocess.run(['rm', 'quick_sort_test'])

def test_selection_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_selection_sort.cpp', 'Sorting_Algorithms/src/3__selection_sort.cpp', '-o', 'selection_sort_test', '-lgtest', '-lgtest_main'])
    print("\n**********selection_sort_test**********\n")
    subprocess.run(['./selection_sort_test'])
    subprocess.run(['rm', 'selection_sort_test'])

options = {
    '1': test_bubble_sort,
    '2': test_insertion_sort,
    '3': test_merge_sort,
    '4': test_quick_sort,
    '5': test_selection_sort,
    '6': lambda: print("Ending the loop.")
}

while True:
    print("Enter the number corresponding to the sorting algorithm you want to test:")
    print("1. Bubble Sort")
    print("2. Insertion Sort")
    print("3. Merge Sort")
    print("4. Quick Sort")
    print("5. Selection Sort")
    print("6. Finish testing")

    choice = input()

    if choice in options:
        options[choice]()
        if choice == '6':
            break
    else:
        print("Invalid choice. Please enter a number between 1 and 6.")
