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

MyWord::getSiteA(){
    return siteA;
}

MyWord::getSiteB(){
    return siteB;
}

MyWord::setSiteA(QString a){
    siteA = a;
}

MyWord::setSiteB(QString b){
    siteB = b;
}
