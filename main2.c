#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
int main(int argc, char const *argv[])
{
    double binario = 100;
    double raio = 0.03;
    double forca_B = 300;
    double angulo = 60;
    double dist_OB = 0.2;

    printf("Digite o distancia OB: ");
    scanf("%lf", &dist_OB);
    printf("Digite a força no ponto B: ");
    scanf("%lf", &forca_B);
    printf("Digite o raio de O para o cabo: ");
    scanf("%lf", &raio);
    printf("Digite a força do binario (N): ");
    scanf("%lf", &binario);
    printf("Digite o angulo: ");
    scanf("%lf", &angulo);

    printf("\n");
    double distO_forcaB = dist_OB * cos(angulo * (PI / 180));
    printf("Distancia O para forca B: %2.f \n", distO_forcaB);
    double momento_gerado_binario = binario * raio * 2;
    printf("Momento gerado pelo binario: %2.f \n", momento_gerado_binario);
    double momento_gerado_forcaB = forca_B * distO_forcaB;
    printf("Momento gerado pela forca B: %2.f \n", momento_gerado_forcaB);

    double momento_total = momento_gerado_binario + momento_gerado_forcaB;
    printf("Momento total: %2.f \n", momento_total);
    //
    double distancia_OC = momento_total / (cos(angulo * (PI / 180)) * forca_B);

    printf("Distancia OC: %f \n", distancia_OC);
    return 0;
}