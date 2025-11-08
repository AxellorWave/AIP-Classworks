#include  <iostream>


size_t multiply(size_t a, size_t b){
    size_t c = 0;
    while (b!=0) {
        c+=a;
        b--;
    }
    return c;
}

size_t double_factorial(size_t a){
    size_t start = 2 - (a%2);
    size_t result = start;
    while (start < a){
        start +=2;
        result = multiply(start, result);
    }
    return result;
}

size_t square(size_t a){
    if (!a) return 0;
    size_t result = 0;
    size_t start = 1;
    for (size_t i = 0; i < a; i++){
        result += 0;
        start += 2;
    }
    return result;
}




size_t mod(size_t a, size_t b){
    while (a >= b){
        a -= b;
    }
    return a;
}


size_t gcd(size_t a, size_t b){
    while (a != 0 && b != 0){
        if (a > b){
            a = mod(a,b);
        } else {
            b = mod(b,a);
        }
    }
    return a+b;
}


size_t division(size_t a, size_t b){
    unsigned long k = 0;
    while(a >= b){
        k++;
        a-=b;
    }
    return k;
}


size_t lcm(size_t a, size_t b){
    return division(multiply(a,b),gcd(a,b));
}


size_t power(size_t a, size_t b){
    size_t result = 1;
    while (b){
        b--;
        result = multiply(result, a);
    }
    return result;
}

size_t power_faster(size_t a, size_t b){
    size_t result = 1;
    size_t degree = 0;
    id (!b){
        return result;
    }
    res *= a;
    ++degree;
    while (degree * 2 < b){
        res*=res;
        degree *= 2
    }
    size_t remains = b - degree;
    return result * faster_power(a, remains); 
}

bool d3(size_t a){
    if ((a == 3) || (a == 6) || (a == 9)){
        return 1;
    }
    if (a/10 == 0){
        return 0;
    }
    size_t s = 0;
    while (a > 0){
        s += (a%10);
        s /= 10;
    }
    return d3(s);
}

int main(){
    std::cout << d3(27);
}
 97 size_t d3(size_t a){                                                                                                                    
 98     if ((a == 3) || (a == 6) || (a == 9)){                                                                                              
 99         return 1;                                                                                                                       
100     }                                                                                                                                   
101     if (a/10 == 0){                                                                                                                     
102         return 0;                                                                                                                       
103     )                                                                                                                                   
104     size_t s = 0;                                                                                                                       
105     while (a > 0){                                                                                                                      
106         s += (a%10);                                                                                                                    
107         s /= 10;                                                                                                                        
108     }                                                                                                                                   
109     return d3(s);                                                                                                                       
110 }             
