#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWebPage>

class WebPage : public QWebPage
{
public:
  WebPage(QObject * parent);

 protected:
  void javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID) override;

signals:

public slots:
};

#endif // WEBPAGE_H
