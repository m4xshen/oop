#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

struct Point {
  int x;
  double y;
};

double w(int cycle, int max_cycle) {
  double w_min = 0.85;
  double w_max = 1.15;

  return w_max-(w_max-w_min) * cycle / max_cycle;
}

double r(int x, double *a, int dim) {
  double ans = 0;
  for(int i = 0; i < dim; i++) {
    ans += a[i] * pow(x, i);
  }
  return ans;
}

int pow(int a, int x) {
  if(x == 0) return 1;
  if(x & 1) return a * pow(a, x-1);
  else return pow(a*a, x/2);
}

double loss(Point *point, int n, double *a, int dim) {
  double ans = 0;
  for(int i = 0; i < n; i++) {
    ans += std::abs(point[i].y - r(point[i].x, a, dim));
  }
  return ans;
}

int main(int argc, char **argv) {
  int dim, num_b, max_cycle;
  double c1, c2;

  // set
  std::ifstream fin(argv[1]);

  std::string trash;
  fin >> trash >> dim >> trash >> num_b >> trash >>
      max_cycle >> trash >> c1 >> trash >> c2;

  int x_min[dim];
  int x_max[dim];
  double x[num_b][dim];
  double v[num_b][dim];

  double p[num_b][dim];
  double g[dim];

  fin >> trash;
  for(int i = 0; i < dim; i++) {
    fin >> x_min[i];
  }

  fin >> trash;
  for(int i = 0; i < dim; i++) {
    fin >> x_max[i];
  }

  double k = 0.5;
  double v_max[dim];
  for(int i = 0; i < dim; i++) {
    v_max[i] = (x_max[i]-x_min[i]) * k / 2;
  }

  fin.close();

  // data
  fin.open(argv[2]);
  int n;
  fin >> n;
  Point point[n];

  for(int i = 0; i < n; i++) {
    fin >> point[i].x >> point[i].y;
  }
  fin.close();

  // init
  for(int i = 0; i < num_b; i++) {
    for(int j = 0; j < dim; j++) {
      x[i][j] = x_min[j] + (x_max[j]-x_min[j]) * i / (num_b-1);
      v[i][j] = 0;
      p[i][j] = x[i][j];
    }
  }

  for(int i = 0; i < dim; i++) {
    g[i] = x[0][i];
  }

  for(int i = 0; i < num_b; i++) {
    if(loss(point, n, g, dim) > loss(point, n, p[i], dim)) {
      for(int j = 0; j < dim; j++) {
        g[j] = p[i][j];
      }
    }
  }

  fin.open(argv[3]); // rand1
  double r1[max_cycle][num_b][dim];
  for(int i = 0; i < max_cycle; i++) {
    for(int j = 0; j < num_b; j++) {
      for(int k = 0; k < dim; k++) {
        fin >> r1[i][j][k];
      }
    }
    fin >> trash;
  }
  fin.close();

  fin.open(argv[4]); // rand2
  double r2[max_cycle][num_b][dim];
  for(int i = 0; i < max_cycle; i++) {
    std::string trash;
    for(int j = 0; j < num_b; j++) {
      for(int k = 0; k < dim; k++) {
        fin >> r2[i][j][k];
      }
    }
    fin >> trash;
  }
  fin.close();

  // iter
  for(int cycle = 0; cycle < max_cycle; cycle++) {
    for(int i = 0; i < num_b; i++) {
      for(int j = 0; j < dim; j++) {
        v[i][j] = v[i][j]*w(cycle, max_cycle) +
            c1*(p[i][j]-x[i][j])*r1[cycle][i][j] +
            c2*(g[j]-x[i][j])*r2[cycle][i][j];

        if(cycle == 50) std::cout << v[i][j] << "\n";

        if(v_max[j] < v[i][j]) v[i][j] = v_max[j];
        if(-v_max[j] > v[i][j]) v[i][j] = -v_max[j];

        x[i][j] += v[i][j];
        if(x_max[j] < x[i][j]) x[i][j] = x_max[j];
        if(x_min[j] > x[i][j]) x[i][j] = x_min[j];
      }

      // update p
      double before = loss(point, n, p[i], dim);
      if(loss(point, n, x[i], dim) < before) {
        for(int k = 0; k < dim; k++) {
          p[i][k] = x[i][k];
        }
      }

      // update g
      if(loss(point, n, g, dim) > loss(point, n, p[i], dim)) {
        for(int k = 0; k < dim; k++) {
          g[k] = p[i][k];
        }
      }
    }
  }

  for(int i = 0; i < dim; i++) {
    std::cout << g[i] << "\n";
  }

  return 0;
}
