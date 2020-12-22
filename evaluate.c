#include "monty.h"

/**
* _evaluate - check if string is a number
* @str: arg passed
* Return: 1 if true
*/
int _evaluate(char *str)
{
	unsigned int i = 0;

	if (!str) /* still return 1 if it is zero */
		return (1);

	while (str[i])
	{
		if (str[i] == '-')
		{/* if not a number or NULL */
			if ((!(str[1] >= '0' && str[1] <= '9')) || !str[1])
				return (0);
			i++;

			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
				if (!str[i])
					return (1);
			}

			return (0);
		}
		else
		{
			i = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
				if (!str[i])
					return (1);
			}
			return (0);
		}
	}
	return (0); /* 0 if nothing passed */
}
