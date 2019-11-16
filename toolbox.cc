#include "toolbox.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent), m_activated(-1), m_padding(10), m_buttonSize(40, 40)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void ToolBox::paintEvent(QPaintEvent *event)
{
    QPainter gc(this);
    gc.setRenderHint(QPainter::Antialiasing);

    QPoint topLeft = event->rect().topLeft();
    QColor highlightedBack(86, 128, 194);
    QColor back(49, 49, 49);
    m_toolRects.clear();

    for(int i=0;i<m_tools.count();i++){
        QRect toolRect(topLeft, m_buttonSize);
        QPainterPath path;
        path.addRoundedRect(toolRect, 3, 3);
        if(i == m_activated){
            gc.fillPath(path, highlightedBack);
        }else{
            gc.fillPath(path, back);
        }
        QRect iconRect = toolRect.adjusted(m_padding, m_padding, -m_padding, -m_padding);
        m_tools[i].icon().paint(&gc, iconRect);
        m_toolRects.push_back(toolRect);
        topLeft += QPoint(0, m_buttonSize.height() + 2);
    }

    this->resize(m_buttonSize.width(),
                 (m_buttonSize.height() + 2) * m_tools.count() + 5);
}

void ToolBox::addTool(Tool t)
{
    m_tools.push_back(t);
}

void ToolBox::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    for(int i=0; i<m_tools.count(); i++){
        if(m_toolRects[i].contains(pos)){
            m_activated = i;
            update();
            return;
        }
    }
}
