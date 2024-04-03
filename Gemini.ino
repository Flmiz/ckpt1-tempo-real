#include <math.h>

// Função para calcular as raízes da equação
void calcularRaizes(float a, float b, float c, float *x1, float *x2) {
  float delta = calcularDiscriminante(a, b, c);

  // Se o discriminante for positivo, existem duas raízes reais
  if (delta > 0) {
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
  } 
  // Se o discriminante for zero, existe apenas uma raíz real
  else if (delta == 0) {
    *x1 = *x2 = -b / (2 * a);
  } 
  // Se o discriminante for negativo, não existem raízes reais
  else {
    *x1 = -b / (2 * a);
    *x2 = sqrt(-delta) / (2 * a);
  }
}

void setup() {
  // Defina os coeficientes da equação
  float a = 1;
  float b = 2;
  float c = -3;

  // Declarando variáveis para armazenar as raízes
  float x1, x2;

  // Calcular as raízes
  calcularRaizes(a, b, c, &x1, &x2);

  // Imprimir os resultados
  Serial.begin(9600);
  Serial.print("Raíz 1: ");
  Serial.println(x1);
  Serial.print("Raíz 2: ");
  Serial.println(x2);

  Serial.print("Tempo de programa: ");
  Serial.println(micros());
}

void loop() {
  // Sem loop infinito, pois a função `setup` já calcula e imprime as raízes.
}
