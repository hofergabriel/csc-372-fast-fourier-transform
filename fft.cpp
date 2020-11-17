#include <bits/stdc++.h>
using namespace std;
using namespace complex_literals;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a) {
  int n = a.size();
  if(n == 1) return;

  vector<cd> a0(n/2), a1(n/2); // change to left and right or E and D
  for(int i=0; 2*i < n; i++) {
    a0[i] = a[2*i];
    a1[i] = a[2*i+1];
  }
  fft(a0);
  fft(a1);

  cd w(1);
  for(int i=0; 2*i < n; i++) {
    w = polar(1.0 , -1*i * 2 * PI / n); // -1 * i (backwards)
    a[i] = a0[i] + w * a1[i];
    a[i + n/2] = a0[i] - w * a1[i];
  }
}

bool cmp(cd a, cd b){
  return (a.real()*a.real() + a.imag()*a.imag()) >
    (b.real()*b.real() + b.imag()*b.imag());
}

void print_result(vector<cd> & a ){
  if(a.size()<=8) for(auto el: a) cout<<el<<endl;
  return;
  sort(a.begin(),a.end(),cmp); 
  vector<pair<int,cd>> indexed(a.size());  
  for(int i=0;i<a.size();i++) indexed[i]={i,a[i]};
  for(auto el: indexed) cout<<el.first<<setw(10)<<el.second<<endl;
}

vector<cd> read_input(){
  int e1; cd e2;
  vector<cd> v;
  while(cin>>e1) v.push_back(e2 = e1 + 0i);
  return v;
}

int main(){
  vector<cd> v = read_input();
  reverse(v.begin(),v.end()); // reads input backwards on the example basically
  fft(v);
  print_result(v);
  return 0;
}






