#include <stdio.h>


int main()
{
    int ages[3];

    for ( int  i = 0; i < 3; i++) {
        scanf("%d", &ages[i]);
    }
    
    for (int i = 0; i < 3; i++) {
	if ( ages[i] == -1 ) {
		printf("age not definen");
	}
    	else {
        	printf("age %d\n", ages[i]);
	}
    }
    
    return 0;
}

