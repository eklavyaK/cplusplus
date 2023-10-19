-- Set Manipulation operators

/*
In order to take UNION or INTERSECTION of two relations R and S
1. R and S must have the same quantity of attributes
2. Attribute domains must be compatible
3. Duplicate tuples get automatically eliminated
*/

UNION -- it used to compile the results of two or more SELECT statements, given the output produced by all of them is compatible

SELECT cust_name FROM depositor
UNION -- union is possible if both tables have compatible records
SELECT cust_name FROM borrower


INTERSECT -- it used to take intersection of the results of two or more SELECT statements, given the output produced by all of them is compatible

SELECT cust_name FROM depositor
INTERSECT -- intersection is possible if both tables have compatible records
SELECT cust_name FROM borrower


MINUS -- it used to take remove the intersection  of the results of one SELECT statement from another, given the output produced by all of them is compatible

SELECT cust_name FROM depositor
MINUS
SELECT cust_name FROM borrower