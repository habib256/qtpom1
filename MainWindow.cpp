#include <QApplication>
#include <QWidget>
#include <QLabel>

#include "MainWindow.h"
#include "Screen.h"

MainWindow::MainWindow()
{
    setFixedSize(600, 400);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    menuBar()->setNativeMenuBar(false); // Put MenuBar in the MainWindow
    Screen *screen = new Screen;
    setCentralWidget(screen);

   setWindowIcon(QIcon(":/images/pom1.png"));

}

void MainWindow::createActions()
{
    loadMemoryAction = new QAction(tr("&Load Memory"),this);
    loadMemoryAction->setIcon(QIcon(":/images/loadMemory.png"));
    connect(loadMemoryAction, SIGNAL(triggered()), this, SLOT(loadMemory()));
    saveMemoryAction = new QAction(tr("&Save Memory"),this);
    saveMemoryAction->setIcon(QIcon(":/images/saveMemory.png"));
    connect(saveMemoryAction, SIGNAL(triggered()), this, SLOT(saveMemory()));
    pasteCodeAction = new QAction(tr("&Paste Code"),this);
    pasteCodeAction->setIcon(QIcon(":/images/pasteCode.png"));
    connect(pasteCodeAction, SIGNAL(triggered()), this, SLOT(pasteCode()));
    quitAction = new QAction(tr("&Quit"),this);
    quitAction->setIcon(QIcon(":/images/quit.png"));
    //quitAction->setIcon(QIcon(":/images/quit.png"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));

    resetAction = new QAction(tr("&Reset"),this);
    resetAction->setIcon(QIcon(":/images/reset.png"));
    connect(resetAction, SIGNAL(triggered()), this, SLOT(reset()));
    hardResetAction = new QAction(tr("&Hard Reset"),this);
    hardResetAction->setIcon(QIcon(":/images/hardreset.png"));
    connect(hardResetAction, SIGNAL(triggered()), this, SLOT(hardReset()));

    configScreenAction = new QAction(tr("&Screen"),this);
    configScreenAction->setIcon(QIcon(":/images/screen.png"));
    connect(configScreenAction, SIGNAL(triggered()), this, SLOT(configScreen()));
    configMemoryAction = new QAction(tr("&Memory"),this);
    configMemoryAction->setIcon(QIcon(":/images/memory.png"));
    connect(configMemoryAction, SIGNAL(triggered()), this, SLOT(configMemory()));

    aboutAction = new QAction(tr("&About"),this);
    aboutAction->setIcon(QIcon(":/images/about.png"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setIcon(QIcon(":/images/aboutQt.png"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadMemoryAction);
    fileMenu->addAction(saveMemoryAction);
    fileMenu->addSeparator();
    fileMenu->addAction(pasteCodeAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    cpuMenu = menuBar()->addMenu(tr("&Cpu"));
    cpuMenu->addAction(resetAction);
    cpuMenu->addAction(hardResetAction);

    configurationMenu = menuBar()->addMenu(tr("&Configuration"));
    configurationMenu->addAction(configScreenAction);
    configurationMenu->addAction(configMemoryAction);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createToolBars()
{
fileToolBar = addToolBar(tr("&File"));
fileToolBar->addAction(loadMemoryAction);
fileToolBar->addAction(saveMemoryAction);
fileToolBar->addAction(pasteCodeAction);
cpuToolBar = addToolBar(tr("&Cpu"));
cpuToolBar->addAction(resetAction);
cpuToolBar->addAction(hardResetAction);
configurationToolBar = addToolBar(tr("&Configuration"));
configurationToolBar->addAction(configScreenAction);
configurationToolBar->addAction(configMemoryAction);
helpToolBar = addToolBar(tr("&Help"));
helpToolBar->addAction(aboutAction);
}

void MainWindow::createStatusBar()
{

}

void MainWindow::loadMemory()
{
}
void MainWindow::saveMemory()
{
}
void MainWindow::pasteCode()
{
}
void MainWindow::quit()
{
}
void MainWindow::reset()
{
}
void MainWindow::hardReset()
{
}
void MainWindow::configScreen()
{
}
void MainWindow::configMemory()
{
}
void MainWindow::about()
{
    QMessageBox::about(this, tr("About qtpom1"), tr("<h2>QtPom1 1.0 - Apple I Emulator</h2>"
                                                    "Copyright &copy; 2000-2014 GPL3."
                                                    "<ul><li>Written by <a style='color:#FF0000'>Arnaud VERHILLE</a> (2000-2014)<br>E.mail : <a href='mailto:gist974@gmail.com'>gist974@gmail.com</a><br> Web : <a href='http://gistlabs.net/Apple1project/'>Apple1 Project : Pom1</a></li>"
                                                    "<li>Enhanced by <a style='color:#FF0000'>Ken WESSEN</a> (21/2/2006)<br>Web : <a href='http://school.anhb.uwa.edu.au/personalpages/kwessen/apple1/Krusader.htm'>KRUSADER Symbolic Assembly on Replica 1</a></li>"
                                                    "<li>Ported to C/SDL by <a style='color:#FF0000'>John D. CORRADO</a> (2006-2014)<br>E.mail : <a href='mailto:jdcorrado@gmail.com'>jdcorrado@gmail.com</a><br> Web : <a href='http://pom1.sourceforge.net/'>Pom 1 C/SDL & Android</a></li></ul"
                                                    "<p>Thanks to :"
                                                    "<ul><li><a style='color:#FF0000'>Steve WOZNIAK(The Brain) & Steve JOBS</a></li>"
                                                    "<li>Fabrice FRANCES (Java Microtan Emulator)</li>"
                                                    "<li>Achim BREIDENBACH from Boinx Software <br>(Sim6502, Online 'Apple-1 Operation Manual')</li>"
                                                    "<li>Juergen BUCHMUELLER (MAME & MESS 6502)</li>"
                                                    "<li>Stephano PRIORE from the MESS DEV</li>"
                                                    "<li>Joe TORZEWSKI(Apple I owners Club)</li>"
                                                    "<li>Tom OWAD (<a href='http://applefritter.com/apple1/'>http://applefritter.com/apple1/</a>)</li></ul>"));
}

