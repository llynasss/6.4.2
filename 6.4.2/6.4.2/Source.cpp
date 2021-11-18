#include <iostream> 

#include <iomanip> 

#include <time.h> 



using namespace std;



void create(double* a, int n, int l, int h, int i);

void print(double* a, int n, int i);

double sum(double* a, int n, double s, int i);

double dob_p(double* a, int n, int i, int j, double dob);

int min_ip(double* a, int n, double min_a, int min_i, int i);

int max_ip(double* a, int n, double max_a, int max_i, int i);

void Sort(double* a, const int size, int i);

void Min(double* a, const int size, double& min, int& imin, int j);



int main() {

    srand((unsigned)time(NULL));



    int n;

    int l = -10;

    int h = 10;

    int k;

    double s;

    double d;

    int i;

    int j;



    cout << "n = "; cin >> n;

    double* a = new double[n];



    create(a, n, l, h, 0);





    print(a, n, 0);



    s = sum(a, n, 0, 0);



    i = min_ip(a, n, a[0], 0, 0);

    j = max_ip(a, n, a[0], 0, 0);



    d = dob_p(a, n, i, j, 1);



    Sort(a, n, 0);



    print(a, n, 0);



    cout << endl << "| s = " << s << " |";

    cout << endl << "| d = " << d << " |";



    cout << endl << "| i min = " << i << " |";

    cout << endl << "| i max = " << j << " |";



    return 0;

}







void create(double* a, int n, int l, int h, int i) {

    a[i] = ((((double)rand()) / (double)RAND_MAX) * ((double)h - (double)l)) + (double)l;

    if (i < n - 1)

        create(a, n, l, h, i + 1);

}



void print(double* a, int n, int i) {

    cout << setw(7) << setprecision(6) << a[i] << " |";



    if (i < n - 1) {

        print(a, n, i + 1);

    }

    else {

        cout << endl;

    }

}



double sum(double* a, int n, double s, int i) {

    if (a[i] < 0) {

        s += a[i];

    }



    if (i < n - 1) {

        return sum(a, n, s, i + 1);

    }

    else {

        return s;

    }



}



double dob_p(double* a, int n, int i, int j, double dob) {

    int tmp;

    if (i > j) {

        tmp = i;

        i = j;

        j = tmp;

    }



    if (dob == 1) {

        i += 1;

    }



    if (i == j) {

        return -1;

    }





    dob *= a[i];



    if (i < j - 1) {

        return dob_p(a, n, i + 1, j, dob);

    }

    else {

        return dob;

    }

}



int min_ip(double* a, int n, double min_a, int min_i, int i) {

    if (a[i] < min_a) {

        min_a = a[i];

        min_i = i;

    }



    if (i < n - 1) {

        return min_ip(a, n, min_a, min_i, i + 1);

    }

    else {

        return min_i;

    }

}



int max_ip(double* a, int n, double max_a, int max_i, int i) {

    if (a[i] > max_a) {

        max_a = a[i];

        max_i = i;

    }



    if (i < n - 1) {

        return max_ip(a, n, max_a, max_i, i + 1);

    }

    else {

        return max_i;

    }

}



void Min(double* a, const int size, double& min, int& imin, int j) {

    if (min > a[j])

    {

        min = a[j];

        imin = j;

    }

    if (j < size - 1)

        Min(a, size, min, imin, j + 1);

}



void Sort(double* a, const int size, int i) {

    double min = a[i];

    int imin = i;

    Min(a, size, min, imin, i + 1);

    a[imin] = a[i];

    a[i] = min;

    if (i < size - 2)

        Sort(a, size, i + 1);

}

