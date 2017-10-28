#include "metadatawidget.h"

MetaDataWidget::MetaDataWidget(QWidget *parent) : QWidget(parent)
{
    backGroundFileEdit = new QLineEdit(this);
    audioFileEdit = new QLineEdit(this);
    background = new QLabel(this);
    timeEdit = new QTimeEdit(this);
    background->setText("Hintergrund");
    audio = new QLabel(this);
    audio->setText("Musik");
    backGroundLayout = new QVBoxLayout();
    backGroundLayout->addWidget(background);
    backGroundLayout->addWidget(backGroundFileEdit);
    audioLayout = new QVBoxLayout();
    audioLayout->addWidget(audio);
    audioLayout->addWidget(audioFileEdit);
    mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(backGroundLayout);
    mainLayout->addLayout(audioLayout);
    mainLayout->addWidget(timeEdit);
}
