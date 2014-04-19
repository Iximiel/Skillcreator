#ifndef SINGLESKILL_H
#define SINGLESKILL_H
#include <QVector>
#include <QMap>
#include <QCheckBox>
#include <QGroupBox>
#include <QString>

namespace Ui {
class SingleSkill;
}

class SingleSkill : public QGroupBox
{
    Q_OBJECT

public:
    explicit SingleSkill(int id, QVector<QString> codes,QMap<QString, QString>names, QWidget *parent = 0);
    ~SingleSkill();

private:
    Ui::SingleSkill *ui;
    QVector<QCheckBox*> Checks;
    QString identity;//code for the skill
};

#endif // SINGLESKILL_H
