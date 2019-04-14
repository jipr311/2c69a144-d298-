#include "PasswordLineEdit.h"

PasswordLineEdit::PasswordLineEdit(QWidget *parent):
    QLineEdit(parent)
{
    this->setEchoMode(QLineEdit::Password);
    QAction* actionEyePassword = addAction(QIcon(":/n/eye1.png"), QLineEdit::TrailingPosition);
    button = qobject_cast<QToolButton*>(actionEyePassword->associatedWidgets().last());
    //button->hide();
    button->setCursor(QCursor(Qt::PointingHandCursor));
    connect(button, &QToolButton::pressed, this, &PasswordLineEdit::onEyePicked);
    connect(button, &QToolButton::released, this, &PasswordLineEdit::onReleased);
}

void PasswordLineEdit::onEyePicked(){
    QToolButton *button = qobject_cast<QToolButton *>(sender());
    button->setIcon(QIcon(":/n/eye.png"));
    setEchoMode(QLineEdit::Normal);
}

void PasswordLineEdit::onReleased(){
    QToolButton *button = qobject_cast<QToolButton *>(sender());
    button->setIcon(QIcon(":/n/eye1.png"));
    setEchoMode(QLineEdit::Password);
}

//void PasswordLineEdit::enterEvent(QEvent *event){
//   // button->show();
//    //QLineEdit::enterEvent(event);
//}

//void PasswordLineEdit::leaveEvent(QEvent *event){
//    button->hide();
//    QLineEdit::leaveEvent(event);
//}

//void PasswordLineEdit::focusInEvent(QFocusEvent *event){
//    button->show();
//    QLineEdit::focusInEvent(event);
//}

//void PasswordLineEdit::focusOutEvent(QFocusEvent *event){
//    button->hide();
//    QLineEdit::focusOutEvent(event);
//}
