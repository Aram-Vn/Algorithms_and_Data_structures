#!/usr/bin/env python3

import subprocess
import os
import signal
from types import FrameType
from typing import List, Union
from rich.console import Console
from pyfiglet import figlet_format

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
    options: dict[str, str] = {
        '1': 'bubble_sort',
        '2': 'insertion_sort',
        '3': 'selection_sort',
        '4': 'quick_sort',
        '5': 'merge_sort',
        '6': 'counting_sort',
        '7': 'Linked_List_Merge_Sort',
        '8': 'heap_sort',
        '9': 'Finish testing', 
    }
    
    quick_sort_options: dict[str, str] = {
        'A': 'first',
        'B': 'last',
        'C': 'medianOfThree',
        'D': 'Random',
    }

    signal.signal(signal.SIGINT, exit_gracefully)

    text: str = "Sorting Algorithms"
    ascii_art = figlet_format(text, font="slant")
    console.print(ascii_art, style="bold cyan")
    
    while True:
        console.print("Enter the number corresponding to the sorting algorithm you want to test:\n", style="bold #00AAA6 u")
        for key, value in options.items():
            if key == str(len(options)):
                console.print(f"[green bold]{key}.[/green bold] {value}", style="b red")
            else:
                console.print(f"[green bold]{key}.[/green bold] {value}")
                
       
        console.print(f"   Choose from [green bold](1 - {len(options)})[green bold]")
        console.print("\n" + "-" * 40 + "\n", style="bold cyan")

        choice: str = input()

        if choice == '4':
            while True:        
                console.print("Choose the version of Quick Sort:")
                
                for key, value in quick_sort_options.items():
                   console.print(f"[green bold]{key}.[/green bold] {value}", style="")
                    
                console.print("[green bold]E.[/green bold] end Quick Sort chise\n", style="red")
                quick_sort_choice: str = input("Enter your choice (a/A/ b/B c/C d/D e/E): ").upper()
                
                if quick_sort_choice in ['A', 'B', 'C', 'D', 'E']:
                    if(quick_sort_choice == 'E'):
                        break
                    else:
                        pivot_name: str = quick_sort_options[quick_sort_choice]
                        test_Quick_Sort(quick_sort_choice, pivot_name)

                else:
                    console.print("Invalid choice. Please enter A, B, C, or D.", style="bold red")
        else:
            if choice in options:
                if choice == str(len(options)):
                    console.print("Ending the loop.", style="bold green")  
                    cleanup_test_files(TEST_FILES)
                    break
                else:
                    algorithm_name: str = options[choice]
                    test_sorting_algorithm(algorithm_name, choice)
            else:
                console.print("\n" + "-" * 60 + "\n", style="bold red \n")
                console.print(f"Invalid choice. Please enter a number between 1 and {len(options)}.", style="bold red \n")
                console.print("\n" + "-" * 60 + "\n", style="bold red \n")

if __name__ == "__main__":
    main()
