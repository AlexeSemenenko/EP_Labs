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

	private: System::Windows::Forms::OpenFileDialog^  open_file_dialog;
	private: System::Windows::Forms::Button^  browse_file;


	private: System::Windows::Forms::DataGridView^  list_show_table;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  capacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  left;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  time;
	private: System::Windows::Forms::SaveFileDialog^  save_file_dialog;
	private: System::Windows::Forms::Button^  save_file_button;
	private: System::Windows::Forms::TextBox^  name_box;
	private: System::Windows::Forms::Button^  search_name_button;
	private: System::Windows::Forms::DataGridView^  search_show_table;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  capacity1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  left1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  date1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  time1;
	private: System::Windows::Forms::TextBox^  name_add;
	private: System::Windows::Forms::TextBox^  capacity_add;
	private: System::Windows::Forms::TextBox^  left_add;
	private: System::Windows::Forms::TextBox^  date_add;
	private: System::Windows::Forms::Button^  add_concert_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DateTimePicker^  date_time_picker1;
	private: System::Windows::Forms::DateTimePicker^  date_time_picker2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  search_date_button;



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
			this->open_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->browse_file = (gcnew System::Windows::Forms::Button());
			this->list_show_table = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->capacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->left = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->save_file_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->save_file_button = (gcnew System::Windows::Forms::Button());
			this->name_box = (gcnew System::Windows::Forms::TextBox());
			this->search_name_button = (gcnew System::Windows::Forms::Button());
			this->search_show_table = (gcnew System::Windows::Forms::DataGridView());
			this->name1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->capacity1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->left1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name_add = (gcnew System::Windows::Forms::TextBox());
			this->capacity_add = (gcnew System::Windows::Forms::TextBox());
			this->left_add = (gcnew System::Windows::Forms::TextBox());
			this->date_add = (gcnew System::Windows::Forms::TextBox());
			this->add_concert_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->date_time_picker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->date_time_picker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->search_date_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_show_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_show_table))->BeginInit();
			this->SuspendLayout();
			// 
			// open_file_dialog
			// 
			this->open_file_dialog->FileName = L"openFileDialog1";
			// 
			// browse_file
			// 
			this->browse_file->Location = System::Drawing::Point(12, 11);
			this->browse_file->Name = L"browse_file";
			this->browse_file->Size = System::Drawing::Size(76, 39);
			this->browse_file->TabIndex = 1;
			this->browse_file->Text = L"Browse the file";
			this->browse_file->UseVisualStyleBackColor = true;
			this->browse_file->Click += gcnew System::EventHandler(this, &MyForm::browse_file_Click);
			// 
			// list_show_table
			// 
			this->list_show_table->AllowUserToAddRows = false;
			this->list_show_table->AllowUserToDeleteRows = false;
			this->list_show_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->list_show_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name,
					this->capacity, this->left, this->date, this->time
			});
			this->list_show_table->Location = System::Drawing::Point(94, 12);
			this->list_show_table->Name = L"list_show_table";
			this->list_show_table->ReadOnly = true;
			this->list_show_table->Size = System::Drawing::Size(543, 165);
			this->list_show_table->TabIndex = 4;
			// 
			// name
			// 
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			// 
			// capacity
			// 
			this->capacity->HeaderText = L"Capacity";
			this->capacity->Name = L"capacity";
			this->capacity->ReadOnly = true;
			// 
			// left
			// 
			this->left->HeaderText = L"Left";
			this->left->Name = L"left";
			this->left->ReadOnly = true;
			// 
			// date
			// 
			this->date->HeaderText = L"Date";
			this->date->Name = L"date";
			this->date->ReadOnly = true;
			// 
			// time
			// 
			this->time->HeaderText = L"Time";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			// 
			// save_file_button
			// 
			this->save_file_button->Location = System::Drawing::Point(643, 12);
			this->save_file_button->Name = L"save_file_button";
			this->save_file_button->Size = System::Drawing::Size(78, 38);
			this->save_file_button->TabIndex = 5;
			this->save_file_button->Text = L"Save the file";
			this->save_file_button->UseVisualStyleBackColor = true;
			this->save_file_button->Click += gcnew System::EventHandler(this, &MyForm::save_file_button_Click);
			// 
			// name_box
			// 
			this->name_box->Location = System::Drawing::Point(94, 205);
			this->name_box->Name = L"name_box";
			this->name_box->Size = System::Drawing::Size(196, 21);
			this->name_box->TabIndex = 6;
			this->name_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// search_name_button
			// 
			this->search_name_button->Location = System::Drawing::Point(154, 232);
			this->search_name_button->Name = L"search_name_button";
			this->search_name_button->Size = System::Drawing::Size(79, 39);
			this->search_name_button->TabIndex = 7;
			this->search_name_button->Text = L"Search by name";
			this->search_name_button->UseVisualStyleBackColor = true;
			this->search_name_button->Click += gcnew System::EventHandler(this, &MyForm::search_name_button_Click);
			// 
			// search_show_table
			// 
			this->search_show_table->AllowUserToAddRows = false;
			this->search_show_table->AllowUserToDeleteRows = false;
			this->search_show_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->search_show_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name1,
					this->capacity1, this->left1, this->date1, this->time1
			});
			this->search_show_table->Location = System::Drawing::Point(94, 277);
			this->search_show_table->Name = L"search_show_table";
			this->search_show_table->ReadOnly = true;
			this->search_show_table->Size = System::Drawing::Size(543, 165);
			this->search_show_table->TabIndex = 8;
			// 
			// name1
			// 
			this->name1->HeaderText = L"Name";
			this->name1->Name = L"name1";
			this->name1->ReadOnly = true;
			// 
			// capacity1
			// 
			this->capacity1->HeaderText = L"Capacity";
			this->capacity1->Name = L"capacity1";
			this->capacity1->ReadOnly = true;
			// 
			// left1
			// 
			this->left1->HeaderText = L"Left";
			this->left1->Name = L"left1";
			this->left1->ReadOnly = true;
			// 
			// date1
			// 
			this->date1->HeaderText = L"Date";
			this->date1->Name = L"date1";
			this->date1->ReadOnly = true;
			// 
			// time1
			// 
			this->time1->HeaderText = L"Time";
			this->time1->Name = L"time1";
			this->time1->ReadOnly = true;
			// 
			// name_add
			// 
			this->name_add->Location = System::Drawing::Point(13, 467);
			this->name_add->Name = L"name_add";
			this->name_add->Size = System::Drawing::Size(195, 21);
			this->name_add->TabIndex = 9;
			this->name_add->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// capacity_add
			// 
			this->capacity_add->Location = System::Drawing::Point(214, 467);
			this->capacity_add->Name = L"capacity_add";
			this->capacity_add->Size = System::Drawing::Size(149, 21);
			this->capacity_add->TabIndex = 10;
			this->capacity_add->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// left_add
			// 
			this->left_add->Location = System::Drawing::Point(369, 467);
			this->left_add->Name = L"left_add";
			this->left_add->Size = System::Drawing::Size(151, 21);
			this->left_add->TabIndex = 11;
			this->left_add->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// date_add
			// 
			this->date_add->Location = System::Drawing::Point(526, 467);
			this->date_add->Name = L"date_add";
			this->date_add->Size = System::Drawing::Size(195, 21);
			this->date_add->TabIndex = 12;
			this->date_add->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// add_concert_button
			// 
			this->add_concert_button->Location = System::Drawing::Point(285, 494);
			this->add_concert_button->Name = L"add_concert_button";
			this->add_concert_button->Size = System::Drawing::Size(165, 32);
			this->add_concert_button->TabIndex = 13;
			this->add_concert_button->Text = L"Add concert";
			this->add_concert_button->UseVisualStyleBackColor = true;
			this->add_concert_button->Click += gcnew System::EventHandler(this, &MyForm::add_concert_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(177, 187);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 15);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Name";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(91, 448);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 15);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(261, 448);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 15);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Capacity";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(418, 449);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 15);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Tickets left";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(574, 449);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 15);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Date(y-m-d h:m)";
			// 
			// date_time_picker1
			// 
			this->date_time_picker1->Location = System::Drawing::Point(328, 205);
			this->date_time_picker1->Name = L"date_time_picker1";
			this->date_time_picker1->Size = System::Drawing::Size(151, 21);
			this->date_time_picker1->TabIndex = 19;
			// 
			// date_time_picker2
			// 
			this->date_time_picker2->Location = System::Drawing::Point(485, 205);
			this->date_time_picker2->Name = L"date_time_picker2";
			this->date_time_picker2->Size = System::Drawing::Size(152, 21);
			this->date_time_picker2->TabIndex = 20;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(385, 187);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 15);
			this->label6->TabIndex = 21;
			this->label6->Text = L"1-st date";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(532, 187);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 15);
			this->label7->TabIndex = 22;
			this->label7->Text = L"2-nd date";
			// 
			// search_date_button
			// 
			this->search_date_button->Location = System::Drawing::Point(441, 232);
			this->search_date_button->Name = L"search_date_button";
			this->search_date_button->Size = System::Drawing::Size(79, 39);
			this->search_date_button->TabIndex = 23;
			this->search_date_button->Text = L"Search by date";
			this->search_date_button->UseVisualStyleBackColor = true;
			this->search_date_button->Click += gcnew System::EventHandler(this, &MyForm::search_date_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 538);
			this->Controls->Add(this->search_date_button);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->date_time_picker2);
			this->Controls->Add(this->date_time_picker1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->add_concert_button);
			this->Controls->Add(this->date_add);
			this->Controls->Add(this->left_add);
			this->Controls->Add(this->capacity_add);
			this->Controls->Add(this->name_add);
			this->Controls->Add(this->search_show_table);
			this->Controls->Add(this->search_name_button);
			this->Controls->Add(this->name_box);
			this->Controls->Add(this->save_file_button);
			this->Controls->Add(this->list_show_table);
			this->Controls->Add(this->browse_file);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Agency";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_show_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->search_show_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void add_to_table(System::Windows::Forms::DataGridView^ table, concert c){

		std::string c_date = std::to_string(c.date.tm_year + 1900) + "-";

		if (c.date.tm_mon + 1 <= 9)
			c_date += "0";
		c_date += std::to_string(c.date.tm_mon + 1) + "-";

		if (c.date.tm_mday <= 9)
			c_date += "0";
		c_date += std::to_string(c.date.tm_mday) + " ";

		std::string c_time;

		if (c.date.tm_hour <= 9)
			c_time += "0";
		c_time += std::to_string(c.date.tm_hour) + ":";

		if (c.date.tm_min <= 9)
			c_time += "0";
		c_time += std::to_string(c.date.tm_min);

		String^ concert_name = msclr::interop::marshal_as<String^>(c.name);
		String^ concert_capacity = msclr::interop::marshal_as<String^>(std::to_string(c.capacity));
		String^ concert_t_left = msclr::interop::marshal_as<String^>(std::to_string(c.left));
		String^ concert_date = msclr::interop::marshal_as<String^>(c_date);
		String^ concert_time = msclr::interop::marshal_as<String^>(c_time);

		table->Rows->Add(concert_name, concert_capacity, concert_t_left,
			concert_date, concert_time);
	}

	private: System::Void redraw_list() {

		list_show_table->Rows->Clear();

		std::stringstream oss;
		oss << list_1;
		char str[128];
		while (oss.getline(str, 128))
		{
			concert c;
			c.get_info(str);
			add_to_table(list_show_table, c);
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

	private: System::Void save_file_button_Click(System::Object^  sender, System::EventArgs^  e) {

		save_file_dialog->ShowDialog();

		std::string filename = msclr::interop::marshal_as<std::string>(save_file_dialog->FileName);

		std::ofstream fout(filename);

		if (!fout.is_open() && filename != "")
		{
			MessageBox::Show("No file selected", "File chooshing warning");
		}
		else if (filename != "")
		{
			fout << list_1;
		}

		fout.close();
	}

	private: System::Void display_founded_concerts(std::vector<concert> f_list)
	{
		for (int i = 0; i < f_list.size(); i++)
		{
			add_to_table(search_show_table, f_list[i]);
		}
	}

	private: System::Void search_name_button_Click(System::Object^  sender, System::EventArgs^  e) {
		search_show_table->Rows->Clear();

		std::string concert_name = msclr::interop::marshal_as<std::string>(name_box->Text);

		if (concert_name.empty() == true)
		{
			MessageBox::Show("Fill in the name field", "Name inputing warning");
		}
		else
		{
			std::vector<concert> found_concerts = list_1.find_first_name(concert_name);

			if (!found_concerts.empty())
			{
				display_founded_concerts(found_concerts);
				name_box->Text = "";
			}
			else
			{
				MessageBox::Show("No concerts with this name", "Empty search");
			}
		}
	}

	private: System::Void add_concert_button_Click(System::Object^  sender, System::EventArgs^  e) {

		std::string concert_name = msclr::interop::marshal_as<std::string>(name_add->Text);
		std::string concert_capacity = msclr::interop::marshal_as<std::string>(capacity_add->Text);
		std::string concert_left = msclr::interop::marshal_as<std::string>(left_add->Text);
		std::string concert_date = msclr::interop::marshal_as<std::string>(date_add->Text);

		if (concert_date == "" || concert_name == "" || concert_left == "" || concert_capacity == "")
		{
			MessageBox::Show("Fill in all the fields", "Inputing warning");
		}
		else
		{
			std::string final_info = concert_name + ";" + concert_capacity + ";" + concert_left + ";" + concert_date;
			list_1.add_concert(final_info);

			name_add->Text = "";
			capacity_add->Text = "";
			left_add->Text = "";
			date_add->Text = "";

			redraw_list();
		}
	}

	private: System::Void search_date_button_Click(System::Object^  sender, System::EventArgs^  e) {

		search_show_table->Rows->Clear();

		std::string date_1 = msclr::interop::marshal_as<std::string>(date_time_picker1->Text);
		std::string date_2 = msclr::interop::marshal_as<std::string>(date_time_picker2->Text);
		tm date1{}, date2{};

		std::stringstream ss(date_1);
		ss >> std::get_time(&date1, "%Y-%m-%d %H:%M");
		ss.clear();
		ss.str(date_2);
		ss >> std::get_time(&date2, "%Y-%m-%d %H:%M");

		std::vector<concert> found_concerts = list_1.find_first_date_between(date1, date2);

		if (!found_concerts.empty())
		{
			display_founded_concerts(found_concerts);
		}
		else
		{
			MessageBox::Show("No concerts in this period", "Failed search");
		}
	}
};
}