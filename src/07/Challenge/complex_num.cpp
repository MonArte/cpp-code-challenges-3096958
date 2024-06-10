#include "complex_num.h"

complex_num::complex_num(double r, double i){
    this->r = r;
    this->i = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    
    z.r = this->r + w.r;
    z.i = this->i + w.i;

    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    
    z.r = this->r - w.r;
    z.i = this->i - w.i;

    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    
    z.r = (this->r * w.r) - (this->i * w.i);
    z.i = (this->r * w.i) + (this->i * w.r);

    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    
    z.r = ((this->r * w.r) + (this->i * w.i)) / ((w.r * w.r)+(w.i * w.i));
    z.i = ((this->i * w.r) - (this->r * w.i)) / ((w.r * w.r)+(w.i * w.i));

    return z;
}

void complex_num::print(std::ostream &os){
    if(this->i >= 0.0)
        os << this->r << " + " << this->i << "i";
    else
        os << this->r << " - " << this->i * -1 << "i";
    os << std::flush;
}