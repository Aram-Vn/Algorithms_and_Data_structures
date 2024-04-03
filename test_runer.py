#!/usr/bin/env python3

import subprocess
import os
import signal
from types import FrameType
from typing import List, Union, Callable
from rich.console import Console

console: Console = Console()

SORTING_ALGORITHMS_PATH: str = 'Sorting_Algorithms/src'
TESTS_PATH: str = 'Sorting_Algorithms/tests'
QUICK_SORT_DIR_PATH: str = 'Sorting_Algorithms/src/4__quick_sort'
TEST_FILES: List[str] = []


def test_Quick_Sort(chise: str, pivot: str) -> None:
    Quick_Sort_path: str = f'{QUICK_SORT_DIR_PATH}/{chise}__quick_sort_{pivot}.cpp'
    Quick_Sort_test_path: str = f'{TESTS_PATH}/test_quick_sort.cpp'
    
    try:        
        if not os.path.exists(Quick_Sort_path) or not os.path.exists(Quick_Sort_test_path):
            if not os.path.exists(Quick_Sort_path):
                console.print(f"\nError: '{Quick_Sort_path}' not found.", style="bold red")
            if not os.path.exists(Quick_Sort_test_path):
                console.print(f"\nError: '{Quick_Sort_test_path}' not found.", style="bold red")
        
            return
           
        subprocess.run(['g++', Quick_Sort_path, Quick_Sort_test_path, '-o', 'quick_sort_test', '-lgtest', '-lgtest_main'])
        console.print(f'\n**********_quick_sort_test_{pivot}**********\n', style="bold cyan")
        TEST_FILES.append('quick_sort_test')
        subprocess.run(['./quick_sort_test'], check=True)
        
    except subprocess.CalledProcessError as e: 
        console.print('\nError:', e, style="red")
        console.print(f"\nError executing command: {e.cmd}", style="red")

    console.print("\n" + "-" * 40 + "\n", style="bold cyan")


def compile_and_run_test(test_file: str, algorithm_source: str, z: str) -> None:
    try:
        sorthing_algorithm_path: str = f'{SORTING_ALGORITHMS_PATH}/{algorithm_source}'
        test_path: str = f'{TESTS_PATH}/{test_file}.cpp'
        
        if not os.path.exists(sorthing_algorithm_path) or not os.path.exists(test_path):
            if not os.path.exists(sorthing_algorithm_path):
                console.print(f"\nError: {sorthing_algorithm_path} not found.", style="bold red")
            if not os.path.exists(test_path):
                console.print(f"\nError: {test_path} not found.", style="bold red")
        
            return

        subprocess.run(['g++', test_path, sorthing_algorithm_path, '-o', f'{z}', '-lgtest', '-lgtest_main'])
        console.print(f"\n**********_{test_file}_**********\n", style="bold cyan")
        TEST_FILES.append(z)
        subprocess.run([f'./{z}'], check=True)
        
    except subprocess.CalledProcessError as e: 
        console.print('\nError:', e, style="red")
        console.print(f"\nError executing command: {e.cmd}", style="red")

    console.print("\n" + "-" * 40 + "\n", style="bold cyan")


def test_sorting_algorithm(algorithm_name: str, num: str) -> None:
    compile_and_run_test(f'test_{algorithm_name}', f'{num}__{algorithm_name}.cpp', f'{algorithm_name}_test')
    

def cleanup_test_files(files: List[str]) -> None:
    for file in files:
        try:
            os.remove(file)
        except FileNotFoundError:
            pass

def exit_gracefully(signal: signal.Signals, frame: Union[FrameType, None]) -> None:
    cleanup_test_files(TEST_FILES)
    console.print("\nCleanup complete.", style="bold cyan")
    console.print("Ending the loop.", style="bold green")
    exit()


def main() -> None:
    options: dict[str, Union[str, Callable[[], None]]] = {
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
        console.print("[green bold]1.[/green bold] Bubble Sort")
        console.print("[green bold]2.[/green bold] Insertion Sort")
        console.print("[green bold]3.[/green bold] Selection Sort")
        console.print("[green bold]4.[/green bold] Quick Sort")
        console.print("[green bold]5.[/green bold] Merge Sort")
        console.print("[green bold]6.[/green bold] Counting Sort")
        console.print("[green bold]7.[/green bold] Finish testing", style="red")
        console.print("   Choose from [green bold](1 - 6)[green bold]")
        console.print("\n" + "-" * 40 + "\n", style="bold cyan")

        choice: str = input()


        if choice == '4':
            while True:        
                console.print("Choose the version of Quick Sort:")
                console.print("[green bold]A.[/green bold] First Element Pivot")
                console.print("[green bold]B.[/green bold] Last Element Pivot")
                console.print("[green bold]C.[/green bold] Median of Three Pivot")
                console.print("[green bold]D.[/green bold] Random Pivot")
                console.print("[green bold]E.[/green bold] end Quick Sort chise\n", style="red")

                quick_sort_choice: str = input("Enter your choice (a/A/ b/B c/C d/D e/E): ").upper()
                
                if quick_sort_choice in ['A', 'B', 'C', 'D', 'E']:
                    if(quick_sort_choice == 'E'):
                        break
                    else:
                        pivot_name: str = options[quick_sort_choice]
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
                    algorithm_name: str = options[choice]
                    test_sorting_algorithm(algorithm_name, choice)
            else:
                console.print("Invalid choice. Please enter a number between 1 and 6.", style="bold red")

if __name__ == "__main__":
    main()
