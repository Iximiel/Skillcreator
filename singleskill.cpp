#include "singleskill.h"
#include <QFormLayout>
//#include "ui_singleskill.h"

//#include <QDebug>

SingleSkill::SingleSkill(int id, QStringList codes, QMap<QString, QString>names, QWidget *parent) :
    QGroupBox(parent)/*,
      ui(new Ui::SingleSkill)*/
{
    identity = codes[id];
    // /*ui->*/setupUi(this);
    QFormLayout *form = new QFormLayout(this);


    LabelABL = new QLabel("Ability");
    comboAbility = new QComboBox();

    form->addRow(LabelABL,comboAbility);
    comboAbility->addItem("Strength");
    comboAbility->addItem("Dexterity");
    comboAbility->addItem("Constitution");
    comboAbility->addItem("Intelligence");
    comboAbility->addItem("Wisdom");
    comboAbility->addItem("Charisma");


    CheckArmor = new QCheckBox("Armor Penality?");

    form->addRow("",CheckArmor);
    CheckArmor->setTristate(true);

    CheckTrain = new QCheckBox("Trained only?");

    form->addRow("",CheckTrain);
    LabelSyn = new QLabel("Synergies From:");
    Scroll = new QScrollArea();
    Scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    form->addRow(LabelSyn,Scroll);

    QWidget *inside = new QWidget (/*ui->*/Scroll);
    QVBoxLayout *grid = new QVBoxLayout();
    for(int i=0;i<codes.size();i++){
        QCheckBox *tCheck =new QCheckBox();
        tCheck ->setText(names[codes[i]]);
        tCheck ->setTristate(true);//partially = circumstantial, check = always
        if (id==i){
            tCheck->setEnabled(false);
            setTitle(names[codes[i]]);
        }
        grid->insertWidget(i,tCheck);
        Checks.push_back(tCheck);
    }

    inside->setLayout(grid);
    /*ui->*/Scroll->setWidget(inside);

}

SingleSkill::~SingleSkill()
{
    //delete ui;
}

QString SingleSkill::use_Ability(){
    QString toreturn;
    toreturn.setNum(/*ui->*/comboAbility->currentIndex());
    return toreturn;
}

QString SingleSkill::has_Armor(){
    QString toreturn;
    toreturn.setNum( /*ui->*/CheckArmor->checkState());
    return toreturn;
}

QString SingleSkill::needs_trained(){
    QString toreturn;
    toreturn.setNum(/*ui->*/CheckTrain->isChecked());
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

void SingleSkill::set_Ability(int ability){/*ui->*/comboAbility->setCurrentIndex(ability);}
void SingleSkill::set_Armor(int armorCheck){
    switch (armorCheck) {
    case 1:
        /*ui->*/CheckArmor->setCheckState(Qt::PartiallyChecked);
        break;
    case 2:
        /*ui->*/CheckArmor->setCheckState(Qt::Checked);
        break;
    }
}
void SingleSkill::set_trained(int trainedOnly){/*ui->*/CheckTrain->setChecked(trainedOnly);}
void SingleSkill::set_Synergies(int SynID){Checks[SynID]->setChecked(true);}
void SingleSkill::set_CyrcSynergies(int SynID){Checks[SynID]->setCheckState(Qt::PartiallyChecked);}
