#include <stdio.h>
#include <string.h>
#include <emscripten.h>

// Global variable to count the number of patients
int nbPatients = 0;

// Function to calculate BMI and return the classification
EMSCRIPTEN_KEEPALIVE
const char* calculate_patient(float weight, float height) {
    static char result[256];
    float bmi = weight / (height * height);
    nbPatients++;

    sprintf(result, "Weight: %.1f kg\nHeight: %.2f m\nBMI: %.1f\n", weight, height, bmi);

    if (bmi < 18.5)
        strcat(result, "Classification: UNDERWEIGHT, HIGH TO VERY HIGH RISK\n");
    else if (bmi < 25)
        strcat(result, "Classification: NORMAL WEIGHT, LOW RISK\n");
    else if (bmi < 30)
        strcat(result, "Classification: OVERWEIGHT, HIGH RISK\n");
    else
        strcat(result, "Classification: OBESE, VERY HIGH RISK\n");
    
    return result;
}

// Function to return the total number of patients
EMSCRIPTEN_KEEPALIVE
int total_patients() {
    return nbPatients;
}
