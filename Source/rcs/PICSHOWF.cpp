head	1.3;
access;
symbols;
locks
	Administrator:1.3; strict;
comment	@// @;


1.3
date	2003.11.23.08.34.29;	author Administrator;	state Exp;
branches;
next	1.2;

1.2
date	2003.04.30.23.21.49;	author Administrator;	state Exp;
branches;
next	1.1;

1.1
date	2003.04.30.23.18.19;	author Administrator;	state Exp;
branches;
next	;


desc
@form for program
@


1.3
log
@*** empty log message ***
@
text
@//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PICSHOWF.h"
#include "about.h"
//---------------------------------------------------------------------------

/*
	$Revision: 1.2 $

	$Log: PICSHOWF.cpp $
	Revision 1.2  2003/04/30 23:21:49  Administrator
	added revision and log fields

*/

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
        TIniFile *ini;
        ini = new TIniFile("METCAL.INI");
        pictureDir = ini->ReadString( "startup", "picdir", "C:\\METCAL\\PIC" );
        PictureList->Mask = ini->ReadString( "picshow", "filefilter","*.bmp;*.jpg;*.wmf");
        delete ini;
        ClipboardNotice->Caption="";
        PictureList->Directory=pictureDir;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PictureListChange(TObject *Sender)
{
        // send the formatted pic list to the clipboard 
        // and update clipboardNotice
        AnsiString pic = ChangeFileExt(ExtractFileName(PictureList->FileName),"");
        AnsiString ext=ExtractFileExt(PictureList->FileName);
        if(pic.Length()==0)return;
        Clipboard()->SetTextBuf(("         PIC          "+pic).c_str());
        // create a holder, load from file and display
        T = new TPicture;         
        System::TMetaClass* vmt = new System::TMetaClass;
        System::TMetaClass* AGC = new System::TMetaClass;
        T->RegisterFileFormat(vmt, "gif", "Graphic Interchange Format", AGC);
        T->LoadFromFile(PictureList->FileName);
        METCALImg->Picture->Graphic = T->Graphic;
        delete T; T=NULL;
        ClipboardNotice->Caption="\""+pic+"\" is on the Clipboard!";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image2DblClick(TObject *Sender)
{
        AboutBox->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        TIniFile *ini;
        ini = new TIniFile("METCAL.INI");
        ini->WriteString("picshow", "filefilter", PictureList->Mask );
        delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PictureListMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Button!=mbRight)return; //ignore other buttons

        AboutBox->Panel1->Visible=false;
        AboutBox->GroupBox1->Visible=true;
         // get mask and parse on ";", remove *. set/reset
         // check boxes
        for(int i = 0; i<AboutBox->ComponentCount;++i){

        }

        AboutBox->ShowModal();

        AboutBox->Panel1->Visible=true;
        AboutBox->GroupBox1->Visible=false;

}
//---------------------------------------------------------------------------

@


1.2
log
@added revision and log fields
@
text
@d7 1
d11 5
a15 1
	$Revision$
a16 1
	$Log$
a25 2
        picextensions = "*.bmp;*.jpg";
        PictureList->Mask=picextensions;
d33 1
d41 2
a42 2
        // send the formatted pic list to the clipboard and update
        // clipboardNotice
d48 4
a51 1
        TPicture* T = new TPicture;
d54 1
a54 1
        delete T;
d59 36
@


1.1
log
@Initial revision
@
text
@d8 7
@
