#ifndef A2_H_INCLUDED
#define A2_H_INCLUDED
#include <algorithm>

namespace cse250{
    class A2{
      public:
      A2(int n, int m):row(n),col(m){
          ptr_ = new double[row*col]();
      }
      double& operator()(const int rown, const int coln){
          int nrow = this.row;
          return ptr_[rown*nrow + coln];
      }
      double rsum(int n){
          double rsumofnum = 0.0;
          for(int i=0; i < this.col; i++){
            rsumofnum += ptr_[(n-1) + i];
          }
          return rsumofnum;
      }
      double csum(int n){
          double csumofnum = 0.0;
          for (int i =0; i < this.row; i++){
            csumofnum += ptr_[(n-1) + (3*i)];
          }
          return csumofnum;
      }
      ~A2(){delete[] ptr_};
      private:
      int size_;
      double* ptr_;
      int row, col;
    };
    /*
    double& A2::operator()(const int rown,const int coln) {
          int nrow = this.row;
          return ptr_[rown*nrow + coln];
    }
    */
}
#endif // A2_H_INCLUDED
