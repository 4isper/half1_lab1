#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

/*
int rounding(double x)
{
  int v = 0;

  v = (int)round(x * 10 / 10.0);
  while ((v % 10) == 0)
  {
    v = v / 10;
  }
  return v;
}
*/
int main() 
{
  int N, i, part, temp, k = 0;
  float *mass, min, max;
  float sum = 0;

  setlocale(LC_ALL, "Rus");

  printf("Введите min = ");
  scanf("%f", &min);
  printf("Введите max = ");
  scanf("%f", &max);

  if (min >= max)
  {
    printf("\vНекорректные значения min и max. Перезапустите программу и введите min < max.\v");
    return 0;
  }

  printf("Введите N = ");
  scanf("%d", &N);

  if (N <= 0)
  {
    printf("\vНекорректное значение N. Перезапустите программу и введите N > 0.\v");
    return 0;
  }

  mass = (float*)malloc(N * sizeof(float));
  if (mass == 0)
    return 0;
   
  temp = N;
  while (temp > 0)
  {
    temp = temp / 10;
    k++;
  }

  srand(time(NULL));

  for (i = 0; i < N; i++)
  {
    mass[i] = ((float)rand() / RAND_MAX) * (max - min) + min;
   // part = abs((((mass[i] - trunc(mass[i])) * pow(10, 6))));

    part = abs((mass[i] - trunc(mass[i])) * pow(10,k));

    if (part < N && part >= 0)
      sum -= mass[i];
    else
      sum += mass[i];
   

    //printf("mass[%d] = %f\t", i, mass[i]);
    //printf("%d\n", part);

  }
  
  printf("Сумма = %f\n", sum);
  free(mass);
  return 0;
}
