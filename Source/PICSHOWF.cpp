//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PICSHOWF.h"
#include "about.h"
//---------------------------------------------------------------------------

/*
	$Revision: 1.3 $

	$Log: PICSHOWF.cpp $
	Revision 1.3  2003/11/23 08:34:29  Administrator
	*** empty log message ***

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

