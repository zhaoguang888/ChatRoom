/********************************************************************************
** Form generated from reading UI file 'LoginUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QLabel *showLabel;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *accountLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *registerBtn;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *serverIPLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLabel *portLabel;
    QPushButton *btnConnectServer;

    void setupUi(QDialog *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QStringLiteral("LoginUI"));
        LoginUI->resize(494, 367);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginUI->sizePolicy().hasHeightForWidth());
        LoginUI->setSizePolicy(sizePolicy);
        LoginUI->setMinimumSize(QSize(0, 0));
        LoginUI->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(LoginUI);
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        minBtn = new QPushButton(LoginUI);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        minBtn->setFont(font);

        horizontalLayout_4->addWidget(minBtn);

        closeBtn = new QPushButton(LoginUI);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMaximumSize(QSize(30, 30));
        closeBtn->setFont(font);

        horizontalLayout_4->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);

        showLabel = new QLabel(LoginUI);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showLabel->sizePolicy().hasHeightForWidth());
        showLabel->setSizePolicy(sizePolicy1);
        showLabel->setMinimumSize(QSize(0, 170));
        QFont font1;
        font1.setPointSize(18);
        showLabel->setFont(font1);
        showLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 0);\n"
""));
        showLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(showLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LoginUI);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        accountLineEdit = new QLineEdit(LoginUI);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));
        accountLineEdit->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setPointSize(14);
        accountLineEdit->setFont(font3);

        horizontalLayout->addWidget(accountLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(LoginUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        passwordLineEdit = new QLineEdit(LoginUI);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(passwordLineEdit->sizePolicy().hasHeightForWidth());
        passwordLineEdit->setSizePolicy(sizePolicy2);
        passwordLineEdit->setFont(font3);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        registerBtn = new QPushButton(LoginUI);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy3);
        registerBtn->setMaximumSize(QSize(16777215, 30));
        QFont font4;
        font4.setPointSize(10);
        registerBtn->setFont(font4);

        horizontalLayout_6->addWidget(registerBtn);

        loginBtn = new QPushButton(LoginUI);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setEnabled(false);
        sizePolicy3.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy3);
        loginBtn->setMinimumSize(QSize(171, 0));
        loginBtn->setMaximumSize(QSize(16777215, 30));
        loginBtn->setFont(font4);

        horizontalLayout_6->addWidget(loginBtn);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(5, 0, 5, -1);
        label_3 = new QLabel(LoginUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMargin(0);

        horizontalLayout_3->addWidget(label_3);

        serverIPLineEdit = new QLineEdit(LoginUI);
        serverIPLineEdit->setObjectName(QStringLiteral("serverIPLineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(serverIPLineEdit->sizePolicy().hasHeightForWidth());
        serverIPLineEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(serverIPLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_4 = new QLabel(LoginUI);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        portLabel = new QLabel(LoginUI);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        sizePolicy2.setHeightForWidth(portLabel->sizePolicy().hasHeightForWidth());
        portLabel->setSizePolicy(sizePolicy2);
        portLabel->setFrameShape(QFrame::Panel);
        portLabel->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(portLabel);

        btnConnectServer = new QPushButton(LoginUI);
        btnConnectServer->setObjectName(QStringLiteral("btnConnectServer"));

        horizontalLayout_3->addWidget(btnConnectServer);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QDialog *LoginUI)
    {
        LoginUI->setWindowTitle(QApplication::translate("LoginUI", "Echat", Q_NULLPTR));
        minBtn->setText(QApplication::translate("LoginUI", "-", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("LoginUI", "X", Q_NULLPTR));
        showLabel->setText(QApplication::translate("LoginUI", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("LoginUI", "\350\264\246\345\217\267", Q_NULLPTR));
        accountLineEdit->setText(QApplication::translate("LoginUI", "100", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginUI", "\345\257\206\347\240\201", Q_NULLPTR));
        passwordLineEdit->setText(QApplication::translate("LoginUI", "abc", Q_NULLPTR));
        registerBtn->setText(QApplication::translate("LoginUI", "\346\263\250\345\206\214", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("LoginUI", "\347\231\273\345\275\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginUI", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        serverIPLineEdit->setText(QApplication::translate("LoginUI", "127.0.0.1", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoginUI", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        portLabel->setText(QString());
        btnConnectServer->setText(QApplication::translate("LoginUI", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
