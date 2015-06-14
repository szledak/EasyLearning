#include "myword.h"
#include <QString>

MyWord::MyWord(QString a, QString b)
{
    siteA = a;
    siteB = b;
}

MyWord::~MyWord()
{

}

QString MyWord::getSiteA() const{
    return siteA;
}

QString MyWord::getSiteB() const{
    return siteB;
}

void MyWord::setSiteA(QString a) const{
    siteA == a;
}

void MyWord::setSiteB(QString b) const{
    siteB == b;
}
