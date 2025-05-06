#!/bin/bash

# Array of map test directories
MAP_DIRS=(
    "./map/not_playable/fd_fails"
    # "./map/not_playable/parse_textures"
    # "./map/not_playable/parse_map"
    # "./map/playable"
)

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
RESET='\033[0m'

# Function to run a test on a map
run_test() {
    local map=$1

    echo -e "${CYAN}Running test on:${RESET} ${YELLOW}$map${RESET}"
    # Run the program and capture both stdout and stderr
    ./cub3d "$map"
    exit_status=$?

    # After the program runs, check if it exited with a non-zero status (failed test)
    # if [ $exit_status -ne 0 ]; then
    #     echo -e "${RED}Exited with non 0 status.${RESET}"
    # else
    #     echo -e "${GREEN}Exited with status 0.${RESET}"
    # fi

    # Only run valgrind on Linux
    if [[ "$(uname)" == "Linux" ]]; then
        # Run valgrind and capture output
        valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./cub3d "$map" 2>&1)

        # Check for memory leaks or errors
        if echo "$valgrind_output" | grep -q "All heap blocks were freed"; then
            echo -e "${GREEN}Memory PASSED: No memory leaks detected.${RESET}"
        else
            echo -e "${RED}Memory issues detected${RESET}"
            echo "$valgrind_output" # Show full valgrind output if there are issues
        fi
    else
        echo -e "${YELLOW}Test does not handle nor support memory check on mac OS${RESET}"
    fi

    # Add a new line after each test
    echo
}

# Display header
echo -e "${MAGENTA}"
echo "╔════════════════════════════════════════════════════╗"
echo "║                PARSER TESTS STARTED                ║"
echo "╚════════════════════════════════════════════════════╝"
echo -e "${RESET}"

# Loop through each directory and run tests on all maps inside
for dir in "${MAP_DIRS[@]}"
do
echo -e "${GREEN}"
echo "═════════════════ Directory:$dir ═════════════════"
echo -e "${RESET}"
    for map in "$dir"/*
    do
        run_test "$map"
    done
done
