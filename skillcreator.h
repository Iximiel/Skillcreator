#ifndef SKILLCREATOR_H
#define SKILLCREATOR_H

#include <QWidget>

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
};

#endif // SKILLCREATOR_H
