/********************************************************************************
** Form generated from reading UI file 'ClientUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTUI_H
#define UI_CLIENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientUIClass
{
public:
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *serverIPLabel;
    QLabel *clientName;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *listWidget;
    QHBoxLayout *horizontalLayout_6;
    QFontComboBox *fontCbx;
    QComboBox *sizeCbx;
    QToolButton *boldTBtn;
    QToolButton *italicTBtn;
    QToolButton *underlineTBtn;
    QToolButton *colorTBtn;
    QToolButton *sendFileTBtn;
    QTextEdit *sendLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendBtn;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *onlineNumber;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ClientUIClass)
    {
        if (ClientUIClass->objectName().isEmpty())
            ClientUIClass->setObjectName(QStringLiteral("ClientUIClass"));
        ClientUIClass->resize(955, 580);
        horizontalLayout_8 = new QHBoxLayout(ClientUIClass);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        serverIPLabel = new QLabel(ClientUIClass);
        serverIPLabel->setObjectName(QStringLiteral("serverIPLabel"));
        QFont font;
        font.setPointSize(11);
        serverIPLabel->setFont(font);

        horizontalLayout_3->addWidget(serverIPLabel);

        clientName = new QLabel(ClientUIClass);
        clientName->setObjectName(QStringLiteral("clientName"));
        clientName->setMinimumSize(QSize(100, 0));
        clientName->setFont(font);
        clientName->setFrameShape(QFrame::WinPanel);
        clientName->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(clientName);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        horizontalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        listWidget = new QTextBrowser(ClientUIClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        listWidget->setFont(font1);

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        fontCbx = new QFontComboBox(ClientUIClass);
        fontCbx->setObjectName(QStringLiteral("fontCbx"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontCbx->sizePolicy().hasHeightForWidth());
        fontCbx->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(fontCbx);

        sizeCbx = new QComboBox(ClientUIClass);
        sizeCbx->setObjectName(QStringLiteral("sizeCbx"));
        sizePolicy1.setHeightForWidth(sizeCbx->sizePolicy().hasHeightForWidth());
        sizeCbx->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(sizeCbx);

        boldTBtn = new QToolButton(ClientUIClass);
        boldTBtn->setObjectName(QStringLiteral("boldTBtn"));
        boldTBtn->setMinimumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ClientUI/Resources/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldTBtn->setIcon(icon);
        boldTBtn->setIconSize(QSize(26, 26));
        boldTBtn->setCheckable(true);
        boldTBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(boldTBtn);

        italicTBtn = new QToolButton(ClientUIClass);
        italicTBtn->setObjectName(QStringLiteral("italicTBtn"));
        italicTBtn->setMinimumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ClientUI/Resources/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicTBtn->setIcon(icon1);
        italicTBtn->setIconSize(QSize(26, 26));
        italicTBtn->setCheckable(true);
        italicTBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(italicTBtn);

        underlineTBtn = new QToolButton(ClientUIClass);
        underlineTBtn->setObjectName(QStringLiteral("underlineTBtn"));
        underlineTBtn->setMinimumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ClientUI/Resources/underlined.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTBtn->setIcon(icon2);
        underlineTBtn->setIconSize(QSize(26, 26));
        underlineTBtn->setCheckable(true);
        underlineTBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(underlineTBtn);

        colorTBtn = new QToolButton(ClientUIClass);
        colorTBtn->setObjectName(QStringLiteral("colorTBtn"));
        colorTBtn->setMinimumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ClientUI/Resources/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorTBtn->setIcon(icon3);
        colorTBtn->setIconSize(QSize(26, 26));
        colorTBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(colorTBtn);

        sendFileTBtn = new QToolButton(ClientUIClass);
        sendFileTBtn->setObjectName(QStringLiteral("sendFileTBtn"));
        sendFileTBtn->setMinimumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ClientUI/Resources/Send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendFileTBtn->setIcon(icon4);
        sendFileTBtn->setIconSize(QSize(26, 26));
        sendFileTBtn->setAutoRaise(true);

        horizontalLayout_6->addWidget(sendFileTBtn);


        verticalLayout_2->addLayout(horizontalLayout_6);

        sendLineEdit = new QTextEdit(ClientUIClass);
        sendLineEdit->setObjectName(QStringLiteral("sendLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(sendLineEdit->sizePolicy().hasHeightForWidth());
        sendLineEdit->setSizePolicy(sizePolicy2);
        sendLineEdit->setFont(font1);

        verticalLayout_2->addWidget(sendLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendBtn = new QPushButton(ClientUIClass);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setCheckable(false);

        horizontalLayout->addWidget(sendBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(ClientUIClass);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_7->addWidget(label);

        onlineNumber = new QLabel(ClientUIClass);
        onlineNumber->setObjectName(QStringLiteral("onlineNumber"));
        onlineNumber->setFont(font1);
        onlineNumber->setFrameShape(QFrame::NoFrame);

        horizontalLayout_7->addWidget(onlineNumber);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tableWidget = new QTableWidget(ClientUIClass);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setMinimumSize(QSize(311, 525));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(125);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_4);


        retranslateUi(ClientUIClass);

        sizeCbx->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ClientUIClass);
    } // setupUi

    void retranslateUi(QWidget *ClientUIClass)
    {
        ClientUIClass->setWindowTitle(QApplication::translate("ClientUIClass", "Echat", Q_NULLPTR));
        serverIPLabel->setText(QApplication::translate("ClientUIClass", "\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        clientName->setText(QApplication::translate("ClientUIClass", "\346\227\240", Q_NULLPTR));
        listWidget->setHtml(QApplication::translate("ClientUIClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        sizeCbx->clear();
        sizeCbx->insertItems(0, QStringList()
         << QApplication::translate("ClientUIClass", "8", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "9", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "10", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "11", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "12", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "13", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "14", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "15", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "16", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "17", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "18", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "19", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "20", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "21", Q_NULLPTR)
         << QApplication::translate("ClientUIClass", "22", Q_NULLPTR)
        );
        boldTBtn->setText(QString());
        italicTBtn->setText(QString());
        underlineTBtn->setText(QString());
        colorTBtn->setText(QString());
        sendFileTBtn->setText(QString());
        sendBtn->setText(QApplication::translate("ClientUIClass", "\345\217\221\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("ClientUIClass", "\345\275\223\345\211\215\345\234\250\347\272\277\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
        onlineNumber->setText(QApplication::translate("ClientUIClass", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClientUIClass", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClientUIClass", "IP\345\234\260\345\235\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientUIClass: public Ui_ClientUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTUI_H
