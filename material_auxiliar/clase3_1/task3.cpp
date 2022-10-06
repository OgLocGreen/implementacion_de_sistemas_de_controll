
#include <QFile>
#include <QTextStream>

// Do with QMake and add in the configfile CONFIG -=qt to -> CONFIG +=qt



int main()
{
    float temp_now = 1;
    int n = 0;
    // config Path for Configfile
    //QFile fconfig("C:\\Users\\user\\Desktop\\config.txt");  //windows
    QFile fconfig("onfig.txt");    //linux
    QFile fdataout("data.txt")

    if(fconfig.open(QIODevice::ReadOnly))
    {
        QTextStream all_xml = fconfig.readAll();
        // num = XmlGetInt(all_xml,"Num")
        // o 
        QStingList lines = all_xml.splitt("\n");        //LF = 3 = "\r"
                                                        //CR = 10 = "\n"
                                                        // lines[j]trim() Unterscheide rausfinden
                                                        // lines[j].timmed()

        n = lines.count();

        if(fdataout.open(QIODevice::WriteOnly))
        {
            fdataout.write(all_xml.left(40).toLatin1())
        }

    }

    // Autopilot
    if(fconfig.open(QIODevice::ReadOnly))
    {
        QTextStream in(&fconfig);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            // do something with line
        }
        fconfig.close();


    }
    else
    {
        // error
    }


}


    /components/QuartusLiteSetup-17.0.0.595-linux.run \
  --mode unattended \
  --unattendedmodeui none \
  --installdir $INSTALLDIR \
  --disable-components quartus_help,modelsim_ase,modelsim_ae \
  --accept_eula 1