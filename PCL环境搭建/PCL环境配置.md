# PCL环境配置

## 1. PCL ALL-IN-ONE 安装

## 2. Windows环境变量

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-12-47-10-image.png)

## 3. VS配置PCL运行环境

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-12-48-15-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-12-48-44-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-12-58-20-image.png)

### 3.1 配置[包含目录]

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-13-08-54-image.png)

C:\Program Files\PCL 1.11.1\include\pcl-1.11;
C:\Program Files\PCL 1.11.1\3rdParty\Boost\include\boost-1_74;
C:\Program Files\PCL 1.11.1\3rdParty\Eigen\eigen3;
C:\Program Files\PCL 1.11.1\3rdParty\FLANN\include;
C:\Program Files\PCL 1.11.1\3rdParty\Qhull\include;
C:\Program Files\PCL 1.11.1\3rdParty\VTK\include\vtk-8.2;
C:\Program Files\PCL 1.11.1\3rdParty\OpenNI2\Include;

### 3.2 配置[库目录]

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-13-16-28-image.png)

C:\Program Files\PCL 1.11.1\3rdParty\Boost\lib;
C:\Program Files\PCL 1.11.1\3rdParty\Qhull\lib;
C:\Program Files\PCL 1.11.1\3rdParty\FLANN\lib;
C:\Program Files\PCL 1.11.1\3rdParty\VTK\lib;
C:\Program Files\PCL 1.11.1\lib;
C:\Program Files\OpenNI2\Lib;

### 3.3 配置附加依赖项

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-15-25-13-image.png)

附加依赖项可参考如下方法获取

Here mainly add the ".lib" file of PCL and the ".lib" file of VTK in the third-party library. Because there are many library files, the library file list can be generated through the command line. Methods as below:

(1) Win+r brings up the "Run" window and outputs cmd;

(2) Enter: cd C:\Program Files\PCL1.10.1\3rdParty\VTK\lib and press Enter (fill in your own path) in order to obtain the VTK library;

Enter: dir /b *.lib >D:\0_VTKLib.txt and press Enter to store the VTK library list in the "0_VTKLib.txt" file on Disk D;

(3) Enter: cd C:\Program Files\PCL1.10.1\lib and press Enter (fill in your own path) to prepare for the PCL library;

Enter: dir /b *.lib >D:\1_PCLLib.txt and press Enter to store the PCL library list in the "1_PCLLib.txt" file on Disk D;

(4) Open the generated text file, "0_VTKLib.txt" and "1_PCLLib.txt", select all and copy them to the additional dependencies respectively.

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-23-31-12-image.png)

#### 注意：lib库要区分是Debug还是Release版本, 这里VTK lib库Debug是-gd后缀, PCL是d后缀, 注意区分. VTK编译过程可参考这篇文章.

### 3.4 SDK Check

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-15-28-22-image.png)

### 3.5 预处理器参数设置

![](https://github.com/stanshi2016/PCLLearning/blob/main/images/2021-12-14-15-31-03-image.png)

## 4 运行PCL第一个Demo

```
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
main(int argc,char**argv)
{
pcl::PointCloud<pcl::PointXYZ> cloud;
// 创建点云
cloud.width=5;
cloud.height=1;
cloud.is_dense=false;
cloud.points.resize(cloud.width*cloud.height);
for(size_t i=0;i<cloud.points.size();++i)
{
cloud.points[i].x=1024*rand()/(RAND_MAX+1.0f);
cloud.points[i].y=1024*rand()/(RAND_MAX+1.0f);
cloud.points[i].z=1024*rand()/(RAND_MAX+1.0f);
}
pcl::io::savePCDFileASCII("test_pcd.pcd",cloud);
std::cerr<<"Saved "<<cloud.points.size()<<" data points to test_pcd.pcd."<<std::endl;
for(size_t i=0;i<cloud.points.size();++i)
std::cerr<<" "<<cloud.points[i].x<<" "<<cloud.points[i].y<<" "<<cloud.points[i].z<<std::endl;
return(0);
}
```
