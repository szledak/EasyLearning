#ifndef MYWORD_H
#define MYWORD_H


class MyWord
{
public:
    MyWord();
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
