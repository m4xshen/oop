#include "Matrix.h"

Matrix::Matrix() : row(0), col(0), data(nullptr) {}

Matrix::Matrix(int row, int col) : row(row), col(col) {
  data = new double*[row];
  for (int i = 0; i < row; i++) {
    data[i] = new double[col];
    for (int j = 0; j < col; j++)
      data[i][j] = 0;
  }
}

Matrix::Matrix(int row, int col, double** arr2D) : row(row), col(col) {
  data = new double*[row];
  for (int i = 0; i < row; i++) {
    data[i] = new double[col];
    for (int j = 0; j < col; j++)
      data[i][j] = arr2D[i][j];
  }
}

Matrix::Matrix(const Matrix& matrix) : row(matrix.row), col(matrix.col) {
  data = new double*[row];
  for (int i = 0; i < row; i++) {
    data[i] = new double[col];
    for (int j = 0; j < col; j++)
      data[i][j] = matrix.data[i][j];
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < row; i++)
    delete[] data[i];
  delete[] data;
}

void Matrix::setValue(int rowIdx, int colIdx, double value) {
  data[rowIdx][colIdx] = value;
}

double Matrix::getValue(int rowIdx, int colIdx) const {
  return data[rowIdx][colIdx];
}

std::ostream &operator<<(std::ostream &out, Matrix m) {
  for (int i = 0; i < m.row; i++) {
    for (int j = 0; j < m.col; j++) {
      out << m.data[i][j] << " ";
    }
    out << "\n";
  }

  return out;
}

Matrix Matrix::operator+(Matrix m) const {
  Matrix ret(row, col);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      ret.data[i][j] = data[i][j] + m.data[i][j];

  return ret;
}

Matrix Matrix::operator-(Matrix m) const {
  Matrix ret(row, col);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      ret.data[i][j] = data[i][j] - m.data[i][j];

  return ret;
}

Matrix operator+(Matrix m) {
  return m;
}

Matrix operator-(Matrix m) {
  Matrix ret(m);
  for (int i = 0; i < m.row; i++)
    for (int j = 0; j < m.col; j++)
      ret.data[i][j] *= -1;

  return ret;
}

Matrix Matrix::transpose() const {
  Matrix ret(col, row);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      ret.data[j][i] = data[i][j];

  return ret;
}

void Matrix::operator=(Matrix m) {
  for (int i = 0; i < row; i++)
    delete[] data[i];
  delete[] data;

  row = m.row;
  col = m.col;
  
  data = new double*[row];
  for (int i = 0; i < row; i++) {
    data[i] = new double[col];
    for (int j = 0; j < col; j++)
      data[i][j] = m.data[i][j];
  }
}

void Matrix::operator+=(Matrix m) {
  (*this) = (*this) + m;
}

void Matrix::operator-=(Matrix m) {
  (*this) = (*this) - m;
}

bool Matrix::operator==(Matrix m) const {
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (data[i][j] != m.data[i][j]) return false;

  return true;
}

bool Matrix::operator!=(Matrix m) const {
  return !(*this == m);
}

Matrix Matrix::operator*(Matrix m) const {
  Matrix ret(row, m.col);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < m.col; j++)
      for (int k = 0; k < col; k++)
        ret.data[i][j] += data[i][k] * m.data[k][j];

  return ret;
}

Matrix Matrix::operator*(double d) const {
  Matrix ret(row, col);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      ret.data[i][j] = d * data[i][j];

  return ret;
}

Matrix operator*(double d, Matrix m) {
  return m * d;
}

void Matrix::operator*=(Matrix m) {
  (*this) = (*this) * m;
}

void Matrix::operator*=(double d) {
  (*this) = (*this) * d;
}

double Matrix::_determinant() const {
  if (row == 1) return data[0][0];

  double ret = 0;
  int sign = 1;
  for (int i = 0; i < col; i++) {
    // TODO

    sign *= -1;
  }

  return ret;
}

double Matrix::determinant() const {
  // TODO

  return 0;
}
