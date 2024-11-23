#include "mainwindow.h"
#include "ui_mainwindow.h"


//static int a;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置主窗口
            setWindowTitle("悬挂件压装力测试系统");
            resize(1200, 800);
#if 1
             MainWindow::initializeControls();
//            timer = new QTimer();
//            elapsedTimer = new QElapsedTimer(); //记录时间
//            startReBtn1 = new QPushButton("开始接收", this);
//            startReBtn2 = new QPushButton("开始接收", this);
//            yazhuang1 = new QLineEdit(this);
//            modbusDevice = new QModbusTcpClient(this);
//            xuanGuaName = new QComboBox(this);
//            jianChaName = new QComboBox(this);
//            caoZuoName = new QComboBox(this);
//            yaZhuangData = new QDateEdit(this);

            connect(startReBtn1, QPushButton::clicked, this, startRefun1);
            timer->start(1000);
            elapsedTimer->start();
            // 异常处理
//            connect(modbusDevice, &QModbusDevice::errorOccurred, this, [this](QModbusDevice::Error error) {
//                qDebug() << "Error occurred:" << error << " - " << modbusDevice->errorString();
//            });


#endif
//            MainWindow::on_readMod_clicked();
#if 1

// 创建菜单栏
QMenuBar *menuBar = new QMenuBar(this);
setMenuBar(menuBar);
menuBar->addMenu("系统(&V)");
menuBar->addMenu("设置(&Y)");
menuBar->addMenu("维护(&P)");
menuBar->addMenu("工具(&T)");
menuBar->addMenu("帮助(&Z)");

// 设置菜单栏样式
menuBar->setStyleSheet("QMenuBar { background-color: #2c3e50; color: white; font-size: 14px; }"
                       "QMenuBar::item { background-color: #34495e; padding: 5px 10px; }"
                       "QMenuBar::item:selected { background-color: #1abc9c; }");

// 创建主窗口的中心部件
QWidget *centralWidget = new QWidget(this);
setCentralWidget(centralWidget);

// 主布局
QGridLayout *mainLayout = new QGridLayout(centralWidget);

// 添加顶部按钮组
QHBoxLayout *topButtonLayout = new QHBoxLayout();
topButtonLayout->addStretch(1); // Add some space at the beginning to push the buttons rightward

// Create buttons with custom style
QPushButton *loginButton = new QPushButton("登录", this);
QPushButton *logoutButton = new QPushButton("注销", this);
QPushButton *standardButton = new QPushButton("悬挂件/压装力标准值和范围", this);
recordQueryButton = new QPushButton("记录查询", this);
QPushButton *dataMaintenanceButton = new QPushButton("数据维护", this);
QPushButton *exitButton = new QPushButton("退出", this);

// Set size policy for uniform button sizes
loginButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
logoutButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
standardButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
recordQueryButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
dataMaintenanceButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
exitButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

// Style buttons
loginButton->setStyleSheet("background-color: #3498db; color: white; border-radius: 5px;");
logoutButton->setStyleSheet("background-color: #e74c3c; color: white; border-radius: 5px;");
standardButton->setStyleSheet("background-color: #2ecc71; color: white; border-radius: 5px;");
recordQueryButton->setStyleSheet("background-color: #f39c12; color: white; border-radius: 5px;");
dataMaintenanceButton->setStyleSheet("background-color: #9b59b6; color: white; border-radius: 5px;");
exitButton->setStyleSheet("background-color: #34495e; color: white; border-radius: 5px;");

// Add buttons to the layout
topButtonLayout->addWidget(loginButton);
topButtonLayout->addWidget(logoutButton);
topButtonLayout->addWidget(standardButton);
topButtonLayout->addWidget(recordQueryButton);
topButtonLayout->addWidget(dataMaintenanceButton);
topButtonLayout->addWidget(exitButton);

// Add the layout to the main layout
mainLayout->addLayout(topButtonLayout, 0, 0, 1, 2);
topButtonLayout->addStretch(1); // Add space after buttons


// 添加工作模式分组
QGroupBox *workModeBox = new QGroupBox("工作方式", this);
QVBoxLayout *workModeLayout = new QVBoxLayout(workModeBox);
workModeLayout->addWidget(new QRadioButton("普通模式", this));
workModeLayout->addWidget(new QRadioButton("维护模式", this));
mainLayout->addWidget(workModeBox, 1, 0);

// 设置工作模式分组样式
workModeBox->setStyleSheet("QGroupBox { background-color: #ecf0f1; border: 2px solid #bdc3c7; border-radius: 8px; padding: 10px; font-size: 14px; }"
                           "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; background-color: #95a5a6; color: white; font-weight: bold; }"
                           "QRadioButton { font-size: 12px; }"
                           "QRadioButton::indicator { width: 15px; height: 15px; }");

// 添加创建记录区
QGroupBox *recordCreationBox = new QGroupBox("创建记录", this);
QGridLayout *recordLayout = new QGridLayout(recordCreationBox);
recordLayout->addWidget(new QLabel("悬挂件名称：", this), 0, 0);
recordLayout->addWidget(xuanGuaName, 0, 1);
// 使用std::vector存储字符串
std::vector<QString> items = {"选项1", "选项2", "选项3", "选项4"};
// 将std::vector转换为QStringList
QStringList itemList = QStringList::fromVector(QVector<QString>::fromStdVector(items));
xuanGuaName->addItems(itemList);

recordLayout->addWidget(new QLabel("修正系数：", this), 0, 2);
recordLayout->addWidget(new QLineEdit(this), 0, 3);
recordLayout->addWidget(new QPushButton("修正曲线",this), 0, 4);

recordLayout->addWidget(new QLabel("压装日期：", this), 1, 0);
recordLayout->addWidget(yaZhuangData, 1, 1);
QDate currentDate = QDate::currentDate();
yaZhuangData->setDate(currentDate);

recordLayout->addWidget(new QLabel("扫描时间：", this), 1, 2);
recordLayout->addWidget(new QSpinBox(this), 1, 3);
recordLayout->addWidget(new QPushButton("保存",this), 1, 4);

recordLayout->addWidget(new QLabel("操作者：", this), 2, 0);
recordLayout->addWidget(caoZuoName, 2, 1);
std::vector<QString> caoZuoNameItems = {"小马", "小明", "小红", "赵武"};
QStringList caoZuoNameItemList = QStringList::fromVector(QVector<QString>::fromStdVector(caoZuoNameItems));
caoZuoName->addItems(caoZuoNameItemList);

recordLayout->addWidget(new QLabel("突变跨度设置：", this), 2, 2);
recordLayout->addWidget(new QLineEdit(this), 2, 3);
recordLayout->addWidget(new QPushButton("保存",this), 2, 4);

recordLayout->addWidget(new QLabel("检查者：", this), 3, 0);
recordLayout->addWidget(jianChaName, 3, 1);
// 使用std::vector存储字符串
std::vector<QString> JianChaNameItem = {"小马", "小明", "小红", "赵武"};
// 将std::vector转换为QStringList
QStringList JianChaNameItemList = QStringList::fromVector(QVector<QString>::fromStdVector(JianChaNameItem));
jianChaName->addItems(JianChaNameItemList);

recordLayout->addWidget(new QPushButton("创建",this), 3, 2);
recordLayout->addWidget(new QLineEdit("0",this), 3, 3);
recordLayout->addWidget(new QPushButton("展开",this), 3, 4);

mainLayout->addWidget(recordCreationBox, 1, 1);

// 设置创建记录区样式
recordCreationBox->setStyleSheet("QGroupBox { background-color: #ecf0f1; border: 2px solid #bdc3c7; border-radius: 8px; padding: 10px; }"
                                 "QLineEdit, QDateEdit,QSpinBox, QComboBox { background-color: #ffffff; border: 1px solid #bdc3c7; border-radius: 5px; padding: 5px; font-size: 12px; }"
                                 "QLabel { font-size: 12px; }");


// 添加数据区
QGroupBox *dataBox = new QGroupBox("数据区域", this);
QVBoxLayout *dataLayout = new QVBoxLayout(dataBox);
dataLayout->addWidget(new QCheckBox("数据点", this));
dataLayout->addWidget(startReBtn1);
dataLayout->addWidget(new QPushButton("结束", this));
dataLayout->addWidget(startReBtn2);
dataLayout->addWidget(new QPushButton("结束", this));
dataLayout->addWidget(new QPushButton("打印", this));
mainLayout->addWidget(dataBox, 2, 0);

// 设置数据区样式
dataBox->setStyleSheet("QGroupBox { background-color: #ecf0f1; border: 2px solid #bdc3c7; border-radius: 8px; padding: 10px; }"
                       "QCheckBox { font-size: 12px; }"
                       "QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 8px 15px; font-size: 12px; }");

// 图表区域
QGroupBox *chartBox = new QGroupBox("图表区域", this);
QGridLayout *chartLayout = new QGridLayout(chartBox);

// 创建两个图表并初始化
QChartView *chartView1 = new QChartView();
QChartView *chartView2 = new QChartView();
QValueAxis *axisX1 = new QValueAxis();
QValueAxis *axisY1 = new QValueAxis();
QValueAxis *axisX2 = new QValueAxis();
QValueAxis *axisY2 = new QValueAxis();
chartView1 = createChartView("压力曲线1", axisX1, axisY1);
chartView2 = createChartView("压力曲线2", axisX2, axisY2);

// 设置图表的大小策略，以确保它们在布局中正确显示
chartView1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
chartView2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

// 将图表添加到布局中
chartLayout->addWidget(chartView1, 0, 0);
chartLayout->addWidget(chartView2, 0, 1);

/**操作通过plc获取压装力值绘制到曲线上**/
QSplineSeries *series1 = new QSplineSeries();
QSplineSeries *series2 = new QSplineSeries();

chartView1->chart()->addSeries(series1);
chartView2->chart()->addSeries(series2);
// 设置轴
chartView1->chart()->setAxisX(axisX1, series1);
chartView1->chart()->setAxisY(axisY1, series1);

chartView2->chart()->setAxisX(axisX2, series2);
chartView2->chart()->setAxisY(axisY2, series2);
//                data1 = { {1, 20}, {2, 50}, {3, 80}, {4, 100},
//                         {5, 20}, {6, 50}, {7, 80}, {8, 100},
//                         {9, 20}, {10, 50}, {11, 80}, {12, 100},
//                         {13, 20}, {14, 50}, {15, 80}, {16, 100}};

//// 创建定时器 前二十秒读取到的值存入data1中并且同时在ui上显示
//MainWindow::insertDataToSeries(series1, series2, data1);
//  --------测试--------------
// 初始化 data1（全局或类内成员）
data1.resize(1);  // 确保 data1 至少有一个点
#if 0
// 定时器槽函数
connect(timer, &QTimer::timeout, this, [=] {
    int elapsedTime = elapsedTimer->elapsed();
    int elapsedSeconds = elapsedTime / 1000;

    qDebug() << "Elapsed time (s):" << elapsedSeconds;

    startRefun1();

    // 更新 data1 的第一个点
    if (data1.size() > 0) {
        data1[0].setX(elapsedSeconds);
        data1[0].setY(a);
    } else {
        qDebug() << "data1 is empty, resizing...";
        data1.resize(1);
        data1[0] = QPointF(0, 0);
    }

    MainWindow::insertDataToSeries(series1, series2, data1);
});
#endif

// 将图表区域添加到主布局中
mainLayout->addWidget(chartBox, 2, 1);

// 设置图表区域样式
chartBox->setStyleSheet("QGroupBox { background-color: #ecf0f1; border: 2px solid #bdc3c7; border-radius: 8px; padding: 10px; }"
                        "QChartView { border: 1px solid #bdc3c7; border-radius: 8px; }");
{
// 确保图表区域占据正确的空间
chartBox->setLayout(chartLayout);

// 将图表添加到布局中
chartLayout->addWidget(chartView1, 0, 0);
chartLayout->addWidget(chartView2, 0, 1);

// 设置图表区域样式
chartBox->setStyleSheet("QGroupBox { background-color: #ecf0f1; border: 2px solid #bdc3c7; border-radius: 8px; padding: 10px; }"
                        "QChartView { border: 1px solid #bdc3c7; border-radius: 8px; }");

// 添加控制区
QGroupBox *controlBox = new QGroupBox("控制区", this);
QGridLayout *controlLayout = new QGridLayout(controlBox);

// 左侧控件组
controlLayout->addWidget(new QLabel("节点序列号：", this), 0, 0);
controlLayout->addWidget(new QLineEdit(this), 0, 1);
controlLayout->addWidget(new QLabel("压装力值：", this), 0, 2);


controlLayout->addWidget(yazhuang1, 0, 3);
controlLayout->addWidget(new QPushButton("打印图表", this), 0, 4);

// 左侧第二行
controlLayout->addWidget(new QLabel("压装结果：", this), 1, 0);
controlLayout->addWidget(new QLineEdit(this), 1, 1);
controlLayout->addWidget(new QLabel("压装力标准：", this), 1, 2);
controlLayout->addWidget(new QLineEdit(this), 1, 3);

// 右侧控件组（与左侧对称）
controlLayout->addWidget(new QLabel("节点序列号：", this), 0, 5);
controlLayout->addWidget(new QLineEdit(this), 0, 6);
controlLayout->addWidget(new QLabel("压装力值：", this), 0, 7);
controlLayout->addWidget(new QLineEdit(this), 0, 8);
controlLayout->addWidget(new QPushButton("打印图表", this), 0, 9);

// 右侧第二行
controlLayout->addWidget(new QLabel("压装结果：", this), 1, 5);
controlLayout->addWidget(new QLineEdit(this), 1, 6);
controlLayout->addWidget(new QLabel("压装力标准：", this), 1, 7);
controlLayout->addWidget(new QLineEdit(this), 1, 8);

// 将控制区添加到主布局
mainLayout->addWidget(controlBox, 3, 0, 1, 2);

// 状态栏
QStatusBar *statusBar = new QStatusBar(this);
setStatusBar(statusBar);

// 设置状态栏样式
statusBar->setStyleSheet("QStatusBar { background-color: #34495e; color: white; font-size: 12px; }");

#endif
}

}

MainWindow::~MainWindow()
{
    delete ui;
}

QChartView* MainWindow::createChartView(const QString &title, QValueAxis *axisX, QValueAxis *axisY) {
     QChart *chart = new QChart();
     chart->setTitle(title);

     QSplineSeries *series = new QSplineSeries();
     series->append(0, 0);

     chart->addSeries(series);
     chart->createDefaultAxes();
     if(title == "压力曲线2")
        axisX->setRange(20, 40);
     else
     axisX->setRange(0, 20);
     axisY->setRange(0, 450);

     chart->setAxisX(axisX, series);
     chart->setAxisY(axisY, series);

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     return chartView;
 }

void MainWindow::insertDataToSeries(QSplineSeries *series1, QSplineSeries *series2, const QVector<QPointF> &dataPoints) {
    if (!series1 && !series2) {
//        qDebug() << "Series is null, cannot insert data!";
        return;
    }
    for (const QPointF &point : dataPoints) {
        if (point.x() <= 20) // 直接访问 point 的 x 坐标
            series1->append(point);
        else
            series2->append(point);
    }

}
#if 1
void MainWindow::startRefun1() {
    if (!modbusDevice) {
        qDebug() << "modbusDevice is not initialized!";
        return;
    }

    qDebug() << "Current state:" << modbusDevice->state();

    // 如果 Modbus 未处于连接状态，尝试连接
    if (modbusDevice->state() != QModbusDevice::ConnectedState) {
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, 502);
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, "192.168.1.10");
        modbusDevice->setTimeout(2000);  // 设置超时时间
        modbusDevice->setNumberOfRetries(2);  // 设置重试次数

        qDebug() << "Attempting to connect to:"
                 << modbusDevice->connectionParameter(QModbusDevice::NetworkAddressParameter).toString()
                 << "Port:"
                 << modbusDevice->connectionParameter(QModbusDevice::NetworkPortParameter).toInt();

        // 捕获连接过程中的错误
        connect(modbusDevice, &QModbusDevice::errorOccurred, this, [this](QModbusDevice::Error error) {
            qDebug() << "Error occurred:" << error << " - " << modbusDevice->errorString();
        });

        // 捕获状态变化
        connect(modbusDevice, &QModbusDevice::stateChanged, this, [](QModbusDevice::State state) {
            qDebug() << "State changed to:" << state;
        });

        if (!modbusDevice->connectDevice()) {
            qDebug() << "Connection attempt failed immediately: " << modbusDevice->errorString();
            return;
        }

        qDebug() << "Connection attempt started...";
//        return; // 等待连接完成后再执行后续操作
    } else {
        qDebug() << "Already connected. Proceeding to read.";
    }
    // 准备读取操作
    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, 1, 1);  // 寄存器起始地址3，读取1个寄存器
    qDebug() << "device. State:-------------" << modbusDevice->state();


    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1)) {  // 设备地址为1
        if (!reply->isFinished()) {
            qDebug() << "reoly -------" << endl;
            connect(reply, &QModbusReply::finished, this, &MainWindow::toReadReady);
        } else {
            qDebug() << "Broadcast reply finished immediately.";
            reply->deleteLater();  // 广播请求立即完成时，清理回复对象
        }
    } else {
        qDebug() << "Send read request failed: " << modbusDevice->errorString();
    }

    QThread::msleep(1);  // 延时1ms（一般不需要，避免使用可能导致非必要的性能问题）
}
#endif

void MainWindow::startRefun2(){
//    timer->start();
}


void MainWindow::dealTimerFun(QTimer *timer){
//    timer->start(1000);

}



void MainWindow::toReadReady()
{
//QModbusReply这个类存储了来自client的数据,sender()返回发送信号的对象的指针
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
    {
        return;
    }
    if (reply->error() == QModbusDevice::NoError)
    {
        //处理成功返回的数据
       const QModbusDataUnit unit = reply->result();
        //quint16 stat = unit.value(1);  //状态（位与关系）
         int a = unit.value(0);
       qDebug() << "hahah" <<endl;
       qDebug()<<"plc值"<<unit.value(0);

       yazhuang1->setText(QString::number(a));

//       timer->start(1000);
//       elapsedTimer->start();
//       qDebug()

    }
}

void MainWindow::recordQueryButtonFun(){
    /**
     * 1、处理点击记录查询按钮弹出记录查询页面
     * 2、按照表格形式 12列显示
     * 3、表格标题主记录列表
     * 4、最顶端有详情明细表 带个下划线
     * 5、最末尾一行是统计消息条数量
    **/

}
void MainWindow::initializeControls()
{
    timer = new QTimer();
    elapsedTimer = new QElapsedTimer(); //记录时间
    startReBtn1 = new QPushButton("开始接收", this);
    startReBtn2 = new QPushButton("开始接收", this);
    yazhuang1 = new QLineEdit(this);
    modbusDevice = new QModbusTcpClient(this);
    xuanGuaName = new QComboBox(this);
    jianChaName = new QComboBox(this);
    caoZuoName = new QComboBox(this);
    yaZhuangData = new QDateEdit(this);

}
