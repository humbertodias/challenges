// Problem   Global Roaming
// Algorithm 3D-Geometry
// Runtime   O(n)

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

const double RAD = 6378.0;
const double PI = 3.14159265358979323846;

void polar2cartesian (double lat, double lon, double &x, double &y, double &z)
{
  lat = 2.0 * PI * (lat / 360.0);
  lon = 2.0 * PI * (lon / 360.0);
  x = cos (lat) * sin (lon);
  y = cos (lat) * cos (lon);
  z = sin (lat);
}

double norm (double x, double y, double z)
{
  return sqrt (x * x + y * y + z * z);
}

int main ()
{
  for (int kase=1 ; ; kase++)
  {
    int n;
    double slat, slon, sdist, sx, sy, sz;
    cin >> n >> slat >> slon >> sdist;
    if (n == 0) break;
    polar2cartesian (slat, slon, sx, sy, sz);
    sx *= sdist + RAD;
    sy *= sdist + RAD;
    sz *= sdist + RAD;
    cout << "Test case " << kase << ":" << endl;
    while (n--)
    {
      string name;
      double nlat, nlon, nx, ny, nz, dx, dy, dz;
      cin >> name >> nlat >> nlon;
      polar2cartesian (nlat, nlon, nx, ny, nz);
      nx *= RAD;
      ny *= RAD;
      nz *= RAD;
      dx = sx - nx;
      dy = sy - ny;
      dz = sz - nz;
      double a = acos ((nx * dx + ny * dy + nz * dz) /
                       (norm (nx, ny, nz) * norm (dx, dy, dz)));
      if (a < 0.5 * PI)
        cout << name << endl;
    }
    cout << endl;
  }
  return 0;
}