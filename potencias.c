
#include<stdio.h>
#include<math.h>

int main (void){
	int n, m, i, pot;
	while(1){
		scanf("%d %d", &n, &m);
		if((n < 1) || (m == 0) || (m == 1) || (m == -1)) break;
		for(i = 0; ; i++){
			pot = pow(m, i);
			if(pot >= n){
				break;
			}
			printf("%d\n", pot);
		}
	}
	return 0;
}