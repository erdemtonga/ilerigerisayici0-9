void main() {
unsigned char sayilar[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};    // 7-SEGMENT DISPLAY AYAR
unsigned char sayac=0; // Bir sayac tanimladik ve ilk degerini 0 olarak atadik.
TRISB=0;              // Mikrodenetleyicinin B portu cikis olarak tanimlandi.
TRISD=0b00000011;     // Mikrodenetleyicinin D portunun ilk iki pini giris olarak tanimlandi.
PORTB=sayilar[0];     // Displaye ilk olarak sayilar dizisinin 0. elemanini bastik.
while(1){
         if(PORTD.RD0 ==0){            //RD0 pini 0 ise ,
              sayac++;                 // sayaci 1 arttir
              if(sayac==10) sayac=9;  // SAYAC =10 oldugunda dizinin 10. elemani olmadigi icin 9'a esitle.
              while(PORTD.RD0 ==0 );  // Yukselen kenar tetikleme icin (aksi halde RD0 pini 1'den 0 oldugu anda butun dongu tamamlanir
                                      // ve display 9 sayisini gosterir.
              }
         if(PORTD.RD1 ==0 && sayac>0){
              sayac--;
              while(PORTD.RD1 ==0 );
              }
PORTB=sayilar[sayac];
        }
}