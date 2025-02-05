## LECTURE 2: Database System Concepts and Architecture

## Data Models:

**Data Model:**

-   Contains Data + Relationship + Semantics + Constraints
-   The database is designed in 3 levels, which are Physical, Logical, and View Model.

View - How users see the database

Logical - How data is implemented

Physical - How data is stored

**Data Model Constraints**

-   Constraints are used to define the database structure
-   Constraints typically include elements (and their data types) as well as groups of elements (entity record, table), and relationships among such groups.

**Data Model Operations:**

-   Generally used for specifying database retrievals and updates by referring to the constraints and structure of the data model.
-   Operations on the data model may include basic model operations.

## Categories of Data Models:

In a high level or Concetual Data Model, we will use concepts such as entities, attributes, and relationsips.

-   **Entity:** Represents a real world opject or concept. Can be a name, place, object, class, etc.

-   **Attribute:** Further describes an entity. Can be age, roll number, or grades for a student.

-   **Relationship:** Relation between two or more entities.

A **Representation or Implementation Data Model** represents only the logical part of the database and does not represent the physical structure.

A **Low Level or Physical Data Model** describes how data is stored in the computer.

## Three Schema Architecture

**Internal Level/Schema:**

-   Describes the physical storage structure of the database and describes how data is stored. Offers complete low level information about the database.
-   Example: Specification of primary and secondary keys, indexes, pointers, and sequencing.

**Conceptual Level/Schema:**

-   Describes what data are to be stored in the database and also describes what relationships exist among said data.
-   Implementation of the data structure is hidden. Concentrates on describing entities, relationships, datatypes, constraints, etc.
-   Generally programmers and database admins work at this level.

**External Level/Schema:**

-   Contains several scehemas that are called as subschema.
-   Subscheme is used to describe the different view of the database that a user is interested in. Hides rest of database from group.
-   Also known as a view scehma.

## Data Definition Language

The DDL is used for creating tables, indexes, constraints, and schema in the Database. Also, the data values that are stored in the database are required to satisfy certain consistency constraints.

**Basic commands:**

-   Create It is used to create objects in the database
-   Alter It is used for change or alter the structure of the database objects
-   Drop It is used for delete objects from the database
-   Truncate It is used for remove all records from a table
-   Rename It is used to rename the object in database
-   Comment It is used for comment on the data dictionary.

## Data Manipulation Language

The Data Manipulation Language is used to manipulate the data in the database by using different commands. In this category we can able to perform Insert new data into Table, Update existing data in the Table, Delete Data from the Table and other
functions we can perform on data by using these DML commands.

**Basic Commands:**

-   Select It is used for select data from the Table based on the requirements
-   Insert It is sued for Inserting data into existing table
-   Update It is used for update data in the Table based on the requirement
-   Delete It is used for delete data from the Table
-   Merge It is used for upsert operations
-   Call It is used for call a structured query language or Java sub program
-   Lock Table It have ability to control the concurrency

## Data Control Language (DCL):

Data control language (DCL) controls access to the data that users store within a database. Essentially, this language controls
the rights and permissions of the database system. It allows users to grant or revoke privileges to the database.

**Here's a list of
DCL statements:**

-   GRANT: Gives a user access to the database
-   REVOKE: Removes a user's access to the databas

## Transaction Control Language (TCL):

Transaction control language (TCL) manages the transactions within a database. Transactions group a set of related tasks into a single, executable task. All the tasks must succeed in order for the transaction to work.

**Here's a list of TCL
statements:**

-   COMMIT: Carries out a transaction
-   ROLLBACK: Restores a transaction if any tasks fail to execute
-   SAVEPOINT: Sets a point in a transaction to save

