#include "Images.h"

Images::Images(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("Choose Folder");

    layout = new QVBoxLayout(this);
    QHBoxLayout* layout2 = new QHBoxLayout(this);

    QList<QString> objects = { "File Name", "Image size", "Resolution","Color Depth", "Image Type" };
    for (int i = 0; i < objects.size(); i++)
    {
        sorts.append(new QPushButton("Sort by " + objects[i].toLower(), this));
        connect(sorts[i], &QPushButton::clicked, [this, i]() {onSortChange(i);});
    }

    table = new QTableWidget(1, 5);
    table->setHorizontalHeaderLabels(objects);
    layout->addWidget(button);

    foreach(QPushButton * butt, sorts)
    {
        layout2->addWidget(butt);
    }
    layout->addLayout(layout2);

    layout->addWidget(table);

    connect(button, SIGNAL(clicked()), this, SLOT(onButtonPress()));

    ui.setupUi(this);
}

Images::~Images()
{}

void Images::onSortChange(int num)
{
    table->sortItems(num);
}

void Images::onButtonPress() 
{
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Select folder", QDir::homePath());
    QDir dir(folderPath);
    QStringList filters;
    filters << "*.jpg" << "*.gif" << "*.tif" << "*.bmp" << "*.png" << "*.pcx";
    dir.setNameFilters(filters);

    QFileInfoList fileList = dir.entryInfoList();
    table->deleteLater();
    table = new QTableWidget(fileList.size(), 5);
    table->setHorizontalHeaderLabels({ "File Name", "Image size", "Resolution(DPI)","Color Depth", "Image Type" });
    int i = 0;
    foreach(QFileInfo fileInfo, fileList)
    {

        QImageReader reader(fileInfo.absoluteFilePath());
        QImage image = reader.read();

        table->setItem(i, 0, new QTableWidgetItem(fileInfo.fileName()));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(image.size().width()) + "x" + QString::number(image.size().height())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(image.logicalDpiX()) + "x" + QString::number(image.logicalDpiY())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(image.depth())));
        table->setItem(i, 4, new QTableWidgetItem(QString(QVariant::fromValue(image.format()).toString())));
        i++;
    }

    layout->addWidget(table);
}