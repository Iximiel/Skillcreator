#include "singleskill.h"
#include "ui_singleskill.h"

#include <QDebug>

SingleSkill::SingleSkill(int id, QVector<QString> codes,QMap<QString, QString>names, QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::SingleSkill)
{
    identity = codes[id];
    ui->setupUi(this);

    QWidget *inside = new QWidget (ui->Scroll);
    QVBoxLayout *grid = new QVBoxLayout();
    for(int i=0;i<codes.size();i++){
        QCheckBox *tCheck =new QCheckBox();
        tCheck ->setText(names[codes[i]]);
        if (id==i){
            tCheck->setEnabled(false);
            setTitle(names[codes[i]]);
        }
        grid->insertWidget(i,tCheck);
        Checks.push_back(tCheck);
    }

    inside->setLayout(grid);
    ui->Scroll->setWidget(inside);

}

SingleSkill::~SingleSkill()
{
    delete ui;
}

QString SingleSkill::use_Ability(){
    QString toreturn;
    toreturn.number(ui->comboAbility->currentIndex());
    return toreturn;
}

QString SingleSkill::has_Armor(){
    QString toreturn;
    toreturn.number( ui->CheckArmor->checkState());
    return toreturn;
}

QString SingleSkill::needs_trained(){
    QString toreturn;
    toreturn.number(ui->CheckTrain->isChecked());
    return toreturn;
}

QVector<int> SingleSkill::give_Synergies()
{
    QVector<int> toreturn;

    for (int i = 0; i < Checks.size(); ++i) {
        if(Checks[i]->isChecked())
            toreturn.push_back(i);
    }
    return toreturn;
}
