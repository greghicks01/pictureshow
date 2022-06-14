head	1.3;
access;
symbols;
locks
	Administrator:1.3; strict;
comment	@ * @;


1.3
date	2003.11.23.08.34.18;	author Administrator;	state Exp;
branches;
next	1.2;

1.2
date	2003.04.30.23.22.13;	author Administrator;	state Exp;
branches;
next	1.1;

1.1
date	2003.04.30.23.19.02;	author Administrator;	state Exp;
branches;
next	;


desc
@header files.
@


1.3
log
@*** empty log message ***
@
text
@//---------------------------------------------------------------------------

#ifndef PICSHOWFH
#define PICSHOWFH
//---------------------------------------------------------------------------

/*
	$Revision: 1.2 $

	$Log: PICSHOWF.h $
	Revision 1.2  2003/04/30 23:22:13  Administrator
	added revision and log fields

*/

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>

#include <Inifiles.hpp>
#include <Clipbrd.hpp>
#include <Graphics.hpp>
#include <Jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *METCALImg;
        TFileListBox *PictureList;
        TImage *Image2;
        TLabel *ClipboardNotice;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall PictureListChange(TObject *Sender);
        void __fastcall Image2DblClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PictureListMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:
        AnsiString pictureDir;	// User declarations
        AnsiString picextensions;
        TPicture* T;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
@


1.2
log
@added revision and log fields
@
text
@d8 5
a12 1
	$Revision$
a13 1
	$Log$
d37 4
d44 1
@


1.1
log
@Initial revision
@
text
@d6 7
@
