import java.util.*;

class Point3{
  public double x,y,z;
  public Point3(double x, double y, double z){
    this.x = x;
    this.y = y;
    this.z = z;
  }
}

class Main{
  static final double RAD = 6378.0d;
  static final double PI = 3.14159265358979323846d;

  static Point3 polar2cartesian (double lat, double lon)
  {
    lat = 2.0 * PI * (lat / 360.0);
    lon = 2.0 * PI * (lon / 360.0);
    double x = Math.cos (lat) * Math.sin (lon);
    double y = Math.cos (lat) * Math.cos (lon);
    double z = Math.sin (lat);
    return new Point3(x,y,z);
  }

  static double norm (double x, double y, double z)
  {
    return Math.sqrt (x * x + y * y + z * z);
  }

  public static void main (String []args)
  {
    Locale.setDefault( Locale.US );
    Scanner scanner = new Scanner(System.in);
    for (int kase=1 ; ; kase++)
    {
      Double sx = 0d, sy = 0d, sz = 0d;
      int n = scanner.nextInt();
      Double slat = scanner.nextDouble();
      Double slon = scanner.nextDouble();
      Double sdist = scanner.nextDouble();
      if (n == 0) break;
      Point3 p3 = polar2cartesian (slat, slon);
      sx = p3.x;
      sy = p3.y;
      sz = p3.z;

      sx *= sdist + RAD;
      sy *= sdist + RAD;
      sz *= sdist + RAD;
      System.out.printf("Test case %d:\n", kase);
      while (n-- > 0)
      {
        Double nx = 0d, ny = 0d, nz = 0d;
        Double dx, dy, dz;
        String name = scanner.next();
        Double nlat = scanner.nextDouble();
        Double nlon = scanner.nextDouble();

        Point3 p33 = polar2cartesian (nlat, nlon);
        nx = p33.x;
        ny = p33.y;
        nz = p33.z;


        nx *= RAD;
        ny *= RAD;
        nz *= RAD;
        dx = sx - nx;
        dy = sy - ny;
        dz = sz - nz;
        double a = Math.acos ((nx * dx + ny * dy + nz * dz) /
                         (norm (nx, ny, nz) * norm (dx, dy, dz)));
        if (a < 0.5 * PI)
          System.out.println(name);
      }
      System.out.println();
    }

  }

}