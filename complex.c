#include "complex.h"

 /*set complex variable*/
void read_comp (complex *cp, double real, double imag){
	cp->real = real;
	cp->imag = imag;
	printf("read succeeded: ");
	print_comp(cp);
}

 /*print complex variable*/
void print_comp (complex *cp){ 
	printf("%.3f ", cp->real);
	if (cp->imag < 0)
		printf("- (%.3f)i\n", -cp->imag);
	else
		printf("+ (%.3f)i\n", cp->imag);
}

/*calculate the sum between two complex numbers*/
void add_comp (complex *cpA ,complex *cpB){
	complex sum;
	sum.real = cpA->real + cpB->real;
	sum.imag = cpA->imag + cpB->imag;
	printf("the sum is : ");
	print_comp(&sum);
}

/*calculate the subtract between two complex numbers
 *and print the sum
 */
void sub_comp (complex *cpA ,complex *cpB){
	complex dif;
	dif.real = cpA->real - cpB->real;
	dif.imag = cpA->imag - cpB->imag;
	printf("the dif is : ");
	print_comp(&dif);
}

/*multiple complex number with scalar
 *argument and print the result*/
void mult_comp_real (complex *cp, double real){
	complex mul;
	mul.real = cp->real * real;
	mul.imag = cp->imag * real;
	printf("the mul of real is : ");
	print_comp(&mul);
}

/*multiple complex number with img number scalar
 *argument and print the result*/
void mult_comp_img (complex *cp, double imag){
	complex mul;
	mul.real = -1 * cp->imag * imag;
	mul.imag = cp->real * imag;
	printf("the mul of imag is : ");
	print_comp(&mul);
}

/*multiple complex number with complex number
 *argument and print the result*/
void mult_comp_comp(complex *cpA, complex *cpB){
	complex mul;
	mul.real = (cpA->real * cpB->real) - (cpA->imag * cpB->imag);
	mul.imag = (cpA->real * cpB->imag) + (cpA->imag * cpB->real);
	printf("the mul of real is : ");
	print_comp(&mul);
}

/*return the absolue value of complex number*/
void abs_comp(complex *cp){
	printf("the absolute value is: %f\n", sqrt(cp->real*cp->real + cp->imag*cp->imag));
}
