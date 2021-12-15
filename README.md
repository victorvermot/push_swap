<h1>Introduction
</h1>

Push_swap is a project developped by myself in ecole 42. The project was developed in C and it was done in a few weeks. The project introduces sorting algorithms and the notion of complexity.

# Goals
The goal of the project was to create a sorting algorithm, that takes a list of integer as argument. The project also had to follows specific rules.
- Only two stacks available to manipulate numbers, stack A and stack B
- Only a couple of specified instructions were available

# Operations available
- **SA** : Swap the two tops int from A.
- **SB** : Swap the two tops int from B.
- **SS** : Do both **SA** and **SB**.
- **PA** : Push a number from B to A.
- **PB** : Push a number from A to B.
- **RA** : Rotate stack A, the first number becomes last.
- **RB** : Rotate stack B, the first number becomes last.
- **RR** : Do both RA and RB.
- **RRA** : Inverted rotation of stack A, the last number becomes first.
- **RRB** : Inverted rotation of stack B, the last number becomes first.
- **RRR** : Do both RRA and RRB.

# Radix Algorithm

If the list given has 5 or less numbers, I hardcoded the solutions.

As for the rest, I chose to use a radix algorithm in order to sort my integers.

The algorithm follows this logic:
1. Simplify numbers so we don't have any negative : `[1, 0, -56]` becomes `[2, 1, 0]`.
2. Loop through my numbers and check each bits from right to left.
3. If the bit is equal to 0, push the number on the stack B. Else, rotate A.
4. Once the loop is over, push all elements from stack B back on top of stack A.
5. Repeat process until the biggest bit is read.

# Visualizer
A visualizer is integrated in the repo in order to get a better idea of how the algo works.

Run the command :

python3 pyviz.py \`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"\`.

[Link](https://github.com/o-reo/push_swap_visualizer) to the source of the script.