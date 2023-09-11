#!/bin/bash
# run in /home/TU/tuq39715/CIS2107-lowlevel-programming directory

# paycheck
gcc -I/home/TU/tuq39715/CIS2107-lowlevel-programming/ -g src/take_input.c src/paycheck.c -o executables/pay

# revenue
gcc -I/home/TU/tuq39715/CIS2107-lowlevel-programming/ -g src/take_input.c src/revenue.c -o executables/rev