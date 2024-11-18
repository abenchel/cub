#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int s[] = {1};
	memset(s, 5, 2);
	memset(s, 57, 1);
	// memset(s, 0, 2);
	// memset(s, 0, 1);


	printf("%d\n", s[0]);
}

// 00000000 00000000 00000101 00111001