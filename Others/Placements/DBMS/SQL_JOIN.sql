Join -- this statement is used to combine data or rows from two or more tables based on a common field between them.

------ inner joins - equi, natural, self joins

EQUI join -- it is done when a theta join uses only the equivalence condition, i.e. = operatior is used in the condition

NATURAL join
-- In this type of join, the attribute should have the same name and domain. In natural join, there should be at least one common attribute between two relations. It does not utilize any of the comparision operators. It performs selection forming equality on those attributes which appear in both relations and eliminates the duplicate attributes
-- ex- 
SELECT * FROM R1 NATURAL JOIN R2; --R1 and R2 are relations

SELF join
-- A self join is a join in which a table is joined with itself. It is also called unary relationships, especially when the table has foreign key which references its own primary key.

------ outer joins - left, right, full

LEFT JOIN -- we use ON keyword to specify the condition of join, in this case left table comes in output completely but records satisfying the condition in ON keyword comes in left join
ex-
SELECT *
FROM table1 RIGHT JOIN table2
ON table.column_name - table2.column_name

RIGHT JOIN -- reverse of left join

FULL OUTER JOIN -- all the records comes in output (matched or unmatched), matched will be placed against each other but unmatched records will have NULL values in rows or attributes corresponding or other table

