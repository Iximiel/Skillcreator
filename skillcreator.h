#ifndef SKILLCREATOR_H
#define SKILLCREATOR_H

#include <QWidget>
#include <QVector>
#include <QMap>

namespace Ui {
class Skillcreator;
}

class Skillcreator : public QWidget
{
    Q_OBJECT

public:
    explicit Skillcreator(QWidget *parent = 0);
    ~Skillcreator();

private:
    Ui::Skillcreator *ui;
    QVector<QString> codes;
    QMap<QString,QString> names;
};

#endif // SKILLCREATOR_H
