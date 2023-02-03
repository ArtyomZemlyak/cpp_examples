#pragma once

// #include <iostream.h>
#include <conio.h>
#include <math.h>

namespace IndividualN2var6
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	///   MyForm
	/// </summary>
public
	ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			// TODO:
			//
		}

	protected:
		/// <summary>
		///    .
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox ^ textBox1;

	protected:
	private:
		/// <summary>
		///   .
		/// </summary>
		System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		///      -
		///       .
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//
			// textBox1
			//
			this->textBox1->AcceptsReturn = true;
			this->textBox1->AcceptsTab = true;
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(745, 493);
			this->textBox1->TabIndex = 0;
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 517);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
													  static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"N2 var 6";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		System::Void MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
		{

			int k = 2;
			Double x = 0.5;
			Double z = 1.0;
			Double p = 1.0;
			int n = 0;
			int factorial = 1;
			Double integral = 0.0;
			Double perehod = 0.5;

			const Double integralV = 0.118987;
			const Double E = 0.001;
			bool done = false;

			this->textBox1->Text = this->textBox1->Text + "E = " + Convert::ToString(E) + "\r" + "\n";

			while (done != true)
			{

				for (int i = 0; i < (n + 1); i++)
				{
					k = 2 + 3 * i;
					z = 1.0;
					factorial = 1.0;
					perehod = 0.5;
					for (int ii = 0; ii < n; ii++)
					{
						z = z * (-1.0);
					}
					for (int ii = 1; ii < (n + 1); ii++)
					{
						factorial = factorial * ii;
					}
					p = Convert::ToDouble(factorial * (k));
					for (int ii = 1; ii < k; ii++)
					{
						perehod = perehod * x;
					}
				}

				integral = integral + z * perehod / p;

				String ^ s = Convert::ToString(n) + ": " + Convert::ToString(integral);
				this->textBox1->Text = this->textBox1->Text + s + " - ";
				this->textBox1->Text = this->textBox1->Text + Convert::ToString(integralV);
				this->textBox1->Text = this->textBox1->Text + " = ";
				this->textBox1->Text = this->textBox1->Text + Convert::ToString(abs(integralV - integral));
				this->textBox1->Text = this->textBox1->Text + "         (k = " + Convert::ToString(k);
				this->textBox1->Text = this->textBox1->Text + " f = " + Convert::ToString(factorial);
				this->textBox1->Text = this->textBox1->Text + " z = " + Convert::ToString(z);
				this->textBox1->Text = this->textBox1->Text + " perehod = " + Convert::ToString(perehod);
				this->textBox1->Text = this->textBox1->Text + " p = " + Convert::ToString(p) + ")" + "\r" + "\n";

				if (abs(integralV - integral) <= E)
				{
					done = true;
					break;
				}
				else
				{
					n++;
				}
				if (n > 15)
				{
					done = true;
					break;
				}
			}
			this->textBox1->Text = this->textBox1->Text + "Integral = " + Convert::ToString(integral);
			this->textBox1->Text = this->textBox1->Text + "   with Taylor decomposition up to " + Convert::ToString(n + 1) + " terms";
		}
	};
}
