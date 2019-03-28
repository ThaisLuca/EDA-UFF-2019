
#include<stdio.h>

int main (void){
	int x, y, z;
	x = 5;
	y = x++;
	z = x--;

	printf("%d\n", !y == !x);

	printf("%d\n", ((x++ > y) || (--z <= y)));

	printf("%d\n", ((!x) || (!(!z))));

	printf("%d\n", (((x + y) > z) && (x++)));

	printf("%d\n", x && y + !3 || 4);

	return 0;
}