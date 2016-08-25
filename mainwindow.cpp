#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <fstream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_invColorbutton_clicked()
{
    for (int c = 0; c < m_image.height(); c++){
        for(int r = 0; r < m_image.width(); r++){
             QRgb color = m_image.pixel(c, r);
             int red = 255 - qRed(color);
             int green = 255 -qGreen(color);
             int blue = 255 - qBlue(color);

             m_image.setPixel(c, r, qRgb( (int) red, (int) green, (int) blue));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(m_image));
    ui->label->show();
}

void MainWindow::on_displayButton_clicked()
{
    QString str1 = ui->lineEdit->text();

    QByteArray ba = str1.toLatin1();
    const char *c_str2 = ba.data();
    if (std::ifstream(c_str2)){
        m_image = QImage(str1);
        ui->label->setPixmap(QPixmap::fromImage(m_image));
        ui->label->show();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("File " + ui->lineEdit->text() + " doesn't exists.");
        msgBox.setStandardButtons(QMessageBox::Save);
        msgBox.setDefaultButton(QMessageBox::Save);
        msgBox.exec();
    }
    ui->lcdNumber->display((ui->lcdNumber->intValue()==9)?0:(ui->lcdNumber->intValue()+1));
}
