# Ex.3 Readme File

## Back ground
Question 3 of Homework 1 of VE475 in UMJI-2020Summer. In this question, we are required to design our own extended-euclidean algorithm(`ex_eu`). Then, we should generate two 4096bits number to calculate their greatest common divisor by the `gcd` algorithm and the `ex_eu` algorithm and compare the two results. 



## Usage
Under Linux operation system, with the [GMP](https://gmplib.org/ "https://gmplib.org/") installed. You can simply run this code with the following commands:
`$ g++ hw1.cpp -c hw1 -lgmpxx -lgmp`

*Remark:* `-lgmpxx` and `-lgmp` must be added


## Algorithm implementation
The algorithm is implemented with C++. The return value is a `std::pair`, consist of bezout coefficients and gcd. 
```cpp
std::pair<mpz_class,std::pair<mpz_class, mpz_class> > ex_eu(mpz_class a, mpz_class b){...}
```


## Outputs
The two random numbers generated will be shown in the output, as well as the calculation results. 

Since our goal is to compare the results of these two algorithms, I output the comparison results as follows,

If the results are the same the program output will be:
`The two results are identical!!!Congradulations!!!`

If the results are not the same the program output will be: 
`Oh no!!There must be something wrong with your algorithm!`

## Contributer
Ming Xingyu
