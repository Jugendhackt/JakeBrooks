#include "textwidget.h"

TextWidget::TextWidget(QWidget *parent) : QWidget(parent)
{
    input = new QLineEdit(this);
    fontComboBox = new QFontComboBox(this);
    QFont font = fontComboBox->font();
    font.setFamily("times New Roman");
    fontComboBox->setCurrentFont(font);
    chooseColorButton = new QPushButton(this);
    removeButton = new QPushButton(this);
    textSizeSpinBox = new QDoubleSpinBox(this);
    textSizeSpinBox->setValue(30);
    timeSpinBox = new QDoubleSpinBox(this);
    layout = new QHBoxLayout(this);
    alphaSpinBox = new QSpinBox(this);
    alphaSpinBox->setValue(75);
    alphaSpinBox->setMaximum(100);
    input->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout->addWidget(input);
    layout->addWidget(fontComboBox);
    layout->addWidget(textSizeSpinBox);
    layout->addWidget(chooseColorButton);
    layout->addWidget(alphaSpinBox);
    layout->addWidget(timeSpinBox);
    layout->addWidget(removeButton);

    removeButton->setText("Löschen");
    chooseColorButton->setText("Farbauswahl");
    connect(chooseColorButton, SIGNAL(clicked(bool)), this, SLOT(chooseColor()));
}

void TextWidget::chooseColor()
{
    QColorDialog a;
    textColor = a.getColor();
}
