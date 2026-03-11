#include <stdio.h>

int main() {
    int x = 0; // 'Uninitialized/Unused variable' (kullanılmayan değişken) uyarısını çözmek için değer atadık
    
    int dizi[15]; // FIX 1: Dizinin boyutunu 15'e çıkardık, böylece 10. indekse yazarken Buffer Overflow olmayacak
    dizi[10] = 50; 
    
    char *p = "12345"; // FIX 2: Tam sayıyı pointer'a atama hatasını (Incompatible pointer) tırnak içine alarak string'e çevirdik
    
    // Değişkenleri ekrana yazdırıyoruz ki derleyici "bu değişkeni tanımladın ama hiç kullanmadın" uyarısı vermesin
    printf("x degeri: %d, dizi[10] degeri: %d, pointer: %s\n", x, dizi[10], p);
    
    return 0;
}
