#include <iostream>
using std::cout;
#include <cmath>
#include <iomanip>
#include <vector>
#include <math.h>
double f1(double x, double y, double y1, double y2)
{
 return y1;
}
double f2(double x, double y, double y1, double y2)
{
 return y2;
}
double f3(double x, double y, double y1, double y2)
{
 return (-5.0*y1)-(0.3)*x*pow(y,3.0);
}
int main()
{
 int n = 1500;
 int m;
 double h = 30 / double(n);
 double i1 = 0.0, i2 = 0.0, i3 = 0.0, i4 = 0.0, i = 0.0;
 double j1 = 0.0, j2 = 0.0, j3 = 0.0, j4 = 0.0, j = 0.0;
 double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0, k = 0.0;
 double x = 0.0, y = 1.0, y1 = 0.0, y2 = 0.0;
 for (int m = 0; m<n; m++)
 {
 i1 = h * f1(x,y,y1,y2);
 j1 = h * f2(x,y,y1,y2);
 k1 = h * f3(x,y,y1,y2);
 i2 = h * f1(x + (h/2.0),y + (i1/2.0),y1 + (j1/2.0),y2 + (k1/2.0));
 j2 = h * f2(x + (h/2.0),y + (i1/2.0),y1 + (j1/2.0),y2 + (k1/2.0));
 k2 = h * f3(x + (h/2.0),y + (i1/2.0),y1 + (j1/2.0),y2 + (k1/2.0));
 i3 = h * f1(x + (h/2.0),y + (i2/2.0),y1 + (j2/2.0),y2 + (k2/2.0));
 j3 = h * f2(x + (h/2.0),y + (i2/2.0),y1 + (j2/2.0),y2 + (k2/2.0));
 k3 = h * f3(x + (h/2.0),y + (i2/2.0),y1 + (j2/2.0),y2 + (k2/2.0));
 i4 = h * f1(x + h,y + i3,y1 + j3,y2 + k3);
 j4 = h * f2(x + h,y + i3,y1 + j3,y2 + k3);
 k4 = h * f3(x + h,y + i3,y1 + j3,y2 + k3);
 i = (1/6.0) * (i1 + (2.0*i2) + (2.0*i3) + i4);
 j = (1/6.0) * (j1 + (2.0*j2) + (2.0*j3) + j4);
 k = (1/6.0) * (k1 + (2.0*k2) + (2.0*k3) + k4);
 x = x + h;
 y = y + i;
 y1 = y1 +j;
 y2 = y2 +k;
 cout.precision(10);
 cout << "x: " << x << " " << "y: " << y << "\n";
 }
return 0;
}
