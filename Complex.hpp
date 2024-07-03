/** noam sayada
 *  noamsayada1@gmail.com
 */
#include <iostream>
#include <string>

class Complex
{
    double real_, image_;

public:

//constractor
    Complex(double real, double image);
    //get real of the complex
    double get_real() const;
    //get image of the complex
    double get_image() const;
    
   //operator >
    bool operator>(const Complex &other) const;
    //operator ==
    friend bool operator==(const Complex &a, const Complex &b){
        return (a.get_real() == b.get_real() && a.get_image() == b.get_image());
    }
    //operator <<
    friend std::ostream &operator<<(std::ostream &os, const Complex &c){
        os << c.get_real() << " + " << c.get_image() << "i";
        return os;
    }


};
