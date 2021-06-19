#!/bin/bash
for i in {1..5};
do
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;
# echo $ARG;
./push_swap $ARG | ./checker_OS $ARG;
./push_swap $ARG | wc -l;
done
# 5 1 4 2 