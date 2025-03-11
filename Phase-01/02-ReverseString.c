#include <stdio.h>

/**
 * my_strlen - My custom strlen function, it count the length of a string
 * @str: the input string
 * Return: it returns the length of the input string
 */
int my_strlen ( const char *str)
{
	int counter = 0;
	while (*str != '\0') {
		counter++;
		str++; // increment the pointer forward
	}

	return counter;
}

/* *
 * reverse_string - My Custom strrev function, that reverse string.
 * @str: input string.
 * Return: the function doesn't return anything, but it modify the value directly.
 */
void reverse_string (char* str)
{
	int left = 0;
	int right = my_strlen(str) - 1;
	while (left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
	}
}


int main ( void )
{
	char test1 [] = "edoc fo esuoH oT emocleW";
	char test2 [] = "uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU";
	char test3 [] = "Hello World";
	char test4 [] = "G";

	printf ("Before: %s\n" , test1 );
	reverse_string(test1);
	printf ("After: %s\n\n" , test1 );

	printf ("Before: %s\n" , test2 );
	reverse_string(test2);
	printf ("After: %s\n\n" , test2 );

	printf ("Before: %s\n" , test3 );
	reverse_string(test3);
	printf ("After: %s\n\n" , test3 );

	printf ("Before: %s\n" , test4 );
	reverse_string(test4);
	printf ("After: %s\n\n" , test4 );

	return 0;
}
