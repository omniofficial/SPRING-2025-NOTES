# CPSC 335 PROJECT 1: ALGORITHM 1 - Greedy Approach to Hamiltonian Problem

**LANGUAGE:** C++

## Brief Overview

A set of cities is laid out in a circle, connected by a circular road that runs clockwise. Each city has a gas station providing fuel, and the distances between neighboring cities are known. A car, capable of driving a certain number of miles per gallon of fuel, must pick a starting city such that it can fill up the tank in that city. The car then drives to the next city, refills with that city’s fuel, continues to the next city, and so on, until it returns to the starting city with 0 or more gallons of fuel remaining. This city is called the preferred starting city. The problem guarantees that there will always be exactly one valid starting city. The input consists of two arrays: one for the distances between neighboring cities and another for the fuel available at each city. The goal is to design an algorithm that returns the index of the preferred starting city.

## How to execute this program

This program can be executed using any C++ compiler, particularly g++. To execute within the terminal, please use the command: `startingcity.cpp`. Then, run the executional file using the command: `./a.out`. An output should display within your desired terminal.

If you would like to run this program in VS Code, you can use the c++ compiler of your choice to compile.


## File Guide

-   `startingcity.cpp:` Main program file of the project
-   `HamiREADME.md`: Initialization file
-   `startingcity_pseudo.md:` Pseudocode for Algorithm
-   `Project Report:` Includes a brief overview, psuedocode, mathematical analysis (proving efficiency classes), and proof of compilation for this algorithm. 