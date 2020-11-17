# csc-372-fast-fourier-transform

   RECURSIVE-FFT(a[]) // a is the list of coefficients
     n=a.length
     If n==1
       Return a
     w[n] = 
     y = [0..n-1]


       // split into the evens
       // split into the odds
      = RECURSIVE-FFT(E) 
     oddResult = RECURSIVE-FFT(
     for k=0 to n/2-1
     //the results are only half, the total length 
     // so this use the fact that the results are mirrored
     y[k] = evenResult[k] + w[n]^k * oddResult[k]
     y[k+n/2] = evenResult[k] - w[n]^k * oddResult[k]
     return y



**y** -- hold new values

