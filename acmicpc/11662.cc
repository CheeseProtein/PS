#include <cmath>
#include <iostream>
using namespace std;

int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

double minho_x(double p) { return p * (Bx - Ax) + Ax; }
double minho_y(double p) { return p * (By - Ay) + Ay; }
double gang_x(double p) { return p * (Dx - Cx) + Cx; }
double gang_y(double p) { return p * (Dy - Cy) + Cy; }
double dist(double p) {
    return sqrt(pow(minho_x(p) - gang_x(p), 2) +
                pow(minho_y(p) - gang_y(p), 2));
}

int main() {
	scanf("%d%d%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);
    double lo = 0, hi = 1;
    for (int iter = 0; iter < 100; ++iter) {
        double a = (2 * lo + hi) / 3.0;
        double b = (lo + 2 * hi) / 3.0;
        if (dist(a) < dist(b))
            hi = b;
        else
            lo = a;
    }
	double answer = dist((lo + hi) / 2.0);
	printf("%.10lf", answer);
	return 0;
}