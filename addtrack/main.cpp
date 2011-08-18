#include <QApplication>
#include <QStringList>
#include <QTextStream>
#include <QRegExp>
#include <QDebug>
#include <QFile>

int main(int argc, char** argv)
{
    //get the arguments
    if(argc==1)
    {
        qDebug()<<"usage: find *.cpp | xargs addtrack\n or: addtrack yoursource.cpp\n";
        return 0;
    }
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //open each file and process
    for(int i=1;i<argc;i++)
    {
        //open and prepare text stream
        QString fn(argv[i]);
        QFile fin(fn);
        if(!fin.open(QIODevice::ReadOnly|QIODevice::Text))
            continue;
        QTextStream fsin(&fin);
        int lineCount=0, foundCount=0;
        QString contents="", original="";
        while(!fsin.atEnd())
        {
            //process each line
            QString line=fsin.readLine();
            original+=line+"\n";
            contents+=line+"\n";
            QRegExp rx("^([\\w|<|>|*|:]* )*[\\*]*[\\w|<|>|:]*::[\\w|~]*\\(.*\\)( const)?[\\s+]?$");
            if(rx.indexIn(line)==0)//it is a function line
            {
                //output the filename/functionname
                cout<<fn<<"/"<<line<<"\n";
                foundCount++;
                //insert debug line to the start of the function
                QString nextline=fsin.readLine();
                original+=nextline+"\n";
                contents+=nextline+"\n";
                if(nextline=="{")
                    contents+="qDebug()<<\"TrCall%\"<<Q_FUNC_INFO;\n";
                else//sometimes there is a trialing line before the function body
                {
                    nextline=fsin.readLine();
                    contents+=nextline+"\n";
                    original+=nextline+"\n";
                    contents+="qDebug()<<\"TrCall%\"<<Q_FUNC_INFO;\n";
                }
            }
            lineCount++;
        }
        qDebug()<<"Total lines: "<<lineCount;
        qDebug()<<"Functions: "<<foundCount;
        fin.close();
        //copy the current file to backup
        QFile fout(fn+".bak");
        if(!fout.open(QIODevice::WriteOnly|QIODevice::Text))
            continue;
        QTextStream fsbak(&fout);
        fsbak<<original;
        fout.close();
        //write to current file
        QFile fchg(fn);
        if(!fchg.open(QIODevice::WriteOnly|QIODevice::Text))
            continue;
        QTextStream fschg(&fchg);
        fschg<<contents;
        fchg.close();
    }
    return 0;
}
