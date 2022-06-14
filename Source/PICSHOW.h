//---------------------------------------------------------------------------

#ifndef PICSHOWH
#define PICSHOWH
//---------------------------------------------------------------------------

/*
	$Revision: 1.2 $

	$Log: PICSHOW.h $
	Revision 1.2  2003/04/30 23:22:13  Administrator
	added revision and log fields

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
