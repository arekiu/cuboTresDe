#!/bin/bash

# Array of map test directories
MAP_DIRS=(
    # "./map/not_playable/fd_fails"
    # "./map/not_playable/parse_textures"
    # "./map/not_playable/parse_map"
    "./map/playable"
)

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
RESET='\033[0m'

# Initialize counters and result arrays
total_tests=0
passed_tests=0
failed_tests=0
passed_list=()
failed_list=()

# Function to run a test on a map
run_test() {
    local map=$1
    local test_result=0
    local output=""
    local valgrind_output=""

    echo -e "${CYAN}Running test on:${RESET} ${YELLOW}$map${RESET}"

    if [[ "$(uname)" == "Linux" ]]; then
        valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./cub3d "$map" 2>&1)
        test_result=$?
        # Capture cub3d output separately (excluding valgrind noise)
        output=$(echo "$valgrind_output" | grep -v "==[0-9]\{5,\}==")

        if echo "$valgrind_output" | grep -q "All heap blocks were freed"; then
            echo -e "${GREEN}Memory PASSED: No memory leaks detected.${RESET}"
            test_result=0
        else
            echo -e "${RED}Memory issues detected${RESET}"
            echo "$valgrind_output"
            test_result=1
        fi
        output=$(./cub3d "$map" 2>&1)
        test_result=$?
        if [ $test_result -eq 0 ]; then
            echo -e "${GREEN}Exited with status 0.${RESET}"
        else
            echo -e "${RED}Exited with non-zero status.${RESET}"
        fi
    fi

    echo -e "${BLUE}Program output:${RESET}"
    echo "$output"
    echo

    ((total_tests++))
    if [ $test_result -eq 0 ]; then
        ((passed_tests++))
        passed_list+=("$map")
    else
        ((failed_tests++))
        failed_list+=("$map")
    fi
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
    echo "═════════════════ Directory: $dir ═════════════════"
    echo -e "${RESET}"
    for map in "$dir"/*
    do
        run_test "$map"
    done
done

# Final results
echo -e "${MAGENTA}"
echo "╔══════════════════════════════════════╗"
echo "║             FINAL RESULTS            ║"
echo "╚══════════════════════════════════════╝"
echo -e "${RESET}"

echo -e "Total tests run: ${CYAN}$total_tests${RESET}"
echo -e "Tests passed:    ${GREEN}$passed_tests${RESET}"
echo -e "Tests failed:    ${RED}$failed_tests${RESET}"

if [ "$failed_tests" -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed!${RESET}"
else
    echo -e "${RED}❌ $failed_tests test(s) missing to complete ${RESET}"
fi

echo
echo -e "${GREEN}✔️  Passing tests:${RESET}"
for name in "${passed_list[@]}"; do
    echo -e "${GREEN}- $name${RESET}"
done

echo
echo -e "${RED}❌ Failing tests:${RESET}"
for name in "${failed_list[@]}"; do
    echo -e "${RED}- $name${RESET}"
done
