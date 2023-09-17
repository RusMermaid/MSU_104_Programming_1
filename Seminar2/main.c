#include <stdio.h>

int Zadanie1_num(FILE *fin, double a0);
int Zadanie2_num(FILE *fin, double a0);
int Zadanie3_num(FILE *fin, double a0);
double Zadanie4_add(FILE *fin, double a0);
double Zadanie5_add(FILE *fin, double a0);
double Zadanie6_mean(FILE *fin, double a0);
int Zadanie7_equ(FILE *fin, double a0);
int Zadanie8_equ(FILE *fin, double a0);
double Zadanie9_max(FILE *fin, double tmp);
int Zadanie10_maxPos(FILE *fin, double a0);
int Zadanie11_equ(FILE *fin, double a0);
int Zadanie12_polygon(FILE *fin, double a0);
double Zadanie13_add(FILE *fin, double a0);
double Zadanie14_max(FILE *fin, double tmp);

int main(void)
{
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    double a0;

    if ((fin != NULL) && (fscanf(fin, "%lf", &a0) != EOF))
    {
        fprintf(fout, "%d", Zadanie14_max(fin, a0)); //Вместо Zadanie14_max напишите или вставте в минеру внутренность нужной вам функции
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

int Zadanie1_num(FILE *fin, double a0)
{
    int num = 1;
    double a;

    while (fscanf(fin, "%lf", &a) != EOF)
    {
        num++;
    }
    return num;
}

int Zadanie2_num(FILE *fin, double a0)
{
    int num = 0;
    double a;

    if (a0 > 0) num++;

    while (fscanf(fin, "%lf", &a) != EOF)
    {
        if (a > 0) num++;
    }
    return num;
}

int Zadanie3_num(FILE *fin, double a0)
{
    int num = 0;
    double a;

    if (a0 < 0) num++;

    while (fscanf(fin, "%lf", &a) != EOF)
    {
        if (a < 0) num++;
    }
    return num;
}

double Zadanie4_add(FILE *fin, double a0)
{
    double res = a0;
    double a;

    while (fscanf(fin, "%lf", &a) != EOF)
        res += a; //эквивалентно записи res = res + a
    return res;
}

double Zadanie5_add(FILE *fin, double a0)
{
    double res = a0, a;

    while (fscanf(fin, "%lf", &a) != EOF)
        res += ((a > 0) ? a : 0);
        res = (a0 < 0) ? 0 : res;
    return res;
}

double Zadanie6_mean(FILE *fin, double a0)
{
    double sum = a0, a;
    int count = 1;
    while (fscanf(fin, "%lf", &a) != EOF && (sum += a, count++));
    return sum / count;
}

int Zadanie7_equ(FILE *fin, double a0)
{
    double a;

    if (a0<0 || a0>0) return 0;

    while (fscanf(fin, "%lf", &a) != EOF)
    {
        if (a<0 || a>0) return 0;
    }
    return 1;
}

int Zadanie8_equ(FILE *fin, double a0)
{
    double a;

    while (fscanf(fin, "%lf", &a) != EOF) {
        if (!((a <= a0) && (a >= a0))) return 1;
    }
    return 0;
}

double Zadanie9_max(FILE *fin, double a0)
{
    double m = a0; //изначально максимум равен первому элементу последовательности
    double a;
    while (fscanf(fin, "%lf", &a) != EOF)
    {
        if (a > m) m = a;
    }
    return m;
}

int Zadanie10_maxPos(FILE *fin, double a0)
{
    double m = a0, a;
    int cp = 1, p = 1;

    while (fscanf(fin, "%lf", &a) != EOF) cp++, (a > m) ? (m = a, p = cp) : 0;

    return p;
}

int Zadanie11_equ(FILE *fin, double a0)
{
    double a;

    while (fscanf(fin, "%lf", &a) != EOF)
    {
        if (!((a<=a0)&&(a>=a0))) //эквивалентно if (a!=a0) или if(!(a==0)) для целых чисел
            return 0;   // Стационарное значение
    }
    return 1;
}

int Zadanie12_polygon(FILE *fin, double a0)
{
    double max = a0;
    double sum = 0.0;
    int n = 1;

    while (fscanf(fin, "%lf", &a0) != EOF)
    {
        n++;
        (a0 > max) ? (sum += max, max = a0) : (sum += a0);
    }
    return (n < 3 || max >= sum) ? 0 : 1;
}

double Zadanie13_add(FILE *fin, double a0)
{
    double p = 1 / a0; double a;

    while (fscanf(fin, "%lf", &a) != EOF) p += (1 / a);

    return 1 / p;
}

double Zadanie14_max(FILE *fin, double a0)
{
    double temp, maxVal = -273.0;

    while (fscanf(fin, "%lf", &temp) != EOF)
    {
        if (temp <= 10.0 && temp > maxVal) maxVal = temp;
    }
    return (maxVal <= -273.0 && maxVal >= -273.0) ? ((a0 <= 10.0) ? a0 : -273.0) : maxVal;
}