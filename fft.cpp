#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0);
    fft(a1);

    double ang = 2 * PI / n;
    cd w(1);
    for (int i = 0; 2 * i < n; i++) {
        w = polar(1.0 , -1*i * 2 * PI / n);
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
    }
}





bool cmp(cd a, cd b){
  return (a.real()*a.real() + a.imag()*a.imag()) >
    (b.real()*b.real() + b.imag()*b.imag());
}


int main(){
  
  int elem;
  vector<int> v;
  while(cin>>elem)
    v.push_back(elem);
  vector<cd> v2(v.size());
  for(int i=0;i<v.size();i++){
    v2[i].real(v[i]);
    v2[i].imag(0);
  }
  reverse(v2.begin(),v2.end());
  fft(v2);
  //reverse(next(v2.begin()),v2.end());
  //sort(v2.begin(),v2.end(),cmp); 

  for(int i=0;i<v2.size();i++)
    cout<<v2[i].real()<<"  "<<v2[i].imag()<<endl;

  return 0;
}

