//process management
#include <eikenv.h>

//popups
#include <AknGlobalNote.h>
#include <avkon.mbg>

//UI:
#include <coemain.h>
LOCAL_C void ExeMainL()
{
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
        TInt id = note->ShowNoteL(EAknGlobalPermanentNote, _L("Error.\nThis app is designed to close WhatsApp. WhatsApp isn't installed or running on your device."));
        User::After(4500000);
        note->CancelNoteL(id);
        CleanupStack::PopAndDestroy(note);
    }
    else
    {
        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        note->SetGraphic(16584,16585);
        TInt id = note->ShowNoteL(EAknGlobalPermanentNote, _L("Success.\nClosed WhatsApp."));

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
            User::LeaveIfError(ph3.Open(find3));
            ph3.Kill(KErrNone);
            ph3.Close();
        }

        User::After(2000000);
        note->CancelNoteL(id);
        CleanupStack::PopAndDestroy(note);
    }
}

TInt E32Main()
{
    CCoeEnv* coe = new CCoeEnv;
    TRAPD(err, coe->ConstructL());
    TRAPD(error, ExeMainL());
    coe->DestroyEnvironment();
    return 0;
}

