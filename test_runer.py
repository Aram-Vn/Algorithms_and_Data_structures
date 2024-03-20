#!/usr/bin/env python3

import subprocess
import os
import signal
from rich.console import Console

console = Console()

def test_bubble_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_bubble_sort.cpp', 'Sorting_Algorithms/src/1__bubble_sort.cpp', '-o', 'bubble_sort_test', '-lgtest', '-lgtest_main'])
    console.print("\n**********_bubble_sort_test_**********\n", style="bold cyan")
    subprocess.run(['./bubble_sort_test'])
    subprocess.run(['rm', 'bubble_sort_test'])
    console.print("\n" + "-" * 40 + "\n", style="bold cyan")

def test_insertion_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_insertion_sort.cpp', 'Sorting_Algorithms/src/2__insertion_sort.cpp', '-o', 'insertion_sort_test', '-lgtest', '-lgtest_main'])
    console.print("\n**********_insertion_sort_test_**********\n", style="bold cyan")
    subprocess.run(['./insertion_sort_test'])
    subprocess.run(['rm', 'insertion_sort_test'])
    console.print("\n" + "-" * 40 + "\n", style="bold cyan")

def test_merge_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_merge_sort.cpp', 'Sorting_Algorithms/src/5__merge_sort.cpp', '-o', 'merge_sort_test', '-lgtest', '-lgtest_main'])
    console.print("\n**********merge_sort_test**********\n", style="bold cyan")
    subprocess.run(['./merge_sort_test'])
    subprocess.run(['rm', 'merge_sort_test'])
    console.print("\n" + "-" * 40 + "\n", style="bold cyan")

def test_quick_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_quick_sort.cpp', 'Sorting_Algorithms/src/4__quic_sort.cpp', '-o', 'quick_sort_test', '-lgtest', '-lgtest_main'])
    console.print("\n**********quick_sort_test**********\n", style="bold cyan")
    subprocess.run(['./quick_sort_test'])
    subprocess.run(['rm', 'quick_sort_test'])
    console.print("\n" + "-" * 40 + "\n", style="bold cyan")

def test_selection_sort():
    subprocess.run(['g++', 'Sorting_Algorithms/tests/test_selection_sort.cpp', 'Sorting_Algorithms/src/3__selection_sort.cpp', '-o', 'selection_sort_test', '-lgtest', '-lgtest_main'])
    console.print("\n**********selection_sort_test**********\n", style="bold cyan")
    subprocess.run(['./selection_sort_test'])
    subprocess.run(['rm', 'selection_sort_test'])
    console.print("\n" + "-" * 40 + "\n", style="bold cyan")

def cleanup_test_files(files):
    for file in files:
        try:
            os.remove(file)
        except FileNotFoundError:
            pass

def exit_gracefully(signal, frame):
    cleanup_test_files(['bubble_sort_test', 'insertion_sort_test', 'merge_sort_test', 'quick_sort_test', 'selection_sort_test'])
    console.print("\nCleanup complete.", style="bold cyan")
    console.print("Ending the loop.", style="bold green")
    exit()

options = {
    '1': test_bubble_sort,
    '2': test_insertion_sort,
    '3': test_merge_sort,
    '4': test_quick_sort,
    '5': test_selection_sort,
    '6': lambda: console.print("Ending the loop.", style="bold green")
}

if __name__ == "__main__":
    signal.signal(signal.SIGINT, exit_gracefully)

    while True:
        console.print("Enter the number corresponding to the sorting algorithm you want to test:")
        console.print("1. Bubble Sort")
        console.print("2. Insertion Sort")
        console.print("3. Merge Sort")
        console.print("4. Quick Sort")
        console.print("5. Selection Sort")
        console.print("6. Finish testing")
        console.print("   chose from [green bold](1 - 6)[green bold]")
        console.print("\n" + "-" * 40 + "\n", style="bold cyan")

        choice = input()

        if choice in options:
            options[choice]()
            if choice == '6':
                break
        else:
            console.print("Invalid choice. Please enter a number between 1 and 6.", style="bold red")