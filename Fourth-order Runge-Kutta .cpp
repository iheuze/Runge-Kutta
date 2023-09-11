
#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

// For differential equation "dx/dt = (1 - t)*(5 - 2t)*sqrt(1 - x)"
double dxdt(double t, double x)
{
  return((1 - t) * (5 - 2 * t) * sqrt(1 - x));
}

// Finds value of x for a given t using step size h
// and initial value x0 at t0.

double rungeKutta(double t0, double x0, double t, double h)
{
 // Count number of iterations using step size or
 // step height h
 
  double n = (t-t0) / double(h);
 
  double k1, k2, k3, k4;
 
// Iterate for number of iterations
  double x = x0;
 
 
  for (int i = 1; i <= n; i++)
  {
    // Apply Runge Kutta Formulas to find
    // next value of y
    k1 = h * dxdt(t0, x); 
    k2 = h * dxdt(t0 + 0.5 * h, x + 0.5 * k1); 
    k3 = h * dxdt(t0 + 0.5 * h, x + 0.5 * k2);
    k4 = h * dxdt(t0 + h, x + k3);
  // cout << "t=" << t0 << ", x=" << x << ", k1=" << k1 << ", k2=" << k2 << ", k3=" << k3 << ", k4=" << k4 << endl;
 
  // Update next value of x
 
    x = x + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
  // Update next value of t
    t0 = t0 + h;
  } 
  return x;
}
double err(double rk, double f)
{
   return abs(rk - f);
}
// Driver Code
int main()
{
  double t0 = 0.0, x0 = -1.0, t = 3.0, h = 0.0002;
  {
    cout.precision(10);
    cout << "The value of x at t=3, for h=0.0002, is " << rungeKutta(t0, x0, t, h) << endl;
  }

  double f = 0.671813483298;
 //double f = 0.5588203436;
  double tolerance = pow(10, -8);
 
  int j = 10;
  int max_run = 1000000000;
  h = (t - t0) / j;
  double rk = rungeKutta(t0, x0, t, h);
  cout.precision(10);
  cout << "The value of x at t=3, for h=" << h << ", is " << rk;
  cout << " Error: " << err(rk, f);
  cout << " Number of runs: " << j << endl;

  cout << "Tolerance:" << tolerance << endl;
  cout << "Minimum number of run:";
  cin >> j;
 
  while ((err(rk, f) > tolerance) && j<= max_run)
  {
    if (err(rk, f) > tolerance)
    {
       h = (t - t0) / j;
       rk = rungeKutta(t0, x0, t, 3.0 / j);
        //cout << "The value of x at t=3, for h=" << h << ", is " << rk;
       //cout << " Error: " << err(rk, f);
       cout << " Number of runs: " << j << endl;
       j = j*10;
   }
 
  if (err(rk, f) < tolerance)
  {
     cout << "The value of x at t=3, for h=" << h << ", is " << rk;
     cout << " Error: " << err(rk, f);
     cout << " Number of runs: " << j << endl;
     break;
   }
 
  if ( j > max_run)
 
  {
     cout << "Max number of runs reached: " << j << endl;
     cout << "The value of x at t=3, for h=" << h << ", is " << rk;
     cout << " Error: " << err(rk, f) << endl;
     break;
  }
 
  }
 
  cin.ignore(); //This & next line pause program after ending.
  cin.get();
  return 0;
}
