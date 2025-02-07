## LECTURE 3: Data Modeling using the Entity - Relationship (ER) Model 

**Data Base Design Process:**

- A series of steps to ensure that a databsae is well-structured, efficient, and meets the needs of its users. It contains a set of tasks involving various steps taken to implement a database. 

## Overview of Database Design Process

**Requirements Collection and Analysis:**
- Initial phase where you gather information about the systems functional and data requirements from the users.
- **Functional Requirements:** Define the tasks the database needs to perform and the operations it should support.
- **Data Requirements:** Identify the data entities, attributes, and relationships, that will be stored in the database. 

Additionally, includes Functional Analysis, Conceptual Design, Logical Design, Physical Design, Application Program Design, and Transaction Implementation. 

## Example of a University Database:

**Entities:**
- STUDENT: Tracks student information like ID, Name, Major, and Advisor.
- COURSE: Holds course details such as Course ID, Title, Credits, and Department.
- FACULTY: Stores faculty details including ID, Name, Office, and Department.
- DEPARTMENT: Manages department data like ID, Name, Building, and Budget.
- ENROLLMENT: Links students to courses, recording grades.
- TEACHES: Connects faculty members to courses they teach.

**Relationships:**
- STUDENT-ENROLLMENT-COURSE: Tracks course enrollments by students.
- FACULTY-TEACHES-COURSE: Manages which faculty teach which courses.
- STUDENT-FACULTY: Links students to their advisors (faculty).
- DEPARTMENT-FACULTY: Indicates which faculty belong to which department.
- DEPARTMENT-COURSE: Shows which department offers each course.


