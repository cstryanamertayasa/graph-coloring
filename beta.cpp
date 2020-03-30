#include <iostream>
#include <string>
using namespace std;
//konsepnya kayak pas SD, pecah dulu yang mana ribuan, ratusan, puluhan, satuan. Mecahinnya pakai mod sama pembagan.
void konversi(int bil) {
  string satuan[20]={"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
  string puluhan[10]={"", "", "dua puluh", "tiga puluh ", "empat puluh ", "lima puluh" , "enam puluh ", "tujuh puluh ", "delapan puluh ", "sembilan puluh "};
  string ratusan[10]={"", "seratus ", "dua ratus ", "tiga ratus ", "empat ratus", "lima ratus ", "enam ratus ", "tujuh ratus ", "delapan ratus ", "sembilan ratus "};
  string ribuan[10]={"", "seribu ", "dua ribu ", "tiga ribu ", "empat ribu ", "lima ribu ", "enam ribu ", "tujuh ribu ", "delapan ribu ", "sembilan ribu "};

  string result = (bil % 100 < 20) ? ribuan[bil/1000] + ratusan[bil%1000/100] + satuan[bil%100] : ribuan[bil/1000] + ratusan[bil%1000/100] + puluhan[bil%100/10] + satuan[bil%10];
  cout<<result;
}
int main()
{
  int tgl, thn;
  string bln;
  cout<<"masukan tanggal lahir: ";
  cin>>tgl>>bln>>thn;
  cout<<"Anda lahir pada: ";
  konversi(tgl);
  cout<<" "<<bln<<" ";
  konversi(thn);
  return 0;
}
