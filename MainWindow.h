#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();

private:

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

    QMenu *configurationMenu;
    QToolBar * configurationToolBar;
    QAction *configScreenAction;
    QAction *configMemoryAction;

    //QMenu *debugMenu;

    QMenu *helpMenu;
    QToolBar *helpToolBar;
    QAction *aboutAction;
    QAction *aboutQtAction;

    void createActions(void);
    void createMenus(void);
    void createToolBars(void);
    void createStatusBar(void);

private slots:

    void loadMemory(void);
    void saveMemory(void);
    void pasteCode(void);
    void quit(void);
    void reset(void);
    void hardReset(void);
    void configScreen(void);
    void configMemory(void);
    void about(void);
};

#endif // MAINWINDOW_H
