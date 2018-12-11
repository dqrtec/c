#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "camera.h"
#include "cena.h"

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int Xcanvas;
    int Ycanvas;
    Cena cena;
    Camera *camera;
    ~MainWindow();
    void criaCenario();
    void plotar();

private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent* e);
};

void normalizeColor(Color &color);
Vetor3D reflects(Vetor3D raio, Vetor3D norm);
void montarCenario(Cena* scene);
void posicionarLuz(Cena* cenario);
void posicionarCamera(Camera* camera);
void corObjetoComLuz(Color *color,Luz luzSelecionada,Vetor3D L,Material materialInterseptado,Intersection intersect,Ray ray);

#endif // MAINWINDOW_H
