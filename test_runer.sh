#!/bin/bash

while true; do
    echo -e "\nEnter the number corresponding to the sorting algorithm you want to test:"
    echo "1. Bubble Sort"
    echo "2. Insertion Sort"
    echo "3. Merge Sort"
    echo "4. Quick Sort"
    echo "5. Selection Sort"
    echo "6. Counting Sort"
    echo -e  "7. End the loop or just press <ctrl + c>\n"

    read choice

    case $choice in
        1)
            g++ Sorting_Algorithms/tests/test_bubble_sort.cpp Sorting_Algorithms/src/1__bubble_sort.cpp -o bubble_sort_test -lgtest -lgtest_main
            echo -e "   \n**********bubble_sort_test**********\n"
            ./bubble_sort_test
            rm bubble_sort_test
            ;;
        2)
            g++ Sorting_Algorithms/tests/test_insertion_sort.cpp Sorting_Algorithms/src/2__insertion_sort.cpp -o insertion_sort_test -lgtest -lgtest_main
            echo -e "   \n**********insertion_sort_test**********\n"
            ./insertion_sort_test
            rm insertion_sort_test
            ;;
        3)
            g++ Sorting_Algorithms/tests/test_merge_sort.cpp Sorting_Algorithms/src/5__merge_sort.cpp -o merge_sort_test -lgtest -lgtest_main
            echo -e  "  \n**********merge_sort_test**********\n"
            ./merge_sort_test
            rm merge_sort_test
            ;;
        4)
            g++ Sorting_Algorithms/tests/test_quick_sort.cpp Sorting_Algorithms/src/4__quick_sort.cpp -o quick_sort_test -lgtest -lgtest_main
            echo -e "   \n**********quick_sort_test**********\n"
            ./quick_sort_test
            rm quick_sort_test
            ;;
        5)
            g++ Sorting_Algorithms/tests/test_selection_sort.cpp Sorting_Algorithms/src/3__selection_sort.cpp -o selection_sort_test -lgtest -lgtest_main
            echo -e "   \n**********selection_sort_test**********\n"
            ./selection_sort_test
            rm selection_sort_test
            ;;
        6)
            g++ Sorting_Algorithms/tests/test_counting_sort.cpp Sorting_Algorithms/src/6__counting_sort.cpp -o counting_sortTest_test -lgtest -lgtest_main
            echo -e "   \n**********Counting Sort**********\n"
            ./counting_sortTest_test
            rm counting_sortTest_test
            ;;
        
        7)
            echo "Ending the loop."
            break
            ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 6."
            ;;
    esac
done
