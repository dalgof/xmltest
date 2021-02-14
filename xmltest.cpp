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



	XmlTextReader^ updreader = gcnew XmlTextReader("..\\upd.xml");


	Generic::List<String^>^ EltId = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrNameList = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrValueList = gcnew Generic::List<String^>();
	Generic::List<String^>^ atrList = gcnew Generic::List<String^>();
	Generic::List<String^>^ prteltnameList = gcnew Generic::List<String^>();

	String^ elttmp;
	String^ tagelt;
	String^ eltset;
	int idxcount = 0;



	while (updreader->Read()) {

		atrList->Clear();
		atrNameList->Clear();
		atrValueList->Clear();
		eltset = "";
		prteltnameList->Clear();
		idxcount = 0;

		switch (updreader->NodeType) {

		case  XmlNodeType::Element:
			String^ currentelt;
			currentelt = updreader->Name;


			//属性チェック　属性なし
			if (!updreader->HasAttributes) {
				sw->WriteLine("タグ：{0}", currentelt);
				sw->Flush();
			}
			//属性あり
			else {
				while (updreader->MoveToNextAttribute())
				{



					atrNameList->Add(updreader->Name);
					atrValueList->Add(updreader->Value);
					sw->WriteLine("MoveToNextAttributeしたよ。");
					sw->Flush();

					atrList->Add(elttmp->Format("[@{0}='{1}']", atrNameList[idxcount], atrValueList[idxcount]));

					//tagelt= tagelt->Format("{0}{1}", eltname, atrList[idxcount]);
					//sw->WriteLine(tagelt);
					//sw->Flush();

					eltset += atrList[idxcount];
					idxcount++;



				};


				//for (int i = 0; i < prteltnameList->Count; i++) {
				//	sw->WriteLine("親：{0}", prteltnameList[i]);

				//}
				XmlNodeList^ list = upddoc->GetElementsByTagName(currentelt);
				for each (XmlNode ^ node in list) {
					String^ tmp = node->ParentNode->Name;
					sw->WriteLine("親：{0}", tmp);
					sw->Flush();
					//XmlNodeList^ grandprt = upddoc->GetElementsByTagName(node->ParentNode->Name);
					XmlNode^ tmp2=upddoc->GetElementById(tmp);

					sw->WriteLine("test:{0}", tmp2->ParentNode);
					sw->Flush();

				}


				sw->WriteLine("属性：{0}", eltset);
				sw->WriteLine("タグ・属性:{0}{1}", currentelt, eltset);
				sw->Flush();

			};

		}
	};

}




