# Song ID Hashing Assignment

## Objective

Implement and analyse a hash table for the song IDs:

`105, 210, 315, 420, 525, 630, 735, 840`

The assignment requires source code, input data, output, trace tables, complexity analysis, comparison, and a final conclusion.

## Files

| File | Purpose |
|---|---|
| `main.c` | C implementation of hashing, insertion, hashing search and linear search |
| `input.txt` | Input data used for the experiment |
| `output.txt` | Recorded execution output |
| `trace_table.md` | Insertion trace and table after every insertion |
| `comparison.md` | Hashing vs linear-search comparison |
| `complexity.md` | Time and space complexity analysis |
| `conclusion.md` | Final conclusion and suitability discussion |
| `Makefile` | Optional commands for compiling/running the C program |

## Method used

- **Hashing method:** Division method
- **Hash function:** `h(k) = k mod 10`
- **Collision resolution:** Linear probing
- **Table size:** 10
- **Load factor:** `8 / 10 = 0.80`

### Important assumption

The supplied question image does not visibly show the table size or a separate list of IDs to search. Therefore this repository uses table size 10 and searches the eight stored IDs. If your original assignment sheet gives different values, update the constants and search list in `main.c` before submission.

## Compile and run

### Linux / macOS / WSL / MinGW

```bash
make
./song_hashing
```

Or directly:

```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o song_hashing
./song_hashing
```

To regenerate the recorded output:

```bash
./song_hashing > output.txt
```

## Main results

### Insertion

| ID | Home index | Collisions | Final index |
|---:|---:|---:|---:|
| 105 | 5 | 0 | 5 |
| 210 | 0 | 0 | 0 |
| 315 | 5 | 1 | 6 |
| 420 | 0 | 1 | 1 |
| 525 | 5 | 2 | 7 |
| 630 | 0 | 2 | 2 |
| 735 | 5 | 3 | 8 |
| 840 | 0 | 3 | 3 |

**Total collisions = 12**

### Final hash table

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Value | 210 | 420 | 630 | 840 | - | 105 | 315 | 525 | 735 | - |

### Search performance

| ID | Hash comparisons | Linear comparisons |
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

## Complexity

Hashing has **O(1) average-case search and insertion**, but can degrade to **O(n) in the worst case** because of collisions. Linear search takes **O(n) average and worst case**.

The detailed analysis is in [`complexity.md`](complexity.md).

## Submission checklist

- [x] C source code
- [x] Input data
- [x] Output
- [x] Trace table
- [x] Complexity analysis
- [x] Comparison table
- [x] Final conclusion
- [ ] Replace assumptions with the exact values from the full question sheet, if different
- [ ] Push repository to GitHub and submit the repository link
