#include<gmpxx.h>
#include<iostream>
#include <utility>
std::pair<mpz_class,std::pair<mpz_class, mpz_class> > ex_eu(mpz_class a, mpz_class b){
	std::pair<mpz_class, mpz_class> r(a, b), s(1, 0), t(0, 1);
	while (r.second!=0)
	{
		mpz_class q = r.first / r.second;
		mpz_class rs = r.first - q * r.second;
		mpz_class ss = s.first - q * s.second;
		mpz_class ts = t.first - q * t.second;
		r = std::make_pair(r.second, rs);
		s = std::make_pair(s.second, ss);
		t = std::make_pair(t.second, ts);
	}
	return std::make_pair(r.first, std::make_pair(s.first, t.first));
}
int main(){
	mpz_class a, b;
	gmp_randclass rr(gmp_randinit_default);
	rr.seed(time(NULL));
	a = rr.get_z_bits(4096);
	b = rr.get_z_bits(4096);
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
	mpz_class r1 = ex_eu(a, b).first, r2 = gcd(a, b);
	std::cout << "gcd(a,b) calculated by extended eucuilidean algorithm: " << r1 << std::endl;
	std::cout << "gcd(a,b) calculated by the build in gcd function: " << r2 << std::endl;
	if (r1 == r2)std::cout << "The two results are identical!!!Congradulations!!!" << std::endl;
	else std::cout << "Oh no!!There must be something wrong with your algorithm!" << std::endl;
	return 0;
}
