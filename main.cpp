#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "watch.h"
#include <unordered_set>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("Watch Application");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption({{"b", "base"}, "Base value for the watch", "value"});
    parser.process(a);

    std::unordered_set<int> validValues = {2, 3, 4, 5, 6, 8, 10, 12};

    int base = 5; // Default base value
    if (parser.isSet("b")) {
        bool ok;
        base = parser.value("b").toInt(&ok);
        if (!ok || validValues.find(base) == validValues.end()) {
            qDebug() << "Error: Invalid base value! Please provide one of the following values for "
                        "the -b option:";
            for (int value : validValues) {
                qDebug() << value;
            }
            return 1;
        }
    }

    Watch w(nullptr, base);
    w.show();

    return a.exec();
}
