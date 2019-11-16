#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "toolbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Tool cropTool("crop", QIcon (":/light_tool_crop.svg"));
    Tool transformTool("transform", QIcon (":/light_krita_tool_transform.svg"));
    Tool rectangularMarqueeTool("rectangular marquee", QIcon (":/light_tool_rect_selection.svg"));
    Tool lassoTool("lasso", QIcon(":/light_tool_outline_selection.svg"));
    Tool rectangleTool("rectangle", QIcon(":/light_krita_tool_rectangle.svg"));
    Tool textTool("text", QIcon(":/light_draw-text.svg"));
    Tool editShapesTool("edit shapes", QIcon(":/light_shape_handling.svg"));

    ToolBox *tb = ui->widget;
    tb->addTool(transformTool);
    tb->addBreak();
    tb->addTool(rectangularMarqueeTool);
    tb->addTool(lassoTool);
    tb->addBreak();
    tb->addTool(cropTool);
    tb->addBreak();
    tb->addTool(rectangleTool);
    tb->addTool(textTool);
    tb->addTool(editShapesTool);

}

MainWindow::~MainWindow()
{
    delete ui;
}

