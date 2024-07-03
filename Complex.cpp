/** noam sayada
 *  noamsayada1@gmail.com
 */
#include "Complex.hpp"
using namespace std;

//constractor
Complex::Complex(double re , double im )
{
    real_ = re;
    image_ = im;
}
 //get real of the complex
double Complex::get_real() const
{
    return real_;
}
//get image of the complex
double Complex::get_image() const
{
    return image_;
}
//operator >
bool Complex::operator>(const Complex &other) const
{
    return (real_ > other.get_real()) || (real_ == other.get_real() && image_ > other.get_image());
}
