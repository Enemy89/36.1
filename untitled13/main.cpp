#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

class ColorChangingCircle : public QWidget {
Q_OBJECT
public:
    ColorChangingCircle(QWidget *parent = nullptr);
    void updateColor(int value);

private:
    QLabel *circleLabel;
    QPixmap greenPixmap;
    QPixmap yellowPixmap;
    QPixmap redPixmap;
};

ColorChangingCircle::ColorChangingCircle(QWidget *parent)
        : QWidget(parent) {
    setFixedSize(100, 100);

    greenPixmap.load("../green.png");
    yellowPixmap.load("../yellow.png");
    redPixmap.load("../red.png");

    circleLabel = new QLabel(this);
    circleLabel->setPixmap(greenPixmap);
    circleLabel->setAlignment(Qt::AlignCenter);
}

void ColorChangingCircle::updateColor(int value) {
    if (value >= 0 && value <= 33) {
        circleLabel->setPixmap(greenPixmap);
    } else if (value > 33 && value <= 66) {
        circleLabel->setPixmap(yellowPixmap);
    } else {
        circleLabel->setPixmap(redPixmap);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.resize(300, 200);

    QSlider slider(Qt::Horizontal);
    slider.setMinimum(0);
    slider.setMaximum(100);

    ColorChangingCircle circle;

    QVBoxLayout layout(&window);
    layout.addWidget(&circle, 0, Qt::AlignCenter);
    layout.addWidget(&slider);

    QObject::connect(&slider, &QSlider::valueChanged, &circle, &ColorChangingCircle::updateColor);

    window.show();

    return app.exec();
}

#include "main.moc"
