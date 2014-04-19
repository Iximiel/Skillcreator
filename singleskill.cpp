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
    QFormLayout *grid = new QFormLayout();
    for(int i=0;i<codes.size();i++){
        QLabel *tLab = new QLabel(names[codes[i]]);
        QCheckBox *tCheck =new QCheckBox();
        if (id==i){
            tLab->setEnabled(false);
            tCheck->setEnabled(false);
            setTitle(names[codes[i]]);
        }
        grid->insertRow(i,tLab, tCheck);
        Checks.push_back(tCheck);
    }

    inside->setLayout(grid);
    ui->Scroll->setWidget(inside);

}

SingleSkill::~SingleSkill()
{
    delete ui;
}
