/*
*      Date: 01.5.2020
*      Author: NATANEL LUSKY
*      Maman 22 - Complex numbers calculator
*/

#include "complex.h"
int main()
{
	char *token;  /*Char array pointer */
		/*an array that store all cmd-complex function*/
	char *cmdName[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop", NULL};
		 /*complex objects pointers array*/
	char *cmdVar[] = {"A", "B", "C", "D", "E", "F", NULL};
	char command[MAXLEN + 1];
	param param1, param2, param3; /* 3 param type */
	int i, num_command;
	complex A, B, C, D, E, F; /*complex varibales*/
			/*an array to store reference all complex numbers variabls*/
	complex *comArr[6];
	comArr[0] = &A;
	comArr[1] = &B;
	comArr[2] = &C;
	comArr[3] = &D;
	comArr[4] = &E;
	comArr[5] = &F;
	while (1)
	{
		while (getLine(command, MAXLEN) > 0) /* Entered when user entered character */
		{
			printf("%s", command);   /* print the command */
			token = strtok(command, " \t\nEOF"); /* parsing the command for token pointer*/
			num_command = -1;
			for (i = 0; cmdName[i] != NULL; i++) /* Loop for finding command number by array cmdName */
			{
				if (!strcmp(token, cmdName[i]))
					num_command = i;
			}
			if (num_command < 0) /* If a valid command is found */
				printf("‫‪Undefined‬‬ ‫‪command‬‬ ‫‪name‬‬\n");
			else
			{
				token = strtok(NULL, "\n"); /* parsing the rest */
				/*check if token its legal*/
				if (checkInput(token, num_command, cmdVar, &param1, &param2, &param3))
					switch (num_command)
					{
					case 0:
						read_comp(comArr[param1.complex], param2.real, param3.real);
						break;
					case 1:
						print_comp(comArr[param1.complex]);
						break;
					case 2:
						add_comp(comArr[param1.complex], comArr[param2.complex]);
						break;
					case 3:
						sub_comp(comArr[param1.complex], comArr[param2.complex]);
						break;
					case 4:
						mult_comp_real(comArr[param1.complex], param2.real);
						break;
					case 5:
						mult_comp_img(comArr[param1.complex], param2.real);
						break;
					case 6:
						mult_comp_comp(comArr[param1.complex], comArr[param2.complex]);
						break;
					case 7:
						abs_comp(comArr[param1.complex]);
						break;
					case 8:
						stop();
						break;
					}
			}
		}
	}

	return 0;
}

/*get user input (p.29 in the book)*/
int getLine(char s[], int lim)
{
	int i;
	int c = 0;
	printf("*****************************************************\n");
	printf("Complex numbers calculator ready, enter your command:\n");
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	s[i++] = c;
	s[i] = '\0';
	if (i - 1 == 0)
		printf("‫‪No command was received\n");
	return i - 1;
}

/*Extracts a complex number variable from stdin, expects char array pointer*/
int setComplex(char *cp, char *cmdvar[], param *p1)
{
	int j = 0;
	p1->complex = -1;
	if (!checkMissParam(cp))
		return 0;
	if (cp) 
	{
		while (cmdvar[j] != NULL && p1->complex == -1)
		{
			if (*cmdvar[j] == cp[0])
			{
				p1->complex = j;
				return YES;
			}
			j++;
		}
	}
	printf("Undefined‬‬ ‫‪complex varibale\n");
	return NO;
}

/*Extracts a double value from stdin, expects char array pointer*/
int setDouble(char *cp, param *p1)
{
	char *pEnd;
	p1->real = strtod(cp, &pEnd);
	if (p1->real == 0.0 && cp[0] != '0')
	{
		if (!checkMissParam(cp))
			return 0;
		printf("invalid paramete - not a number\n");
		return NO;
	}
	return pEnd - cp;
}

/*check comma placement, expects char array pointer*/
int checkComma(char *cp)
{
	int i;
	int count = 0;
	for (i = 0; cp[i] == ' ' || cp[i] == '\t' || cp[i] == ','; i++)
		if (cp[i] == ',')
			count++;
	if (count == 0)
	{
		printf("Missing comma\n");
		return NO;
	}
	if (count > 1)
	{
		printf("Multiple consecutive commas\n");
		return NO;
	}
	return i;
}

/*Skips white spaces, expects char array pointer*/
int skipSpacer(char *cp)
{
	int j;
	if (cp != NULL)
		for (j = 0; cp[j] == ' ' || cp[j] == '\t'; j++)
			;
	return j;
}

/*check for miss parameter, expects char array pointer*/
int checkMissParam(char *cp)
{

	if (cp == NULL || cp[skipSpacer(cp)] == '\0')
	{
		printf("Missing parameter\n");
		return 0;
	}
	return 1;
}

/*stop the program*/
void stop()
{
	exit(0);
}

/*check for error in the text from stdin, return YES(1) if command its legal and NO(0) else  */
int checkInput(char *cp, int num_command, char *cmdvar[], param *p1, param *p2, param *p3)
{
	int index = 0;
	int tmp;
	if (num_command != 8 && cp == NULL)
	{
		printf("Missing parameter\n");
		return NO;
	}
	index += skipSpacer(cp + index);
	if (num_command != 8)
	{
		if (!setComplex(cp + index, cmdvar, p1))
			return NO;
		index++;
		index += skipSpacer(cp + index);
		if (num_command != 1 && num_command != 7)
		{
			tmp = checkComma(cp + index);
			if (tmp == 0)
				return NO;
			index += tmp;
			if (num_command == 2 || num_command == 3 || num_command == 6)
			{
				if (setComplex(cp + index, cmdvar, p2) == 0)
					return NO;
				index++;
			}
			if (num_command == 0 || num_command == 4 || num_command == 5)
			{
				tmp = setDouble(cp + index, p2);
				if (tmp == 0)
					return NO;
				index += tmp;
				if (num_command == 0)
				{
					index += skipSpacer(cp + index);
					tmp = checkComma(cp + index);
					if (tmp == 0)
						return NO;
					index += tmp;
					tmp = setDouble(cp + index, p3);
					if (tmp == 0)
						return NO;
					index += tmp;
				}
			}
		}
		index += skipSpacer(cp + index);
	}
	if (cp && cp[index] != '\0')
	{
		printf("Extraneous text after end of command\n");
		return 0;
	}

	return YES;
}

