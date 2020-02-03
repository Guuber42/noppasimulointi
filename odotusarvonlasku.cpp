#include<bits/stdc++.h>
#include<gmp.h>
#include<gmpxx.h>
// qq on tyypiltään murtoluku
typedef mpq_class qq;
// ll on tyypiltään bigint
typedef mpz_class ll;
using namespace std;

// Funktio, joka laskee luvun n potenssiin m arvon
qq exp(qq n, ll m){
    if(m == 0) return ll(1);
    qq puoli = exp(n, m/2);
    if(m % 2 == 1) return n*puoli*puoli;
    else return puoli*puoli;
}

qq infSum(ll j, ll d, qq x){
    return qq(x*(exp(x,j-1)*(j*(1-exp(x,d)) + d*exp(x,d)))) / exp((exp(x,d)-1),2);
}


ll n;
ll m;
// vektori a_k kertoo luvun a_i arvon
vector<ll> a_k;

// map tulokohta kertoo luvun a_k ensimmäisen esiintymiskohdan
map<int, int> tulokohta;

int main(){
    cin >> n >> m;
    a_k.push_back(ll(1));

    int s = 0; // Kertoo milloin sykli alkaa
    int d = 0; // Kertoo syklin pituuden
    tulokohta[1] = 0;
    // Seuraavaksi etsitään arvot luvuille s ja d
    for(int i = 1; i <= 2*m; i++){
        a_k.push_back(n*(a_k[i-1]%m));
        if(tulokohta.count(a_k[(a_k.size()-1)].get_si())){
            s = tulokohta[(a_k[(a_k.size()-1)].get_si())];
            d = i-s;
            break;
        }
        tulokohta[(a_k[(a_k.size()-1)]).get_si()] = i;
    }
    qq su2(0); // Laskettava summa
    // Lasketaan tämä summa
    for(int i = a; i < a_k.size()-1; i++){
        su2 += ((a_k[i]/m)*m)*infSum(i%m, d, qq(1,n));
    }

    for(int i = 1; i < a; i++){
        su2 += qq((a_k[i]/m)*m*i)/exp(qq(n,1),i);
    }
    cout << su2 << "\n";
    cout << su2.get_d() << "\n";
}
