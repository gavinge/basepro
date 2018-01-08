# basepro
大型团队的工程管理至关重要。

如何易用、规范、高效的管理多人团队的工程代码。是架构师们要面临的一项重要任务。

一个真正的技术高手，必须具备两项素养：一是横向的架构能力、二是纵向的垂直解决问题能力。

本项目，从架构师的角度，将win端的项目以模板形式生产，以简单易用为出发点，从根本上解决大型团队的工程代码的规范性问题。


-----------------------------------------------------------------------------------------
项目文件说明：

bin：读者可以下载直接简历工程模板.

wtlGenerator 工程:生成exe工程生成代码 VS2013

dllGenerator 工程:生成dll工程生成代码 VS2013

dll_baseproj工程: 标准普通dll工程母本 （支持VS2008）
                 将导出函数，回掉函数集合都标准化。
dll_wtlbaseproj工程: 标准WTL dll工程母本 （支持VS2008）
                 将导出函数，回掉函数集合都标准化（支持WTL）
exe_wtlbaseproj工程: 标准exe工程母本  (支持VS2008)
                 规范工程主逻辑，让代码逻辑清晰简单。（只支持WTL）
