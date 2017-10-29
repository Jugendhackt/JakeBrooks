#ifndef METADATAWIDGET_H
#define METADATAWIDGET_H

#include <QtWidgets>

class MetaDataWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MetaDataWidget(QWidget *parent = 0);
    QLabel *background, *audio;
    QVBoxLayout *backGroundLayout, *audioLayout;
    QHBoxLayout *mainLayout;
    QLineEdit *backGroundFileEdit, *audioFileEdit;
    QTimeEdit *timeEdit;

signals:

public slots:
};

#endif // METADATAWIDGET_H
