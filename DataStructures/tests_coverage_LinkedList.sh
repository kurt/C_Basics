#bin/bash

gcc test_LinkedList.c LinkeListFunctions.c  -o testlinklist -fprofile-arcs -ftest-coverage
./testlinklist
lcov  --directory . --no-external  -c --output-file testout
genhtml testout --output-directory LinkedListCoverage
rm *.gcno *.gcda testout

