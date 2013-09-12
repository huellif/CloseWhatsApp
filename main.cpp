#include <QApplication>
#include <QTest>

#include <apgtask.h>
#include <eikenv.h>
#include <akndiscreetpopup.h>
#include <aknnotewrappers.h>
int main(int argc, char *argv[])
{
    bool running = false;


        TFullName res;
        TFindProcess find;
        while(find.Next(res) == KErrNone)
        {
            RProcess ph;
            ph.Open(res);

            if(ph.SecureId() == 0x2002B30D)

            if (ph.ExitType() == EExitPending)
            {
                running = true;
                break;
            }

            ph.Close();
        }

    QApplication app(argc, argv);

    if (running == false)
    {
        TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("This app is designed to close WhatsApp.")), (_L("WhatsApp isn't installed or running on your Device.")),KAknsIIDNone, KNullDesC, 0, 0, KAknDiscreetPopupDurationLong));}
    else
    {
        CAknConfirmationNote* run = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(run->ExecuteLD(_L("Closed WhatsApp")));
        TFullName res1;
        TFindProcess find1(_L("*[2002B306]*"));

        while(find1.Next(res1) == KErrNone)
        {
            RProcess ph1;
            ph1.Open(find1);
            ph1.Kill(KErrNone);
            ph1.Close();
        }

        TFullName res2;
        TFindProcess find2(_L("*[2002B310]*"));

        while(find2.Next(res2) == KErrNone)
        {
            RProcess ph2;
            ph2.Open(find2);
            ph2.Kill(KErrNone);
            ph2.Close();
        }

        TFullName res3;
        TFindProcess find3(_L("*[2002B30D]*"));

        while(find3.Next(res3) == KErrNone)
        {
            RProcess ph3;
            ph3.Open(find3);
            ph3.Kill(KErrNone);
            ph3.Close();
        }
    }

    QTest::qWait(1500);

    return 1;
}
