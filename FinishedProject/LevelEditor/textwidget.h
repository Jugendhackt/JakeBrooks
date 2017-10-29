#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QtWidgets>
#include <QColorDialog>

class TextWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TextWidget(QWidget *parent = 0);
    QLineEdit *input;
    QFontComboBox *fontComboBox;
    QPushButton *chooseColorButton, *removeButton;
    QDoubleSpinBox *textSizeSpinBox, *timeSpinBox;
    QSpinBox *alphaSpinBox;
    QColor textColor;
    QHBoxLayout *layout;

signals:

public slots:
    void chooseColor();
};

#endif // TEXTWIDGET_H
