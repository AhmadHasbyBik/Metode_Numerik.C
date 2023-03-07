#include <stdio.h>
#include <math.h>
#define eksak 0.4364203757557

float f(float x){
	return ((exp(-x)) / (1 + sqrt(x) + pow(x,2)));
}

/* Simpson's 1/3 */
float simpsons1(float a, float b, int n){
	float h,integral,x,sum,fx,error;
	int i;
	h = fabs(b-a)/n;
	printf("\nNo\t\tx\t\t\tf(x)\n");
	for(i=0;i<n;i++){
		x=a+i*h;
		fx=f(x);
		if(i%2==0){
			sum=sum+(2*fx);
		}
		else{
			sum=sum+(4*fx);
		}
		printf("%d\t\t%f\t\t%.25f\n",i,x,fx);
	}
	integral=(h/3)*sum;
	error=eksak-integral;
	printf("\nNilai h : %.10f", h);
	printf("\nSUM f(x) : %.10f", sum);
	printf("\nIntegral : %.10f", integral);
	printf("\nNilai Eksak : %.10f", eksak);	
	printf("\nNilai Error : %.10f", error);	
}

/* Simpson's 3/8 */
float simpsons2(float a, float b, int n){
	float h, integral,x,sum=0,fx,error;
	int i;
	h=fabs(b-a)/n;
	printf("\nNo\t\tx\t\t\tf(x)\n");
    for(i=1;i<n;i++){
    	x=a+i*h;
    	fx=f(x);
    	if(i%2==0){
    		sum=sum+2*fx;
		}
		else{
			sum=sum+4*fx;
		}
		printf("%d\t\t%f\t\t%.25f\n",i,x,fx);
	}
	integral=(3*h)/8*sum;
	error=eksak-integral;
	printf("\nNilai h : %.10f", h);
	printf("\nSUM f(x) : %.10f", sum);
	printf("\nIntegral : %.10f", integral);
	printf("\nNilai Eksak : %.10f", eksak);	
	printf("\nNilai Error : %.10f", error);
}

/* Reimann */
float reimann(float a, float b, int n){
	float x,h, sum=0, integral,fx,error;
	int i;
	h=fabs(b-a)/n;
	printf("\nNo\t\tx\t\t\tf(x)\n");
	for(i=1;i<n;i++){
		x=a+i*h;
		fx=f(x);
		sum=sum+fx;
		printf("%d\t\t%f\t\t%.25f\n",i,x,fx);
	}
	integral=h*sum;
	error=eksak-integral;
	printf("\nNilai h : %.10f", h);
	printf("\nSUM f(x) : %.10f", sum);
	printf("\nIntegral : %.10f", integral);
	printf("\nNilai Eksak : %.10f", eksak);	
	printf("\nNilai Error : %.10f", error);
}

/* Trapesium */
float trapezoidal(float a, float b, int n){
	float x,h, sum=0, integral,fx,error;
	int i;
	h=fabs(b-a)/n;
	printf("\nNo\t\tx\t\t\tf(x)\n");
	for(i=1;i<n;i++){
		x=a+i*h;
		fx=f(x);
		sum=sum+fx;
		printf("%d\t\t%f\t\t%.25f\n",i,x,fx);
	}
	integral=(h/2)*sum;
	error=eksak-integral;
	printf("\nNilai h : %.10f", h);
	printf("\nSUM f(x) : %.10f", sum);
	printf("\nIntegral : %.10f", integral);
	printf("\nNilai Eksak : %.10f", eksak);	
	printf("\nNilai Error : %.10f", error);
}

void main(){
	int n, menu;
	float a, b;
up :
	system("cls");
	printf("========== DAFTAR PROGRAM ==========\n");
	printf("1. METODE SIMPSONS 1/3\n");
	printf("2. METODE SIMPSONS 3/8\n");
	printf("3. METODE REIMANN\n");
	printf("4. METODE TRAPESIUM\n");
	printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);
    printf("\n");

    printf("========== INPUT INTEGRAL ==========\n");
	printf("Masukkan Batas Atas : ");
	scanf("%f", &b);
	printf("Masukkan Batas Bawah : ");
	scanf("%f", &a);
	printf("Masukkan Jumlah Pembagi  : ");
	scanf("%d", &n);

    switch(menu){
        case 1:
            simpsons1(a, b, n);
            printf("\n");
			printf("\nTekan enter untuk kembali ke menu sebelumnya.");
            getch();
            goto up;
        case 2:
            simpsons2(a,b,n);
            printf("\n");
			printf("\nTekan enter untuk kembali ke menu sebelumnya.");
            getch();
            goto up;
        case 3:
            reimann(a,b,n);
            printf("\n");
			printf("\nTekan enter untuk kembali ke menu sebelumnya.");
            getch();
            goto up;
        case 4:
        	trapezoidal(a,b,n);
            printf("\n");
			printf("\nTekan enter untuk kembali ke menu sebelumnya.");
            getch();
            goto up;
        default:
            printf("Maaf, input yang anda masukkan salah/invalid.");
            printf("\n");
            printf("\nTekan enter untuk kembali ke menu sebelumnya.");
            getch();
            goto up;
        }
}
