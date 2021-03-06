#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include "headers/mostrador.h"
#include "headers/poligono.h"


QT_CHARTS_USE_NAMESPACE

Mostrador::Mostrador(){

}

Mostrador::Mostrador(int argc, char *argv[], Poligono poligono, bool enquadrar){
    //! Código adaptado do exemplo 'areachart' do próprio website do Qt.
    //! site: https://doc.qt.io/qt-5.10/qtcharts-areachart-example.html
    //! Caso necessario:
    //! $ sudo apt install libgl1-mesa-dev

    QApplication a(argc, argv);

//![1]
    QLineSeries *series0 = new QLineSeries();
//![1]

//![2]
    //! setar_limites enquadra o poligono para ficar encaixado
    //! na origem
    float x_range, y_range;
    setar_limites(&poligono, &x_range, &y_range, enquadrar);
    for (int i = 0; i < poligono.qtd_pontos; i++)
        *series0 << QPointF(poligono.pontos[i].x(), poligono.pontos[i].y());
//![2]

//![3]
    QAreaSeries *series = new QAreaSeries(series0);
    series->setName("Polígono");
    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);
//![3]

//![4]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Mostrando Polígono");
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, x_range);
    chart->axisY()->setRange(0, y_range);
//![4]

//![5]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![5]

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(600, 600);
    window.show();

    a.exec();


}

void Mostrador::setar_limites(Poligono* poligono, float *a, float *b, bool enquadrar){
    float x_menor, y_menor;
    float x_maior, y_maior;
    float padding = 0.5;

    x_menor = poligono->pontos[0].x();
    y_menor = poligono->pontos[0].y();

    for (int i = 1; i < poligono->qtd_pontos; i++){
        if(poligono->pontos[i].x() < x_menor)
            x_menor = poligono->pontos[i].x();
        if(poligono->pontos[i].y() < y_menor)
            y_menor = poligono->pontos[i].y();

    }

    // Puxa para a origem
    if (enquadrar)
        poligono->transladar(-1*x_menor, -1*y_menor);

    x_maior = poligono->pontos[0].x();
    y_maior = poligono->pontos[0].y();

    for (int i = 0; i < poligono->qtd_pontos; i++){
        if(poligono->pontos[i].x() > x_maior)
            x_maior = poligono->pontos[i].x();
        if(poligono->pontos[i].y() > y_maior)
            y_maior = poligono->pontos[i].y();
    }

    *a = x_maior + padding;
    *b = y_maior + padding;

}
