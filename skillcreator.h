#ifndef SKILLCREATOR_H
#define SKILLCREATOR_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QScrollArea>
#include <QPushButton>
#include "singleskill.h"

namespace Ui {
class Skillcreator;
}

class Skillcreator : public QWidget
{
    Q_OBJECT

public:
    explicit Skillcreator(QWidget *parent = 0);
    ~Skillcreator();

public slots:
    void Save_toFile();

private:
    //Ui::Skillcreator *ui;
    QPushButton *ButtSave;
    QScrollArea *scrollArea;
    QStringList codes;
    QMap<QString,QString> names;
    QVector<SingleSkill*> skillAddress;
};

#endif // SKILLCREATOR_H
