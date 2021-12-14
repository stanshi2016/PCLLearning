# PCL, QT, VTK 创建项目

## 1. VS安装QT插件

## 2. VS创建QT项目

![](images\2021-12-14-12-13-26-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-12-14-11-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-22-44-27-image.png)

进行窗口设计

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-22-46-04-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-22-47-17-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-22-54-19-image.png)

main.cpp

```
#include "pclvisualizer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PCLVisualizer w;
    w.show();
    return a.exec();
}
```

编译代码

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-23-06-46-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-23-07-45-image.png)

![](C:\Users\sjl\AppData\Roaming\marktext\images\2021-12-14-23-32-45-image.png)
