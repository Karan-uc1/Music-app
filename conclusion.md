# Final Conclusion

The program demonstrates the Division Method for hashing with linear probing as the collision-resolution technique.

For the given song IDs, the hash function `h(k) = k mod 10` maps most records to only two home positions (0 and 5). This creates 12 insertion collisions and two clusters in the final table. The load factor is 0.80.

For the successful searches used in this experiment, hashing required an average of 2.50 comparisons, while linear search required an average of 4.50 comparisons. This illustrates the expected average-case advantage of hashing for direct ID lookup.

Therefore, hashing is appropriate for a music application when frequent ID-based lookup is required. In practice, the collision rate can be reduced by selecting a suitable table size and hash function and by keeping the load factor at a reasonable level.


