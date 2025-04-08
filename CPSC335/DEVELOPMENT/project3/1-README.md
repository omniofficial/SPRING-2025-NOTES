# CPSC 335 PROJECT 3: ALGORITHM 1 - The Spread of Fire in a Forest

**LANGUAGE:** PYTHON

## Brief Overview (From document)

Imagine you are a forest ranger monitoring a forest that has recently experienced a wildfire. The forest is represented by a grid, where each cell can either be:
• 0: an empty area (no trees),
• 1: a healthy tree,
• 2: a burned tree (representing a tree affected by the wildfire).
Your task is to figure out how many days it will take for all healthy trees to burn down, considering that every day, any healthy tree that is adjacent (up, down, left, or right) to a burned tree will also burn down. You need to calculate the minimum number of days it will take for all healthy trees to burn, or return -1 if it is impossible for some trees to burn (i.e., if there are healthy trees that are not adjacent to any burned trees).

## How to execute this program

This program can be executed using any Python interpreter. To run it from the terminal, use the following command: `python3 fireforest.py`

If you would like to run this program in VS Code, you can use the integrated terimnal. Via VSCode, you can right click the file and select "Run Python File in Terminal", or you can use the following command: `python fireforest.py`.

## File Guide

-   `fireforest.py:` Main program file of the project
-   `1-README.md`: Initialization file
-   `1-PSEUDOCODE.txt:` Pseudocode for Algorithm
-   `Project Report:` Includes a brief overview, psuedocode, mathematical analysis (proving efficiency classes), and proof of compilation for this algorithm.
