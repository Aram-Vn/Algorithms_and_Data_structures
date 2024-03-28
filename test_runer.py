#!/usr/bin/env python3

import subprocess
import os
import signal
from rich.console import Console

console = Console()

SORTING_ALGORITHMS_PATH = 'Sorting_Algorithms/src'
TESTS_PATH = 'Sorting_Algorithms/tests'
TEST_FILES = []

def compile_and_run_test(test_file, algorithm_source, z):
    try:
        subprocess.run(['g++', f'{TESTS_PATH}/{test_file}.cpp', f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}', '-o', f'{z}', '-lgtest', '-lgtest_main'])
        print('g++', f'{TESTS_PATH}/{test_file}.cpp', f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}', '-o', f'{z}', '-lgtest', '-lgtest_main')
        print(f'./{z}')
        console.print(f"\n**********_{test_file}_**********\n", style="bold cyan")
        subprocess.run([f'./{z}'], check=True)
        TEST_FILES.append(z)
        
    except subprocess.CalledProcessError as e: 
        console.print('\nError:', e, style="red")
        console.print(f"\nError executing command: {e.cmd}", style="red")

    console.print("\n" + "-" * 40 + "\n", style="bold cyan")


def test_sorting_algorithm(algorithm_name, algorithm_source, num):
    algorithm_source_without_extension = algorithm_source.split('.')[0]
    compile_and_run_test(f'test_{algorithm_name}', f'{num}__{algorithm_source}', f'{algorithm_source_without_extension}_test')

def cleanup_test_files(files):
    for file in files:
        try:
            os.remove(file)
        except FileNotFoundError:
            pass

def exit_gracefully(signal, frame):
    cleanup_test_files(TEST_FILES)
    console.print("\nCleanup complete.", style="bold cyan")
    console.print("Ending the loop.", style="bold green")
    exit()

options = {
    '1': ('bubble_sort', 'bubble_sort.cpp'),
    '2': ('insertion_sort', 'insertion_sort.cpp'),
    '3': ('selection_sort', 'selection_sort.cpp'),
    '4': ('quick_sort', 'quic_sort.cpp'),
    '5': ('merge_sort', 'merge_sort.cpp'),
    '6': ('counting_sort', 'counting_sort.cpp'),
    '7': lambda: console.print("Ending the loop.", style="bold green")
}

def main():
    signal.signal(signal.SIGINT, exit_gracefully)

    while True:
        console.print("Enter the number corresponding to the sorting algorithm you want to test:")
        console.print("1. Bubble Sort")
        console.print("2. Insertion Sort")
        console.print("3. Selection Sort")
        console.print("4. Quick Sort")
        console.print("5. Merge Sort")
        console.print("6. Counting Sort")
        console.print("7. Finish testing")
        console.print("   Choose from [green bold](1 - 6)[green bold]")
        console.print("\n" + "-" * 40 + "\n", style="bold cyan")

        choice = input()

        if choice in options:
            if choice == '7':
                options[choice]()
                break
            else:
                algorithm_name, algorithm_source = options[choice]
                test_sorting_algorithm(algorithm_name, algorithm_source, choice)
        else:
            console.print("Invalid choice. Please enter a number between 1 and 6.", style="bold red")

if __name__ == "__main__":
    main()
