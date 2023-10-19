Transaction -- it is a collection of operations that performs a single logical unito of work

Schedule -- A schedule is the arrangement of transaction operations. It is the order in which the operations of a transaction are executed.

-- we do concurrent scheduling instead of series scheduling to save time due to execution of two or more schedules simultaneously. But there can be read - write, write - write conflict which we have to take care of

-- Classification of schedules based on recoverability

/*
Non recoverable schedule (classification of non serial schedule):
A schedule is recoverable if each transaction commits only after all the transactions from which it has read have committed. In other words, if some transaction Ty reads a value that has been updated/written by some other transaction Tx, then the commit of Ty must occur after the commit of Tx. This is because if Tx is aborted then we have a chance to abort Ty to maintain a consistent database state.

Recoverable schedule (classification of non serial schedule):
If a transaction reads the value of an operation from an uncommitted transaction and commits before the transaction from where it has read the value, then such a schedule is called Non-Recoverable schedule. A non-recoverable schedule means when there is a system failure, we may not be able to recover to a consistent database state. If the commit operation of Ti doesn't occur before the commit operation of Tj, it is non-recoverable. Because Tj has already the update the database permanently, and if Ti fails then database might have inconsistent data, because database was update by Tj and the source of data for Tj was Ti which was a failure.

cascading rollbacks (classification of recoverable schedule):
This schedule are not recommended.
In this case there are series of transactions which are executed where next transaction takes value form previous one. In this case the the commit of a transaction is scheduled after it's source. In this case it is okay if it's parent's trasaction is aborted, because we can abort the subsequent trasactions as their commits are scheduled after.

cascadeless schedule (classification of recoverable schedule):
This schedule are recommended.
If in a schedule, a transaction is not allowed to read a data item until and unless the last transaction that has been written is committed/aborted, then such a schedule is called a Cascadeless Schedule. It avoids cascading rollback and thus saves CPU time. To prevent cascading rollbacks, it disallows a transaction from reading uncommitted changes from another transaction in the same Schedule. In other words, if some transaction Ty wants to read a value that has been updated or written by some other transaction Tx, then only after the commit of Tx, the commit of Ty must read it.

strict schedule:
This schedule are recommended.
In this case a transaction can read the data from the database only after a pervious trasaction which was operating on the same data has been completed (committed / aborted). In this case there no chance of incosistency as data read is always original.
Every strict schedule is cacadeless.
*/

-- serializability

/*
serial schedule - every transaction is performed in series. so they are always consistent but it takes lot of time. wastage of resources

non serial schedule - executing some operations from one trasaction and then executing some operations from another trasaction. Here we're not completing one trasaction completely before moving onto another. so this is a non serial schedule
*/

-- classification of non serial schedule

/*
conflict serializable schedules:
A schedule is called conflict serializable if after swapping non-conflicting operations, it can transform into a serial schedule.

conflicting operations - 1. they must operate on the same data. 2. these operations must belong to different transactions. 3. at least one  of the operations must be write (because read - read cannot be conflicting)
for better understanding : https://www.youtube.com/watch?v=zv0ba0Iok1Y
*/