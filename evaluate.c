#include "monty.h"

/**
* _evaluate - check if string is a number
* @str: arg passed
* Return: 1 if true
*/
char _evaluate(char *str)
{
	int num = 0;

	while (str[num])
	{
		if (str[num] < 48 || str[num] > 57)
			return (0);
		num++;
	}
	return (1);
}
