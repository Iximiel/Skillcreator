#include "skillcreator.h"
#include "ui_skillcreator.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
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
    QVBoxLayout *dataholder = new QVBoxLayout();
    int skillnumber = codes.size();
    for (int i = 0; i < skillnumber; ++i) {
        skillAddress.push_back(new SingleSkill(i,codes,names));
        dataholder->addWidget(skillAddress[i]);
    }
    data->setLayout(dataholder);
    ui->scrollArea->setWidget(data);
}

Skillcreator::~Skillcreator()
{
    delete ui;
}

void Skillcreator::Save_toFile(){
    QFile file("Skills_data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"errore salvataggio";
        //add an alert!
    }else{
        /*
        <skills>
            <skill>
                <code>app</code>
                <attribute>INT</attribute>
                <armor>0</armor><!--moltiplica per-->
                <untrained>1</untrained>
                <synergy><synergy><!--sarebbe from usa codice skill-->
            </skill>
        </skills>
        */
        QXmlStreamWriter xml(&file);
        xml.writeStartDocument();
        xml.writeStartElement("skills");
        //xml.writeTextElement("\n");
        for (int i = 0; i < 3/*skillAddress.size()*/; ++i) {
            xml.writeStartElement("skill");
            xml.writeStartElement("code");
        }
    }
}
