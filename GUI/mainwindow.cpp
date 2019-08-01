#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QVBoxLayout * leftText = new QVBoxLayout(this);
    QVBoxLayout * rightText = new QVBoxLayout(this);
    QHBoxLayout * upperPart = new QHBoxLayout(this);
    QVBoxLayout * centralLayout = new QVBoxLayout(this);
    QWidget * centralWidget = new QWidget(this);
    leftTextForm = new QLabel(this);
    rightTextForm = new QLabel(this);
    bottomTextForm = new QLabel(this);
    topTextForm = new QLabel(this);
    map = new BattleMap(8,8, this);

    connect(map, SIGNAL(leftTeamInfo(QString)), this, SLOT(updLeftText(QString)));
    connect(map, SIGNAL(rightTeamInfo(QString)), this, SLOT(updRightText(QString)));
    connect(map, SIGNAL(turnInfo(QString)), this, SLOT(updTopText(QString)));

    QLabel * leftTitle = new QLabel("first  Team Unit          ", this);
    QLabel * rightTitle = new QLabel("second Team Unit         ", this);

    leftTitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    rightTitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    leftTextForm->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    rightTextForm->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    topTextForm->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    topTextForm->setAlignment(Qt::AlignHCenter);
    bottomTextForm->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    bottomTextForm->setAlignment(Qt::AlignHCenter);
    bottomTextForm->setText("Hello");

    leftText->addWidget(leftTitle);
    leftText->addWidget(leftTextForm);
    rightText->addWidget(rightTitle);
    rightText->addWidget(rightTextForm);
    
    upperPart->addLayout(leftText);
    upperPart->addWidget(map);
    upperPart->addLayout(rightText);

    centralLayout->addWidget(topTextForm);
    centralLayout->addLayout(upperPart);
    centralLayout->addWidget(bottomTextForm);

   
    centralWidget->setLayout(centralLayout);
    this->setCentralWidget(centralWidget);
    this->setWindowTitle("ARMY v0.1");
    this->resize(1000, 700);
}

MainWindow::~MainWindow() {

}

void MainWindow::updLeftText(QString msg) {
    leftTextForm->setText(msg);
}

void MainWindow::updRightText(QString msg) {
    rightTextForm->setText(msg);
}

void MainWindow::updTopText(QString msg) {
    topTextForm->setText(msg);
}
