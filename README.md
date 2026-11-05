## Yahtzee (C++)

A simple console-based implementation of the classic Yahtzee dice game, written in C++.

## Features
- Roll five six-sided dice.
- Reroll selected dice up to two times per turn.
- 13 traditional Yahtzee scoring categories.
- Automatic score calculation and scorecard tracking.
- Bonus points for reaching 63 points in the upper section.
- Additional Yahtzee bonus scoring.

## Compilation

Compile the project using g++:

```bash
g++ game.cpp yahtzee.cpp -o yahtzee
```
# How to Play
1. Roll the five dice.
2. Decide whether to reroll.
3. Select which dice to keep or reroll.
4. You can roll up to three times per turn.
5. Choose one of the 13 scoring categories.
6. Repeat until all the slots have been filled.

Run the executable:


```bash
./yahtzee
```
On Windows:


```bash
yahtzee.exe
```

## Files
- `game.cpp` – Main game logic and player interaction.
- `yahtzee.hpp` – Scoring function declarations.
- `yahtzee.cpp` – Scoring calculations and sorting algorithm.
