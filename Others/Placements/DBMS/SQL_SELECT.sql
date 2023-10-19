-- "Select" statement structure
SELECT () FROM () WHERE () GROUP BY () HAVING () ORDER BY ()

SELECT job, employee id--columns name separated by commas, to select all columns simply use * symbol, to select distinct values from a column use -
SELECT DISTINCT -- It can be used to extract only distinct values present in the set of columns
FROM --table name
WHERE job = 'CLERK' -- here, only rows having clerk are displayed

-- in sql != operator is  prepresented as <>

-- in sql &, |, ! are written as AND, OR, NOT

ORDER BY -- ASC - for ascending, DESC - for descending
-- columns separated by commas, first column is most priority in case of sorting like first column of a row in case of sorting 2D vectors

LIKE 
/*
Wildcard operators:
They are used to match zero or more characters of a string. They are used with where clause:

% matches zero, one or more characters
_ matches one characters

for ex-
WHERE job LIKE '_R_D%'

this can match TRADER, _ matches with T, _ matches with A, and % matches with ER
*/


NULL
/*
some cells may be empty, these cells are considered to have NULL value
to check whether they're null we use:
IS NULL
IS NOT NULL

for ex-
WHERE ph_no IS NULL
it selects only records where ph_no is not provided by a person
*/

SUM(ATTRIBUTE), AVG(), MIN(), MAX(), COUNT() -- SUM(cost), AVG(marks)
SELECT SUM(marks) FROM marksheet; -- it sums all the values in marks column
SELECT SUM(DISTINCT marks) -- it sums only distinct values in the column
SELECT COUNT(*) FROM markseet -- returns the number of records
SELECT COUNT(col_name) -- returns total number of records excluding NULL values
SELECT COUNT(DISTINCT col_name) -- returns total number of distinct not null values

GROUP BY dept_number; -- columns by commas
/*
if we don't apply GROUP BY clause, all the records are considered while applying aggregate functions, but when we apply GROUP BY clause, all the records where dept_number (or a group of columns) having same values are groped to form a single record in final output, and aggregate functions are applied on each group separately

for ex-
SELECT dept_number, SUM(salary) AS TCTC
GROUP BY dept_number;

AS is alias name of the COLUMN produced by SUM
all the records having same dept_number will be summed their salary
and will be represented as one record having two attributes dept_number and TCTC
*/

HAVING count(*) > 4
/*
HAVING clause is used to filter groups
in above case all the dept_numbers having more than 4 occurances are filtered for the final result
*/

-- HAVING FILTERS GROUPS, WHERE FILTER RECORDS


