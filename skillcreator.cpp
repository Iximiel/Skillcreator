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
    connect(ui->ButtSave,SIGNAL(pressed()),this,SLOT(Save_toFile()));
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
                <ability>INT</ability>
                <armor>0</armor><!--moltiplica per-->
                <untrained>1</untrained>
                <synergy>blu<synergy><!--sarebbe from usa codice skill-->
            </skill>
        </skills>
        */
        QXmlStreamWriter xml(&file);
        xml.setAutoFormatting(true);
        xml.setAutoFormattingIndent(2);
        xml.writeStartDocument();
        xml.writeStartElement("skills");

        for (int i = 0; i < skillAddress.size(); ++i) {
            xml.writeStartElement("skill");

            xml.writeTextElement("code",codes[i]);
            xml.writeTextElement("ability",skillAddress[i]->use_Ability());
            xml.writeTextElement("armor",skillAddress[i]->has_Armor());
            xml.writeTextElement("onlytrained",skillAddress[i]->needs_trained());
            QVector<int> synID = skillAddress[i]->give_Synergies();
            for (int j = 0; j < synID.size(); ++j)
                xml.writeTextElement("synergy",codes[synID[j]]);

            xml.writeEndElement();
        }
        xml.writeEndElement();
        xml.writeEndDocument();
    }
}
