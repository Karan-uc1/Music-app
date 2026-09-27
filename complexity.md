# Complexity Analysis

## Hashing with division method and linear probing

Let `n` be the number of stored records and `m` the hash-table size.

| Operation | Average case | Worst case |
|---|---|---|
| Hash calculation | O(1) | O(1) |
| Search | O(1) | O(n) |
| Insertion | O(1) | O(n) |
| Space | O(n) | O(n) |

The worst case occurs when many keys collide and probing must inspect many positions.

## Linear search

| Operation | Best case | Average case | Worst case |
|---|---|---|---|
| Search | O(1) | O(n) | O(n) |
| Space | O(1) auxiliary | O(1) auxiliary | O(1) auxiliary |

## Load factor

`alpha = n / m = 8 / 10 = 0.80`

A load factor of 0.80 means 80% of the table is occupied. A high load factor generally increases the number of probes required by open-addressed hashing.
