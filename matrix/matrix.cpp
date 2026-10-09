#include "matrix.hpp"

#include <ostream>
#include <stdexcept>

Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : data_(values)
{
    if (data_.empty() || data_.front().empty()) {
        throw std::invalid_argument("a matrix must have at least one row and one column");
    }

    const std::size_t column_count = data_.front().size();
    for (const auto& row : data_) {
        if (row.size() != column_count) {
            throw std::invalid_argument("all matrix rows must have the same length");
        }
    }
}

std::size_t Matrix::rows() const
{
    return data_.size();
}

std::size_t Matrix::cols() const
{
    return data_.front().size();
}

double& Matrix::at(std::size_t row, std::size_t col)
{
    return data_.at(row).at(col);
}

double Matrix::at(std::size_t row, std::size_t col) const
{
    return data_.at(row).at(col);
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
    // TODO: Check dimensions and return the element-wise sum.
    (void)rhs;
    int r1=rows(); //or use this points to the class itself r1=this->rows()
    int r2=rhs.rows();
    int c1=cols();
    int c2=rhs.cols();
    if (r1!=r2||c1!=c2)
    {
        throw std::invalid_argument("matrix addition: dimensions do not match");
    }
    std::vector<std::vector<double>> ans1;
    for (std::size_t i = 0; i < rows(); ++i)
    {
        std::vector<double> new_row;
        for (std::size_t j = 0; j < cols(); ++j)
        {
            new_row.push_back( at(i,j) + rhs.at(i,j) ); //or this->at(i,j)
        }
        ans1.push_back(std::move(new_row));
    }
    return Matrix(ans1);
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    // TODO: Check dimensions and return the matrix product.
    if (cols() != rhs.rows())
    {
        throw std::invalid_argument("matrix multiplication: dimension mismatch");
    }

    std::size_t m = rows();
    std::size_t n = cols();
    std::size_t p = rhs.cols();

    std::vector<std::vector<double>> ans2(m, std::vector<double>(p, 0.0));

    for (std::size_t i = 0; i < m; ++i)
    {
        for (std::size_t j = 0; j < p; ++j)
        {
            double sum = 0.0;
            for (std::size_t k = 0; k < n; ++k)
            {
                sum += at(i,k) * rhs.at(k,j);
            }
            ans2[i][j] = sum;
        }
    }
    return Matrix(ans2);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    // TODO: Write the matrix to os, one row per line.
    (void)matrix;
    std::size_t r = matrix.rows();
    for (std::size_t i = 0; i < r; ++i)
    {
        std::size_t c = matrix.cols();
        for (std::size_t j = 0; j < c; ++j)
        {
            if (j > 0) os << " ";
            os << matrix.at(i,j);
        }
        os << "\n";
    }
    return os;
}
