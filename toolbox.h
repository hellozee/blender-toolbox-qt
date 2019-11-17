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

private:
    int m_activated, m_padding, m_subToolActivated;
    QSize m_buttonSize;
    QVector<QRect> m_toolRects, m_secondaryTools;
    QVector<Tool> m_tools;
    QVector<int> m_breaks;
    QTimer m_timer;
    bool m_longPressed, m_toolBoxHandlePressed, m_unlocked;
    QPoint m_lastMousePos;
    QMenu *m_contextMenu;
    QAction *m_rotateAction, *m_unlockAction, *m_rowModeAction;
};

#endif // TOOLBOX_H
