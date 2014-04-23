#include "singleskill.h"
#include <QFormLayout>
//#include "ui_singleskill.h"

//#include <QDebug>

SingleSkill::SingleSkill(int id, QStringList codes, QMap<QString, QString>names, QWidget *parent) :
    QGroupBox(parent)
{
    identity = codes[id];
    setMinimumSize(100,250);

    QFormLayout *form = new QFormLayout(this);
    LabelABL = new QLabel("Ability");
    comboAbility = new QComboBox();
    comboAbility->setToolTip(tr("Chose the Ability to use with this skill"));
    form->addRow(LabelABL,comboAbility);
    comboAbility->addItem("Strength");
    comboAbility->addItem("Dexterity");
    comboAbility->addItem("Constitution");
    comboAbility->addItem("Intelligence");
    comboAbility->addItem("Wisdom");
    comboAbility->addItem("Charisma");


    CheckArmor = new QCheckBox("Armor Penality?");
    CheckArmor->setToolTip(tr("1 click armor penality, 2 clicks for double armor penality"));
    form->addRow("",CheckArmor);
    CheckArmor->setTristate(true);

    CheckTrain = new QCheckBox("Trained only?");
    CheckTrain->setToolTip(tr("Check if this skill could not be used if untrained"));
    form->addRow("",CheckTrain);
    LabelSyn = new QLabel("Synergies From:");
    Scroll = new QScrollArea();
    Scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    form->addRow(LabelSyn,Scroll);

    QWidget *inside = new QWidget (Scroll);
    QVBoxLayout *grid = new QVBoxLayout();
    for(int i=0;i<codes.size();i++){
        QCheckBox *tCheck =new QCheckBox();
        tCheck ->setText(names[codes[i]]);
        tCheck ->setTristate(true);//partially = circumstantial, check = always
        tCheck->setToolTip(tr("single click for circumstantial synergy, 2 clicks for normal synergy"));
        if (id==i){
            tCheck->setEnabled(false);
            setTitle(names[codes[i]]);
        }
        grid->insertWidget(i,tCheck);
        Checks.push_back(tCheck);
    }

    inside->setLayout(grid);
    Scroll->setWidget(inside);

}

SingleSkill::~SingleSkill()
{

}

QString SingleSkill::use_Ability(){
    QString toreturn;
    toreturn.setNum(comboAbility->currentIndex());
    return toreturn;
}

QString SingleSkill::has_Armor(){
    QString toreturn;
    toreturn.setNum( CheckArmor->checkState());
    return toreturn;
}

QString SingleSkill::needs_trained(){
    QString toreturn;
    toreturn.setNum(CheckTrain->isChecked());
    return toreturn;
}

QVector<int> SingleSkill::give_Synergies()
{
    QVector<int> toreturn;

    for (int i = 0; i < Checks.size(); ++i) {
        if(Checks[i]->checkState()==2)
            toreturn.push_back(i);
    }
    return toreturn;
}

QVector<int> SingleSkill::give_CyrcSynergies()
{
    QVector<int> toreturn;

    for (int i = 0; i < Checks.size(); ++i) {
        if(Checks[i]->checkState() == 1)
            toreturn.push_back(i);
    }
    return toreturn;
}

void SingleSkill::set_Ability(int ability){comboAbility->setCurrentIndex(ability);}
void SingleSkill::set_Armor(int armorCheck){
    switch (armorCheck) {
    case 1:
        CheckArmor->setCheckState(Qt::PartiallyChecked);
        break;
    case 2:
        CheckArmor->setCheckState(Qt::Checked);
        break;
    }
}
void SingleSkill::set_trained(int trainedOnly){CheckTrain->setChecked(trainedOnly);}
void SingleSkill::set_Synergies(int SynID){Checks[SynID]->setChecked(true);}
void SingleSkill::set_CyrcSynergies(int SynID){Checks[SynID]->setCheckState(Qt::PartiallyChecked);}
