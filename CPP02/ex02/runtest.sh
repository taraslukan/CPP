#!/bin/bash

echo "== Subject Test =="
./fixed

echo "== Compare Test =="
c++ test_compare.cpp Fixed.cpp -o cmp -std=c++98 -Wall -Wextra -Werror
./cmp

echo "== Arithmetic Test =="
c++ test_arith.cpp Fixed.cpp -o ar -std=c++98 -Wall -Wextra -Werror
./ar

echo "== Increment Test =="
c++ test_inc.cpp Fixed.cpp -o inc -std=c++98 -Wall -Wextra -Werror
./inc

echo "== Min/Max Test =="
c++ test_minmax.cpp Fixed.cpp -o mm -std=c++98 -Wall -Wextra -Werror
./mm
