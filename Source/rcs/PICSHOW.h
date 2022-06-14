head	1.2;
access;
symbols;
locks
	Administrator:1.2; strict;
comment	@ * @;


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


1.2
log
@added revision and log fields
@
text
@//---------------------------------------------------------------------------

#ifndef PICSHOWH
#define PICSHOWH
//---------------------------------------------------------------------------

/*
	$Revision$

	$Log$
*/

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TFileListBox *FileListBox1;
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
@


1.1
log
@Initial revision
@
text
@d6 7
@
