#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget* boardPanel, QWidget* parent = nullptr);

private:
    void setupUI(QWidget* boardPanel);
};

#endif  // MAINWINDOW_HPP
