# C Data Structures & Tricks 🎯

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**Clean C implementations** + **selected examples** from:

## 📚 **Recommended Books** (read **originals** in English!)
- *Modern C* by Jens Gustedt  
- *Expert C Programming* by Peter van der Linden  

> **These books are MUST-READ for serious C programmers.**  
> Way more interesting + harder examples than this repo!

## 📋 Implemented Modules
| Module | Complexity |
|--------|------------|
| [Binary Tree](./Binary_tree) | O(log n) |
| [Red-Black Tree](./Red_black_tree) | O(log n) |
| [Doubly Linked List](./Doubly_linked_list) | O(1) |
| [Heap](./Heap) | O(log n) |
| [Huffman Coding](./Huffman_coding) | O(n log n) |

## Quick Build (from root)

**CMake (recommended):**  
cmake -S Binary_tree -B Binary_tree/build  
cmake --build Binary_tree/build  
cd Binary_tree/build && ./Binary_tree  

**Makefile:**  
make -C Binary_tree  
cd Binary_tree/build && ./Binary_tree  

## ⚠️ **Binary Location Note**
- **Most modules**: Binary in `Module/build/` (run from `build/`)
- **Huffman Coding** works differently: Binary in `Huffman_coding/` (next to `main.c`)

**Huffman example:**  
cmake -S Huffman_coding -B Huffman_coding/build  
cmake --build Huffman_coding/build  
cd Huffman_coding && ./Huffman_coding  

## C_tricks/
15 examples from above books (fair use/educational).
See [C_tricks/README.md](C_tricks/README.md) for details.

