#include "Point2D.h"
#include "Vector.h"
#include <iostream>

int main() {
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  Vector<double> dvec(n,1);

  double *b = new double[n];
  for (int i=0;i<n;i++) b[i] = i;
  Vector<double> dvec2(n,b);

  std::cout << "dvec = "; dvec.display();  
  std::cout << "dvec2 = "; dvec2.display(); 
  dvec2 += dvec;
  std::cout << "new dvec2 = "; dvec2.display(); 

  double c = dot(dvec, dvec2); //dot operation
  std::cout << "dot(dvec, dvec2) = " << c << std::endl << std::endl;

  srand(1);    

  Vector<Point2D> vp1(n, Point2D());// Point2D() (x,y) = (1,1)
  Point2D *v = new Point2D[n];
  rand1D<Point2D>(v,n);   //0~9
  Vector<Point2D> vp2(n,v);

  std::cout << "vp1 = "; vp1.display();
  std::cout << "vp2 = "; vp2.display();

  vp2 += vp1; 

  std::cout << "new vp2 = "; vp2.display();

  Point2D d = dot(vp1, vp2);
  std::cout << "dot(vp1, vp2) = " << d << endl;

  return 0;
}
