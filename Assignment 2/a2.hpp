#ifndef A2_H_INCLUDED
#define A2_H_INCLUDED
#include <algorithm>

class A2{
    public:
        explicit A2(int n, int m):size_(std::max(0,n*m)){
            if (size_ == 0){
                ptr_ = 0;
                row_ = 0;
                col_ = 0;
            }
            else{
                ptr_ = new double[size_];
                row_ = m;
                col_ = n;
            }
        }//A2 Constructor

        A2(const A2& A): size_(A.size_){
            if (size_ == 0){
                ptr_ = 0;
                row_ = 0;
                col_ = 0;
            }
            else{
                row_ = A.row_;
                col_ = A.col_;
                ptr_ = new double[size_];
                std::copy(A.ptr_,A.ptr_ + size_, ptr_);
            }
        }
        A2(){
            ptr_ = 0;
            size_ = 0;
            row_ = 0;
            col_ = 0;
        }
        A2& operator=(const A2& A){
            if (this == &A) return *this; //self-assignment
            delete[] ptr_;
            size_ = A.size_;
            if (size_ == 0){
                ptr_ = 0;
                row_ = 0;
                col_ = 0;
            }
            else{
                ptr_ = new double[size_];
                row_ = A.row_;
                col_ = A.col_;
                std::copy(A.ptr_, A.ptr_ + size_, ptr_);
            }
            return *this;
        }
        ~A2(){delete[] ptr_;}

        double& operator()(int row,int col){
            int index = (row*row_) + col;
            return ptr_[index];
        }
        const double& operator()(int row,int col) const{
            int index = (row*row_) + col;
            return ptr_[index];
        }

        double rsum(int n){
            double rsumofnum = 0.0;
            for(int i=0; i < col_; i++){
              rsumofnum += ptr_[(n-1) + i];
            }
            return rsumofnum;
        }
        double csum(int n){
            double csumofnum = 0.0;
            for (int i =0; i < row_; i++){
              csumofnum += ptr_[(n-1) + (row_*i)];
            }
            return csumofnum;
        }
    private:
        int size_;
        int row_, col_;
        double* ptr_;
};
    /*
    double& A2::operator()(const int rown,const int coln) {
          int nrow = this.row;
          return ptr_[rown*nrow + coln];
    }
    */
#endif // A2_H_INCLUDED
