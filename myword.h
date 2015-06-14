#ifndef MYWORD_H
#define MYWORD_H
#include <QString>

class MyWord
{
public:
    MyWord(QString, QString);
    ~MyWord();
    void setSiteA(const QString) const;
    void setSiteB(QString) const;
    QString getSiteA() const;
    QString getSiteB() const;


private:
    QString siteA;
    QString siteB;
};

#endif // MYWORD_H
