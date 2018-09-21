#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scribblearea.h"

MainWindow::MainWindow() : QMainWindow(), pArea(new ScribbleArea(this))
{
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    /*tworzenie menu itd.*/
    this->createActions();
    this->createMenus();
    this->createStatusBar();

    this->readSettings();
    this->setCurrentFile("");
    //connect(this, SIGNAL(paintArea), pArea, SLOT(paint()));
    //this->setStyleSheet("background-color: yellow;");

    layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetNoConstraint);
    layout->addWidget(pArea, 0, 0);
    //this->setLayout(layout);

    setCentralWidget(pArea);
}

MainWindow::~MainWindow()
{
/*
    delete fileMenu;
    delete editMenu;
    delete helpMenu;

    delete newAct;
    delete openAct;
    delete saveAct;
    delete exitAct;
    delete aboutAct;*/
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    this->writeSettings();
    event->accept();
}

/*private----------------------------------START*/
void MainWindow::createActions()
{
    /*akcja New z menu*/
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new gesture"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    /*akcja Open z menu*/
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing neural network"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    /*akcja Save z menu*/
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save neural network changes to the disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    /*akcja Exit z menu*/
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    /*akcja About z menu*/
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Network"));

    /*dodawanie do menu wszystkich akcji*/
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();//separator
    fileMenu->addAction(exitAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}


void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
    QSettings settings("Bartłomiej Rosa", "Mouse gestures recognition: PROEmgr");
    //this->resize(400, 400);
    this->move(200, 200);
    this->setMaximumSize(400, 400);
    this->setMinimumSize(400, 400);
}

void MainWindow::writeSettings()
{
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    setCurrentFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("What to do"),
                             tr("Not specified file%1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}


void MainWindow::setCurrentFile(const QString &fileName)
{
    currentFile = fileName;
    setWindowModified(false);

    QString shownName = currentFile;
    if(currentFile.isEmpty()) shownName = "NN.txt";
    setWindowFilePath(shownName);
}

/*----------------------------------END private*/
/*private slots----------------------------------START*/

void MainWindow::newFile()
{
        setCurrentFile("NN.txt");
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) loadFile(fileName);
}

bool MainWindow::save()
{
    return saveFile(currentFile);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>PROEmgr</b> was written by Bartłomiej Rosa as a project of PROE class."));
}


void MainWindow::paintArea()
{

}











