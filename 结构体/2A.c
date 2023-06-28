#include<stdio.h>
typedef struct{
    double real;
    double imag;
}Complex;
Complex add(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}
Complex subtract(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}
Complex multiply(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}
Complex divide(Complex c1, Complex c2){
    Complex result;
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    return result;
}
int main(){
    Complex c1 = {1.0, 2.0};
    Complex c2 = {3.0, 4.0};
    printf("The first complex number is: %.2lf + %.2lfi\n", c1.real, c1.imag);
    printf("The second complex number is: %.2lf + %.2lfi\n", c2.real, c2.imag);
    Complex c_add = add(c1, c2);
    printf("The sum of the two complex numbers is: %.2lf + %.2lfi\n", c_add.real, c_add.imag);
    Complex c_subtract = subtract(c1, c2);
    printf("The difference of the two complex numbers is: %.2lf + %.2lfi\n", c_subtract.real, c_subtract.imag);
    Complex c_multiply = multiply(c1, c2);
    printf("The product of the two complex numbers is: %.2lf + %.2lfi\n", c_multiply.real, c_multiply.imag);
    Complex c_divide = divide(c1, c2);
    printf("The quotient of the two complex numbers is: %.2lf + %.2lfi", c_divide.real, c_divide.imag);
    return 0;
}
