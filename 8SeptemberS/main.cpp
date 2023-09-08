#include <iostream>


int Chislo_Resheniy_Uravneniy1(double a, double b)
{

    int n;

    scanf("%lf%lf", &a, &b);

    n = (a == 0.0 ? 1 : 2) + (b != 0.0 && b != a ? 1 : 0);
    return n;
}

int Chislo_Resheniy_Uravneniy2(double a, double b)
{
    int n;

    scanf("%lf%lf", &a, &b);

    double det = a * a + 4 * b;
    //МОИ РАЗМЫШЛЕНИЯ:
    // x1 = b
    // x2 = root(a)
    // x3 = -root(a)

    // If a==0:
    // n=2, (x2=x3=0, b)
    // Else:
    // n=3

    // If b==root(a) || b==-root(a):
    // n--;
    // If a==b==0:
    // n=1
    // If a<0:
    // n=1

    n = (a == 0.0) ? ((b == 0.0) ? 1 : 2) : ((b == sqrt(a) || b == -sqrt(a)) ? 2 : (a < 0.0 ? 1 : 3));
    return n;
}


int main() {

    int n = INFINITY;

    printf("1 Часть\n");
    n = Chislo_Resheniy_Uravneniy1(1.0, 2.0);
    printf("Число различных корней равно: %d", n);

    printf("\n2 Часть\n");
    n = Chislo_Resheniy_Uravneniy2(-2.0, 2.0);
    printf("Число различных корней равно: %d", n);
    return 0;
}
