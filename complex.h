#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#define MAXLEN 100 /* max size for text */
enum {NO,YES};

typedef struct Complex{ /* complex data type, complex number containing a 2 double variables */
     double real; /* real number */
     double imag;  /* imaginary number */
} complex;

typedef union param { /* param type, holding complex or double number */
	int complex; /* location i array */
	double real; /* real or imaginary number */
} param;

/* >>>>>>>>>>>>>>>>>>>>>>>>> FUNCTION DECLARTION >>>>>>>>>>>>>>>>>>>>>>>>> */

/*
 *set complex variable with
 *params: cp pointer to complex, double real, double imag
 */
void read_comp (complex *cp, double real, double imag);

/*
 *print complex variable
 *params: cp pointer to complex
 */
void print_comp (complex *cp);

/*add two complex numbers
and print the sum of them
 */
void add_comp (complex *cpA ,complex *cpB);

/*subtract two complex numbers
 *and print the sum of them
 */
void sub_comp (complex *cpA ,complex *cpB);

/*multiple complex number with real number scalar
 *argument and print the result*/
void mult_comp_real (complex *cp, double real);

/*multiple complex number with img number scalar
 *argument and print the result*/
void mult_comp_img (complex *cp, double imag);

/*multiple complex number with complex number
 *argument and print the result*/
void mult_comp_comp(complex *cpA, complex *cpB);

/*return the absolue value of complex number*/
void abs_comp(complex *cp);

/*stop the program*/
void stop();

/*get user input (p.29 in the book)*/
int getLine(char s[], int lim);

/*Extracts a complex number variable from stdin, expects char array pointer*/
int setComplex(char *cp, char *cmdvar[], param *p1);

/*Extracts a double value from stdin, expects char array pointer*/
int setDouble(char *cp, param *p1);

/*check comma placement, expects char array pointer*/
int checkComma(char *cp);

/*Skips white spaces, expects char array pointer*/
int skipSpacer(char *cp);

/*check for miss parameter, expects char array pointer*/
int checkMissParam(char *cp);

/*check for error in the text from stdin, return YES(1) if command its legal and NO(0) else */
int checkInput(char *cp, int num_command,char *cmdvar[], param *p1, param *p2, param *p3);
