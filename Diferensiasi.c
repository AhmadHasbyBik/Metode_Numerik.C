#include <stdio.h>
#include <math.h>

float fx(float x);

void main() {
	float  atas, bawah, h, x, x2, y;
	int n, i;
	printf ("Masukkan batas atas : ");
	scanf("%f",&atas);
	printf ("Masukkan batas bawah : ");
	scanf("%f",&bawah);
	printf ("Masukkan pembagian n : ");
	scanf("%d",&n);
	
	h = (atas-bawah)/n;
	printf("No \t x \t\t f(x) \t\t Error\n");
	
	for (i=0;i<n;i++){
		x = bawah + (i*h);
		x2 = bawah + ((i+1)*h);
		y = fx(x);
			printf("%d\t%f\t%f\t%f\n",i+1,x,y,fabs(y));
	
		if(fx(x)==0)
		{
			printf("titik potong sumbu x saat nilai x %f\n",x); 
			break;
		}	
		else if ((fx(x)*fx(x2))<0)
		{	
			if (fabs(fx(x) < fabs(fx(x2))))
			{
				printf("titik potong sumbu x mendekati nilai x %f dengan %f - %f dan error - %f\n",x,fx(x),fabs(fx(x)));
				break;
			}
			else
				printf("titik potong sumbu x mendekati nilai x %f dengan %f - %f dan error - %f\n",x,fx(x),fabs(fx(x2)));
				break;
		}
	}
}

float fx(float x){
	float y;
	y = exp(x)+x;
	return y;
}


