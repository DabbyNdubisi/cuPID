#include "codingwidget.h"
#include "ui_codingwidget.h"

CodingWidget::CodingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodingWidget)
{
    ui->setupUi(this);
    highlighter = new Highlighter(ui->txtEdit->document());
}

void CodingWidget::viewWillAppear()
{
    //Set all buttons and text to default state
    QAbstractButton *button = NULL;
    button = ui->q1ButtonGroup->checkedButton();
    if(button != NULL)
    {
        button->group()->setExclusive(false);
        button->setChecked(false);
        button->group()->setExclusive(true);
    }

    button = NULL;
    button = ui->q2ButtonGroup->checkedButton();
    if(button != NULL)
    {
        button->group()->setExclusive(false);
        button->setChecked(false);
        button->group()->setExclusive(true);
    }

    button = NULL;
    button = ui->q3ButtonGroup->checkedButton();
    if(button != NULL)
    {
        button->group()->setExclusive(false);
        button->setChecked(false);
        button->group()->setExclusive(true);
    }

    button = NULL;
    button = ui->q4ButtonGroup->checkedButton();
    if(button != NULL)
    {
        button->group()->setExclusive(false);
        button->setChecked(false);
        button->group()->setExclusive(true);
    }

    button = NULL;
    button = ui->q5ButtonGroup->checkedButton();
    if(button != NULL)
    {
        button->group()->setExclusive(false);
        button->setChecked(false);
        button->group()->setExclusive(true);
    }

    ui->txtEdit->setPlainText("");
}

CodingWidget::~CodingWidget()
{
    delete highlighter;
    delete ui;
}

bool CodingWidget::checkAllQuestionsAnswered()
{
    return ui->q1ButtonGroup->checkedButton() != NULL && ui->q2ButtonGroup->checkedButton() != NULL && ui->q3ButtonGroup->checkedButton() != NULL
            && ui->q4ButtonGroup->checkedButton() != NULL && ui->q5ButtonGroup->checkedButton() != NULL && ui->txtEdit->toPlainText() != "";
}

QString CodingWidget::getCodeTextFromTextView()
{
    return ui->txtEdit->toPlainText();
}

int CodingWidget::getMultipleChoiceResults(){
    int total = 0;
    if(ui->q1Opt2->isChecked())
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
