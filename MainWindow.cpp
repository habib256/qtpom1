// Pom1 Apple 1 Emulator
// Copyright (C) 2012 John D. Corrado
// Copyright (C) 2000-2014 Verhille Arnaud
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.


#include <iostream>

#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDockWidget>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>

#include "MainWindow.h"
#include "MemoryViewer.h"
#include "Memory.h"


MainWindow::MainWindow()
{
    setFixedSize(800, 600);

    createActions();
    createMenus();
    createToolBars();
    createDocks();
    createStatusBar();

    createPom1();

    setCentralWidget(screen);
    setWindowIcon(QIcon(":/images/pom1.png"));
}

MainWindow::~MainWindow()
{
    destroyPom1();
}

void MainWindow::createPom1()
{
    cout << "Welcome to qtPom1 - Apple I Emulator" << endl;
    memory = new Memory();
    cpu = new M6502(memory);
    screen = new Screen();

    for (int i = 0; i < 64*1024; i++){
       memoryViewer->populateTable(i,memory->memRead(i));
    }

}

void MainWindow::destroyPom1()
{
    delete memory;
    delete cpu;
    delete screen;
}

void MainWindow::createActions()
{
    loadMemoryAction = new QAction(tr("&Load Memory from disk"),this);
    loadMemoryAction->setIcon(QIcon(":/images/loadMemory.png"));
    connect(loadMemoryAction, SIGNAL(triggered()), this, SLOT(loadMemory()));
    saveMemoryAction = new QAction(tr("&Save Memory to disk"),this);
    saveMemoryAction->setIcon(QIcon(":/images/saveMemory.png"));
    connect(saveMemoryAction, SIGNAL(triggered()), this, SLOT(saveMemory()));
    pasteCodeAction = new QAction(tr("&Paste Code"),this);
    pasteCodeAction->setIcon(QIcon(":/images/pasteCode.png"));
    connect(pasteCodeAction, SIGNAL(triggered()), this, SLOT(pasteCode()));
    quitAction = new QAction(tr("&Quit QtPom1"),this);
    quitAction->setIcon(QIcon(":/images/quit.png"));
    //quitAction->setIcon(QIcon(":/images/quit.png"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));

    resetAction = new QAction(tr("Soft &Reset"),this);
    resetAction->setIcon(QIcon(":/images/reset.png"));
    connect(resetAction, SIGNAL(triggered()), this, SLOT(reset()));
    hardResetAction = new QAction(tr("&Hard Reset"),this);
    hardResetAction->setIcon(QIcon(":/images/hardreset.png"));
    connect(hardResetAction, SIGNAL(triggered()), this, SLOT(hardReset()));
    debugCpuAction = new QAction(tr("&Debug Console"),this);
    debugCpuAction->setIcon(QIcon(":/images/debug.png"));
    connect(debugCpuAction, SIGNAL(triggered()), this, SLOT(debugCpu()));

    configScreenAction = new QAction(tr("&Screen Options"),this);
    configScreenAction->setIcon(QIcon(":/images/screen.png"));
    connect(configScreenAction, SIGNAL(triggered()), this, SLOT(configScreen()));
    configMemoryAction = new QAction(tr("&Memory Options"),this);
    configMemoryAction->setIcon(QIcon(":/images/memory.png"));
    connect(configMemoryAction, SIGNAL(triggered()), this, SLOT(configMemory()));

    aboutAction = new QAction(tr("&About QtPom1"),this);
    aboutAction->setIcon(QIcon(":/images/about.png"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    aboutQtAction = new QAction(tr("About &Qt"),this);
    aboutQtAction->setIcon(QIcon(":/images/aboutQt.png"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    menuBar()->setNativeMenuBar(false); // Put MenuBar in the MainWindow

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
    cpuMenu->addSeparator();
    cpuMenu->addAction(debugCpuAction);

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
    cpuToolBar->addAction(debugCpuAction);
    configurationToolBar = addToolBar(tr("&Configuration"));
    configurationToolBar->addAction(configScreenAction);
    configurationToolBar->addAction(configMemoryAction);
    helpToolBar = addToolBar(tr("&Help"));
    helpToolBar->addAction(aboutAction);
}

void MainWindow::createDocks()
{
    QDockWidget *dock = new QDockWidget(tr("Memory Viewer"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    memoryViewer = new MemoryViewer(dock);
    dock->setWidget(memoryViewer);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    cpuMenu->addAction(dock->toggleViewAction());
}

void MainWindow::createStatusBar()
{

}

void MainWindow::loadMemory()
{
    QString fichier = QFileDialog::getOpenFileName(this, tr("Open Memory File"));
}
void MainWindow::saveMemory()
{
    QString fichier = QFileDialog::getSaveFileName(this, tr("Save Memory as a File"));
}
void MainWindow::pasteCode()
{
}
void MainWindow::quit()
{
    int reponse = QMessageBox::warning(this, tr("Quit"),tr("Do you really want to quit qtPom1 ?"),QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        close();
    }
}
void MainWindow::reset()
{
}
void MainWindow::hardReset()
{
}
void MainWindow::debugCpu()
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
                                                    "<li>Ported to C/SDL by <a style='color:#FF0000'>John D. CORRADO</a> (2006-2014)<br>E.mail : <a href='mailto:jdcorrado@gmail.com'>jdcorrado@gmail.com</a><br> Web : <a href='http://pom1.sourceforge.net/'>Pom 1 for C/SDL & Android</a></li></ul"
                                                    "<p>Thanks to :"
                                                    "<ul><li><a style='color:#FF0000'>Steve WOZNIAK(The Brain) & Steve JOBS</a></li>"
                                                    "<li>Vince BRIEL ( <a href='http://www.brielcomputers.com/wordpress/?cat=17'>Replica 1 at brielcomputers.com</a> & <br><a href='https://cowgod.org/replica1/applesoft/'> Applesoft Lite: Applesoft BASIC for the Replica-1</a>)</li>"
                                                    "<li>Fabrice FRANCES (<a href='http://oric.free.fr/microtan/microtan_java.html'>Java Microtan Emulator</a>)</li>"
                                                    "<li>Achim BREIDENBACH from Boinx Software <br>(Sim6502, Online 'Apple-1 Operation Manual')</li>"
                                                    "<li>Juergen BUCHMUELLER (MAME & MESS 6502)</li>"
                                                    "<li>Stephano PRIORE from the MESS DEV</li>"
                                                    "<li>Joe TORZEWSKI(Apple I owners Club)</li>"
                                                    "<li>Tom OWAD (<a href='http://applefritter.com/apple1/'>http://applefritter.com/apple1/</a>)</li></ul>"));
}

