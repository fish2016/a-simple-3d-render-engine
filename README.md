#a-simple-3d-render-engine

一个简单的3d底层渲染引擎，兼容d3d接口；

于2013年开发

#软3D渲染引擎开发(一)  ----目的和初衷
看完了 《3D游戏编程大师技巧 Andre LaMothe》，理论上说，如果真正是理解了里面的内容，是有能力去实现一个软件3D渲染引擎的；一直觉得，计算机编程是一门理论和实践结合的学科，总觉得不实践一下自己做一个软件3D引擎出来，终究不算真的理解里面的知识点，所以决定自己也利用《3D游戏编程大师技巧 Andre LaMothe》
不自己实现一把，总觉得理解不够深刻，也不敢怕着胸膛说，我懂了；
所以，决定自己实现一把软件3D引擎
这个软件3D引擎的名字，暂定为my_d3dx
目标定得太高，容易打击积极性，目标现暂定为先实现线框引擎，着色部分看以后的时间，一步一个台阶，线框是基础，先把基础实现了；

#软3D渲染引擎开发(二)  ----规划接口及头文件分析
众所周知，DirectX是最流行的3D底层渲染引擎，我的想法是，以与DirectX相同的接口，作为my_d3dx的接口，也就是DirectX外部接口与my_d3dx接口是一样的；这样选择有三点好处：
1. 在实现软件3D引擎的同时随带熟悉dx的接口
2. dx接口是经过微软审定而制定的，有一定的权威和优点，接口形式都比较规范精简，包含的功能不会有遗漏，有利于给实现作参考；
3. 兼容dx接口，可以很方便的与一些使用dx接口的程序例子，很方便的验证和对比效果；
头文件分析
d3d9.h主要是一些抽象类的声明，如IDirect3D9 IDirect3DDevice9 IDirect3DVertexBuffer9 IDirect3DResource9， IDirect3DVertexBuffer9 继承自IDirect3DResource9，还有一个关键的全局函数的声明Direct3DCreate9；
  d3d9caps  d3d9types
d3dx9.h  主要作用是包裹一些主要的头文件（如d3d9.h），和一些常用的全局宏

d3dx9math.h 


#软3D渲染引擎开发(三)  ----操作后缓存方式的选择及其分析
三种选择，如果有更好的请一定告诉我
1、使用bitblt接口
2、使用dx9 CreateOffscreenPlainSurface
（参考http://azykise.blog.163.com/blog/static/17308024420105343326678/）
3、使用dx7接口，那么这种方式与上一种有什么不同呢，由于我们的是模拟dx9接口，所以同样使用dx9的接口会造成重名；

在操作后缓冲区这一层，我们做一个隔离，让上层不感知是使用哪一个方案；


#软3D渲染引擎开发(四)..引擎模块的分层

#软3D渲染引擎开发(五)..原则
会参考使用3d游戏编程大师技巧代码的数据结构定义,但是函数实现不会照搬;

