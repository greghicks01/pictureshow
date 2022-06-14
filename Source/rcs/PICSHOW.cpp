head	1.2;
access;
symbols;
locks
	Administrator:1.2; strict;
comment	@// @;


1.2
date	2003.04.30.23.21.49;	author Administrator;	state Exp;
branches;
next	1.1;

1.1
date	2003.04.30.23.18.19;	author Administrator;	state Exp;
branches;
next	;


desc
@reads bmp and jpg nd creates pic statement in clipboard
@


1.2
log
@added revision and log fields
@
text
@//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("PICSHOW.res");
USEFORM("PICSHOWF.cpp", Form1);
USEFORM("..\Images\Icon\about.cpp", AboutBox);
//---------------------------------------------------------------------------

/*
	$Revision$

	$Log$
*/
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Picture Show";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
@


1.1
log
@Initial revision
@
text
@d9 6
@
