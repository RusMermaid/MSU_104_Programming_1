#include <stdio.h>
#include <stdlib.h>

// Function to read and print the contents of a file
int R(const char *filename) {
    FILE *IN;
    char ch;
    if (!(IN = fopen(filename, "r"))) { perror("Error opening file"); return 1; }
    while ((ch = fgetc(IN)) != EOF && putchar(ch));
    fclose(IN);
    return 0;
}

int RN(const char *filename, double *result) {
    FILE *IN;
    char ch;
    char numberBuffer[256];
    int bufferIndex = 0;

    if (!(IN = fopen(filename, "r"))) {
        perror("Error opening file");
        return 1;
    }
    // Читаем сиволы и кладем в буффер
    while ((ch = fgetc(IN)) != EOF) {
        if ((ch == '+' || ch == '-' || ch == '.' || (ch >= '0' && ch <= '9')) && bufferIndex < sizeof(numberBuffer) - 1) {
            numberBuffer[bufferIndex++] = ch;
        }
        else
        {
            break;
        }
    }

    numberBuffer[bufferIndex] = '\0';
    *result = atof(numberBuffer);
    fclose(IN);
    return 0;
}

// Function to write data to a file
int W(const char *filename, const char *data) {
    FILE *IN;
    if (!(IN = fopen(filename, "w"))) { perror("Error opening file"); return 1; }
    if (fputs(data, IN) == EOF) { perror("Error writing to file"); fclose(IN); return 1; }
    fclose(IN);
    return 0;
}

int findMax(int arr[]) {
    int max = arr[0];
    for (int i = 1; arr[i] != -1; i++) max = (arr[i] > max) ? arr[i] : max;
    return max;
}

int countMax(int arr[]) {
    int max = findMax(arr);
    int count = 0;

    for (int i = 0; arr[i] != -1; i++) count += (arr[i] == max) ? 1 : 0;

    return count;
}

int main() {
    const char *IN = "test2.txt";
    const char *OUT = "output.txt";
    char data[] = "ПИШЕМ В ФАЙЛ output";

    int output = (R(IN) == 0 && W(OUT, data) == 0) ? 0 : 1;

    double number;
    int result = RN(IN, &number);
    (result == 0) ? printf("\nЧисло считано: %lf\n", number) : printf("Ошибка чтения файла.\n");

    int numbers[] = {42, 15, 7, 23, 56, 9, 31, -1};
    int max = findMax(numbers);
    if (max != -1) {
        printf("Макс число: %d\n", max);
    } else {
        printf("Ошибка \n");
    }

    return output && result;
}
