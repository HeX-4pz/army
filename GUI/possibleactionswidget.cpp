#include "possibleactionswidget.h"


PossibleActionsWidget::PossibleActionsWidget(QVector<QString> actions, QVector<int> visible, QPoint point, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * lay = new QVBoxLayout;
    int amount = actions.size();
    buttons.resize(amount);
    
    for (int i = 0; i < amount; ++i ) {
        buttons[i] = new QPushButton(actions[i]);
        lay->addWidget(buttons[i]);
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(buttonWasClicked()));
        if (!visible[i]) {
            buttons[i]->setEnabled(false);
        }
    }
    
    this->setLayout(lay);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    
    this->setGeometry(point.x(), point.y(), 10, 10);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    
    
}

PossibleActionsWidget::~PossibleActionsWidget()
{
    for (int i = 0; i < buttons.size(); ++i) {
        delete buttons[i];
    }
}

void PossibleActionsWidget::buttonWasClicked() {
    emit choiceIsMade(dynamic_cast<QPushButton *> (sender())->text());
}

