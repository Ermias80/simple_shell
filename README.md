# 🐚 Simple Shell  

A **Simple Shell** is a basic command-line interpreter that allows users to interact with an operating system by executing commands. It mimics the functionality of standard Unix/Linux shells like **bash** or **sh**, but with a minimal set of features.  

## 📌 Overview  
In a Unix-based system, the shell serves as an interface between the **user** and the **kernel**, enabling users to:  
- Run programs  
- Manage files  
- Perform system operations  

## 🔥 Features  
A **Simple Shell** typically includes:  
✔ **Command Execution** – Running system commands like `ls`, `pwd`, and `echo`  
✔ **Parsing & Tokenization** – Breaking user input into commands and arguments  
✔ **Process Management** – Creating child processes using `fork()` and executing commands with `execve()`  
✔ **Error Handling** – Managing invalid commands and system errors  

## 💡 Why Build a Simple Shell?  
Building a simple shell is a **fundamental exercise** in understanding:  
- **System Calls** (`fork()`, `execve()`, `wait()`, etc.)  
- **Process Control**  
- **Memory Management**  

It is commonly assigned in computer science courses to teach **operating system concepts** and programming with **system-level functions** in C.  

## 🛠️ Getting Started  
To compile and run the shell:  
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./simple_shell
