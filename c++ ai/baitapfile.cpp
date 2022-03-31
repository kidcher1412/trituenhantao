#include <iostream>
#include <fstream>
const int MAX_SIZE = 1000;
using namespace std;
void input(int a[], int &n, int &s) {
	ifstream fi("num.inp");
	fi >> n >> s;
	for (int i = 0 ; i<n; ++i) fi >> a[i];
	fi.close();
}
int soCapBangS(int a[], int n, int s) {
	int counter = 0 ;
	for (int i=0; i<n-1;++i)
	for (int j=i+1; j<n;++j)
		if (a[i]+a[j]==s) ++counter ;
	return counter ;
}
int maxSubtract(int a[], int n) {
	int max = a[1] - a[0];
	for (int i=0; i<n-1;++i)
	for (int j=i+1; j<n;++j)
		if (a[j]-a[i]>max)	max = a[j]-a[i];
	return max;
}
int gcd(int a, int b) { if (b==0) return a; else return gcd(b, a%b); }
int nguyenToCungNhau(int a[], int n){
	int counter = 0;
	for (int i=0; i<n-1;++i)
	for (int j=i+1; j<n;++j)
		if (gcd(a[i], a[j]) == 1) ++counter;
	return counter;
}
int doiMotKhacNhau(int a[], int n) {
	for (int i=0; i<n-1;++i)
	for (int j=i+1; j<n;++j)
		if (a[i]>a[j]) swap(a[i],a[j]) ;
	int counter = n ;
	for (int i=0; i<n-1;++i)
		if (a[i]==a[i+1])	--counter;
	return counter;
}
int main () {
	ofstream fo("num.out");
	int a[MAX_SIZE], n, s;
	input(a, n, s);
	fo << soCapBangS(a, n, s) << endl ;
	fo << maxSubtract(a, n) << endl ;
	fo << nguyenToCungNhau(a, n) << endl ;
	fo << doiMotKhacNhau(a, n);
	fo.close();
	return 0;
}
