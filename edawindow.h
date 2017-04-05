#ifndef EDAWINDOW_H
#define EDAWINDOW_H

#include <QMainWindow>

namespace Ui {
class EDAWindow;
}

class EDAWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit EDAWindow(QWidget *parent = 0);
    ~EDAWindow();

private slots:
    void on_actionSalir_triggered();

    void on_pathButton_clicked();

    void on_addAllButton_clicked();

private:
    Ui::EDAWindow *ui;
};

#endif // EDAWINDOW_H
