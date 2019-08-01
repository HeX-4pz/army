#include "widgetmagicbook.h"

WidgetMagicBook::WidgetMagicBook(std::map<std::string, Spell *> book, QPoint pos, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * lay = new QVBoxLayout;

    for ( std::map<std::string, Spell *>::iterator it = book.begin(); it != book.end(); ++it ) {
        QPushButton * newButton = new QPushButton(QString::fromStdString((*it).first));
        buttons.push_back(newButton);
        lay->addWidget(newButton);
        connect(newButton, SIGNAL(clicked()), this, SLOT(buttonWasClicked()));
    }

    this->setLayout(lay);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    this->setGeometry(pos.x(), pos.y(), 10, 10);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

WidgetMagicBook::~WidgetMagicBook()
{
    for (int i = 0; i < buttons.size(); ++i) {
        delete buttons[i];
    }
}

void WidgetMagicBook::buttonWasClicked()
{
    emit choiceNewSpell(dynamic_cast<QPushButton *> (sender())->text().toStdString());
}



