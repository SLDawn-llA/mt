#include <iostream>
#include "Eigen/Dense"
#include<unsupported/Eigen/FFT>
#include"soci/soci.h"
#include"soci/odbc/soci-odbc.h"
#include <cmath>
#include <stdexcept> //用于抛出异常
using namespace Eigen;
using namespace std;
using namespace soci;

namespace FFTLibrary {
    //1对一维向量进行傅里叶变换
    Eigen::VectorXcd fft1D(const Eigen::VectorXcd& input, int n = -1) {
        Eigen::FFT<double> fft;
        int size = (n == -1) ? input.size() : n;

        Eigen::VectorXcd padded_input(size);
        if (n == -1) {
            padded_input = input;
        } else if (input.size() < n) {
            padded_input.setZero();
            padded_input.head(input.size()) = input;
        } else {
            padded_input = input.head(n);
        }

        Eigen::VectorXcd result(size);
        fft.fwd(result, padded_input);
        return result;
    }

    //对向量进行傅里叶变换
    Eigen::VectorXcd fft(const Eigen::VectorXcd& input, int n = -1) {
        return fft1D(input, n);
    }
//2对矩阵的列进行傅里叶变换
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& input, int n = -1) {
        int rows = input.rows();
        int cols = input.cols();

        Eigen::MatrixXcd output(rows, cols);
        for (int col = 0; col < cols; ++col) {
            Eigen::VectorXcd column = input.col(col);
            output.col(col) = fft1D(column, n);
        }
        return output;
    }

    //对矩阵的行或列进行FFT
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& input, int n, int dim) {
        if (dim != 0 && dim != 1) {
            throw std::out_of_range("Dimension must be 0 (columns) or 1 (rows)");
        }

        Eigen::MatrixXcd output(input.rows(), input.cols());
        if (dim == 0) { //对列进行变换
            for (int col = 0; col < input.cols(); ++col) {
                Eigen::VectorXcd column = input.col(col);
                output.col(col) = fft1D(column, n);
            }
        } else { //对行进行变换
            for (int row = 0; row < input.rows(); ++row) {
                Eigen::VectorXcd row_vec = input.row(row).transpose();
                output.row(row) = fft1D(row_vec, n).transpose();
            }
        }
        return output;
    }
}


int main() {
    using namespace FFTLibrary;

    //1 一维向量
    Eigen::VectorXcd X(5);
    X<< 1, 2, 3, 4, 5;
    Eigen::VectorXcd Y1 = FFTLibrary::fft(X, 8); //返回8点DFT
    std::cout << "一维向量FFT:\n" << Y1 << std::endl;

    //2 二维矩阵
    Eigen::MatrixXcd X2(3, 4);
    X2 << 1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12;


    Eigen::MatrixXcd Y2 = FFTLibrary::fft(X2, 5, 1); //对每一行进行5点DFT
    std::cout << "二维矩阵FFT:\n" << Y2 << std::endl;



    return 0;
}

