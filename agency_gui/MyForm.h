#pragma once

#include "concerts.h"
#include <msclr/marshal_cppstd.h>

namespace agency20 {

	concerts_list list_1;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  show_list_box;
	private: System::Windows::Forms::OpenFileDialog^  open_file_dialog;
	private: System::Windows::Forms::Button^  browse_file;
	private: System::Windows::Forms::Button^  sort_by_date;
	private: System::Windows::Forms::Button^  sort_by_name;
	protected:

	protected:




	protected:



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->show_list_box = (gcnew System::Windows::Forms::TextBox());
			this->open_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->browse_file = (gcnew System::Windows::Forms::Button());
			this->sort_by_date = (gcnew System::Windows::Forms::Button());
			this->sort_by_name = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// show_list_box
			// 
			this->show_list_box->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_list_box->Location = System::Drawing::Point(12, 219);
			this->show_list_box->Multiline = true;
			this->show_list_box->Name = L"show_list_box";
			this->show_list_box->ReadOnly = true;
			this->show_list_box->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->show_list_box->Size = System::Drawing::Size(460, 146);
			this->show_list_box->TabIndex = 0;
			// 
			// open_file_dialog
			// 
			this->open_file_dialog->FileName = L"openFileDialog1";
			// 
			// browse_file
			// 
			this->browse_file->Location = System::Drawing::Point(396, 174);
			this->browse_file->Name = L"browse_file";
			this->browse_file->Size = System::Drawing::Size(76, 39);
			this->browse_file->TabIndex = 1;
			this->browse_file->Text = L"Browse the file";
			this->browse_file->UseVisualStyleBackColor = true;
			this->browse_file->Click += gcnew System::EventHandler(this, &MyForm::browse_file_Click);
			// 
			// sort_by_date
			// 
			this->sort_by_date->Location = System::Drawing::Point(26, 13);
			this->sort_by_date->Name = L"sort_by_date";
			this->sort_by_date->Size = System::Drawing::Size(83, 45);
			this->sort_by_date->TabIndex = 2;
			this->sort_by_date->Text = L"Sort by date";
			this->sort_by_date->UseVisualStyleBackColor = true;
			this->sort_by_date->Click += gcnew System::EventHandler(this, &MyForm::sort_by_date_Click);
			// 
			// sort_by_name
			// 
			this->sort_by_name->Location = System::Drawing::Point(26, 64);
			this->sort_by_name->Name = L"sort_by_name";
			this->sort_by_name->Size = System::Drawing::Size(83, 41);
			this->sort_by_name->TabIndex = 3;
			this->sort_by_name->Text = L"Sort by name";
			this->sort_by_name->UseVisualStyleBackColor = true;
			this->sort_by_name->Click += gcnew System::EventHandler(this, &MyForm::sort_by_name_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 377);
			this->Controls->Add(this->sort_by_name);
			this->Controls->Add(this->sort_by_date);
			this->Controls->Add(this->browse_file);
			this->Controls->Add(this->show_list_box);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Agency";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void redraw_list() {

		show_list_box->Text = "";

		std::stringstream oss;
		oss << list_1;
		char str[128];
		while (oss.getline(str, 128))
		{
			String^ temp = msclr::interop::marshal_as<String^>(str);

			show_list_box->Text += temp;
			show_list_box->Text += Environment::NewLine;
		}
	}

	private: System::Void browse_file_Click(System::Object^  sender, System::EventArgs^  e) {

		open_file_dialog->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(open_file_dialog->FileName);

		std::ifstream fin(filename);

		if (!fin.is_open() && filename != "")
		{
			MessageBox::Show("No file selected", "File selecting warning");
		}
		else if (filename != "")
		{
			while (!fin.eof())
			{
				fin >> list_1;
			}
		}

		fin.close();

		redraw_list();
	}

	private: System::Void sort_by_date_Click(System::Object^  sender, System::EventArgs^  e) {

		if (list_1.get_concert_amount() == 0)
		{
			MessageBox::Show("You can't sort an empty list", "Invalid sort");
		}
		else
		{
			list_1.sort_by_date();
			redraw_list();
		}
	}
	private: System::Void sort_by_name_Click(System::Object^  sender, System::EventArgs^  e) {

		if (list_1.get_concert_amount() == 0)
		{
			MessageBox::Show("You can't sort an empty list", "Invalid sort");
		}
		else
		{
			list_1.sort_by_name();
			redraw_list();
		}
	}
	};
}