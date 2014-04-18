#include "skillcreator.h"
#include "ui_skillcreator.h"

#include "singleskill.h"

Skillcreator::Skillcreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Skillcreator)
{
    ui->setupUi(this);
    ui->scrollArea->setWidget(new SingleSkill("app"));
}

Skillcreator::~Skillcreator()
{
    delete ui;
}
