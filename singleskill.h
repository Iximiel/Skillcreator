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
    QString use_Ability();
    QString has_Armor();
    QString needs_trained();
    QVector<int> give_Synergies();
    void set_Ability(int ability);
    void set_Armor(int armorCheck);
    void set_trained(int trainedOnly);
    void set_Synergies(QVector<int> SynIDs);
private:
    Ui::SingleSkill *ui;
    QVector<QCheckBox*> Checks;
    QString identity;//code for the skill
};

#endif // SINGLESKILL_H
