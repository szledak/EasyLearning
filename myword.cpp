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

QString MyWord::getSiteA(){
    return siteA;
}

QString MyWord::getSiteB(){
    return siteB;
}

void MyWord::setSiteA(QString a){
    siteA = a;
}

void MyWord::setSiteB(QString b){
    siteB = b;
}
