#include "ostream"

// Matrix.h
class Matrix {
   private:
    double** data;
    int row;
    int col;

   public:
    // Level 1
    // Constructors and destructor
    Matrix();                                  // Set row and col to 0, data to nullptr
    Matrix(int row, int col);                  // Create a zero matrix
    Matrix(int row, int col, double** arr2D);  // Copy from array
    Matrix(const Matrix& matrix);              // Copy from another matrix
    ~Matrix();                                 // Delete data

    // Setters and Getters
    // Set the value of the given row and col
    void setValue(int rowIdx, int colIdx, double value);
    // Get the value of the given row and col
    double getValue(int rowIdx, int colIdx) const;

    // Transpose
    Matrix transpose() const;  // Return a new transposed matrix

    // Operator Overload
    // Overload =, +=, -=, +, -, +m, -m, ==, !=, ostream<<
    void operator=(Matrix);   // Copy to a new matrix
    void operator+=(Matrix);  // Matrix addition, ex: a += b;
    void operator-=(Matrix);  // Matrix subtraction, ex: a -= b;
    Matrix operator+(Matrix) const;   // Matrix addition, ex: c = a + b;
    Matrix operator-(Matrix) const;   // Matrix subtraction, ex: c = a - b;
    friend Matrix operator+(Matrix);   // Positive Matrix, ex: Matrix b = +a;
    friend Matrix operator-(Matrix);   // Negative Matrix, ex: Matrix b = -a;
    bool operator==(Matrix) const;  // Return true if the two matrix is equal
    bool operator!=(Matrix) const;  // Return false if the two matrix is equal
    friend std::ostream &operator<<(std::ostream &, Matrix);  // Output the matrix, ex: cout << a;

    // Level 2
    // Overload *=, *
    void operator*=(Matrix); // Matrix and Matrix multiplication
    void operator*=(double); // Matrix and double multiplication
    Matrix operator*(Matrix) const; // Matrix and Matrix multiplication
    Matrix operator*(double) const; // Matrix and double multiplication
    friend Matrix operator*(double, Matrix); // double and Matrix multiplication

    // Level 3
    double determinant() const;  // The determinant of the matrix
    double _determinant() const;
};
