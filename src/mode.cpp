#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
 double mode(NumericVector x) {
   int max = 0;
   double mostFreq = x[0];
   for(int i=0; i < x.size(); i++)
    {
      if (R_IsNA(x[i])) {
        Rcpp::stop("Missing values not allowed");
      }
      int cand = (int) std::count(x.begin(), x.end(), x[i]);
      if(cand > max)
      {  
        max = cand;
        mostFreq = x[i];
      }
    }
    return mostFreq;
  }