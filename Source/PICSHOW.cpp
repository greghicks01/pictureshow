//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("PICSHOW.res");
USEFORM("PICSHOWF.cpp", Form1);
USEFORM("..\Images\Icon\about.cpp", AboutBox);
//---------------------------------------------------------------------------

/*
	$Revision: 1.2 $

	$Log: PICSHOW.cpp $
	Revision 1.2  2003/04/30 23:21:49  Administrator
	added revision and log fields

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
