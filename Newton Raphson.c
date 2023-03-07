#include <stdio.h>
#include <math.h>

float f(float x){
	return exp(x) - 5 * (x * x);
}

float g(float x){
	return exp(x) - 10 * x;
}

int main(){
	float x0, f0, x1, x2, f1, g0, e=0.00001;
	int i, n=10;
	printf("\nMasukkan nilai tebakan: ");
	scanf("%f", &x0);
	
	printf("\nIterasi\t\tx0\t\t|(x1-x0)/x1|\n");
	printf("=======================================================\n");
	do{
	f0 = f(x0);
	g0 = g(x0);
		if(g0 == 0.0){
			printf("Perhitungan Eror.");
			break;
		}
		x1 = x0 - f0/g0;
		x2 = fabs((x1-x0)/x1);
		printf("%d\t\t%f\t%f\n",i+1,x0,x2);
		x0 = x1;	  
		
		if(i > n){
			printf("Perhitungan deihentikan, tidak divergen.");
			break;
		  	}
	i++;		  
	}while (x2>e);
	printf("\n=====================================================\n");
	
	printf("\nHampiran akar adalah : %f", x1);

return 0;
}
