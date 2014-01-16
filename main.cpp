#include <AknGlobalNote.h>

LOCAL_C TBool running()
{
    TBool ret = EFalse;
    TFullName res;
    TFindProcess find;
    while(find.Next(res) == KErrNone)
    {
        RProcess ph;
        User::LeaveIfError(ph.Open(res));
        if(ph.SecureId() == 537047821)
            if (ph.ExitType() == EExitPending)
            {
                ret = ETrue;
                break;
            }
        ph.Close();
    }
    return ret;
}

LOCAL_C void kill(const TDesC &process)
{
    TFullName res;
    TFindProcess find(process);
    while(find.Next(res) == KErrNone)
    {
        RProcess ph;
        User::LeaveIfError(ph.Open(find));
        ph.Kill(KErrNone);
        ph.Close();
    }
}

LOCAL_C void ExeMainL()
{
    if (!running())
    {
        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        TRequestStatus iStatus;
        note->ShowNoteL(iStatus, EAknGlobalErrorNote, _L("Error.\nThis app is designed to close WhatsApp. WhatsApp isn't installed or running on your device."));
        User::WaitForRequest(iStatus);
        CleanupStack::PopAndDestroy(note);
    }
    else
    {
        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        TRequestStatus iStatus;
        note->ShowNoteL(iStatus, EAknGlobalConfirmationNote, _L("Success.\nClosed WhatsApp."));


        kill(_L("*[2002B306]*"));
        kill(_L("*[2002B310]*"));
        kill(_L("*[2002B30D]*"));

        User::WaitForRequest(iStatus);
        CleanupStack::PopAndDestroy(note);
    }
}

TInt E32Main()
{
    CTrapCleanup* cl=CTrapCleanup::New();
    TRAPD(error, ExeMainL());
    delete cl;
    return 0;
}

