#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage m_image;


private slots:

    void on_invColorbutton_clicked();

    void on_displayButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
