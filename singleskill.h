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
    int use_Ability();
    int has_Armor();
    int needs_trained();
    QVector<QString> give_Synergies(QVector<QString> codes);
private:
    Ui::SingleSkill *ui;
    QVector<QCheckBox*> Checks;
    QString identity;//code for the skill
};

#endif // SINGLESKILL_H
