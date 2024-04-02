#!/usr/bin/env python3

import subprocess
import os
import signal
from rich.console import Console

console = Console()

SORTING_ALGORITHMS_PATH = 'Sorting_Algorithms/src'
TESTS_PATH = 'Sorting_Algorithms/tests'
TEST_FILES = []


def test_Quick_Sort(chise, pivot):
    try:           
        subprocess.run(['g++', f'Sorting_Algorithms/src/4__quick_sort/{chise}__quick_sort_{pivot}.cpp', f'{TESTS_PATH}/test_quick_sort.cpp', '-o', 'quick_sort_test', '-lgtest', '-lgtest_main'])
        console.print(f'\n**********_quick_sort_test_{pivot}**********\n', style="bold cyan")
        TEST_FILES.append('quick_sort_test')
        subprocess.run(['./quick_sort_test'], check=True)
        
    except subprocess.CalledProcessError as e: 
        console.print('\nError:', e, style="red")
        console.print(f"\nError executing command: {e.cmd}", style="red")

    console.print("\n" + "-" * 40 + "\n", style="bold cyan")


def compile_and_run_test(test_file, algorithm_source, z):
    try:
   
        if not os.path.exists(f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}') or not os.path.exists(f'{TESTS_PATH}/{test_file}.cpp'):
            if not os.path.exists(f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}'):
                console.print(f"\nError: {SORTING_ALGORITHMS_PATH}/{algorithm_source} not found.", style="bold red")
            if not os.path.exists(f'{TESTS_PATH}/{test_file}.cpp'):
                console.print(f"\nError: {TESTS_PATH}/{test_file} not found.", style="bold red")
        
            return

           
        subprocess.run(['g++', f'{TESTS_PATH}/{test_file}.cpp', f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}', '-o', f'{z}', '-lgtest', '-lgtest_main'])
        console.print(f"\n**********_{test_file}_**********\n", style="bold cyan")
        TEST_FILES.append(z)
        subprocess.run([f'./{z}'], check=True)
        
    except subprocess.CalledProcessError as e: 
        console.print('\nError:', e, style="red")
        console.print(f"\nError executing command: {e.cmd}", style="red")

    console.print("\n" + "-" * 40 + "\n", style="bold cyan")


def test_sorting_algorithm(algorithm_name, num):
    compile_and_run_test(f'test_{algorithm_name}', f'{num}__{algorithm_name}.cpp', f'{algorithm_name}_test')
    

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


def main():
    options = {
        '1': 'bubble_sort',
        '2': 'insertion_sort',
        '3': 'selection_sort',
        'A': 'first',
        'B': 'last',
        'C': 'medianOfThree',
        'D': 'Random',
        '5': 'merge_sort',
        '6': 'counting_sort',
        '7': lambda: console.print("Ending the loop.", style="bold green")  
    }

    signal.signal(signal.SIGINT, exit_gracefully)

    while True:
        console.print("Enter the number corresponding to the sorting algorithm you want to test:")
        console.print("1. Bubble Sort")
        console.print("2. Insertion Sort")
        console.print("3. Selection Sort")
        console.print("4. Quick Sort")
        console.print("5. Merge Sort")
        console.print("6. Counting Sort")
        console.print("7. Finish testing", style="red")
        console.print("   Choose from [green bold](1 - 6)[green bold]")
        console.print("\n" + "-" * 40 + "\n", style="bold cyan")

        choice = input()


        if choice == '4':
            while True:        
                console.print("Choose the version of Quick Sort:")
                console.print("[green bold]A.[/green bold] First Element Pivot")
                console.print("[green bold]B.[/green bold] Last Element Pivot")
                console.print("[green bold]C.[/green bold] Median of Three Pivot")
                console.print("[green bold]D.[/green bold] Random Pivot")
                console.print("[green bold]E.[/green bold] end Quick Sort chise\n", style="red")

                quick_sort_choice = input("Enter your choice (a/A/ b/B c/C d/D): ").upper()
                
                if quick_sort_choice in ['A', 'B', 'C', 'D', 'E']:
                    if(quick_sort_choice == 'E'):
                        break
                    else:
                        pivot_name = options[quick_sort_choice]
                        test_Quick_Sort(quick_sort_choice, pivot_name)

                else:
                    console.print("Invalid choice. Please enter A, B, C, or D.", style="bold red")
        else:
            if choice in options:
                if choice == '7':
                    options[choice]()
                    cleanup_test_files(TEST_FILES)
                    break
                else:
                    algorithm_name = options[choice]
                    test_sorting_algorithm(algorithm_name, choice)
            else:
                console.print("Invalid choice. Please enter a number between 1 and 6.", style="bold red")

if __name__ == "__main__":
    main()
