#include <stdio.h>
#include <math.h>

#define LEARNING_RATE 0.1
#define THRESHOLD 0.5

int main() {
// Initialize weights and bias
float w1 = 0.5, w2 = 0.5, b = -0.7;

// Input data for AND gate
int x1[4] = {0, 0, 1, 1};
int x2[4] = {0, 1, 0, 1};
int y[4] = {0, 0, 0, 1};
  
// Loop for 1000 epochs
for (int i = 0; i < 1000; i++) {
// Loop through all input data
for (int j = 0; j < 4; j++) {
// Calculate output using dot product and bias
float output = x1[j]*w1 + x2[j]*w2 + b;
// Apply activation function
output = (output > THRESHOLD) ? 1 : 0;
// Calculate error
float error = y[j] - output;
// Update weights and bias
w1 += LEARNING_RATE * error * x1[j];
w2 += LEARNING_RATE * error * x2[j];
b += LEARNING_RATE * error;
}
}

// Test artificial neuron with all input data
for (int j = 0; j < 4; j++) {
float output = x1[j]*w1 + x2[j]*w2 + b;
  output = (output > THRESHOLD) ? 1 : 0;
printf("%f\n", output);
}
return 0;
}