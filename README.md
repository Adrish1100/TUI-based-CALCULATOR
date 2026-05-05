# 🧮 Calculator

> A console-based, menu-driven calculator written in **C**. Perform arithmetic, powers, roots, and logarithmic operations — all through an interactive terminal UI.

---

## 🗂️ Table of Contents

- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Limitations](#limitations)
- [File Structure](#file-structure)
- [Future Plans](#future-plans)

---

## 📖 About

This project is a **Terminal-Based Calculator** built in C. It provides both basic and advanced mathematical operations through a structured menu system.

The program uses ANSI escape codes (`gotoxy`) and system commands to simulate a UI-like experience in the terminal.

Built and tested in a standard C environment (Linux/Android).

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ Addition | Add two numbers |
| ➖ Subtraction | Subtract two numbers |
| ✖️ Multiplication | Multiply two numbers |
| ➗ Division | Divide numbers and show remainder |
| 🔢 Square / Cube | Compute square and cube |
| 📐 Roots | Square root and cube root |
| 🔋 General Power | Raise number to any exponent |
| 📊 Logarithms | Common (log10), Natural (ln), Binary (log2) |
| 🖥️ Terminal UI | Uses cursor positioning and formatted layout |



## 🚀 Getting Started

### Prerequisites

- A C compiler such as **GCC**
- Terminal (Linux/macOS/Windows or Android via CxxDroid)

### Compilation

gcc calculator.c -o calculator -lm
Run
Bash
./calculator
🖥️ Usage
On launch, a welcome screen is displayed followed by the main menu:

1) ADDITION
2) SUBTRACT
3) MULTIPLY
4) DIVIDE
5) SQUARE
6) SQUARE ROOT
7) CUBE
8) CUBE ROOT
9) GENERAL POWER
10) COMMON LOG
11) NATURAL LOG
12) BINARY LOG
Input Rules
Options 1–4 require two numbers
Options 5–12 require one number
General power asks for an additional exponent

⚠️ Limitations

1. Mixed Input Methods
Uses both scanf() and fgets(), which may cause:
skipped inputs:extra ENTER presses

2. Program Exit on Invalid Input
Invalid numeric input causes immediate termination using exit(1).

3. Platform Dependency
system("clear") works only on Linux/macOS
unistd.h and sleep() are not fully portable
ANSI escape codes (gotoxy) may not work in all terminals

4. UI Rigidity
The layout is hardcoded and may break on different terminal sizes.

5. Mathematical Edge Cases
Floating-point remainder (fmod) may not match user expectations
Power suffix logic (ST/ND/RD/TH) is not fully correct
📁 File Structure

.
├── calculator.c    # Main source file
└── README.md       # Documentation
🔮 Future Plans
[ ] Replace scanf() with safer input handling
[ ] Improve UI portability (remove gotoxy)
[ ] Add calculation history
[ ] Support full expression input (e.g., 2 + 3 * 5)
[ ] Modularize into multiple files
[ ] Improve error handling (no abrupt exits)
👤 Author
Adrish Datta
Made with C using structured programming and terminal UI concepts.
