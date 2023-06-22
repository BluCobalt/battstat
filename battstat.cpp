#include <QApplication>
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <string>
#include "battstat.h"
#include <QTimer>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <cmath>

float get_power()
{
    std::string line;
    std::ifstream file( READ_FILE );
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            float fixed = std::stof(line) * READ_MULTIPLIER;
            return fixed;
        }
    }
    return 0.0;
}

float two_digit_round(float value)
{
    return std::round(value * 100) / 100;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTimer timer = QTimer();
    QWidget window;
    QVBoxLayout layout(&window);
    QLabel wattage("0.0w");
    QObject::connect(&timer, &QTimer::timeout, [&wattage]() {
        wattage.setText(QString::fromStdString(std::to_string(two_digit_round(get_power())) + " watts"));
    });
    timer.setInterval( READ_INTERVAL );
    timer.start();
    wattage.setAlignment(Qt::AlignCenter);
    wattage.setStyleSheet("QLabel { font-size: 24px; }");
    layout.addWidget(&wattage);
    layout.setAlignment(Qt::AlignCenter);


    window.setMinimumSize(500, 200);
    window.setWindowTitle("battstat 0.01");
    window.setStyleSheet("QWidget { background-color: black; color: red;}");
    window.show();
    return QApplication::exec();
}
