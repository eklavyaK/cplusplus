-- Selection and Projection
/*
Pi symbol is used for selection (like SELECT clause)
sigma symbol is used for applying condition (like WHERE clause)
*/

-- Set manipulation operators - union, intersection, difference
/*
Union - same as union as discussed, symbol is U
Intersection - same as intersection as discussed, symbol is inverse(U)
Difference - same as minus as discussed, symbol is -
*/

-- Cartesian product of R1 and R2 - for each record of R1 we'll place each record of R2, so total number of records will get multiplied and total number of attributes will get added

-- rename operator (symbol is rho) - it used to change the name of a relation

-- conditional join / theta join also called inner join (joininig two tables based on a condition), symbol is horizontal hour glass

-- outer join has all the rows of the first table and matched rows of second table, symbol is two match sticks attached at corners of hour glass symbol accordingly (for left, right, full)

-- division operator
A / B -- it means that all the tuples in A which have relation with every tuple in B comes in output where attributes of B are not presen in the output