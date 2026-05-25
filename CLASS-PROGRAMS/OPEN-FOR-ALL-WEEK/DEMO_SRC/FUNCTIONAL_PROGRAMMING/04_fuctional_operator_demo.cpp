#include <iostream> 
#include <cstdlib> 
#include <stdexcept> 
#include <functional>

class matrix{
    
    private: 
        int* p_matrix; 
        int rows; 
        int cols; 
    
    public: 

        matrix(int nr_rows, int nr_cols){
            if(nr_rows <= 0 || nr_cols <= 0)
                throw std::domain_error("Bad dimension"); 
            rows = nr_rows; 
            cols = nr_cols; 
            p_matrix = new int[rows * cols * sizeof(int)]; 
            for(int i = 0; i < rows; ++i)
                for(int j = 0; j < cols; ++j)
                    if(rows == cols && i == j)
                        *(p_matrix + i * cols + j) = 1; 
                    else 
                        *(p_matrix + i * cols + j) = 0; 
        }

        matrix& operator+(const matrix& other)const{
            matrix* p_addition_matrix = 0; 
            if(rows != other.rows || cols != other.cols)
                throw std::length_error("addned matrices: dimension differ"); 
            p_addition_matrix = new matrix(rows, cols); 
            for(int i = 0; i < rows; ++i)
                for(int j = 0; j < cols; ++j)
                    *(p_addition_matrix->p_matrix + i * cols + j) = *(p_matrix + i * cols + j) + 
                                                                    *(other.p_matrix + i * cols + j); 
            return (*p_addition_matrix); 
        }

        matrix& operator-(const matrix& other)const{
            matrix* p_subtraction_matrix = 0; 
            if(rows != other.rows || cols != other.cols)
                throw std::length_error("addned matrices: dimension differ"); 
            p_subtraction_matrix = new matrix(rows, cols); 
            for(int i = 0; i < rows; ++i)
                for(int j = 0; j < cols; ++j)
                    *(p_subtraction_matrix->p_matrix + i * cols + j) = *(p_matrix + i * cols + j) - 
                                                                    *(other.p_matrix + i * cols + j); 
            return (*p_subtraction_matrix); 
        }

        matrix& operator*(const matrix& other){
            if(cols != other.rows)
                throw std::length_error("Cols of matrix 1 != Rows in matrix 2"); 
            matrix* p_mul_matrix = new matrix(rows, other.cols); 

            return (*p_mul_matrix); 
        }

        int get(int i, int j){
            if(!(0 <= i && i < rows) || !(0 <= j && j < cols))
                throw std::range_error("i or j are out of range"); 
            return (*(p_matrix + i * cols + j)); 
        }

        void set(int i, int j, int val){
            if(!(0 <= i && i < rows) || !(0 <= j && j < cols))
                throw std::range_error("i or j are out of range"); 
            *(p_matrix + i * cols + j) = val; 
        }

        ~matrix()
        {
            delete[] p_matrix; 
        }

        friend std::ostream& operator<<(std::ostream& o_stream, const matrix& other); 
}; 

std::ostream& operator<<(std::ostream& o_stream, const matrix& other){
    for(int i = 0; i < other.rows; ++i)
        for(int j = 0; j < other.cols; ++j) 
            o_stream << "M[" << i << "][" << j << "]:" << *(other.p_matrix + i * other.cols + j) 
                        << std::endl; 
    return o_stream; 
}

int main(void){
    int R=3, C=3; 
    matrix M1(R,C), M2(R,C);

    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            M1.set(i, j, (i+j)*5); 

    std::cout << "M1:" << std::endl << M1; 

    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            M2.set(i, j, (i+j)*10); 
    
    std::cout << "M2:" << std::endl << M2; 

    matrix& M_add = M1 + M2; 
    std::cout << "M1 + M2:" << std::endl << M_add << std::endl; 

    matrix& M_sub = M1 - M2; 
    std::cout << "M1 - M2:" << std::endl << M_sub << std::endl; 

    std::plus<matrix> add_matrices; 
    std::minus<matrix> subtract_matrices; 

    const matrix &m_add1 = add_matrices(M1, M2); 
    std::cout << "M1+M2:" << m_add1 << std::endl; 

    const matrix& m_sub1 = subtract_matrices(M1, M2); 
    std::cout << "M1 - M2:" << m_sub1 << std::endl; 

    delete &M_add; 
    delete &M_sub; 
    delete &m_add1; 
    delete &m_sub1; 
    puts("END"); 

    return (0); 
}

/* 
    matrix::add(&m1, m2);   // PROCEDURAL 

    m1.add(m2);     // OBJECT BASED PROGRAMMING 

    m1 + m2;        // OBJECT BASED PROGRAMMING WITH OO 

    std::plus<matrix> addm; 

    addm(M1, M2);   // FUNCTIONAL PROGRAMMING 
    == 
    std::plus<matrix>::operator(M1, M2); // OBJECT BASED PROGRAMMING WITH OO 
    == 
    M1 + M2 // // OBJECT BASED PROGRAMMING WITH OO  
    == 
    M1.opeartor+(M2);   // OBJECT BASED PROGRAMMING 
    ==
    matrix::operator+(&M1, M2); 
*/