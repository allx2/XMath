#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;


class matrix{
    private:
        int row;
        int colum;
        float **M;
    public:
        matrix();
        matrix(int,int);
        matrix(const matrix&);
        ~matrix();
        matrix operator + (const matrix & in_matrix);
		matrix operator - (const matrix & in_matrix);
        matrix operator * (const matrix & in_matrix);
		matrix operator=(const matrix & in_matrix);
        friend ostream & operator << (ostream&, const matrix &);
        friend istream & operator >> (istream&, const matrix &);
};

#endif
