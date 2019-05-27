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
#include <QtWidgets/QFrame>
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
    QVBoxLayout *verticalLayout_3;
    QLabel *showLabel;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
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
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *serverIPLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLabel *portLabel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QStringLiteral("LoginUI"));
        LoginUI->resize(533, 352);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginUI->sizePolicy().hasHeightForWidth());
        LoginUI->setSizePolicy(sizePolicy);
        LoginUI->setMinimumSize(QSize(0, 0));
        LoginUI->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(LoginUI);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        showLabel = new QLabel(LoginUI);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showLabel->sizePolicy().hasHeightForWidth());
        showLabel->setSizePolicy(sizePolicy1);
        showLabel->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(18);
        showLabel->setFont(font);
        showLabel->setStyleSheet(QStringLiteral(""));
        showLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(showLabel);

        frame_2 = new QFrame(LoginUI);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 150));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 5, -1, 5);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        accountLineEdit = new QLineEdit(frame_2);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));
        accountLineEdit->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setPointSize(14);
        accountLineEdit->setFont(font2);

        horizontalLayout->addWidget(accountLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        passwordLineEdit = new QLineEdit(frame_2);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(passwordLineEdit->sizePolicy().hasHeightForWidth());
        passwordLineEdit->setSizePolicy(sizePolicy2);
        passwordLineEdit->setFont(font2);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        registerBtn = new QPushButton(frame_2);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy3);
        registerBtn->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setPointSize(10);
        registerBtn->setFont(font3);

        horizontalLayout_6->addWidget(registerBtn);

        loginBtn = new QPushButton(frame_2);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setEnabled(true);
        sizePolicy3.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy3);
        loginBtn->setMinimumSize(QSize(171, 0));
        loginBtn->setMaximumSize(QSize(16777215, 30));
        loginBtn->setFont(font3);

        horizontalLayout_6->addWidget(loginBtn);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(frame_2);

        frame = new QFrame(LoginUI);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMargin(0);

        horizontalLayout_3->addWidget(label_3);

        serverIPLineEdit = new QLineEdit(frame);
        serverIPLineEdit->setObjectName(QStringLiteral("serverIPLineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(serverIPLineEdit->sizePolicy().hasHeightForWidth());
        serverIPLineEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(serverIPLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        portLabel = new QLabel(frame);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        sizePolicy2.setHeightForWidth(portLabel->sizePolicy().hasHeightForWidth());
        portLabel->setSizePolicy(sizePolicy2);
        portLabel->setFrameShape(QFrame::Panel);
        portLabel->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(portLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(frame);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QDialog *LoginUI)
    {
        LoginUI->setWindowTitle(QApplication::translate("LoginUI", "ChatRoom", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
