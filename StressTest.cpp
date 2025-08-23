/*
#!/bin/bash

g++ -std=c++17 -O2 -Wall $1.cpp -o main
g++ -std=c++17 -O2 -Wall brute.cpp -o brute
g++ -std=c++17 -O2 -Wall rand.cpp -o rand

test_count=100
passed=0


for ((i=1; i<=$test_count; i++))
do
    
    ./rand > in.txt
    
    
    ./main < in.txt > out.txt
    ./brute < in.txt > ans.txt
    
        cat in.txt
    if diff -q out.txt ans.txt > /dev/null; then
        echo -e "\033[32m测试 #$i AC\033[0m"
        ((passed++))
    else
        echo -e "\033[31m测试 #$i WA\033[0m"
        cat in.txt
        cat out.txt
        echo -e "\n\033[36m[正确输出]:\033[0m"
        cat ans.txt
        exit 1
    fi
done

echo -e "\033[34m测试完成，通过率: $passed/$test_count\033[0m"
*/