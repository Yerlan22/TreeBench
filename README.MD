# 🌳 TreeBench — Generic Tree Structures Benchmark

**TreeBench** is a C++ interactive console program designed to **implement, test, and compare different tree data structure representations**.  
It also includes a **queue (Cola)** data structure and supports **execution time measurements** to analyze the performance of various algorithms.

---

## 🚀 Overview

This project provides a **hands-on environment** for studying and experimenting with several tree representations, including:

- **Child List (ALH)**  
- **Leftmost Child–Right Sibling (AHMI–HD)**  
- **Last Pointer to Parent (AUPP)**  
- **Parent Pointer Array (AARP)**  

The active representation can be selected by defining one of the following macros at the top of the main file:

```cpp
#define ALG_BUSQUEDA_ALH
#define ALG_BUSQUEDA_AHMI_HD
#define ALG_BUSQUEDA_AUPP
#define ALG_BUSQUEDA_AARP
