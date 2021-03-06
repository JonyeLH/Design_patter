## 简单工厂 ##

- 应用场景：
    需要对原始代码进行业务拓展，并且拓展内容存在大量复用。


- 优势：
    1、"针对接口编程而不是针对具体编程原则"
        提供了专门的工厂类用于创建对象，将对象的创建和对象的使用分离开。
        也就是说工厂类封装了变化，封装了对象创建的具体细节，对客户端隐藏对象创建的细节，使得客户类针对接口进行编程。
    2、"迪米特法则，也就是和直接朋友通信原则"
        客户端无须知道所创建的具体产品类的类名，只需要知道具体产品类所对应的参数即可，对于一些复杂的类名
    3、"封装变化原则"
        具体对象创建是一个变化过程，因此把对象的创建封装起来


- 劣势：
    1、由于工厂类集中了所有产品的创建逻辑，职责过重，一旦不能正常工作，整个系统都要受到影响，违背"单一原则"。
    2、使用简单工厂模式势必会增加系统中类的个数（引入了新的工厂类），增加了系统的复杂度和理解难度。
    3、系统扩展困难，一旦添加新产品就不得不修改工厂逻辑，在产品类型较多时，有可能造成工厂逻辑过于复杂，不利于系统的扩展和维护。违背"开发封闭原则"。
    4、简单工厂模式由于使用了静态工厂方法，造成工厂角色无法形成基于继承的等级结构。


- 具体应用
    (1)通常在使用word办公软件的时候，会根据需要绘制出饼状图，柱状图，折线图等图形。可以提供一个工厂类，根据用户的选择创建出不同类型的图形。

    (2)QQ空间背景样式，博客背景样式等都提供了各种风格的样式。提供一个工厂，根据用户选择的具体风格样式，创建出各个不同的背景风格，用来装饰QQ空间。

    (3)网页下载工具的开发: 根据需要可以下载新浪网页、腾讯网页、搜狐网页等。根据用户的选择，把网页类型传进工厂，将下载该类型的网页内容。

    (4)淘宝购物最后一个支付环节，可以选择货到付款、网上银行、支付宝等类型支付。用户可以选择具体的支付方式完成订单,这也是简单工厂模式的一种应用。

    (5)电影院打折算法: VIP5折、学生票5折、成人票正常收费等打折算法。

    (6)多功能计算器的开发:封装加减乘除等运算操作(大话设计模式的例子)

    (7)在很多游戏场合，游戏角色可以选择各种各样的武器，如:手枪、AK47、步枪、大刀等。

    (8)如果电脑上装有QQ输入法、搜狗输入法、微软拼音输入法，用户可以设置使用哪种类型的输入法。类似的还可以设置IE浏览器、谷歌浏览器、火狐浏览器。可以设置word2003或者金山的WPS。这些都可以理解为简单工厂模式的一种运用。

    (9)软件公司决策是否开发哪一种产品，银行卡识别、身份证识别还是驾驶证识别。

    (10)生活中也有很多类似的工厂: 富士康代工工厂；安踏加工厂；咖啡生产基地；沃尔玛等超市提供各种产品供用户使用；肯德基马当劳等。