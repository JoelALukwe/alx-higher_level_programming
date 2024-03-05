SQL Queries Project

some of the tackled functions in this project included

How to create a new MySQL user?

sudo mysql

Note: If your root MySQL user is configured to authenticate with a password, you will need to use a different command to access the MySQL shell. The following will run your MySQL client with regular user privileges, and you will only gain administrator privileges within the database by authenticating with the correct password:

mysql -u root -p


2.How to manage privileges for a user to a database or table?

the general command for adding users previledges is as below:

GRANT PRIVILEGE ON database.table TO 'username'@'host';

Note: The PRIVILEGE value in this example syntax defines what actions the user is allowed to perform on the specified database and table. You can grant multiple privileges to the same user in one command by separating each with a comma. You can also grant a user privileges globally by entering asterisks (*) in place of the database and table names. In SQL, asterisks are special characters used to represent “all” databases or tables.



3.What’s a PRIMARY KEY?  
A primary key is MySQL is a column or a group of columns that uniquely identifies each row in a table, it must have a unique value and not be NULL,Typically, an auto-incrementing integer column is used as a primary key.this ensures each row has a unique identifier automatically assigned.


4.What’s a FOREIGN KEY?

A foreign key in MySQL is a column that links one table to another. It ensures data consistency by requiring values in this column to match values in another table's primary key column.

example. Let's say we have two tables: students and classes. Each student belongs to a class, and we want to link them using a foreign key.

CREATE TABLE students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    class_id INT,
    FOREIGN KEY (class_id) REFERENCES classes(class_id)
);

CREATE TABLE classes (
    class_id INT AUTO_INCREMENT PRIMARY KEY,
    class_name VARCHAR(50)
);


5.How to use NOT NULL and UNIQUE constraints

In MySQL, you can use NOT NULL and UNIQUE constraints to enforce data integrity rules on columns in a table.

NOT NULL Constraint: This constraint ensures that a column cannot contain NULL values, meaning every row must have a value for that column.

Example:

CREATE TABLE employees (
    employee_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL
);
In this example, both the name and email columns are marked as NOT NULL, so every row inserted into the employees table must have values for these columns.


UNIQUE Constraint: This constraint ensures that the values in a column (or a group of columns) are unique across all rows in the table.

Example:

CREATE TABLE students (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    student_number INT UNIQUE,
    email VARCHAR(100) UNIQUE
);
In this example, the student_number and email columns are marked as UNIQUE, so each value in these columns must be unique within the students table. Attempting to insert a duplicate value will result in an error.


You can also combine both constraints on a single column:

CREATE TABLE products (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_code VARCHAR(20) NOT NULL UNIQUE,
    name VARCHAR(50) NOT NULL,
    price DECIMAL(10, 2) NOT NULL
);
In this example, the product_code column must have a value (NOT NULL) and each value must be unique (UNIQUE).



To retrieve data from multiple tables in a single request in MySQL, you typically use JOIN clauses. Here's an example of how you can achieve this:

Suppose you have two tables: students and classes, and you want to retrieve information about students along with the class they belong to.


SELECT students.student_id, students.name AS student_name, classes.class_id, classes.class_name
FROM students
JOIN classes ON students.class_id = classes.class_id;
In this query:

We select columns from both the students and classes tables.
We use the JOIN keyword to join the two tables based on the class_id column, which is common between them.
We specify the columns we want to retrieve, including any aliases (AS) for readability.
This query retrieves data from both tables in a single result set, combining information about students and their corresponding classes.
There are different types of joins you can use depending on your requirements, such as INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN. Each type of join determines how rows from one table are combined with rows from another table. The example above uses an INNER JOIN, which only returns rows where there is a match between the joined tables.


7.What are subqueries?

Subqueries, also known as nested queries or inner queries, are SQL queries embedded within another SQL query. These subqueries can be used in various parts of a SQL statement, such as in the SELECT, FROM, WHERE, or HAVING clauses.

Here's a brief overview of how subqueries work and where they can be used:

Subqueries in SELECT clause: You can use a subquery to retrieve a single value or a list of values, and then use that result within the SELECT clause of the outer query.

Example:


SELECT column1, (SELECT AVG(column2) FROM table2) AS average_column2
FROM table1;
Subqueries in FROM clause: A subquery in the FROM clause acts as a derived table or inline view, providing a temporary table that can be used in the outer query.

Example:


SELECT column1, derived_table.average_column2
FROM table1, (SELECT AVG(column2) AS average_column2 FROM table2) AS derived_table;
Subqueries in WHERE clause: Subqueries in the WHERE clause are used to filter results based on a condition that involves data from another table.

Example:


SELECT column1
FROM table1
WHERE column2 IN (SELECT column2 FROM table2 WHERE condition);
Subqueries in HAVING clause: Similar to the WHERE clause, you can use subqueries in the HAVING clause to filter grouped results.

Example:


SELECT column1, COUNT(*)
FROM table1
GROUP BY column1
HAVING COUNT(*) > (SELECT AVG(count_column) FROM count_table);
Subqueries provide a powerful way to write complex queries by breaking them down into smaller, more manageable parts. They allow you to perform operations on data from multiple tables and to use the results of one query as input to another query.




8.What are JOIN and UNION?

JOIN and UNION are two different SQL operations used for combining data from multiple tables or query results.

JOIN:
JOIN is used to retrieve data from multiple tables based on a related column between them. There are different types of JOINs:

INNER JOIN: Returns only the rows where there is a match between the columns in both tables.


SELECT *
FROM table1
INNER JOIN table2 ON table1.column = table2.column;
LEFT JOIN (or LEFT OUTER JOIN): Returns all rows from the left table and the matched rows from the right table. If there is no match, NULL values are returned for the columns from the right table.


SELECT *
FROM table1
LEFT JOIN table2 ON table1.column = table2.column;
RIGHT JOIN (or RIGHT OUTER JOIN): Returns all rows from the right table and the matched rows from the left table. If there is no match, NULL values are returned for the columns from the left table.


SELECT *
FROM table1
RIGHT JOIN table2 ON table1.column = table2.column;
FULL JOIN (or FULL OUTER JOIN): Returns all rows when there is a match in either table. If there is no match, NULL values are returned for the columns from the table that lacks a matching row.


SELECT *
FROM table1
FULL JOIN table2 ON table1.column = table2.column;
UNION:
UNION is used to combine the results of two or more SELECT statements into a single result set. It removes duplicate rows by default.

UNION ALL: Similar to UNION but retains duplicate rows.

SELECT column1 FROM table1
UNION ALL
SELECT column1 FROM table2;
Example:


SELECT employee_id, name
FROM employees
UNION
SELECT student_id, name
FROM students;
This query retrieves a list of all unique names from both the employees and students tables, combining them into a single result set while removing duplicate entries.





