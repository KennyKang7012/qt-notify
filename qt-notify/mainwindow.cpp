#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notifymanager.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton * button = new QPushButton("Pop-up Window", this);
    NotifyManager *manager = new NotifyManager(this);

    connect(button, &QPushButton::clicked, manager, [manager]{
            manager->notify("New Message", "Hello Qt !! Hello Qt !! Hello Qt !!", "://img/message.png", "http://www.github.com");
        });

    /*
        NotifyManager *manager = new NotifyManager(this);
        manager->notify(title, body, icon, url);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

