//---------------------------------------------------------------------------

#include <vcl.h>
#include <vfw.h>  //Подлючаем библиотеку VFW (Video for Windows)
HWND MyWebCam; //Подключаем дискриптор форточек (окон)
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  MyWebCam=capCreateCaptureWindowA("Name My WEB Cam",WS_CHILD | WS_VISIBLE | WS_CAPTION, 0,0,650,480,Handle,0);
  capDriverConnect (MyWebCam,0); //Подключаемся
  capPreviewRate (MyWebCam,60); //Выставили частоту кадров
  capPreview (MyWebCam,True); //Смотрим
}
//---------------------------------------------------------------------------
