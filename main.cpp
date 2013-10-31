#include <QApplication>

#include <apgtask.h>
#include <eikenv.h>


#include <AknGlobalNote.h>
#include <avkon.rsg>
#include <aknappui.h>
#include <avkon.mbg>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TBool running = EFalse;


        TFullName res;
        TFindProcess find;
        while(find.Next(res) == KErrNone)
        {
            RProcess ph;
            User::LeaveIfError( ph.Open(res) );

            if(ph.SecureId() == 0x2002B30D)

            if (ph.ExitType() == EExitPending)
            {
                running = ETrue;
                break;
            }

            ph.Close();
        }


    if (!running)
    {


        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        note->SetGraphic(16572,16573);
        TInt id = note->ShowNoteL(EAknGlobalPermanentNote, _L("Error.\nThis app is designed to close WhatsApp. WhatsApp isn't installed or running on your Device."));
        User::After(4500000);
        note->CancelNoteL(id);
        CleanupStack::PopAndDestroy(note);
    }
    else
    {

        CAknGlobalNote* note1 = CAknGlobalNote::NewLC();
        note1->ShowNoteL(EAknGlobalConfirmationNote,(_L("Success.\nClosed WhatsApp.")));

        TFullName res1;
        TFindProcess find1(_L("*[2002B306]*"));

        while(find1.Next(res1) == KErrNone)
        {
            RProcess ph1;
            User::LeaveIfError( ph1.Open(find1) );
            ph1.Kill(KErrNone);
            ph1.Close();
        }

        TFullName res2;
        TFindProcess find2(_L("*[2002B310]*"));

        while(find2.Next(res2) == KErrNone)
        {
            RProcess ph2;
            User::LeaveIfError(  ph2.Open(find2) );
            ph2.Kill(KErrNone);
            ph2.Close();
        }

        TFullName res3;
        TFindProcess find3(_L("*[2002B30D]*"));

        while(find3.Next(res3) == KErrNone)
        {
            RProcess ph3;
            User::LeaveIfError(  ph3.Open(find3) );
            ph3.Kill(KErrNone);
            ph3.Close();
        }


        User::After(2400000);
        CleanupStack::PopAndDestroy(note1);
    }

    return 1;
}
