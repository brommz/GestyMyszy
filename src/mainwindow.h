#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "scribblearea.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QWidget;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

    QString strippedName(const QString &fullFileName);
    QString currentFile;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *aboutAct;
    ScribbleArea *pArea;
    QGridLayout *layout;

private slots:
    void newFile();
    void open();
    bool save();
    void about();
    void paintArea();
};

#endif // MAINWINDOW_H
