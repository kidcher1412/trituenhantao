#include <iostream>
#include <fstream>
#include <cmath>
using namespace std ;
struct phanSo{
	int tu, mau ;
	float value ;
};
ofstream fo("fraction.out");
void input(phanSo a[], int &n) {
	ifstream fi("fraction.inp") ;
	fi >> n ;
	for (int i=0; i<n;++i) {
		fi >> a[i].tu >> a[i].mau ;
		a[i].value = 1.0*a[i].tu/a[i].mau ;
	}
	fi.close() ;
}
void bubbleSort(phanSo a[], int n) {
	for (int i=0; i<n-1; ++i)
	for (int j=i+1; j<n; ++j)
		if (a[i].value>a[j].value) {
			swap(a[i].tu, a[j].tu) ;
			swap(a[i].mau, a[j].mau) ;
			swap(a[i].value, a[j].value) ;
		}
}
void output(phanSo a[], int n) {
	for (int i=0; i<n; ++i)
		fo << a[i].tu << "/" << a[i].mau << " " ;
	fo << endl ;
}
int gcd(int a, int b) { if (b==0) return a ; else return gcd(b, a%b); }
phanSo add(phanSo x, phanSo y) {
	phanSo temp ;
	int k ;
	temp.tu=x.tu*y.mau+x.mau*y.tu ;
	temp.mau=x.mau*y.mau ;
	k = gcd(temp.tu, temp.mau) ;
	temp.tu/=k;
	temp.mau/=k;
	return temp ;
}
phanSo sumOfArray(phanSo a[], int n) {
	phanSo temp ;
	temp.tu=0 ;
	temp.mau=1 ;
	for (int i=0; i<n;++i) temp = add(a[i], temp) ;
	return temp;
}
int main () {
	int n ;
	phanSo a[100] ;
	input(a, n) ;
//	bai20a
	bubbleSort(a, n) ;
	output(a, n) ;
//	bai20b
	fo << sumOfArray(a, n).tu << "/" << sumOfArray(a, n).mau ;
	fo.close() ;
	return 0 ;
}
