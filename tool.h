#ifndef TOOL_H
#define TOOL_H

#include <QString>
#include <QIcon>

class Tool
{
public:
    Tool(QString name, QIcon icon);
    Tool() {}

    QIcon icon();
    QString name();
    void addSubTool(Tool t);
    QVector<Tool> subTools();
    void swap(int index);

private:
    QString m_name;
    QIcon m_icon;
    QVector<Tool> m_subTools;
};

#endif // TOOL_H
