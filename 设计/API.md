
##View
###ListVeiw
**简介：**
以列表的形式来显示控件，使用获取数据的数据对*ListItem*进行渲染。
**继承关系**
父类：QScrollArea
###方法：
###public
void setOrientation(Qrien orien=ListView: :Vertical);
void setData(QList<QVariant> data);
void setItem(ListItem\* item);
void setBackgroundColor(const QColor &color);
int firstVisibleItemIndex();
void setItemSpacing(int space);
###private
void mousePressEvent(QMouseEvent \*event);

**详细说明**
1. void setOrientation(Qrien orien=ListView: :Vertical);
	设置list view的呈现方向，有两种选择：水平方向，垂直方向
2. void setData(QList<QVariant> data);
	为list view设置数据集，list view通过将数据集和与之对应的listItem相匹配，从而对数据进行渲染，展现出自定义的视图。
3. void setItem(ListItem\* item);
	设置listitem，是数据集渲染的依据。使用者想要自定义渲染的效果，则需要继承ListItem类，并实现其中的updateItem方法。
4. void setBackgroundColor(const QColor &color);
	设置listView的背景色。
5. int firstVisibleItemIndex();
	获取第一个可见项的索引，索引的值从0开始计数。
6. void setItemSpacing(int space);
	设置列表项之间的间距。
----

##MarkDown

###MarkDownEdit
**简介：**
markdown编辑器，具有语法高亮。目前还不具备自动补全的功能之后完善。
**继承关系：**
父类：QTextEdit
###方法：
void setTheme(MarkDownEdit::Theme theme);
void initDarkTheme();

###MarkDownHighlighter
**简介：**
对markdownedit中对内容进行语法高亮，其中设置语法高亮形式以及规则
**继承关系：**
父类：QSyntaxHighlighter
###方法：
###public
void createTypeFormat();
void setTypeColor(const QHash<Type,QColor> &value);
###private
void initTypeColor();
void initPartFormat()
###protected
void highlightBlock(const QString &text);

**详细说明**
1. void createTypeFormat();
	初始化字体样式的类型，设定关键字的字体的各种属性，（大小，颜色以及基本样式）
2. setTypeColor(const QHash<Type,QColor> &value);
	设置相应关键字的颜色
3. void highlightBlock(const QString &text);
	语法高亮功能的具体实现，通过正则表达式锁定关键词区间。

###MarkDownToHtml
**简介:**
主要功能是将markdown标签对应到相应到html标签，提供给NormalMarkDownToHtml相应到转化规则。
**继承关系：**
父类：QObject
###方法
###public
QVector<HtmlRule> getHtmlRules() const;
QHash<QString ,QString> getLabelHash() const;
###private
void initHtmlReg();
void createLabel();
###struct
struct HtmlRule;

**详细说明**
1. QVector<HtmlRule> getHtmlRules() const;
	获取转换规则，其中该规则使用正则表达式实现。
2. QHash<QString ,QString> getLabelHash() const;
	获取标签的映射关系，通过给定的开始标签，得到相应的结束标签。
3. struct HtmlRule;
	记录转换规则所需要的信息。
	- label:记录当前关键字所匹配的标签
	- markLength：所对应的markdown标签的长度
	- type：标签的类型
		- 1:没有结束标签
		- 2:普通的标签，带结尾标签。
		- 3:列表标签，需要 进行特别处理
	- endType：记录markdown标签是否带有结束标签如粗体（**）。当值为0时表示不带结尾标签。


###NormalMarkDownToHtml
**简介：**
根据获取到的规则，将得到的markdown文本转化成html文本。分析时采用逐行扫描的方式，解析markdown文档。
**继承关系：**
父类：QObject
###方法：
###public
QString createHtml();
###private
QStringList splitMarkDown();
QString paserLine(QString text);
void paserOrderList(QString *text, int index, int length, HtmlRule rule);
QString endOrderList(int endIndex);
int getTabNum(QString str);
###struct
struct OrderList;

**详细说明**
1. QString createHtml();
	生成html格式的字符串，
2. QStringList splitMarkDown();
	将获得时markdown文档进行分割，以换行符作为分隔符。将文档分成以行组织的列表，方便之后的处理。
3. QString paserLine(QString text);
	对每一行的文本进行转换，解析成对应的html文档。对于跨多行的元素进行特俗处理。当行或行内元素则采取相同的处理方式






















