#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QTimer>

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

private:
    int m_activated, m_padding, m_subToolActivated;
    QSize m_buttonSize;
    QVector<QRect> m_toolRects, m_secondaryTools;
    QVector<Tool> m_tools;
    QVector<int> m_breaks;
    QTimer m_timer;
    bool m_longPressed;
};

#endif // TOOLBOX_H
