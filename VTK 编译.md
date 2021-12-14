# VTK 编译

## 1. 下载源文件

官方GIT库下载VTK源码[Tags · VTK / VTK · GitLab](https://gitlab.kitware.com/vtk/vtk/-/tags)， 由于PCL 1.20.0对应的VTK库版本是9.0，所以选择对应的版本下载即可

将源码解压以后开始编译. 

创建VTK文件，在此文件夹下新建两个如下图所示的文件夹：vtk_src和vtk_bin，将解压的VTK9.0.3放入vtk_src文件夹下。

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-07-44-38-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-07-46-11-image.png)

## 2. Cmake编译

2.1 启动CMake，将路径写

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-07-47-48-image.png)

2.2 使用 `Add Entry` 按钮添加缓存变量 `CMAKE_DEBUG_POSTFIX`，类型为 `STRING`，值设置为 `-gd`。这是为了将最后编译的 `debug` 文件与 `release` 文件区分开来。

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-07-52-00-image.png)

2.3 如下图，点击Configure

<img src="file:///C:/Users/sjl/AppData/Roaming/marktext/images/2021-12-12-07-53-41-image.png" title="" alt="" width="463">



2.4 选择BUILD_SHADRED_LIBS，BUILD_EXAMPLES, BUILD_TESTING

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-08-01-57-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-08-02-25-image.png)

2.5 设置安装目录 

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-08-03-24-image.png)

2.6 设置QT，然后再次点击Configuration

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-11-36-23-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-11-37-47-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-11-39-07-image.png)

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-11-39-44-image.png)

2.7 确认QT的路径是否正确

![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-08-09-56-image.png)

2.8 点击Generate，编译库

打开解决方案（用VS2019打开.sln文件），其中包含了上百个即项目，默认是 Debug x64 模式，右击 ALL_BUILD 项目，选择生成，生成完成后，右击 INSTALL 项目，选择生成，即开始安装，将生成 debug 库文件。待构建完成后，切换为 Release x64 模式，按同样的操作，生成 release 库文件。最终完成 VTK 的构建，可以在先前配置的安装目录下找到构建好
![](https://github.com/stanshi2016/PCLLearning/blob/main/images\2021-12-12-08-14-03-image.png)

2.9 将生成的文件拷贝到PCL中


