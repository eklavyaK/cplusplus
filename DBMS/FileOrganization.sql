Blocking factor -- average number of records which can be stored in a block

spanned strategy -- it allows partial record to be stored in a block. this is used in variable length records
--- advantages - no memory wastage
--- disadvantages - a record might be in two blocks so increased access time

unspanned strategy -- it doesn't allow partial storing
-- used for fixed length records, memory wastage, low access time

unordered file organization -- placing the file is easy, because we don't follow any order. searching is linear time

ordered file organization -- placing is difficult, but searching is easy (log n) time

-- mostly ordered file organization is used because searchig is done more often than insertion

sparse index -- the index record appears only for a few items in the data file. each items points to  a block as shows. To locate a record, we find the index record with the largest search key value less than or equal to the search key value we are looking for using binary search

dense index -- a record is created for every search key value in the database. This helps you to search faster but needs more space to store index records. In this indexing, method records contain search key value and points to the real record on the disk.

-- index table contains - search key in first column and it's corresponding block pointer in second column

primary indexing -- It is sparse indexing. Primary Index is an ordered file whose records are of fixed length with two fields. The first field of the index replicates the primary key of the data file in an ordered manner, and the second field of the ordered file contains a pointer that points to the data-block where a record containing the key is available.

Cluster indexing -- A clustered index is an index that specifies the physical arrangement of a database's table records. There can only be one clustered index per table since there can only be one method that records are physically maintained in a database table. It stores the records in sorted order.

secondary indexing -- It is like dense indexing. Secondary Indexing: It is a two-level indexing technique used to reduce the mapping size of the primary index. The secondary index points to a certain location where the data is to be found but the actual data is not sorted like in the primary indexing. Secondary Indexing is also known as non-clustered Indexing.