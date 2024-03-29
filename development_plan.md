Plan 1:
    Algorithm to use: Vector operations
        -   Use vector as underlying data structure
        -   For every insertion check the entire vector for the string and if not present insert at the back
        -   For every deletion swap the element with the rear element and delete from back, saves time to rearrange entire vector
        -   For search just lookup the element in the vector and return the result
    Pros:
        -   Easy to implement
        -   Straight forward algorithm
    Cons:
        -   Very high time complexity, every operation will be o(n) [where 'n' is the  number elements present in the vector]
        -   Will need dynamic memory allocation and copying data, which can get expensive for large data set

Plan 2:
    Algorithm to use: Hashmap with linked list [simple]
        -   Idea is to use hash as bucket
        -   create a vector/array of the size equal to number of buckets desired
        -   Use vector/array to store head of linked list associated with the bucket
        -   For every insertion, hash the string to find its bucket. go to its bucket and iterate over the linked list to find it and insert it accordingly
        -   For every deletion hash the string, find the bucket and find the element in the linked list and delet it accordingly
        -   For every search hash the string, find the bucket and find the string in the linked list and return the result
    Pros:
        -   Improved average time complexity, even though BigO = o(n)
        -   Knd of Straight forward
        -   Memory allocation on heap and no data rearraging needed reducing the cost of memory allocation.
    Cons:
        -   Increased implementation complexity
        -   BigO is still same o(n).
        -   Adds a overhead of hashing which can add to time complexity