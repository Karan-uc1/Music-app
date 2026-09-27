# Comparison Table

The search comparison below uses the eight stored IDs as the search IDs because a separate search list is not visible in the supplied question image.

| ID | Hash search comparisons | Linear search comparisons |
|---:|---:|---:|
| 105 | 1 | 1 |
| 210 | 1 | 2 |
| 315 | 2 | 3 |
| 420 | 2 | 4 |
| 525 | 3 | 5 |
| 630 | 3 | 6 |
| 735 | 4 | 7 |
| 840 | 4 | 8 |
| **Average** | **2.50** | **4.50** |

## Interpretation

- Hashing uses the division method to jump directly to the key's home index.
- Because several IDs have the same remainder modulo 10, collisions occur.
- Linear probing resolves the collisions by checking the next table positions.
- For this dataset, hashing requires fewer comparisons on average than sequential linear search.
