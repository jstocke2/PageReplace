# PageReplace

A C++ implementation of the page replacement algorithm for operating systems.

## Description

This project demonstrates the page replacement algorithm, a critical component of virtual memory management in operating systems. It simulates how an OS manages limited physical memory when running programs that require more memory than available.

## Features

- Page replacement simulation
- Multiple replacement strategies support
- Memory management visualization
- Page fault tracking
- Efficient memory utilization

## Technology Stack

- **Language**: C++
- **Standard**: C++11 or later

## Prerequisites

- C++ compiler (GCC 5.0+, Clang 3.8+, MSVC 2015+)
- C++11 or later standard

## Supported Algorithms

The implementation supports various page replacement strategies:

1. **FIFO (First-In-First-Out)**
   - Simple queue-based replacement
   - Replaces oldest page first

2. **LRU (Least Recently Used)**
   - Replaces least recently accessed page
   - Requires tracking page access times

3. **LFU (Least Frequently Used)**
   - Replaces least frequently used page
   - Requires tracking access frequency

4. **Optimal (Belady's Algorithm)**
   - Theoretical best performance
   - Replaces page needed furthest in future

## Building

### Compilation
```bash
g++ -std=c++11 -o page_replace page_replace.cpp main.cpp
```

With optimization and warnings:
```bash
g++ -std=c++11 -O2 -Wall -Wextra -o page_replace page_replace.cpp main.cpp
```

## Usage

```cpp
#include "PageReplace.h"

int main() {
    PageReplacer pr(3);  // 3 page frames
    
    // Simulate page requests
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    
    for (int page : pages) {
        pr.access_page(page);
    }
    
    cout << "Page faults: " << pr.get_page_faults() << endl;
    return 0;
}
```

## Implementation Details

### Page Frame Management
- Fixed number of physical page frames
- Tracks which pages are in memory
- Monitors page access patterns

### Page Fault Handling
- Detects when a needed page isn't in memory
- Selects victim page using replacement algorithm
- Loads requested page into memory
- Updates page table

### Performance Metrics
- Total page faults
- Page fault rate
- Memory utilization
- Hit/miss ratio

## Project Structure

```
PageReplace/
├── page_replace.h      # Header file with class definition
├── page_replace.cpp    # Implementation
├── main.cpp            # Test/demo program
└── Makefile            # Build instructions
```

## Example Output

```
Page Reference String: 7 0 1 2 0 3 0 4

FIFO Algorithm:
Page Faults: 6
Hit Rate: 25%

LRU Algorithm:
Page Faults: 5
Hit Rate: 37.5%

Optimal Algorithm:
Page Faults: 4
Hit Rate: 50%
```

## How Virtual Memory Works

1. Program requests a memory page
2. OS checks if page is in physical memory
3. If page is present: page hit (fast access)
4. If page is absent: page fault
5. OS selects victim page using replacement algorithm
6. Victim page is written to disk (if modified)
7. Requested page is loaded from disk
8. Memory access continues

## Requirements

- C++11 or later
- Standard C++ Library

## License

No license specified. See LICENSE file if present.

---

**Last Updated**: 2016
