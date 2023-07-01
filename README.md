# candsqlite
A semister project i made in Data insertion and retrieval from database using C and Sqlite Database


1. Install the GCC compiler on your system if you haven't already. You can download the MinGW-w64 compiler # Student Registration System 
This is a simple student registration system implemented in C, which allows users to register new students and retrieve student details by their ID. 
The program utilizes the SQLite database to store and manage student records. ## Features 
- Register new students with their details: registration number, name, major, and year of study. 
- Retrieve student details by their ID. 
## Prerequisites 
- C compiler 
- SQLite library 
## Getting Started 
### Windows 
from the official website: https://mingw-w64.org/doku.php 
2. Install the SQLite library: 
- Download the SQLite precompiled binaries for Windows from the official website: https://www.sqlite.org/download.html 
- Extract the downloaded file to a location on your system. 
- Add the path to the extracted SQLite binaries to your system's PATH environment variable. This step ensures that the compiler can find the necessary SQLite files during compilation. 
3. Compile and run the program: 
- Open a command prompt or terminal. 
- Navigate to the directory containing the source code files. 
- Run the following command to compile the program: 
``` 
gcc app.c -o app -lsqlite3 
``` 
- Once the compilation is successful, you can run the program by executing the generated executable: 
``` 
app.exe 
```
### Linux (Debian) 
1. Install the GCC compiler and SQLite library on your system: 
- Open a terminal. 
- Run the following command to install the GCC compiler: 
``` 
sudo apt-get install build-essential 
``` 
- Run the following command to install the SQLite library: 
``` 
sudo apt-get install libsqlite3-dev 
``` 
2. Compile and run the program: 
- Open a terminal. 
- Navigate to the directory containing the source code files. 
- Run the following command to compile the program: 
``` 
gcc app.c -o app -lsqlite3 
``` 
- Once the compilation is successful, you can run the program by executing the generated executable: 
``` 
./app 
``` 
## Usage 
Upon running the program, you will be presented with a menu: 
1. Register: Allows you to register a new student by entering their details.
2. 2. Your Account: Allows you to retrieve student details by entering the student ID.
3. Exit: Exits the program.

   
Follow the on-screen prompts to navigate through the menu and interact with the program. 
Please note that a SQLite database file named "registration.db" will be created in the same directory as the executable. This file will store the student records. 

NOTE: ID - is the student registration number which consist of 14 characters MAJOR - Your enrolled course to the institute, ie. BCS,BIT for Bachelor Of Computer Science and Bachelor of Information Technology respectively 
NAME: Full name of Student not more than 50 characters
