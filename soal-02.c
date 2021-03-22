#include <stdio.h>
#include <math.h>

double itungPass (int x, int i,int n){
    double j;
    j = ((double) 1503*pow(x+n-1,3)) / ((double) x+n);

//klo mo cek :
//printf("nilai j : %lf untuk n : %d\n",j,n);
//printf("atas %lf\n", (double) 1503*pow(x+n-1,3));
//printf("bawah %lf\n",(double) x+n );
    n++;
  if (n<=i){
    return j += itungPass(x,i,n);
  } else {
      return j;
  }
}

void geserPass (int *passRekursif, int shift){
int tempP[5];
int shiftmod;
int h,i;

    shiftmod = (shift)%6;
    printf("\nPassword akhirnya \t: ");
    for (h=0; h<=5;h++){
        if(((h+shiftmod)<=5)){
        tempP[h] = passRekursif[h+shiftmod];
        } else{
        tempP[h] = passRekursif[((h+shiftmod)%6)];
        }
        printf("%d ", tempP[h]);
    }
}

float nilai; //harusnya double.. hampura >.<
int x,i,nilaiInt,tempNilai,change,shf;
int passRekursif[5];

int main() {
    printf("Silahkan masukkan nilai x : ");
    scanf(" %d",&x);
    if (x >= 10){
        printf("Silahkan masukkan nilai n : ");
        scanf(" %d",&i);
        if (i >= 1){
            printf ("Password akan digeser sebanyak : ");
            scanf(" %d", &shf);
            nilai = itungPass(x,i,0);
            printf("nilai dalam desimal : %lf\n", nilai);
            nilaiInt = (int)nilai;
            printf("nilai dalam integer : %d\n", nilaiInt);
            printf("Password dari fungsi \t: ");
            for (int k=0;k<=5;k++){
                tempNilai = nilaiInt%10;
                nilaiInt /= 10;
                passRekursif[k]=tempNilai;
                printf("%d ", tempNilai);
            }
            geserPass(passRekursif,shf);
        }else {
            printf("Nilai n harus lebih besar sama dengan 1 !");
        }
    }else{
        printf("Nilai x harus lebih besar sama dengan 10 !");
    }
}
