# 🧭 File Explorer in C++

## 📄 Project Overview
This project is a **Command-Line File Explorer** developed in **C++** using **Linux System Calls**.  
It allows users to explore directories, view file contents, and perform common file operations directly from the terminal.

---

## ⚙️ Features
✅ List all files and directories  
✅ Change the current working directory  
✅ Create or remove directories  
✅ Delete files  
✅ Rename files or directories  
✅ View the content of a file  
✅ Search for files recursively  
✅ Display current path  

---

## 🧰 Technologies Used
- **Language:** C++  
- **Concepts:** File handling, directories, recursion, system calls  
- **Libraries:** `<dirent.h>`, `<sys/stat.h>`, `<unistd.h>`, `<ctime>`, `<iomanip>`  
- **Platform:** Linux / Ubuntu (via WSL or native)

---

## 🏗️ Folder Structure
file_explorer_cpp/
├── src/
│ └── file_explorer.cpp # main program
├── sample/
│ └── test.txt # sample file for testing
├── docs/
│ ├── README.md # documentation
│ └── demo_steps.md
└── Makefile


---

## 🖥️ How to Run
1. Open terminal inside the project folder.  
2. Compile and run using:
   ```bash
   make run

or manually-

g++ src/file_explorer.cpp -o file_explorer
./file_explorer

===== FILE EXPLORER MENU =====
1. List current directory
2. Change directory
3. Create directory
4. Remove directory
5. Delete file
6. Rename file/directory
7. View file content
8. Search for file
9. Show current path
0. Exit
==============================

Enter your choice: 1
Contents of /home/student/file_explorer_cpp:
src                 DIR        4096      2025-11-09 10:15:22
sample              DIR        4096      2025-11-09 10:12:08
Makefile            FILE       1024      2025-11-09 10:10:44

Learning Outcome:-
Through this project, I learned how to:
Use Linux system calls (opendir, readdir, mkdir, rmdir, remove, rename)
Handle file operations and directories in C++
Apply recursion for file searching
Create a simple interactive terminal-based application


🧾 License:-
This project is open-source and available under the MIT License.

👤 Author
Somnath Roul
Email: somnathroul377@gmail.com
GitHub: https://github.com/somnathroul
