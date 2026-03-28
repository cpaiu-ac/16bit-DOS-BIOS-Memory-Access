# 16bit-DOS-BIOS-Memory-Access
# 16-bit DOS & BIOS Memory Access in C

## 📌 About the Project
This repository contains a collection of low-level C programs designed for 16-bit DOS environments (e.g., Turbo C++). The code demonstrates direct memory access to the BIOS Data Area (BDA), segment:offset pointer manipulation, and bitwise operations to interrogate hardware configurations directly from memory.

Understanding these foundational concepts of memory mapping and hardware interaction is highly beneficial for bare-metal embedded systems and automotive software engineering.

## ⚙️ Core Features
* **BIOS Data Extraction:** Uses the `MK_FP` macro to create `far` pointers targeting segment `0x0040` in order to read the base addresses for COM1/COM2, LPT1, and the base memory size.
* **Hardware Equipment Interrogation:** Accesses the raw equipment list at `0x0040:0010` and applies bitwise masks to extract hardware details such as math coprocessor presence, video modes, and the number of serial/parallel ports.
* **Segment/Offset Manipulation:** Demonstrates the extraction of memory addresses from `far` pointers using the `FP_SEG` and `FP_OFF` macros to understand physical memory placement.
* **Dynamic Memory Algorithms:** Implements an algorithm to find the longest strictly increasing substring, showcasing dynamic memory allocation (`malloc`, `free`) and block memory copying (`memcpy`).

## 🛠️ Tech Stack & Concepts
* **Language:** C (16-bit DOS / Turbo C++ standard)
* **Concepts:** Segmented Memory Architecture, BIOS Data Area (BDA), Bitwise Operations, Direct Memory Access, `far` Pointers.

## 📁 Repository Structure
* `l31.c` - Extracts COM and LPT port addresses directly from the BIOS.
* `l32.c` - Parses the BIOS equipment word bit-by-bit.
* `l33.c` - Segment and offset address extraction utility.
* `l34.c` - Dynamic memory allocation and substring manipulation.
