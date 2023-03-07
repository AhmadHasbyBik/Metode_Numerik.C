#include<stdio.h>
#include<math.h>

/* 
SOAL !
Didefinisikan persoalan dari persamaan non-linier dengan fungsi sebagai berikut:
- f(x) = e^-x - x
- Dapatkan nilai Xr setiap iterasi, mulai dari awal sampai dengan akhir iterasi.
- Akhir iterasi ditentukan sampai dengan 10 iterasi atau jika nilai [(b-a)| <e 
- Nilai error akar (e) ditentukan = 0.0001 sebagai pembatas iterasi nilai f(x).
- Input batas bawah (a) dan batas bawah (b) berasal dari input dari user.  
PEMBAHASAN!
1. a=0, b=1
2. a=0.25, b=0.75
3. a=0,5, b=0.75
4. a=0.5, b=0.6
*/

float f(float x) {
	return (exp(-x)-x);
}

int main() {
float a,b,x,e = 0.0001;
int i,status,n = 9;
	status=1;
	printf("Menentukan dari pers f(x) = e^-x -x dg Metode Regula Falsi \n");
	printf("\n");
	printf("Masukkan nilai (a)   : ");
	scanf("%f",&a);
	printf("Masukkan nilai (b)   : ");
	scanf("%f",&b);
	printf("\n");
	printf("Iterasi\t\ta\t\tb\t\tx\t\tf(x)\n");
	printf("===========================================================================\n");
		if (f(a)*f(b) < 0) {
			for(i=0;i<=n;i++){ 
				x=a-(f(a)*(b-a))/(f(b)-f(a));
				printf("%d\t%.10f\t%.10f\t%.10f\t%.10f\n",i+1,a,b,x,f(x));

			if ( f(a)*f(x) == 0) {
				status=0;
			}
			else {
				if (f(a)*f(x) < 0)
					b=x;
				else
					a=x;

					if (e > fabs(x))
						status=0;

					if (i >= n )
						status=0;
					}
			}
		}
		else {
			printf("Maaf, pilih nilai a dan b kembali. karena tidak mengandung akar");
			getch();
		}
}
