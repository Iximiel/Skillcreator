#include "singleskill.h"
#include "ui_singleskill.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>

SingleSkill::SingleSkill(QString id, QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::SingleSkill)
{
    identity = id;
    ui->setupUi(this);
    QFile file("Skills_Eng.txt");
    QWidget *inside = new QWidget (ui->Scroll);
    QFormLayout *grid = new QFormLayout();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"errore";
        //add an alert!
    }
    else{

        QXmlStreamReader xml(&file);

        xml.readNext();
        if(xml.name()!="skills")
            xml.readNext();
        for(int i=0;!xml.atEnd();){
            if(xml.readNext() == 4){
                bool set = (xml.name().toString()==id);
                if(xml.readNext() == 6){
                    QString temp=xml.text().toString();
                    QLabel *tLab = new QLabel(temp);
                    QCheckBox *tCheck =new QCheckBox();
                    if (set){
                        tLab->setEnabled(false);
                        tCheck->setEnabled(false);
                        setTitle(temp);
                    }
                    grid->insertRow(i,tLab, tCheck);
                    Checks.push_back(tCheck);
                    i++;
                }
            }
            if (xml.hasError()) {
                // do error handling
            }
        }
    }
    inside->setLayout(grid);
    ui->Scroll->setWidget(inside);

}

SingleSkill::~SingleSkill()
{
    delete ui;
}
