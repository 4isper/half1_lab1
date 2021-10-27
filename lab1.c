#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int main() 
{
  int *part, N, i, j, temp, k = 0;
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
  part = (int*)malloc(N * sizeof(int));
  if ((mass == 0) || (part == 0))
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
    part[i] = (int)(abs((mass[i] - trunc(mass[i])) * pow(10,k)));

    //printf("mass[%d] = %f\t", i, mass[i]);
    //printf("%d\n", part[i]);

  }

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      if (part[i] == j)
      {
        sum -= mass[j];
        mass[j] = 0;
      }
    }  
  }

  for (i = 0; i < N; i++)
    sum += mass[i];
 
  
  printf("Сумма = %f\n", sum);
  free(part);
  free(mass);
  return 0;
}
