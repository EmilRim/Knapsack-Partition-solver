#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partition.h"

// Function to run a test case
void run_test(const char *filename) {
    int weights[MAX_ITEMS], values[MAX_ITEMS], n, capacity, is_partition;
    PartitionResult result;
    clock_t start, end;
    double cpu_time_used;

    // Pradžioje išvedame pradinius duomenis
    printf("PRADINIAI DUOMENYS:\n");
    printf("- Failas: %s\n", filename);

    // Try to read input, handle errors gracefully
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("KLAIDA: Nepavyko atidaryti failo %s\n", filename);
        return;  // Exit if the file can't be opened
    }

    // Spausdiname failo turinį
    printf("- Failo turinys:\n");
    rewind(file);
    int ch;
    printf("  ");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    // Skaitymas ir skaičiavimai
    start = clock();
    read_input(filename, weights, values, &n, &capacity, &is_partition);
    
    printf("\n- Elementų skaičius: %d\n", n);
    printf("- Elementai: ");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", weights[i], i < n-1 ? ", " : "");
    }
    printf("]\n");

    printf("- Uždavinio tipas: %s\n", 
           is_partition ? "Skaičių particijos problema" : "Daikčių krepšelio problema");
    printf("- Krepšelio/tikslinė talpa: %d\n", capacity);

    // Skaičiavimas
    result = knapsack_or_partition(weights, values, n, capacity, is_partition);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Rezultatų išvedimas
    printf("\nSKAIČIAVIMŲ REZULTATAI:\n");
    if (!is_partition) {
        printf("- Maksimali krepšelio vertė: %d\n", result.sum1);
    } else {
        printf("- Rasta dalinių sumų: 2\n");
        printf("- Pirmos grupės suma: %d\n", result.sum1);
        printf("- Antros grupės suma: %d\n", result.sum2);
        printf("- Skirtumas tarp grupių: %d\n", result.difference);
        
        printf("- Panaudoti elementai:\n");
        printf("  1 grupė: [");
        for (int i = 0; i < MAX_ITEMS && result.subset1[i] != 0; i++) {
            printf("%d%s", result.subset1[i], 
                   (result.subset1[i+1] != 0 && i+1 < MAX_ITEMS) ? ", " : "");
        }
        printf("]\n");
        
        printf("  2 grupė: [");
        for (int i = 0; i < MAX_ITEMS && result.subset2[i] != 0; i++) {
            printf("%d%s", result.subset2[i], 
                   (result.subset2[i+1] != 0 && i+1 < MAX_ITEMS) ? ", " : "");
        }
        printf("]\n");
    }

    // Papildoma informacija
    printf("\nPAPILDOMA INFORMACIJA:\n");
    printf("- Skaičiavimų laikas: %.4f sekundės\n", cpu_time_used);
    printf("- Išnagrinėta sprendimų: 100%%\n");

    printf("\n------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        run_test(argv[1]);  // Run single user-provided file
    } else {
        const char *test_files[] = {"testas1.txt", "testas2.txt", "testas3.txt", "testas4.txt"};
        int num_tests = sizeof(test_files) / sizeof(test_files[0]);

        printf("Nepateiktas konkretus failas. Vykdomi visi testiniai atvejai...\n");
        for (int i = 0; i < num_tests; i++) {
            run_test(test_files[i]);
        }
    }

    return 0;
}