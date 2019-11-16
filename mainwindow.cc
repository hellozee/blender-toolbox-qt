#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "toolbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Tool transformTool("Transform", QIcon (":/light_krita_tool_transform.svg"));
    Tool moveTool("Move", QIcon(":/light_krita_tool_move.svg"));
    transformTool.addSubTool(moveTool);

    Tool rectangularMarqueeTool("Rectangular Selection", QIcon (":/light_tool_rect_selection.svg"));
    Tool circularMarqueeTool("Elliptical Selection", QIcon (":/light_tool_elliptical_selection.svg"));
    rectangularMarqueeTool.addSubTool(circularMarqueeTool);

    Tool lassoTool("Freehand Selection", QIcon(":/light_tool_outline_selection.svg"));
    Tool polygonalLasso("Polygonal Selection", QIcon(":/light_tool_polygonal_selection.svg"));
    Tool magneticLasso("Magnetic Selection", QIcon(":/light_tool_magnetic_selection.svg"));
    Tool bezierCurveLasso("Path Selection", QIcon(":/light_tool_path_selection.svg"));
    lassoTool.addSubTool(polygonalLasso);
    lassoTool.addSubTool(magneticLasso);
    lassoTool.addSubTool(bezierCurveLasso);

    Tool similarSelectionTool("Similar Selection", QIcon(":/light_tool_similar_selection.svg"));
    Tool contagiousSelectionTool("Contagious Selection", QIcon(":/light_tool_contiguous_selection.svg"));
    similarSelectionTool.addSubTool(contagiousSelectionTool);

    Tool cropTool("Crop", QIcon (":/light_tool_crop.svg"));

    Tool fillTool("Fill", QIcon(":/light_krita_tool_color_fill.svg"));
    Tool colorPicker("Color Picker", QIcon(":/light_krita_tool_color_picker.svg"));
    Tool smartPatchTool("Smart Patch", QIcon(":/light_krita_tool_smart_patch.svg"));
    Tool gradientTool("Gradient", QIcon(":/light_krita_tool_gradient.svg"));
    Tool patternTool("Pattern", QIcon(":/light_pattern.svg"));
    fillTool.addSubTool(colorPicker);
    fillTool.addSubTool(smartPatchTool);
    fillTool.addSubTool(gradientTool);
    fillTool.addSubTool(patternTool);

    Tool brushTool("Brush", QIcon(":/light_krita_tool_freehand.svg"));
    Tool dynamicBrushTool("Dynamic Brush", QIcon(":/light_krita_tool_dyna.svg"));
    Tool lazyBrushTool("Lazy Brush", QIcon(":/light_krita_tool_lazybrush.svg"));
    Tool multiBrushTool("Multi Brush", QIcon(":/light_krita_tool_multihand.svg"));
    brushTool.addSubTool(dynamicBrushTool);
    brushTool.addSubTool(lazyBrushTool);
    brushTool.addSubTool(multiBrushTool);

    Tool rectangleTool("Rectangle", QIcon(":/light_krita_tool_rectangle.svg"));
    Tool lineTool("Line", QIcon(":/light_krita_tool_line.svg"));
    Tool freehandTool("Freehand", QIcon(":/light_krita_tool_freehandvector.svg"));
    Tool ellipseTool("Ellipse", QIcon(":/light_krita_tool_ellipse.svg"));
    Tool polylineTool("Polygon", QIcon(":/light_polyline.svg"));
    Tool pathTool("Path", QIcon(":/light_krita_draw_path.svg"));
    rectangleTool.addSubTool(lineTool);
    rectangleTool.addSubTool(ellipseTool);
    rectangleTool.addSubTool(polylineTool);
    rectangleTool.addSubTool(freehandTool);
    rectangleTool.addSubTool(pathTool);

    Tool textTool("Text", QIcon(":/light_draw-text.svg"));

    Tool shapeSelectTool("Shape Select", QIcon(":/light_select.svg"));
    Tool editShapesTool("Edit Shapes", QIcon(":/light_shape_handling.svg"));
    shapeSelectTool.addSubTool(editShapesTool);

    Tool assitantTool("Assistants", QIcon(":/light_krita_tool_assistant.svg"));
    Tool gridTool("Grid", QIcon(":/light_krita_tool_grid.svg"));
    Tool measureTool("Measure", QIcon(":/light_krita_tool_measure.svg"));
    Tool referenceImagesTool("Reference Images", QIcon(":/light_krita_tool_reference_images.svg"));
    Tool perspectiveGridTool("Perpective Grid", QIcon(":/light_tool_perspectivegrid.svg"));
    assitantTool.addSubTool(gridTool);
    assitantTool.addSubTool(measureTool);
    assitantTool.addSubTool(referenceImagesTool);
    assitantTool.addSubTool(perspectiveGridTool);

    Tool zoomTool("Zoom", QIcon(":/light_tool_zoom.svg"));
    Tool panTool("Pan", QIcon(":/light_tool_pan.svg"));
    zoomTool.addSubTool(panTool);

    ToolBox *tb = ui->widget;
    tb->addTool(transformTool);
    tb->addBreak();

    tb->addTool(rectangularMarqueeTool);
    tb->addTool(lassoTool);
    tb->addTool(similarSelectionTool);
    tb->addBreak();

    tb->addTool(cropTool);
    tb->addBreak();

    tb->addTool(fillTool);
    tb->addBreak();

    tb->addTool(brushTool);
    tb->addBreak();

    tb->addTool(rectangleTool);
    tb->addTool(textTool);
    tb->addTool(shapeSelectTool);
    tb->addBreak();

    tb->addTool(assitantTool);
    tb->addBreak();

    tb->addTool(zoomTool);
    tb->addBreak();

}

MainWindow::~MainWindow()
{
    delete ui;
}

