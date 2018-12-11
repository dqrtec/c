#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QKeyEvent>
#include "esfera.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    Xcanvas = 500;//tamanho da tela,
    Ycanvas = 500;
    ui->setupUi(this);
    criaCenario();//posiciona luz , camera e objetos no
    plotar();//plota cenario na interface grafica
}

MainWindow::~MainWindow() {delete ui;}

void MainWindow::keyPressEvent(QKeyEvent* e){
    if(e->key()==Qt::Key_A){
            Ponto p = camera->capturaPosicao();
            p = Ponto{-10,10,10};
            camera->setposicaoCamera(p);
            //criaCenario();

            QGraphicsScene * graphic = new QGraphicsScene( this );
            graphic->clear();
            ui->graphicsView->close();
            ui->graphicsView->setScene(graphic);

            plotar();
        }
        if(e->key()==Qt::Key_W){
            Ponto p = camera->capturaPosicao();
            p = Ponto{10,10,10};
            camera->setposicaoCamera(p);
            //criaCenario();

            QGraphicsScene * graphic = new QGraphicsScene( this );
            graphic->clear();
            ui->graphicsView->close();
            ui->graphicsView->setScene(graphic);

            plotar();
        }
        if(e->key()==Qt::Key_D){
            Ponto p = camera->capturaPosicao();
            p = Ponto{10,10,-10};
            camera->setposicaoCamera(p);
            //criaCenario();

            QGraphicsScene * graphic = new QGraphicsScene( this );
            graphic->clear();
            ui->graphicsView->close();
            ui->graphicsView->setScene(graphic);

            plotar();
        }
        if(e->key()==Qt::Key_S){
            Ponto p = camera->capturaPosicao();
            p = Ponto{-10,10,-10};
            camera->setposicaoCamera(p);
            //criaCenario();

            QGraphicsScene * graphic = new QGraphicsScene( this );
            graphic->clear();
            ui->graphicsView->close();
            ui->graphicsView->setScene(graphic);

            plotar();
        }
}

void MainWindow::criaCenario(){
    montarCenario(&cena);
    posicionarLuz(&cena);
    camera = new Camera(Xcanvas, Ycanvas);//cria camera que ira gerar X * Y raios
    posicionarCamera(camera);
}

void MainWindow::plotar(){
    QImage image;

    //COLOCA TUDO EM UMA ESPECIE DE CUBMAPING = finge que tudo ta dentro de um quadrado e cada lado tem um plano de fundo
    if(camera->posicaoCamera.x >=0 && camera->posicaoCamera.y >=0 && camera->posicaoCamera.z >=0 ){
        image = QImage("/home/zzzmata/Downloads/iceflats_ft.jpg");
    }else if(camera->posicaoCamera.x <0 && camera->posicaoCamera.y >=0 && camera->posicaoCamera.z >=0 ) {
        image = QImage("/home/zzzmata/Downloads/iceflats_rt.jpg");
    }else if(camera->posicaoCamera.x >= 0 && camera->posicaoCamera.y >=0 && camera->posicaoCamera.z < 0 ){
        image = QImage("/home/zzzmata/Downloads/iceflats_lf.jpg");
    }else{
        image = QImage("/home/zzzmata/Downloads/iceflats_bk.jpg");
    }
    //image = QImage( Xcanvas, Ycanvas, QImage::Format_RGB32 );


    for( int linhaPixel=0; linhaPixel<Xcanvas; linhaPixel++ ){//percorre linhas
        for( int colunaPixel=0; colunaPixel<Ycanvas; colunaPixel++ ){//percorre colunas
            Ray ray = camera->criarRay(linhaPixel, colunaPixel);//cria raio de acordo com a linha e coluna

            Intersection intersect;//armazenar atributos do objeto que sera interseptado
            if(cena.intersecao(ray, intersect))//verifica se algum objeto foi interseptado, se sim coloca as informacoes em intersect
            {
                Color color;
                Material materialInterseptado = intersect.material;//material que foi atingido

                color.r = materialInterseptado.ambient.r * materialInterseptado.Ka;
                color.g = materialInterseptado.ambient.g * materialInterseptado.Ka;
                color.b = materialInterseptado.ambient.b * materialInterseptado.Ka;

                for(int indiceLuz=0; indiceLuz < cena.luzes.size(); indiceLuz++){
                    Luz luzSelecionada = cena.luzes[indiceLuz];
                    Vetor3D L = luzSelecionada.posicao - intersect.point;// raio que vai da do ponto atingido ate a luz
                    L.normalizar();// a cor tem que ser 0<cor<1 se a cor for maior ela será mudada para 1
                    corObjetoComLuz(&color,luzSelecionada,L,materialInterseptado,intersect,ray);//aplica difusa e especular
                }

                normalizeColor(color);// a cor tem que ser 0<cor<1 se a cor for maior ela será mudada para 1
                image.setPixel( linhaPixel, colunaPixel, qRgb( color.r*255, color.g*255, color.b*255) );//plota o pixel com a cor do objeto depois de todos os calculos
            }
        }
    }

    QGraphicsScene * graphic = new QGraphicsScene;
    graphic->addPixmap( QPixmap::fromImage( image ) );
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->show();
}

Vetor3D reflects(Vetor3D raio, Vetor3D norm){
    raio.x *= -1.0;
    raio.y *= -1.0;
    raio.z *= -1.0;
    Vetor3D reflect = raio - ( norm * (2.0 * ProdEsc(raio,norm) ) );// formula para ver reflexao
    reflect.normalizar();
    return reflect;
}

void normalizeColor(Color &color){
    if( color.r > 1.0 )color.r = 1.0;
    if( color.g > 1.0 )color.g = 1.0;
    if( color.b > 1.0 )color.b = 1.0;
}

void montarCenario(Cena* cenario){
    Material amarelo(
                Color{0.1, 0.1, 0.08},
                Color{0.9, 0.5, 0.1},
                Color{1.0, 1.0, 1.0},
                4, 1.0, 1.0, 1.0 );

    Material laranja(
                Color{0.2, 0.15, 0.0},
                Color{1, 0.5, 0},
                Color{0.2, 0.2, 0.2},
                200, 1.0, 1.0, 0.5 );

    Material vermelho(
                Color{0.1, 0.0, 0.0},
                Color{1.0, 0.3, 0.3},
                Color{0.8, 0.3, 0.3},
                200, 1.0, 1.0, 0.5 );

    Material branco(
                Color{0.2, 0.2, 0.2},
                Color{1.0, 1.0, 1.0},
                Color{1.0, 1.0, 1.0},
                200, 1.0, 1.0, 0.05 );

    Material preto(
                Color{0.0, 0.0, 0.0},
                Color{0.0, 0.0, 0.0},
                Color{0.0, 0.0, 0.0},
                200, 1.0, 1.0, 0.05 );

    cenario->adEsfera( Ponto{0,0,0}, 4, vermelho );// adiciona uma esfera na lista de objetos que compoem o cenario
    cenario->adEsfera( Ponto{0,5,0}, 2, branco );

    cenario->adEsfera( Ponto{0,6.2,2.3}, 0.2, vermelho );
    cenario->adEsfera( Ponto{1,6.2,2.3}, 0.2, preto );
}

void posicionarLuz(Cena* cenario){
    cenario->adLuz(Ponto{5, 10, 15}, 1.0, 1.0, 1.0);// adiciona luz na lista de luz do cenario
}

void posicionarCamera(Camera* camera){
    camera->setposicaoCamera( Ponto{10, 10, 10} );//define camera
    camera->lookAt( Ponto{0, 2, 0} );// define lookat
}

void corObjetoComLuz(Color* color,Luz luzSelecionada,Vetor3D L,Material materialInterseptado,Intersection intersect,Ray ray){
    //    SIMPLISMENTE NAO SEI EXPLICAR
    double fator_dif = ProdEsc(intersect.norm, L);
    if( fator_dif <= 0.01  ) fator_dif = 0.0;

    color->r += luzSelecionada.cor.r * fator_dif* materialInterseptado.diffuse.r *materialInterseptado.Kd;
    color->g += luzSelecionada.cor.g * fator_dif*materialInterseptado.diffuse.g*materialInterseptado.Kd;
    color->b += luzSelecionada.cor.b * fator_dif*materialInterseptado.diffuse.b*materialInterseptado.Kd;

    Vetor3D reflexao = reflects(L,intersect.norm);
    double fator_esp = ProdEsc( ray.ray(), reflexao );
    if( fator_esp <= 0.01  ) fator_esp = 0.0;

    color->r += luzSelecionada.cor.r * pow(fator_esp, materialInterseptado.k)*materialInterseptado.specular.r*materialInterseptado.Ks;
    color->g += luzSelecionada.cor.g * pow(fator_esp, materialInterseptado.k)*materialInterseptado.specular.g*materialInterseptado.Ks;
    color->b += luzSelecionada.cor.b * pow(fator_esp, materialInterseptado.k)*materialInterseptado.specular.b*materialInterseptado.Ks;
}
