#include <bits/stdc++.h>
using namespace std;
using namespace complex_literals;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a) {
  int n = a.size();
  if(n == 1) return;
  vector<cd> E(n/2), D(n/2); 
  for(int i=0; 2*i < n; i++) {
    E[i] = a[2*i];
    D[i] = a[2*i+1];
  }
  fft(E);
  fft(D);
  cd w(1);
  for(int i=0; 2*i < n; i++) {
    w = polar(1.0 , -1*i * 2 * PI / n); 
    a[i] = E[i] + w * D[i];
    a[i + n/2] = E[i] - w * D[i];
  }
}

bool cmp(pair<int,cd> a, pair<int,cd> b){
  return (a.second.real()*a.second.real() + a.second.imag()*a.second.imag()) >
    (b.second.real()*b.second.real() + b.second.imag()*b.second.imag());
}

void print_result(vector<cd> & a ){
  cout<<setprecision(2)<<fixed;
  if(a.size()<=8) for(auto el: a) cout<<el<<endl;
  else {
    vector<pair<int,cd>> indexed(a.size());  
    for(int i=0;i<a.size();i++) indexed[i]={i,a[i]};
    sort(indexed.begin(),indexed.end(),cmp); 
    for(int i=0;i<7;i++) cout<<setw(10)<<left<<indexed[i].first<<indexed[i].second<<endl;
  }
}

vector<cd> read_input(){
  int e1; cd e2;
  vector<cd> v;
  while(cin>>e1) v.push_back(e2 = e1 + 0i);
  reverse(v.begin(),v.end()); // reverse the input
  while(__builtin_popcount(v.size())>1) v.push_back(0);
  return v;
}

int main(){
  vector<cd> v = read_input();
  fft(v);
  print_result(v);
  return 0;
}


