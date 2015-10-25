#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSizePolicy>
#include <QWebFrame>
#include <QWebSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    page(this),
    gl(this)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setViewport(&gl);

 QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    scene.addItem(&webview);

    page.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,
				  true);

    webview.setPage(&page);
    webview.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    webview.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    webview.load(QUrl(ui->lineEdit->text()));

    connect(webview.page()->mainFrame(), &QWebFrame::urlChanged,
	    this, &MainWindow::url_changed);
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

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   // Your code here.
   qDebug() << "S:" << size() << "VS:" << ui->graphicsView->size();
   webview.resize(ui->graphicsView->size());
}
