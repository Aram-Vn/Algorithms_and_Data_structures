cmake_minimum_required(VERSION 3.10)

project(RB_Tree)

add_executable(RB_Tree main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(RB_Tree PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(RB_Tree PRIVATE 
    -Wall                       # Enable almost all compiler warnings.
    -Wextra                     # Provides additional warning messages.
    -Wshadow                    # Warns when a local variable shadows another variable.
    -Wswitch                    # Warns about missing cases in switch statements.
    -pedantic                   # Ensures strict ISO C++ compliance.
    -Wformat=2                  # Checks printf-style format strings for correctness.
    -Wconversion                # Warns about implicit type conversions.
    -Wnull-dereference          # Warns about potential null pointer dereferences.
    -Wunused-parameter          # Warns about function parameters that are declared but not used.
    -Wunreachable-code          # Warns about code that can never be reached.
    -Wimplicit-fallthrough      # Warns when a switch case falls through without a break.
    
    -Werror                                # Treats all warnings as errors.
    -Werror=return-type                    # Treats functions that fail to return a value as errors.
    -Werror=uninitialized                  # Treats the use of uninitialized variables as errors.
    -Werror=unused-result                  # Treats the use of an expression result as an error if it's unused.
    -Werror=strict-overflow                # Treats certain kinds of integer overflow as errors.
    -Werror=implicit-function-declaration  # Treats calls to functions without a previous declaration as errors.
   
    -fsanitize=address         # Enables AddressSanitizer (ASan) for memory error detection.
    -fsanitize=undefined       # Enables UndefinedBehaviorSanitizer (UBSan) for undefined behavior detection.
   
    -fno-omit-frame-pointer    # Instructs the compiler not to omit the frame pointer in generated code.
)

target_link_options(RB_Tree PRIVATE 
    -fsanitize=address      # Links with AddressSanitizer (ASan) runtime library.
    -fsanitize=undefined    # Links with UndefinedBehaviorSanitizer (UBSan) runtime library.
)

target_compile_features(RB_Tree PRIVATE cxx_std_20)
