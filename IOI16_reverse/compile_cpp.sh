#!/bin/bash

problem=reverse

g++ -O2 -std=c++11 -o $problem grader.cpp $problem.cpp
