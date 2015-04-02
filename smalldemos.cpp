
#include <QtWidgets>
#include <opencv2/opencv.hpp>

int openCVbasicDemo(QApplication *app)
{
    cv::Mat image= cv::imread("D:/IMG_9786.jpg", 1);
    cv::namedWindow("Tulips");
    cv::imshow("Tulips", image);
    cv::waitKey(1000);
    return app->exec();
}

int graphicSceneDemo(QApplication *app){
//    // Create the scene and set its dimensions
//    QGraphicsScene scene;
//    scene.setSceneRect( 0.0, 0.0, 400.0, 400.0 );

//    // create an item that will hold an image
//    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(0);

//    // load an image and set it to the pixmapItem
//    QPixmap pixmap("D:/Uluru.jpg");
//    item->setPixmap(pixmap);

//    // add the item to the scene
//    scene.addItem(item);

//    item->setPos(200,200); // set the item's position in the scene

//    // create a view to look into the scene
//    QGraphicsView view( &scene );
//    view.setRenderHints( QPainter::Antialiasing );
//    view.show();

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap("D:/Uluru.jpg"));
    scene.addItem(&item);
    view.show();
    return app->exec();
}
