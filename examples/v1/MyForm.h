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
		System::Windows::Forms::DataVisualization::Charting::Chart ^ chart1;

	private:
		System::Windows::Forms::TextBox ^ textBox1;

	private:
		System::Windows::Forms::Label ^ label1;

	private:
		System::Windows::Forms::Button ^ button1;

	private:
		System::Windows::Forms::TextBox ^ textBox2;

	private:
		System::Windows::Forms::Timer ^ timer1;

	private:
		System::Windows::Forms::Timer ^ timer2;

	private:
		System::IO::Ports::SerialPort ^ serialPort1;

	private:
		System::Windows::Forms::Timer ^ timer3;

	private:
		System::IO::Ports::SerialPort ^ serialPort2;

	private:
		System::Windows::Forms::Timer ^ timer4;

	private:
		System::ComponentModel::IContainer ^ components;

	protected:
	protected:
	private:
		/// <summary>
		///   .
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		///      -
		///       .
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea ^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend ^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series ^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->serialPort2 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			//
			// chart1
			//
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->LabelToolTip = L"#VAL";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1659, 909);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			//
			// textBox1
			//
			this->textBox1->Location = System::Drawing::Point(658, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(99, 29);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(627, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"n =";
			this->label1->Visible = false;
			//
			// button1
			//
			this->button1->Location = System::Drawing::Point(654, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			//
			// textBox2
			//
			this->textBox2->Location = System::Drawing::Point(639, 169);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(99, 29);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"";
			this->textBox2->Visible = false;
			//
			// timer1
			//
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			//
			// timer2
			//
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			//
			// serialPort1
			//
			this->serialPort1->BaudRate = 115200;
			this->serialPort1->PortName = L"COM4";
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			//
			// timer3
			//
			this->timer3->Interval = 1;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			//
			// serialPort2
			//
			this->serialPort2->BaudRate = 115200;
			this->serialPort2->PortName = L"COM4";
			this->serialPort2->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort2_DataReceived);
			//
			// timer4
			//
			this->timer4->Interval = 10;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1716, 921);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
													  static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"N1 var 6";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		float y = 0.0;
		float y_o = 30.0;
		float time = 0.0;
		float tstart = 0.0;
		float timer = 0.0;
		float u = 0.0;

		float timer_2 = 0.0;
		float y_before = 0.0;
		float y_after = 0.0;
		float pulse = 0.0;
		float delta = 0.0;
		float timer_2_s = 0.0;
		float timer_2_ss = 0.0;
		float delta_sum = 0.0;
		float numbers = 0.0;

		int datasInt = 0;

		float timer_4 = 0.0;
		String ^ dataStr = "1";

	private:
		System::Void MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
		{

			this->chart1->Series["Series1"]->Points->Clear();
			// tstart = 0.0;
			// this->timer1->Enabled = true;
			// this->timer2->Enabled = true;
			// this->timer3->Enabled = true;
			// y = 13.5; time = 4.4;

			this->timer4->Enabled = true;
			this->serialPort2->Open();

			/*this->chart1->Series["Series1"]->Points->AddXY(0, 0);
			this->chart1->Series["Series1"]->Points->AddXY(0.5, 0.3);
			this->chart1->Series["Series1"]->Points->AddXY(0.7, 0.6);
			this->chart1->Series["Series1"]->Points->AddXY(0.8, 0.9);
			this->chart1->Series["Series1"]->Points->AddXY(time, y);*/
		}

	private:
		System::Void textBox1_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (this->textBox1->Text != "")
			{
				if (this->textBox1->Text != " " &&
					Convert::ToChar("0") < Convert::ToChar(this->textBox1->Text[this->textBox1->Text->Length - 1]) &&
					Convert::ToChar("9") >= Convert::ToChar(this->textBox1->Text[this->textBox1->Text->Length - 1]))
				{
					if (this->textBox2->Text == "")
					{
						int n = Convert::ToInt16(this->textBox1->Text);
						for (int i = 0; i < 10001; i++)
						{
							Double X = 0.0;
							Double Y = 0.0;
							Double nn = Convert::ToDouble(n);
							Double Stepen1 = 1 / nn;
							Double Stepen2 = 2 / nn;
							X = 0.00001 * i;
							Y = pow(X, Stepen1) - pow(X, Stepen2);
							this->chart1->Series["Series1"]->Points->AddXY(X, Y);
						}
						for (int i = 0; i < 101; i++)
						{
							Double X = 0.0;
							Double Y = 0.0;
							Double nn = Convert::ToDouble(n);
							Double Stepen1 = 1 / nn;
							Double Stepen2 = 2 / nn;
							X = 0.01 * i;
							Y = pow(X, Stepen1) - pow(X, Stepen2);
							this->chart1->Series["Series1"]->Points->AddXY(X, Y);
						}
					}
					else
					{
						int n = Convert::ToInt16(this->textBox1->Text);

						for (int i = 100; i > -1; i--)
						{
							Double X = 0.0;
							Double Y = 0.0;
							Double nn = Convert::ToDouble(n);

							X = -0.01 * i;
							if (abs(X) < (1 / nn))
							{
								Y = pow(2.71, -nn / (1 - nn * nn * X * X));
							}
							if (abs(X) >= (1 / nn))
							{
								Y = 0;
							}
							this->chart1->Series["Series1"]->Points->AddXY(X, Y);
						}
						for (int i = 1; i < 101; i++)
						{
							Double X = 0.0;
							Double Y = 0.0;
							Double nn = Convert::ToDouble(n);

							X = 0.01 * i;
							if (abs(X) < (1 / nn))
							{
								Y = pow(2.71, -nn / (1 - nn * nn * X * X));
							}
							if (abs(X) >= (1 / nn))
							{
								Y = 0;
							}
							this->chart1->Series["Series1"]->Points->AddXY(X, Y);
						}
					}
				}
				else
				{
					this->textBox1->Text = "";
				}
			}
		}

	private:
		System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			this->chart1->Series["Series1"]->Points->Clear();
		}

	private:
		System::Void MyForm_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			if (u >= 0)
			{
				u = u + 10.0;
			}
			if (u < 0)
			{
				u = 15.0;
			}
			tstart = timer;
			y_o = y;
		}

	private:
		System::Void timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
		{
			float odin = 0.1;
			timer = timer + odin;
			time = timer - tstart;
			y = y_o - 5 * time * time + u * time;
			u = u - 5 * time;

			// this->chart1->Series["Series1"]->Points->AddXY(timer, y);
		}

	private:
		System::Void timer2_Tick(System::Object ^ sender, System::EventArgs ^ e)
		{

			float odin = 0.1;
			timer_2 = timer_2 + odin;

			pulse = cos(timer_2 * 5) * 10;
			y_before = sin(timer_2 / 10) * 100 + pulse;

			delta_sum = delta_sum + y_before;
			numbers++;

			if ((timer_2 - timer_2_s) > 0.6)
			{
				timer_2_s = timer_2;
				delta = delta_sum / numbers;
				delta_sum = 0;
				numbers = 0;
			}

			y_after = y_before - delta;

			this->chart1->Series["Series1"]->Points->AddXY(timer_2, y_after);
		}

	private:
		System::Void serialPort1_DataReceived(System::Object ^ sender, System::IO::Ports::SerialDataReceivedEventArgs ^ e)
		{

			float odin = 0.1;
			timer_2 = timer_2 + odin;
			auto datas = this->serialPort1->ReadLine();
			datasInt = Convert::ToInt32(datas);
		}

	private:
		System::Void timer3_Tick(System::Object ^ sender, System::EventArgs ^ e)
		{

			delta_sum = delta_sum + datasInt;
			numbers++;

			if ((timer_2 - timer_2_s) > 1)
			{
				timer_2_s = timer_2;
				delta = delta_sum / numbers;
				delta_sum = 0;
				numbers = 0;
			}

			if ((timer_2 - timer_2_ss) > 10)
			{
				timer_2_ss = timer_2;
				this->chart1->Series["Series1"]->Points->Clear();
			}

			y_after = datasInt - delta;

			this->chart1->Series["Series1"]->Points->AddXY(timer_2, y_after);
		}

	private:
		System::Void serialPort2_DataReceived(System::Object ^ sender, System::IO::Ports::SerialDataReceivedEventArgs ^ e)
		{
			auto datas = this->serialPort1->ReadLine();
			dataStr = Convert::ToString(datas);
		}

	private:
		System::Void timer4_Tick(System::Object ^ sender, System::EventArgs ^ e)
		{
			timer_4++;
			this->chart1->Series["Series1"]->Points->AddXY(timer_4, Convert::ToInt32(dataStr[0]));
			this->textBox1->Text = dataStr;
		}
	};
}
