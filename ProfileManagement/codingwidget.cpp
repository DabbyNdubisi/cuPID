#include "codingwidget.h"
#include "ui_codingwidget.h"

CodingWidget::CodingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodingWidget)
{
    ui->setupUi(this);
    highlighter = new Highlighter(ui->txtEdit->document());
}

CodingWidget::~CodingWidget()
{
    delete highlighter;
    delete ui;
}

int CodingWidget::getCodingQuestionResult(){
    return 0;

}

int CodingWidget::getMultipleChoiceResults(){
    int total = 0;
    if(ui->q1Opt1->isChecked())
        total++;
    if(ui->q2Opt2->isChecked())
        total++;
    if(ui->q3Opt1->isChecked())
        total++;
    if(ui->q4Opt1->isChecked())
        total++;
    if(ui->q5Opt2->isChecked())
        total++;
    return total;

}
