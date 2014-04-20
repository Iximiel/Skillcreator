#include "skillcreator.h"
#include "ui_skillcreator.h"

#include "singleskill.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QLayout>

Skillcreator::Skillcreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Skillcreator)
{
    ui->setupUi(this);

    QFile file("Skills_Eng.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"errore";
        //add an alert!
    }
    else{
        QXmlStreamReader xml(&file);
        xml.readNext();
        if(xml.name()!="skills")
            xml.readNext();
        while(!xml.atEnd()){
            if(xml.readNext() == 4){
                QString code = xml.name().toString();
                codes.push_back(code);
                if(xml.readNext() == 6){
                    names.insert(code, xml.text().toString());
                }
            }
            if (xml.hasError()) {
                // do error handling
            }
        }
    }
    QWidget *data = new QWidget ();
    QLayout *dataholder = new QLayout();
    dataholder->setAlignment()

    ui->scrollArea->setWidget(new SingleSkill(1,codes,names));
}

Skillcreator::~Skillcreator()
{
    delete ui;
}
