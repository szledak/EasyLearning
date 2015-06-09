#ifndef MYWORD_H
#define MYWORD_H
#include <QString>

class MyWord
{
public:
    MyWord(QString, QString);
    ~MyWord();
    void setSiteA(QString);
    void setSiteB(QString);
    QString getSiteA();
    QString getSiteB();


private:
    QString siteA;
    QString siteB;
};

#endif // MYWORD_H
