# Custom Dynamic Array (C++)

Hi there! I'm currently a second-year computer engineering student, and I started this repository as part of a 6-month deep dive into advanced C++ and software architecture. 

The idea here isn't just to write code that works, but to actually understand what happens under the hood. Instead of taking the easy route and using `std::vector`, I'm building fundamental data structures from scratch. My main focus is on manual memory management, clean code principles, and keeping an eye on algorithmic efficiency.

##  Technical Details

I built a dynamic array that handles its own memory allocation. Here are the technical details I focused on:
* **Rule of Three:** Wrote a custom copy constructor and assignment operator to prevent shallow copy bugs and memory leaks.
* **Dynamic Resizing:** The array automatically doubles its capacity when it hits the limit.
* **Memory Optimization:** Added a `shrink_to_fit` method because leaving unused RAM allocated is a bad habit.
* **Operations:** Supports `push_back`, `pop_back`, `insert`, and `erase` with proper index boundary checks.

##  Big-O Complexity

Here is the time complexity breakdown for the array operations:

| Operation | Time Complexity | Note |
| :--- | :--- | :--- |
| Access `[i]` | $O(1)$ | Direct pointer arithmetic |
| Push Back | $O(1)$ | Amortized (due to occasional resizing) |
| Insert / Erase | $O(n)$ | Requires shifting existing elements |

## How to Run It

If you want to compile and test this specific module, run these commands:

```bash
cd Array
g++ -std=c++17 main.cpp -o my_array
./my_array
