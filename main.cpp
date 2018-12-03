#include <QtWidgets>

#include "Exemples/00_Table/table.h"

#include "Serie03_Inputs/Radio_01/s03e01.h"
#include "Serie03_Inputs/Radio_02/s03e02.h"
#include "Serie03_Inputs/Radio_03/s03e03.h"
#include "Serie03_Inputs/Radio_04/s03e04.h"

#include "Serie04_Lists/Lists_01/s04e01.h"
#include "Serie04_Lists/Lists_02/s04e02.h"
#include "Serie04_Lists/Lists_03/s04e03.h"
#include "Serie04_Lists/Lists_04/s04e04.h"

#include "Serie05_WrapUp/WrapUp_01_Convert/convert.h"
#include "Serie05_WrapUp/WrapUp_02_Chrono/chrono.h"

#include "Serie06_Paint/Paint_01/s06e01.h"
#include "Serie06_Paint/Paint_02/s06e02.h"
#include "Serie06_Paint/Paint_03/s06e03.h"

#include "Serie07_GraphicsView/GraphicsV_01/s07e01.h"
#include "Serie07_GraphicsView/GraphicsV_02/s07e02.h"

#include "Serie09_Coords/Coords_01/s09e01.h"

int main(int argc,char *argv[]) {
    QApplication app(argc,argv);

//    Table w;

//    S03E01 w;
//    S03E02 w;
//    S03E03 w;
//    S03E04 w;

//    S04E01 w;
//    S04E02 w;
//    S04E03 w;
//    S04E04 w;

//    Convert w;
//    Chrono w;

//    S06E01 w;
//    S06E02 w;
//    S06E03 w;

//    S07E01 w;
//    S07E02 w;

    S09E01 w;

    w.show();

    return app.exec();
}
