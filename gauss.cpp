#include<iostream>
#include<cstdio>

using namespace std;

struct rational{
	int l;
	int m;
};

int GCD(int a, int b){							//algorytm Euklidesa
    int temp;
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

void fraction(rational *a){
	if(a->l	!= 0){									//sprowadzanie do ułamka prostego
		int temp = GCD(a->l, a->m);
		a->l /= temp;
		a->m /= temp;
	} else {
		a->m = 1;
	}
}

rational reduce(rational a, rational b){		//odejmowanie liczb wymiernych
	rational ret;
	ret.l = (a.l*b.m)-(a.m*b.l);
	ret.m = a.m*b.m;
	fraction(&ret);
	return ret;
}

int index(int i, int j, int n){
	 return i*n+j;
}

void wypisz_dane(rational *C, int n){
	for(int i=0; i<n; i++){
		for(int j=i*n; j<(i+1)*n; j++){
		cout <<C[j].l << "/" << C[j].m << " ";
		}
	cout <<endl;
	}
	cout <<endl;
}

void wypisz_wynik(rational *D, int n){
	for(int i=0; i<n; i++){
		cout << D[i].l << "/" << D[i].m << " ";
	}
	cout << endl;
}

void to_rational(int *Al, int *Am, int *Bl, int *Bm, rational *C, rational *D, int n){
	for(int i=0; i<n*n; i++){			//tworzy tabele C - równań i D - wyników
			C[i].l = Al[i];
			C[i].m = Am[i];
			fraction(&C[i]);
	}
	for(int i=0; i<n; i++){
		D[i].l = Bl[i];
		D[i].m = Bm[i];
		fraction(&D[i]);
	}
}

rational inverse(rational x){
	rational y;	
	y.l = x.m;
	y.m = x.l;
	return y;
}
rational multiply(rational a, rational b){
	a.l *= b.l;
	a.m *= b.m;
	fraction(&a);
	return a;
}

void multiply_row(rational *C, rational *D, int n, int i, rational x){		//r(i) = r(i)*x
	for(int k=0; k<n; k++){
		C[index(i, k, n)] = multiply(C[index(i, k, n)], x);
	}
	D[i] = multiply(D[i], x);
}

void subtract_row_from_row(rational *C, rational *D, int n, int i, int k, rational x){ //r(k) -= r(i)*x
	for(int j=0; j<n; j++){
		C[index(k, j, n)] = reduce(C[index(k, j, n)], multiply(C[index(i, j, n)], x));
	}
	D[k] = reduce(D[k], multiply(D[i], x));
}

void clean_below(rational *C, rational *D, int n){		//doprowadza do postaci trójkątnej
	for(int i=0; i<n; i++){
		// TODO: jeśli wiersz ma zero na przekątnej, to zamień z niezerowym wierszem poniżej
		multiply_row(C, D, n, i, inverse(C[index(i, i, n)]));
		for(int k=i+1; k<n; k++){
			subtract_row_from_row(C, D, n, i, k, C[index(k, i, n)]);
		}
	}
}

void clean_above(rational *C, rational *D, int n){
	for(int j=n-1; j>=0; j--){
		for(int i=j-1; i>=0; i--){		
			subtract_row_from_row(C, D, n, j, i, C[index(i, j, n)]);
		}
	}
}

void rozwiaz(int *Al, int *Am, int *Bl, int *Bm, int *Xl, int *Xm, int n){
	rational *C = new rational[n*n];
	rational *D = new rational[n];
	to_rational(Al, Am, Bl, Bm, C, D, n);
	wypisz_dane(C, 3);
	wypisz_wynik(D, 3);
	cout <<endl <<endl;
	clean_below(C, D, 3);
	wypisz_dane(C, 3);
	wypisz_wynik(D, 3);
	cout <<endl <<endl;
	clean_above(C, D, n);
	wypisz_dane(C, 3);
	wypisz_wynik(D, 3);
	cout <<endl <<endl;
	delete[] C;
	delete[] D;
}

int Al[9] = {1, 2, 3, 4, 5, 6, 7, 8, 1};
int Am[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
int Bl[3] = {3, 3, 3};
int Bm[3] = {1, 1, 1};
int Xl[3] = {1, 1, 1};
int Xm[3] = {1, 1, 1};


int main(){


rozwiaz(Al, Am, Bl, Bm, Xl, Xm, 3);


return 0;
}
