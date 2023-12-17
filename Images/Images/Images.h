#pragma once

#include <QtWidgets/QWidget>
#include "ui_Images.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QImageReader>
#include <QMimeDatabase>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Images : public QWidget
{
    Q_OBJECT

public:
    Images(QWidget *parent = nullptr);
    ~Images();

private:
    QPushButton* button;
    QTableWidget* table;
    QVBoxLayout* layout;
    Ui::ImagesClass ui;
    QList<QPushButton*> sorts;
private slots:
    void onButtonPress();
    void onSortChange(int num);
};
