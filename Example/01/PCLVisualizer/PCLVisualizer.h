#ifndef PCLVISUALIZER_H
#define PCLVISUALIZER_H

#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QMainWindow>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include "ui_pclvisualizer.h"

class PCLVisualizer : public QMainWindow
{
	Q_OBJECT
public:
	PCLVisualizer(QWidget* parent = 0);
	~PCLVisualizer();

private:
	Ui::PCLVisualizerClass ui;
	//Ui::PCLVisualizerClass ui;
	//�������ݴ洢
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

	//��ʼ��vtk����
	void initialVtkWidget();

private slots:
	//�����򿪲�
	void onOpen();
	void exit();
	//void setcolor();
};

#endif // PCLVISUALIZER_H