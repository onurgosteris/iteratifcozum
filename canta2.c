#include <stdio.h>
#include <stdlib.h>
 
int main() {
   printf("\n----------------------------------------------\n");
   printf("\n  CANTAYI EN PAHALI SEKILDE DOLDURAN PROGRAM\n");
   printf("\n----------------------------------------------\n");
   float agirlik[100], fiyat[100],canta[100], kapasite,toplam=0;
   int esya, sayac1, sayac2,sayac3;
   float oran[100], yedek;
    printf("\nEsya sayisi: ");
   scanf("%d", &esya);
    printf("\nCantanizin kapasitesini giriniz : ");
   scanf("%f", &kapasite);
   for (sayac1 = 0; sayac1 < esya; sayac1++) {
   	printf("\n %d.Esyanin agirligi : ",sayac1+1);
    scanf("%f", &agirlik[sayac1]);
    printf(" %d.Esyanin fiyati : ",sayac1+1);
    scanf("%f",&fiyat[sayac1]);
   }
   for (sayac1 = 0; sayac1 < esya; sayac1++) {
      oran[sayac1] = fiyat[sayac1] / agirlik[sayac1];
   }
   for (sayac1 = 0; sayac1 < esya; sayac1++) {
      for (sayac2 = sayac1 + 1; sayac2 < esya; sayac2++) {
         if (oran[sayac1] < oran[sayac2]) {
            yedek = oran[sayac2];
            oran[sayac2] = oran[sayac1];
            oran[sayac1] = yedek;
 
            yedek = agirlik[sayac2];
            agirlik[sayac2] = agirlik[sayac1];
            agirlik[sayac1] = yedek;
 
            yedek = fiyat[sayac2];
            fiyat[sayac2] = fiyat[sayac1];
            fiyat[sayac1] = yedek;
         }
      }
   }
   for (sayac3 = 0; sayac3 < esya; sayac3++)
      canta[sayac3] = 0.0;
   for (sayac3 = 0; sayac3 < esya; sayac3++) {
      if (agirlik[sayac3] > kapasite)
         break;
      else {
         canta[sayac3] = 1.0;
         toplam = toplam + fiyat[sayac3];
         kapasite = kapasite - agirlik[sayac3];
      }
   }
   if (sayac1 < esya)
      canta[sayac3] = kapasite / agirlik[sayac3];
   toplam = toplam + (canta[sayac3] * fiyat[sayac3]);
   printf("\nToplayabileceginiz maksimum fiyat: %.2f TL", toplam);
   return(0);
}
