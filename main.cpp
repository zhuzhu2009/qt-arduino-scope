#include <qapplication.h>
#include "mainwindow.h"
#include "samplingthread.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );
    app.setPalette( Qt::darkGray );

    MainWindow window;
    window.resize( 800, 400 );
   
    SamplingThread samplingThread;
    if(argc==1){
      samplingThread.setPort(QString('/dev/ttyUSB0'));
    }else{
      samplingThread.setPort(argv[1]);
    }
    QObject::connect(&samplingThread, SIGNAL(overload(bool)),
                     &window,  SLOT( swoverloadled(bool ) ));
  //  samplingThread.setFrequency( window.frequency() );
  //  samplingThread.setAmplitude( window.amplitude() );
    samplingThread.setInterval( window.signalInterval() );
   
//    window.connect( &window, SIGNAL( frequencyChanged( double ) ),
//        &samplingThread, SLOT( setFrequency( double ) ) );
    window.connect( &window, SIGNAL( amplitudeChanged( double ) ),
        &samplingThread, SLOT( setAmplitude( double ) ) );
    window.connect( &window, SIGNAL( signalIntervalChanged( double ) ),
        &samplingThread, SLOT( setInterval( double ) ) );

    window.show();
    
    samplingThread.start();
    window.start();

    bool ok = app.exec();
    
    samplingThread.stop();
    samplingThread.wait( 1000 );

    return ok;
}
