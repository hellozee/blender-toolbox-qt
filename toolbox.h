#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QTimer>
#include <QMenu>
#include <QAction>

#include "tool.h"

class ToolBox : public QWidget
{
    Q_OBJECT

private:
    enum ToolBoxOrientation{
        Vertical, Horizontal
    };

    enum SubToolsOrientation{
        Right, Left
    };

    enum RowMode{
        Single, Double
    };

    enum ToolBoxState{
        Locked, Unlocked
    };

public:
    explicit ToolBox(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void addTool(Tool t);
    void addBreak();

public Q_SLOTS:
    void longPressEvent();
    void showContextMenu(QPoint pos);
    void slotUnlockToolBox();
    void slotRotateToolBox();
    void slotChangeRowMode();
    void slotFlipToolBox();

private:
    int m_activated, m_padding, m_subToolActivated;
    QSize m_buttonSize;
    QVector<QRect> m_toolRects, m_secondaryTools;
    QVector<Tool> m_tools;
    QVector<int> m_breaks;
    QTimer m_timer;
    bool m_longPressed, m_toolBoxHandlePressed;
    QPoint m_lastMousePos;
    QMenu *m_contextMenu;
    QAction *m_rotateAction, *m_unlockAction, *m_rowModeAction, *m_flipAction;
    ToolBoxOrientation m_toolBoxOrientation;
    SubToolsOrientation m_subToolsOrientation;
    RowMode m_rowMode;
    ToolBoxState m_toolBoxState;
};

#endif // TOOLBOX_H
