#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define NUM_IDS 8
#define NUM_SEARCH_IDS 8

int song_ids[NUM_IDS] = {105, 210, 315, 420, 525, 630, 735, 840};

int search_ids[NUM_SEARCH_IDS] = {105, 210, 315, 420, 525, 630, 735, 840};

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void print_table(const int table[]) {
    int i;
    printf("Index :");
    for (i = 0; i < TABLE_SIZE; i++) printf(" %4d", i);
    printf("\nValue :");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1)
            printf(" %4s", "-");
        else
            printf(" %4d", table[i]);
    }
    printf("\n");
}

int insert(int table[], int key, int *final_position) {
    int index = hash_function(key);
    int collisions = 0;

    while (table[index] != -1) {
        collisions++;
        index = (index + 1) % TABLE_SIZE;
        if (collisions >= TABLE_SIZE) {
            return -1;
        }
    }

    table[index] = key;
    *final_position = index;
    return collisions;
}

bool hash_search(const int table[], int key, int *comparisons) {
    int index = hash_function(key);
    int i;
    *comparisons = 0;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[index] == -1)
            return false;

        (*comparisons)++;
        if (table[index] == key)
            return true;

        index = (index + 1) % TABLE_SIZE;
    }

    return false;
}

bool linear_search(const int data[], int n, int key, int *comparisons) {
    int i;
    *comparisons = 0;

    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (data[i] == key)
            return true;
    }
    return false;
}

int main(void) {
    int table[TABLE_SIZE];
    int i;
    int total_collisions = 0;
    int total_hash_comparisons = 0;
    int total_linear_comparisons = 0;

    for (i = 0; i < TABLE_SIZE; i++) table[i] = -1;

    printf("SONG ID HASHING ASSIGNMENT\n");
    printf("=========================\n");
    printf("Division method: h(k) = k mod %d\n", TABLE_SIZE);
    printf("Collision resolution: Linear probing\n\n");

    printf("A) INSERTION TRACE\n");
    printf("------------------\n");

    for (i = 0; i < NUM_IDS; i++) {
        int home = hash_function(song_ids[i]);
        int final_position;
        int collisions = insert(table, song_ids[i], &final_position);

        if (collisions < 0) {
            printf("Table full. Could not insert %d.\n", song_ids[i]);
            return 1;
        }

        total_collisions += collisions;
        printf("Insert %d | h(k) = %d | collisions = %d | final index = %d\n",
               song_ids[i], home, collisions, final_position);
        print_table(table);
        printf("\n");
    }

    printf("B) SEARCH COMPARISON\n");
    printf("--------------------\n");
    printf("%-8s %-16s %-18s\n", "ID", "Hash comparisons", "Linear comparisons");

    for (i = 0; i < NUM_SEARCH_IDS; i++) {
        int hash_comp, linear_comp;
        bool h_found = hash_search(table, search_ids[i], &hash_comp);
        bool l_found = linear_search(song_ids, NUM_IDS, search_ids[i], &linear_comp);

        total_hash_comparisons += hash_comp;
        total_linear_comparisons += linear_comp;

        printf("%-8d %-16d %-18d\n",
               search_ids[i], hash_comp, linear_comp);
        (void)h_found;
        (void)l_found;
    }

    printf("\nC) ANALYSIS\n");
    printf("-----------\n");
    printf("Records (n)              = %d\n", NUM_IDS);
    printf("Table size (m)           = %d\n", TABLE_SIZE);
    printf("Load factor (alpha)      = %.2f\n", (double)NUM_IDS / TABLE_SIZE);
    printf("Total insertion collisions = %d\n", total_collisions);
    printf("Average hash comparisons = %.2f\n", (double)total_hash_comparisons / NUM_SEARCH_IDS);
    printf("Average linear comparisons = %.2f\n", (double)total_linear_comparisons / NUM_SEARCH_IDS);

    return 0;
}
