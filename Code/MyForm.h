#pragma once
using namespace std;

namespace NodeIDE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  runButton;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  codeBlock;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->codeBlock = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(12, 12);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(75, 23);
			this->runButton->TabIndex = 1;
			this->runButton->Text = L"Run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &MyForm::runButton_Click);
			// 
			// codeBlock
			// 
			this->codeBlock->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->codeBlock->Location = System::Drawing::Point(13, 43);
			this->codeBlock->Multiline = true;
			this->codeBlock->Name = L"codeBlock";
			this->codeBlock->Size = System::Drawing::Size(794, 376);
			this->codeBlock->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 431);
			this->Controls->Add(this->codeBlock);
			this->Controls->Add(this->runButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"NodeIDE";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {

		msclr::interop::marshal_context context;
		std::string input = context.marshal_as<std::string>(codeBlock->Text);
		ofstream myfile("script.js");
		myfile << input;
		myfile.close();
		system("@echo off && node script.js && pause");

	}
	};
}
