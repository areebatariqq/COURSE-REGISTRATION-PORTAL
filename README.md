# COURSE-REGISTRATION-PORTAL
 (C Language Project)
📌 Project Overview

This project is a Course Registration Portal built in C language as part of my 1st semester coursework.
It simulates a basic university course management system where students can:

Register and sign in with credentials (Student ID & Password).

Register for available courses.

View registered courses.

Provide feedback (ratings) for courses and teachers.

Print feedback reports.

The system uses file handling to store student data (students.txt) and applies concepts of arrays, loops, structures, functions, and file I/O.

⚙️ Features

✅ Student registration and login system (with file storage).
✅ Course registration (up to 9 courses).
✅ View registered courses.
✅ Course feedback (1–5 rating system).
✅ Teacher feedback (1–5 rating system).
✅ Print evaluation results.
✅ Error handling for invalid input.

🛠️ Technologies & Concepts Used

Language: C

IDE/Compiler: GCC / Dev-C++ / Code::Blocks

Concepts:

File Handling

Arrays

Loops

Structures

Functions

User Authentication

📂 Project Structure
Course-Registration-Portal/
│
├── main.c          # Source code
├── students.txt    # File storing registered student IDs & passwords
└── README.md       # Documentation


(Exclude main.exe and .obj files from GitHub as they are system-specific build files.)

🚀 How to Run the Project

Clone the repository:

git clone https://github.com/yourusername/Course-Registration-Portal.git
cd Course-Registration-Portal


Compile the code:

gcc main.c -o portal


Run the program:

./portal


The program will create/append to students.txt automatically when new users are registered.

📸 Sample Menu
--- Menu ---
1. Register Courses
2. View Registered Courses
3. Evaluate Courses
4. Evaluate Teachers
5. Print Evaluation
6. Exit

✨ Learning Outcomes

Strengthened understanding of C programming fundamentals.

Gained hands-on experience with file handling in C.

Applied OOP concepts, arrays, loops, and data structures.

Learned about user authentication and feedback systems in console applications.
