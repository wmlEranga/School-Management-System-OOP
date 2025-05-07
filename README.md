# School Management System

A comprehensive Object-Oriented Programming solution for managing school operations, including students, teachers, courses, and administrative tasks.

## Overview

This School Management System provides an intuitive platform to handle various aspects of school administration using OOP principles in Python. The system organizes entities like students, teachers, and courses in a structured, maintainable manner.

## Features

- **User Management**: Different types of users with specific roles and permissions
- **Student Management**: Enrollment, attendance tracking, grade management
- **Teacher Management**: Subject assignments, schedule management
- **Course Management**: Course creation, assignment, and tracking
- **Grade Management**: Record and calculate student grades
- **Attendance System**: Track student attendance records
- **Payment Handling**: Manage student fees and payments
- **Reports Generation**: Create detailed reports for various entities

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/wmlEranga/School-Management-System-OOP.git
   cd School-Management-System---OOP
   ```

2. Install required dependencies:

   ```
   pip install -r requirements.txt
   ```

3. Run the application:
   ```
   python main.py
   ```

## Usage

The system implements various classes for different entities in a school environment:

- Use the `Student` class to manage student information and academic records
- Use the `Teacher` class to handle faculty information and teaching assignments
- Use the `Course` class to create and manage academic courses
- Use the `Grade` class to record and calculate student performance
- Use the `Attendance` class to track student presence

## Project Structure

```
School-Management-System---OOP/
├── classes/               # Core class implementations
│   ├── student.py         # Student class implementation
│   ├── teacher.py         # Teacher class implementation
│   ├── course.py          # Course class implementation
│   ├── grade.py           # Grade management
│   └── attendance.py      # Attendance system
├── utils/                 # Utility functions
├── data/                  # Data storage
├── main.py                # Application entry point
└── README.md              # Project documentation
```

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b new-feature`
3. Commit your changes: `git commit -am 'Add new feature'`
4. Push to the branch: `git push origin new-feature`
5. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.
