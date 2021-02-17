#include "pch.h"

using namespace System;
using namespace System::Xml;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections;
using namespace std;

#include <vector>
#include <cliext/vector>




void main()
{
	StreamWriter^ sw = gcnew StreamWriter("test.txt");

	XmlDocument^ orgdoc = gcnew XmlDocument();
	orgdoc->Load("..\\org.xml");
	XmlDocument^ upddoc = gcnew XmlDocument();
	upddoc->Load("..\\upd.xml");

	XmlElement^ root = orgdoc->DocumentElement;



	XmlTextReader^ updreader = gcnew XmlTextReader("..\\upd.xml");

	XmlReaderSettings^ settings = gcnew XmlReaderSettings();
	settings->IgnoreWhitespace = true;
	settings->IgnoreComments = true;

	StreamReader^ updsr = gcnew StreamReader("..\\upd.xml");

	XmlReader^ UpdReader;
	UpdReader = UpdReader->Create(updsr, settings);


	Generic::List<String^>^ EltId = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrNameList = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrValueList = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrList = gcnew Generic::List<String^>();
	Generic::List<String^>^ prteltnameList = gcnew Generic::List<String^>();

	String^ elttmp;
	String^ tagelt;
	String^ eltset;
	int idxcount = 0;

	//
	Generic::List<String^>^ eltlist = gcnew Generic::List<String^>();
	String^ updxpath;


	while (UpdReader->Read()) {


		atrList->Clear();
		atrNameList->Clear();
		atrValueList->Clear();
		eltset = "";
		prteltnameList->Clear();
		idxcount = 0;
		updxpath = "";


		switch (UpdReader->NodeType) {
		case XmlNodeType::Element:
		{

			//XmlNode^ node = upddoc->ReadNode(UpdReader);

			upddoc->FirstChild;

		}
		case XmlNodeType::Text:
		{
			String^ currentnood;
			//現在位置のテキストがあるノードの取得できる-->
			UpdReader->ReadInnerXml();
			currentnood = UpdReader->Name;

			//<--
		}







	//		for (int i = 0; i < eltlist->Count; i++) {
	//			updxpath = String::Join("/", eltlist);
	//		}
	//		updxpath = "//" + updxpath;

	//		XmlNode^ book;
	//		try{
	//		book = root->SelectSingleNode(updxpath);
	//		if (book) {
	//			if (book->InnerText != updreader->Value) {
	//				sw->WriteLine(book->InnerText);
	//				sw->WriteLine(updreader->Value);
	//				sw->Flush();
	//			}
	//		}
	//		}
	//		catch (...) {
	//			sw->WriteLine("例外");
	//			sw->Flush();
	//		}

		}
	};

}




