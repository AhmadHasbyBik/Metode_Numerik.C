#include <stdio.h>
#include <math.h>
#define e 0.0001

float f(float x){
	return (e*exp(-x)+1);
}

/* Sesuai PPT a=-1, b=0, n=10*/
int main(){
	int i,n=10;
	float a,b,e,fa,fb,fx,xr,fxr;
	printf("Masukkan batas bawah (a) : ");
	scanf("%f",&a);
	printf("Masukkan batas atas (b) : ");
	scanf("%f",&b);
	printf("Masukkan eeransi (e) : ");
	scanf("%f",&e);
	fa=f(a);
	fb=f(b);
		if(fa*fb>0){
			printf("Maaf, akar tidak ditemukan dalam iterasi ke-%d\n",n);
		}
		else{
			printf("\nIterasi\t\ta\t\tb\t\tx\t\tf(x)\t\tf(a)\n");
			for(i=0;i<=n;i++){
				xr=(a+b)/2;
				fx=f(xr);
				fxr=f(xr);

                printf("%d\t\t%f\t%f\t%f\t%f\t%f\n",i+1,a,b,xr,fxr,fa);

                if(fx*fa<0){
                    b=xr;
                    fb=fxr;
                }
                else{
                    a=xr;
                    fa=fxr;
                }

				if (fabs(b-a)<=e || i>(n-1))
                    break;
			}
		}
}
