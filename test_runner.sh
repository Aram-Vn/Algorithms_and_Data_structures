#!/bin/bash

TEST_FILES=()

# Function to compile and run test
compile_and_run_test() {
    test_file=$1
    algorithm_source=$2
    z=$3

    sorting_algorithm_path="Sorting_Algorithms/src/$algorithm_source"
    test_path="Sorting_Algorithms/tests/$test_file.cpp"

    if [ ! -f "$sorting_algorithm_path" ] || [ ! -f "$test_path" ]; then
        echo "Error: $sorting_algorithm_path or $test_path not found." >&2
        return 1
    fi

    g++ "$test_path" "$sorting_algorithm_path" -o "$z" -lgtest -lgtest_main
    echo -e "\n*********\-$test_file-/**********\n"

    if ! ./"$z"; then
        echo "Error executing test $z"
        return 1
    fi

    TEST_FILES+=("$z")

    echo -e "\n----------------------------------------\n"
}

# Function to test Quick Sort
test_Quick_Sort() {
    chise=$1
    pivot=$2
    Quick_Sort_path="Sorting_Algorithms/src/4__quick_sort/${chise}__quick_sort_${pivot}.cpp"
    Quick_Sort_test_path="Sorting_Algorithms/tests/test_quick_sort.cpp"

    if [ ! -f "$Quick_Sort_path" ] || [ ! -f "$Quick_Sort_test_path" ]; then
        echo "Error: $Quick_Sort_path or $Quick_Sort_test_path not found." >&2
        return 1
    fi

    g++ "$Quick_Sort_path" "$Quick_Sort_test_path" -o "quick_sort_test" -lgtest -lgtest_main
    echo -e "\n**********\-quick_sort_test-/$pivot**********\n"

    if ! ./quick_sort_test; then
        echo "Error executing test quick_sort_test"
        return 1
    fi

    TEST_FILES+=("quick_sort_test")

    echo -e "\n----------------------------------------\n"
}

# Function to cleanup test files
cleanup_test_files() {
    for file in "$@"; do
        if [ -f "$file" ]; then
            rm "$file"
        fi
    done
}

# Function to handle graceful exit
exit_gracefully() {
    cleanup_test_files "${TEST_FILES[@]}"
    echo -e "\nCleanup complete.\nEnding the loop.\n"
    exit
}

# Main function
main() {
    # Declare arrays
    options=("bubble_sort" "insertion_sort" "selection_sort" "quick_sort" "merge_sort" "counting_sort" "Linked_List_Merge_Sort" "heap_sort" "Finish testing")
    quick_sort_options=("first" "last" "medianOfThree" "Random")

    # Trap SIGINT signal
    trap exit_gracefully SIGINT

    # Main loop
    while true; do
        echo "Enter the number corresponding to the sorting algorithm you want to test:"
        # Print options
        for ((i=0; i<${#options[@]}; i++)); do
                echo "${i}. ${options[i]}"
        done

        echo "Choose from (0 - $(( ${#options[@]} - 1 ))):"
        read -r choice

        if [ "$choice" == "3" ]; then
            while true; do
                echo "Choose the version of Quick Sort (A B C D):"
                echo "A. first"
                echo "B. last"
                echo "C. median Of Three"
                echo "D. Random"
                echo "E. end Quick Sort chise"
                read -r quick_sort_choice

                case $quick_sort_choice in
                    [ABCD])
                        pivot_name=${quick_sort_options[$(( $(printf "%d" "'$quick_sort_choice") - $(printf "%d" "'A") ))]}
                        test_Quick_Sort "$quick_sort_choice" "$pivot_name"
                        ;;
                    [Ee])
                        break
                        ;;
                    *)
                        echo "Invalid choice. Please enter A, B, C, D, or E."
                        ;;
                esac
            done
        else
            if [ "$choice" -ge 1 ] && [ "$choice" -lt $(( ${#options[@]} - 1 )) ]; then
                algorithm_name=${options[$choice]}
                choice=$((choice + 1)) 
                compile_and_run_test "test_$algorithm_name" "$choice""__${algorithm_name}.cpp" "${algorithm_name}_test"

            elif [ "$choice" -eq $(( ${#options[@]} - 1 )) ]; then
                echo "Ending the loop."
                exit_gracefully
                break
            else
                echo "Invalid choice. Please enter a number between 0 and $(( ${#options[@]} - 1 ))."
            fi
        fi
    done
}

# Run main function
main
