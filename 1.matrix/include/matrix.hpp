#ifndef MATRIX_HPP_
#define MATRIX_HPP_

//***************************************************
template<typename T>
class Matrix{
private:
    int m_row;
    int m_col;
    T** m_data;

    template<typename Func>
    void _foreach(Func func) const;

public:
    //构造和析构
    explicit Matrix(T data); //构造函数, 默认为2*2矩阵
    Matrix(int row, int col); //构造函数, 指定行列, 默认为0
    Matrix(int row, int col, T data); //构造函数, 指定行列, 指定值
    Matrix(const Matrix& matrix); //拷贝构造函数
    ~Matrix(); //析构函数

    //输入和输出
    void print() const; //打印矩阵
    template<typename T_>
    friend std::ostream &operator<<(std::ostream &os, Matrix<T>& matrix);//重载输出运算符

    void input(); //输入矩阵
    template<typename T_>
    friend std::istream &operator>>(std::istream &is, Matrix<T_>& matrix); //重载输入运算符

    //todo 运算与运算符重载

};
//***************************************************

template<typename T>
template<typename Func>
void Matrix<T>::_foreach(Func func) const {
    for(int i = 0; i < m_row; i++){
        func(i);
    }
}

template<typename T>
Matrix<T>::Matrix(T data) : m_row(2), m_col(2) {
    m_data = new T*[m_row];
    _foreach([&](int i){
        m_data[i] = new T[m_col];
        for(int j = 0; j < m_col; j++) {
            m_data[i][j] = data;
        }
    });
}

template<typename T>
Matrix<T>::Matrix(int row, int col) : m_row(row), m_col(col) {
    m_data = new T*[m_row];
    _foreach([&](int i){
        m_data[i] = new T[m_col];
        for(int j = 0; j < m_col; j++) {
            m_data[i][j] = 0;
        }
    });
}

template<typename T>
Matrix<T>::Matrix(int row, int col, T data) : m_row(row), m_col(col) {
    m_data = new T*[m_row];
    _foreach([&](int i){
        m_data[i] = new T[m_col];
        for(int j = 0; j < m_col; j++) {
            m_data[i][j] = data;
        }
    });
}


template<typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    m_row = matrix.m_row;
    m_col = matrix.m_col;
    m_data = new T*[m_row];
    _foreach([&](int i){
        m_data[i] = new T[m_col];
        for(int j = 0; j < m_col; j++) {
            m_data[i][j] = matrix.m_data[i][j];
        }
    });
}

template<typename T>
Matrix<T>::~Matrix() {
    _foreach([&](int i) {
        delete[] m_data[i];
    });
    delete[] m_data;
}


template<typename T>
void Matrix<T>::print() const {
    std::cout << "output matrix: " << std::endl;
    std::cout << "\t";
   for(int i = 0; i < m_col; i++){
       std::cout << "[ ," << i+1 << "]\t";
   }
    std::cout << std::endl;
    _foreach([&](int i) {
        std::cout << "[" << i+1 << ", ]\t";
        for(int j = 0; j < m_col; j++) {
            std::cout << m_data[i][j] << "\t";
        }
        std::cout << std::endl;
    });
    std::cout << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, Matrix<T>& matrix){ //重载输出运算符
    matrix.print();
    return os;
}

template<typename T>
void Matrix<T>::input() {
    std::cout << "input matrix: (num) + <TAB>" << std::endl;
    std::cout << "\t";
    for(int i = 0; i < m_col; i++){
        std::cout << "[ ," << i+1 << "]\t";
    }
    std::cout << std::endl;
    _foreach([&](int i) {
        std::cout << "[" << i+1 << ", ]\t";
        for(int j = 0; j < m_col; j++) {
            std::cin >> m_data[i][j];
        }
    });
}

template<typename T>
std::istream &operator>>(std::istream &is, Matrix<T>& matrix){ //重载输入运算符
    matrix.input();
    return is;
}
#endif