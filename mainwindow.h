#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QGraphicsScene>
#include <QGraphicsWebView>

#include "webpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void resizeEvent(QResizeEvent * event) override;

public slots:
   void file_quit();

   void btn_go();
   void btn_back();

   void url_changed(const QUrl& url);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsWebView webview;
    WebPage page;
    QOpenGLWidget gl;

};

#endif // MAINWINDOW_H
