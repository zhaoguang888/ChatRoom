/********************************************************************************
** Form generated from reading UI file 'RegisterUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUI_H
#define UI_REGISTERUI_H

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

class Ui_RegisterUI
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_R;
    QLineEdit *password_R;
    QLineEdit *passwordSure_R;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_OK;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_5;
    QLineEdit *serverIP;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *RegisterUI)
    {
        if (RegisterUI->objectName().isEmpty())
            RegisterUI->setObjectName(QStringLiteral("RegisterUI"));
        RegisterUI->resize(414, 270);
        RegisterUI->setMinimumSize(QSize(389, 230));
        verticalLayout_4 = new QVBoxLayout(RegisterUI);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(RegisterUI);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 70));
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(RegisterUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label = new QLabel(RegisterUI);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(RegisterUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMargin(0);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        name_R = new QLineEdit(RegisterUI);
        name_R->setObjectName(QStringLiteral("name_R"));

        verticalLayout_2->addWidget(name_R);

        password_R = new QLineEdit(RegisterUI);
        password_R->setObjectName(QStringLiteral("password_R"));

        verticalLayout_2->addWidget(password_R);

        passwordSure_R = new QLineEdit(RegisterUI);
        passwordSure_R->setObjectName(QStringLiteral("passwordSure_R"));
        passwordSure_R->setSizeIncrement(QSize(0, 0));

        verticalLayout_2->addWidget(passwordSure_R);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btn_Cancel = new QPushButton(RegisterUI);
        btn_Cancel->setObjectName(QStringLiteral("btn_Cancel"));
        btn_Cancel->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(btn_Cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_OK = new QPushButton(RegisterUI);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));

        horizontalLayout_3->addWidget(btn_OK);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        label_5 = new QLabel(RegisterUI);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        serverIP = new QLineEdit(RegisterUI);
        serverIP->setObjectName(QStringLiteral("serverIP"));

        horizontalLayout_4->addWidget(serverIP);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(RegisterUI);

        QMetaObject::connectSlotsByName(RegisterUI);
    } // setupUi

    void retranslateUi(QDialog *RegisterUI)
    {
        RegisterUI->setWindowTitle(QApplication::translate("RegisterUI", "RegisterUI", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterUI", "\346\263\250\345\206\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterUI", "\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterUI", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterUI", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btn_Cancel->setText(QApplication::translate("RegisterUI", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_OK->setText(QApplication::translate("RegisterUI", "\347\241\256\345\256\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("RegisterUI", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        serverIP->setText(QApplication::translate("RegisterUI", "127.0.0.1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterUI: public Ui_RegisterUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUI_H
