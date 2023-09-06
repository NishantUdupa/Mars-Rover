// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
using namespace std;

MyString::MyString():sizeArray(0), MyChar(new char[0])
{}

MyString::MyString(const char* Stringy):sizeArray(0), MyChar(new char[0])
{
    size_t i = 0;

    while( Stringy[i] != '\0' )
    {
        i++;
    }

    sizeArray = i;

    MyChar = new char[sizeArray];
    for (size_t j = 0; j < sizeArray; j++){
        MyChar[j] = Stringy[j];
    }
}

MyString::MyString(const MyString& str1):sizeArray(0), MyChar(new char[0]){
    MyChar = new char[str1.sizeArray];
    for(size_t i = 0; i < str1.sizeArray; i++)
    {
        MyChar[i] = str1.at(i);
    }
    this->sizeArray = str1.sizeArray;
}

MyString::~MyString(){
    delete[] MyChar;
}

size_t MyString::size() const noexcept
{
    return sizeArray;
}

size_t MyString::length() const noexcept
{
    return sizeArray;
}

MyString& MyString::operator=(const MyString& str1)
{
    MyChar = new char[str1.sizeArray];
    for(size_t i = 0; i < str1.sizeArray; i++)
    {
        MyChar[i] = str1.at(i);
    }
    this->sizeArray=str1.sizeArray;
    return *this;
}

const char* MyString::data(){
    return MyChar;
}
bool MyString::empty() const noexcept{
    return (sizeArray == 0);
}

const char& MyString::at(size_t mypos) const
{
    if(!(mypos < sizeArray))
    {
        throw std::out_of_range("Out Of Range");
    }
    return MyChar[mypos];
}

const char& MyString::front() const
{
    if(sizeArray == 0){
        throw std::out_of_range("Out Of Range");
    }
    return MyChar[0];
}

void MyString::clear() noexcept{
    delete[] MyChar;
    MyChar = new char[0];
    sizeArray = 0;
}

std::ostream& operator<<(std::ostream& ostr, const MyString& str1)
{
    for(size_t i = 0; i < str1.size(); i++)
    {
        ostr << str1.at(i);
    }
    return ostr;
}
bool operator== (const MyString& leftside, const MyString& rightside)
{
    if(rightside.size() != leftside.size())
    {
        return false;
    }
    else{
        for(size_t i = 0; i < leftside.size(); i++)
        {
            if(leftside.at(i) != rightside.at(i))
            {
                return false;
            }
        }
        return true;
    }
}
MyString operator+(const MyString& leftside, const MyString& rightside)
{
    char* MyChar = new char[leftside.size() + rightside.size()];

    for(size_t i = 0; i < (leftside.size() + rightside.size()); i++)
    {
        if(i > leftside.size())
        {
            MyChar[i] = rightside.at(i - leftside.size());
        }
        else{
            MyChar[i] = leftside.at(i);
        }
    }
    MyString Mystr = MyString(MyChar);
    return Mystr;

}

MyString& MyString::operator+= (const MyString& str1)
{
    char* clone = new char[str1.size() + sizeArray];
    for(size_t i = 0; i < str1.size() + sizeArray; i++)
    {
        if(i < sizeArray)
        {
            clone[i] = MyChar[i];
        }
        else{
            clone[i] = str1.at(i - sizeArray);
        }
    }
    MyChar = clone;
    sizeArray = str1.size() + sizeArray;
    return *this;
}

size_t MyString::find(const MyString& str1, size_t mypos) const noexcept{
    size_t trial = 0;
    if(mypos != 0){
        if(sizeArray < str1.size())
        {
            return -1;
        }
        else
        {
            for(size_t i = mypos; i < sizeArray; i++)
            {
                for(size_t j = 0; j < str1.size(); j++)
                {
                    if(i+j < sizeArray)
                    {
                        if(str1.at(j) != MyChar[i + j])
                        {
                            if(trial == str1.size())
                            {
                                if(i > 0)
                                {
                                    return i - 1;
                                }
                                return i;
                            }
                            break;
                        }
                        else if(trial == str1.size()-1 && str1.at(j) == MyChar[i + j] && i+j == sizeArray-1)
                        {
                            return i;
                        }
                        else{
                            trial++;
                        }
                    }
                }
            }
            return -1;
        }
    } 
    else
   {
        if(sizeArray < str1.size())
        {
            return -1;
        }
        else
        {
            for(size_t i = 0; i < sizeArray; i++)
            {
                for(size_t j = 0; j < str1.size(); j++)
                {
                    if(i + j < sizeArray){
                        if(str1.at(j) != MyChar[i + j]){
                            if(trial == str1.size()){
                                if(i > 0){
                                    return i-1;
                                }
                                return i;
                            }
                            break;
                        }
                        else if(trial==str1.size() - 1 && (i+j) == sizeArray -1 && str1.at(j) == MyChar[i + j] )
                        {
                            return i;
                        }
                        else{
                            trial++;
                        }
                    }
                }
            }
            return -1;
        }

    }
}
   