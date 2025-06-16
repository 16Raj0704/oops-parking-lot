# 🚗 OOP-Based Parking Lot Management System

A C++ implementation of a Parking Lot Management System following Object-Oriented Programming principles. This project demonstrates practical usage of classes, encapsulation, and STL containers to simulate real-world parking operations.

---
## 📌 Table of Contents


- [Features](#features)
- [Tech Stack](#tech-stack)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Sample I/O](#sample-io)
- [Folder Structure](#folder-structure)
- [License](#license)

---

## ✅ Features

- Create and manage a parking lot of dynamic size
- Allocate and deallocate parking slots
- Track cars by registration number and color
- Query current status and search efficiently
- Designed using SOLID OOP principles

---

## 🛠️ Tech Stack

| Tool         | Description                       |
|--------------|-----------------------------------|
| C++          | Core programming language         |
| STL          | `vector`, `unordered_map`, etc.   |
| Git & GitHub | Version control & collaboration   |

---

## 🚀 Getting Started

### 1️⃣ Clone the repository

git clone https://github.com/16Raj0704/oops-parking.git
cd oops-parking

### 2️⃣ Compile
```bash
g++ main.cpp -o parking
```
### 3️⃣ Run 

```bash
./parking 
```
 
## Usage
```bash
create_parking_lot 6
park KA-01-HH-1234 White
park KA-01-HH-9999 White
leave 2
status
registration_numbers_for_cars_with_colour White

```

---
## 📤 Sample I/O

### input
```bash
create_parking_lot 3
park KA-01-HH-1234 White
park KA-01-HH-9999 Black
park KA-01-BB-0001 Red
leave 1
```
### 📥 Output
```bash
Created a parking lot with 3 slots
Allocated slot number: 1
Allocated slot number: 2
Allocated slot number: 3
Slot number 1 is free
 
```
---
## 📁 Folder Structure
```bash
oops-parking/
├── main.cpp           # Core logic
├── README.md          # Project documentation
└── input.txt (optional)
```
---
###  📝 License 
This project is licensed under the MIT License

---
### 👤 Author 

**Raj**  
GitHub: [@16Raj0704](https://github.com/16Raj0704)  
🚀 LeetCode: [raj0014](https://leetcode.com/raj0014) 
💼 LinkedIn: [rajmohite](https://www.linkedin.com/in/rajmohite)
