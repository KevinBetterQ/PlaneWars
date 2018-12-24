# 飞机大战
大一的课程设计，做一个基于MFC的飞机大战单机版游戏。  
游戏主要角色有战机、敌机、战机导弹、敌机子弹、客机、保护膜星星及保护膜，其中战机可升级，有五种形态，导弹可随战机等级升高数目增多，形态变化。

## 游戏规则和逻辑
1. 打开游戏进入开始界面，有文字提示，可以观看游戏规则及玩法，按Enter键开始游戏。
2. 开始后进入游戏界面，玩家用键盘方向键控制战机方向，空格键控制导弹发射。敌机随机产生，速度随机，子弹发射随机。战机导弹击中敌机，敌机消失，导弹消失，产生爆炸效果与爆炸音效，玩家游戏分数增加。敌机子弹击中战机或敌机撞到战机，战机生命数目会相应减少，产生不同爆炸音效。游戏进行过程中会随机产生客机。客机分四个区域，机头，机身，机翅，油箱，战机导弹击中客机不同区域会相应减少不同分数与生命值，客机也会相应发生不同行为。游戏过程会随机产生小星星，战机碰到星星会产生动态保护膜，持续一段时间后会自动消失。
3. 采取游戏积分制，随着战机杀敌数目增加，战机可以升级，每升一级，战机类型变化，导弹随之变化形态，威力加强，升到五级之后变为“最强战机”形态，不再变化。随着得分数目增加到设定分数，可以过一关，每过一关，游戏背景会切换一次，敌机生命值会增加，数目增加，从而游戏难度相应增加。关卡无限。积分、生命、关卡在上方显示。
4.游戏设置栏可以设置无敌模式和普通模式。死后可以原地复活和重新开始游戏。原地复活是使生命值恢复，重新开始则回到开始界面再来一次。

## 开发环境：
VS2010 + windows 7 

## 相关技术：  
- 文字显示
- 透明贴图技术
- 图片链表实现爆炸和保护膜动画
- 键盘消息响应
- 定时器的使用
- 双缓冲技术
- 碰撞检测技术
- 内存释放

## 功能需求：
### 主要功能模块
1. 开始界面模块。在此界面，可以阅读游戏规则。
2. 战机的升级与键盘控制模块，升级后形态变化，子弹威力加强。
3. 战机导弹类型变化模块。随战机升级，导弹类型不同。
4. 敌机数量、速度以及子弹的数量、方向和速度随机产生模块。
5. 敌机、子弹和战机、导弹的碰撞检测消除以及爆炸模块。
6. 客机随机出现与移动，分区域检测模块，击中不同位置产生不同行为。
7. 游戏关卡控制模块，难易度变化，每关切换不同背景。
8. 保护膜模块。游戏中随机产生小星星，战机接触后会产生动态保护膜，持续一定时间后自动消失，保护膜期间战机呈现无敌模式。
9. 战机速度设置模块。可以自行设置战机速度，增加难度。
10. 分数制与生命记录模块。游戏根据设定分数与杀敌数判断过关与战机升级。
11. 游戏模式（无敌与普通）选择模块。
12. 游戏重新开始与原地复活模块。
13. 游戏音效产生模块。
14. 对象出界删除，内存释放模块。
### 扩展功能及设计思路
1、飞机采取等级制，可以升级，变换不同形态。  
选择原因：学会图片链表与贴图技术之后，积累了好多飞机材料图片，想要利用起来，于是想到飞机可以升级从而变化形态，即重新装载一张图片。  
实现原理：首先在战机类CPlane中再写几个LoadImage1、LoadImage2、LoadImage3等函数，分别装载不同图片。飞机等级用文字显示出来，用一个int变量，飞机达到一定杀敌数，变量加一。升级后，首先将战机图片链表清空，用m_Images.DeleteImageList()实现，然后调用不同的装载图片的函数（LoadImage），即实现飞机形态变化。  

2、动态飞机防护罩。当战机碰到随机产生的小星星时，会产生保护膜，持续一定时间后消失。保护膜期间，战机都不会减少生命。  
选择原因：实训做到快最后时，发现其他同学没太有做动态保护膜这个功能的，而我觉得模仿爆炸的类可以做出一个来，于是我就想试试，作为一个特色。刚开始觉得很简单，做起来才发现有很多问题，包括控制保护膜开关与保护膜持续时间等，最终通过借鉴网络搜索与自己试验成功添加保护膜。  
实现原理： 先建一个产生星星的类protection，模仿敌机产生的类。再建一个保护膜的类protect，在类中设置一个int  on来记录保护膜开启（1为开，0为关）当战机接触小星星时，时on=1，设置int st_time;表示防护罩开始开启时间，int w_nWait;表示防护罩开启时长。时间控制上利用了GetTickCount()函数，此函数返回从操作系统启动到现在所经过的毫秒数。当两次利用GetTickCount()获取时间之差大于设定w_nWait（开启时间）数值后，删除防护罩从而控制其自动消失。防护罩图片播放上模仿爆炸利用图片链表与图片索引实现。  

3、不同类型子弹。数量不同，形态不同。  
选择原因：为战机升级后提升导弹威力而加，随着战机升级，想要使战机力量方面有一些变化，于是想到改变导弹数量与形态。  
实现原理：首先加一个if判断语句，判断级数从而产生不同类型导弹，导弹数目变化即在相对飞机不同位置再在导弹链表中加几次导弹，用list_bomb.AddTail(new CBomb(pMyPlane->GetPoint().x + 3, pMyPlane->GetPoint().y + 20));实现。导弹形态变化即改变导弹图片，原理是先删除导弹链表图片，再装载不同导弹图片。  

4、积分过关制与过关背景切换   
选择原因：觉得此项功能实现起来较为容易。  
实现原理：定义两个int型变量，pass表示关数，score表示分数，在游戏界面实时显示，然后再按击落敌机数使score++，pass++。关数增加后，会有背景图的切换利用pass%4得到不同的数，从而在位图上装载不同背景图片，进行切换，丰富画面。  

5、增加客机功能。  
选择原因：加客机后会使游戏变得更有趣。  
实现原理：新建一个客机的类，将客机分为四个区域，机头，机身，机翅，油箱。分别在类中写四个GetRect的函数，获得这四个区域，再与战机导弹碰撞检测，检测到不同区域，使客机产生不同行为变化。  

6、难度设计。  
选择原因：增强游戏耐玩性  
实现原理：首先自己可以利用对话框设置战机速度，玩家可以自己挑战难度选择。  
其次，过一关后，游戏难度也会增加，每一架敌机命数也会相应增加一条，实现是利用一个全局变量num，加在导弹与敌机的碰撞检测上。当nmu % pass（关数）时才删除敌机，从而实现敌机命数增加。同时利用pass数的变化来使敌机产生增多。  

7、添加了一个开始界面  
选择原因：首先想要有一个界面说明一下游戏规则与玩法，于是添加。其次使玩家打开游戏时有一个缓冲，不要一运行就直接产生战机开始游戏。  
实现原理：建立一个计时器，直接运行，在这个计时器里，利用双缓冲那些方法添加一张大背景图片，并呈现文字规则与玩法介绍。当接收到ente键按下时，Killtime（1），建立第二个计时器，第二个计时器里则为游戏运行时所需代码。包括设置的“重新开始”也是利用这个1号计时器再建立从而返回开始界面来重新开始。  
