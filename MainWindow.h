#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>

#include "Memory.h"
#include "M6502.h"
#include "Screen.h"
#include "DebugWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();
    ~MainWindow();

private:

    // Pom1 Apple I Hardware
    M6502 *cpu;
    Memory *memory;
    Screen *screen;
    DebugWidget *debugWidget;

    // Pom1 functions
    void createPom1(void);
    void destroyPom1(void);


    // QMenu, QToolBar & QAction
    QMenu *fileMenu;
    QToolBar *fileToolBar;
    QAction *loadMemoryAction;
    QAction *saveMemoryAction;
    QAction *pasteCodeAction;
    QAction *quitAction;

    QMenu *cpuMenu;
    QToolBar *cpuToolBar;
    QAction *resetAction;
    QAction *hardResetAction;
    QAction *debugCpuAction;

    QMenu *configurationMenu;
    QToolBar *configurationToolBar;
    QAction *configScreenAction;
    QAction *configMemoryAction;

    QMenu *helpMenu;
    QToolBar *helpToolBar;
    QAction *aboutAction;
    QAction *aboutQtAction;

    // MainWindow Init
    void createActions(void);
    void createMenus(void);
    void createToolBars(void);
    void createStatusBar(void);

private slots:

    // QAction linked functions
    void loadMemory(void);
    void saveMemory(void);
    void pasteCode(void);
    void quit(void);
    void reset(void);
    void hardReset(void);
    void debugCpu(void);
    void configScreen(void);
    void configMemory(void);
    void about(void);
};

#endif // MAINWINDOW_H
