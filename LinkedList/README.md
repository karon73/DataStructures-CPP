# C++ Data Structures Library

This repository is a foundational C++ library built entirely from scratch. The core objective is to implement fundamental data structures without relying on the standard library (`std::vector`, `std::list`), focusing heavily on manual memory management, object-oriented design, and algorithmic efficiency.

## 🏗️ Project Structure

The repository is modularized into distinct directories, each containing the class implementation and its respective test file:

* **`Array/`**: Contains `DynamicArray`, a self-resizing contiguous memory block implementation.
* **`LinkedList/`**: Contains a robust Singly Linked List with deep encapsulation.

## ⚙️ Technical Highlights

* **Memory Safety & Destructors:** Strict adherence to memory management. Custom destructors are implemented to explicitly `delete` all dynamically allocated heap memory, ensuring zero memory leaks.
* **Encapsulation:** Node structures are securely nested (`private struct Node`) within the main classes to prevent external manipulation and ensure data integrity.
* **Resource Ownership:** Copy constructors and assignment operators are explicitly deleted (`= delete`) to prevent shallow copy bugs and enforce strict ownership of pointers.

## 📊 Big-O Complexity Matrix

| Data Structure | Operation | Time Complexity | Note |
| :--- | :--- | :--- | :--- |
| **Dynamic Array** | Access `[i]` | $O(1)$ | Direct pointer arithmetic |
| | Push Back | $O(1)$ | Amortized due to resizing |
| | Insert / Erase | $O(n)$ | Requires shifting elements |
| **Singly Linked List** | Push Front | $O(1)$ | Head pointer reassignment |
| | Push Back | $O(n)$ | Requires traversal to the tail |
| | Insert (Index) | $O(n)$ | Requires traversal to index |
| | Pop Front | $O(1)$ | Direct memory deallocation |

## 🚀 Getting Started

To compile and run the data structures locally, use a standard C++17 compiler. 

```bash
# Clone the repository
git clone [https://github.com/karon73/DataStructures-CPP.git](https://github.com/karon73/DataStructures-CPP.git)
cd "DataStructures-CPP"

# Example: Compiling and running the LinkedList tests
cd LinkedList
g++ -std=c++17 main.cpp -o run_list
./run_list
