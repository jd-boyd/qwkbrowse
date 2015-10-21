#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    page(this)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    scene.addItem(&webview);

    page.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,
				  true);

    webview.setPage(&page);

    webview.load(QUrl(ui->lineEdit->text()));

    connect(webview.page()->mainFrame(), &QWebFrame::urlChanged, this, &MainWindow::url_changed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::file_quit() {
  qDebug() << "file_quit()";
  QApplication::quit();
}

void MainWindow::btn_go() {
  qDebug() << "GOTO:" << ui->lineEdit->text();
  webview.load(QUrl(ui->lineEdit->text()));
}

void MainWindow::btn_back() {
}

void MainWindow::url_changed(const QUrl& url) {
  qDebug() << "URL Changed:" << url;
  ui->lineEdit->setText(url.toDisplayString());
}
