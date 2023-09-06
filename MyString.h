// TODO: Implement this header file
#include <iostream>
#ifndef MYSTRING_H
#define MYSTRING_H
using namespace std;

class MyString{
    public:
        MyString();

        MyString(const char* Stringy);
        MyString(const MyString& str1);

        size_t size() const noexcept;
        size_t length() const noexcept;

        MyString& operator= (const MyString& str1);
        const char& at (size_t mypos) const;
        const char* data();
        bool empty() const noexcept;
        const char& front() const;

        void clear() noexcept;
        MyString& operator+= (const MyString& str1);
        size_t find (const MyString& str1, size_t mypos = 0) const noexcept;
        ~MyString(); 

    private:

        size_t sizeArray;
        char* MyChar;
};

std::ostream& operator<<(std::ostream& ostr, const MyString& str1);
bool operator== (const MyString& leftside, const MyString& rightside);
MyString operator+ (const MyString& leftside, const MyString& rightside);

#endif