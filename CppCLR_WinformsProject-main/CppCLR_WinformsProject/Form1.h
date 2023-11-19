#pragma once
#include <Windows.h>
#include <vcclr.h>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <list>
#include <cliext/list> 
#include <iostream>
#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace cliext;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int currentImageIndex;
		bool overlay;
		bool stream;
		bool cancel_loop;
		int IndexCam;
		float height, width, marker_size;
		std::vector<cv::Point3f>* rectangle_corners;
		std::vector<cv::Vec3d>* rvec;
		std::vector < cv::Vec3d>* tvec;
		std::vector<cv::Point2f>* rectangle_corners_image;
		std::vector<cv::Point2f>* translation_point;
		
		// Variables globales pour stocker les coordonnées de translation

		// Variable pour indiquer si la souris est enfoncée
		bool mousePressed;
		String^ image_path;
		String^ selected_im_Path;
		cv::Point2f* delta;
		cv::Mat* camMax;
		cv::Mat* distCoeff;
		cv::Mat* res_overlay;
		cv::Point2f* last_mouse_pos;
		cv::VideoCapture* cap;
		float rotation_angle;
	public: std::vector<cv::Mat>* calibrationResult;

	public:
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownIndexCam;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownMSLV;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownOWLV;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownOHLV;
	private: System::Windows::Forms::Button^ buttonAddLV;
	private: System::Windows::Forms::Label^ label24;

	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonUpdate;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownMSIV;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownOWIV;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownOHIV;
	private: System::Windows::Forms::Button^ buttonAddObjectImageSpace;

	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Button^ buttonAddRoomImage;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TabPage^ tabPage1;


	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxK2;
	private: System::Windows::Forms::TextBox^ textBoxP1;
	private: System::Windows::Forms::TextBox^ textBoxP2;
	private: System::Windows::Forms::TextBox^ textBoxK3;
	private: System::Windows::Forms::TextBox^ textBoxK1;
	private: System::Windows::Forms::TextBox^ textBoxFy;
	private: System::Windows::Forms::TextBox^ textBoxCx;
	private: System::Windows::Forms::TextBox^ textBoxCy;
	private: System::Windows::Forms::TextBox^ textBoxSkew;
	private: System::Windows::Forms::TextBox^ textBoxFx;
	private: System::Windows::Forms::TextBox^ textBoxUpload;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ buttonCalibrate;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownWidth;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownHeigh;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonImage_Path;
	private: System::Windows::Forms::TabControl^ tabControl1;

	private: Thread^ videoThread;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::ListView^ listView3;
	private: System::Windows::Forms::ListView^ listView2;



	public:

		  List<String^>^ imagePaths;
		  List<String^>^ imagePathsListView2;
		  List<String^>^ imagePathsListView4;
private: System::Windows::Forms::ListView^ listView4;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::NumericUpDown^ numericUpDownAngle;
public:
	List<String^>^ imagePathsListView3;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currentImageIndex = 0;
			IndexCam = 0;
			height = width = marker_size = 0;
			cancel_loop = false;
			imagePaths = gcnew List<String^>();
			imagePathsListView2 = gcnew List<String^>();
			imagePathsListView3 = gcnew List<String^>();
			imagePathsListView4 = gcnew List<String^>();
			camMax = new cv::Mat();
			cap = new cv::VideoCapture();
			distCoeff = new cv::Mat();
			image_path = gcnew String("vide");
			mousePressed = false;
			rotation_angle = 0.0;
			overlay = false;
			stream = false;
			res_overlay = new cv::Mat();
			selected_im_Path = gcnew String("vide");
			last_mouse_pos = new cv::Point2f(0,0);
			delta = new cv::Point2f(0,0);
			rectangle_corners = new std::vector<cv::Point3f>;
			rectangle_corners_image = new std::vector<cv::Point2f>;
			rvec = new std::vector<cv::Vec3d>;
			tvec = new std::vector<cv::Vec3d>;
			translation_point = new std::vector<cv::Point2f>;
			calibrationResult = new std::vector<cv::Mat>;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete delta;
				delete camMax;
				delete distCoeff;
				delete res_overlay;
				delete last_mouse_pos;
				delete cap;
				delete rectangle_corners;
				delete rvec;
				delete tvec;
				delete rectangle_corners_image;
				delete translation_point;
				delete selected_im_Path;
				delete image_path;
				delete selected_im_Path;
				delete imagePaths;
				delete imagePathsListView2;
				delete imagePathsListView4;
				delete calibrationResult;
				delete imagePathsListView3;

			}
		}

	protected:

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->listView4 = (gcnew System::Windows::Forms::ListView());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownIndexCam = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownMSLV = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownOWLV = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownOHLV = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonAddLV = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->numericUpDownAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownMSIV = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownOWIV = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownOHIV = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonAddObjectImageSpace = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->buttonAddRoomImage = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxK2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxP1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxP2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxK3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxK1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCx = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSkew = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFx = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUpload = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonCalibrate = (gcnew System::Windows::Forms::Button());
			this->numericUpDownWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownHeigh = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonImage_Path = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownIndexCam))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMSLV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOWLV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOHLV))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAngle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMSIV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOWIV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOHIV))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHeigh))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::AliceBlue;
			this->tabPage3->Controls->Add(this->listView4);
			this->tabPage3->Controls->Add(this->buttonStop);
			this->tabPage3->Controls->Add(this->label31);
			this->tabPage3->Controls->Add(this->buttonStart);
			this->tabPage3->Controls->Add(this->pictureBox3);
			this->tabPage3->Controls->Add(this->label30);
			this->tabPage3->Controls->Add(this->label29);
			this->tabPage3->Controls->Add(this->trackBar2);
			this->tabPage3->Controls->Add(this->label28);
			this->tabPage3->Controls->Add(this->label27);
			this->tabPage3->Controls->Add(this->label26);
			this->tabPage3->Controls->Add(this->label25);
			this->tabPage3->Controls->Add(this->numericUpDownIndexCam);
			this->tabPage3->Controls->Add(this->numericUpDownMSLV);
			this->tabPage3->Controls->Add(this->numericUpDownOWLV);
			this->tabPage3->Controls->Add(this->numericUpDownOHLV);
			this->tabPage3->Controls->Add(this->buttonAddLV);
			this->tabPage3->Controls->Add(this->label24);
			this->tabPage3->Location = System::Drawing::Point(4, 29);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1900, 1018);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"LiveView";
			// 
			// listView4
			// 
			this->listView4->HideSelection = false;
			this->listView4->Location = System::Drawing::Point(84, 171);
			this->listView4->Name = L"listView4";
			this->listView4->Size = System::Drawing::Size(138, 181);
			this->listView4->SmallImageList = this->imageList1;
			this->listView4->TabIndex = 18;
			this->listView4->UseCompatibleStateImageBehavior = false;
			this->listView4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView4_SelectedIndexChanged);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(1317, 693);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(75, 33);
			this->buttonStop->TabIndex = 17;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &Form1::buttonStop_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(1144, 122);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(146, 20);
			this->label31->TabIndex = 16;
			this->label31->Text = L"Visualization Box";
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(935, 693);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(75, 33);
			this->buttonStart->TabIndex = 15;
			this->buttonStart->Text = L"Start";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &Form1::buttonStart_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->Location = System::Drawing::Point(696, 169);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(928, 493);
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(140, 716);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(275, 20);
			this->label30->TabIndex = 13;
			this->label30->Text = L"0°                                                       360°";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(115, 633);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(107, 20);
			this->label29->TabIndex = 12;
			this->label29->Text = L"Rotate Image";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(119, 667);
			this->trackBar2->Maximum = 360;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(308, 69);
			this->trackBar2->TabIndex = 11;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(112, 549);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(108, 20);
			this->label28->TabIndex = 10;
			this->label28->Text = L"Camera Index";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(112, 496);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(93, 20);
			this->label27->TabIndex = 9;
			this->label27->Text = L"Marker Size";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(112, 448);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(100, 20);
			this->label26->TabIndex = 8;
			this->label26->Text = L"Object Width";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(112, 401);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(106, 20);
			this->label25->TabIndex = 7;
			this->label25->Text = L"Object Height";
			// 
			// numericUpDownIndexCam
			// 
			this->numericUpDownIndexCam->Location = System::Drawing::Point(331, 549);
			this->numericUpDownIndexCam->Name = L"numericUpDownIndexCam";
			this->numericUpDownIndexCam->Size = System::Drawing::Size(120, 26);
			this->numericUpDownIndexCam->TabIndex = 6;
			// 
			// numericUpDownMSLV
			// 
			this->numericUpDownMSLV->Location = System::Drawing::Point(331, 494);
			this->numericUpDownMSLV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownMSLV->Name = L"numericUpDownMSLV";
			this->numericUpDownMSLV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownMSLV->TabIndex = 5;
			// 
			// numericUpDownOWLV
			// 
			this->numericUpDownOWLV->Location = System::Drawing::Point(331, 446);
			this->numericUpDownOWLV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownOWLV->Name = L"numericUpDownOWLV";
			this->numericUpDownOWLV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownOWLV->TabIndex = 4;
			this->numericUpDownOWLV->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownOWLV_ValueChanged);
			// 
			// numericUpDownOHLV
			// 
			this->numericUpDownOHLV->Location = System::Drawing::Point(331, 399);
			this->numericUpDownOHLV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownOHLV->Name = L"numericUpDownOHLV";
			this->numericUpDownOHLV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownOHLV->TabIndex = 3;
			this->numericUpDownOHLV->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownOHLV_ValueChanged);
			// 
			// buttonAddLV
			// 
			this->buttonAddLV->Location = System::Drawing::Point(340, 235);
			this->buttonAddLV->Name = L"buttonAddLV";
			this->buttonAddLV->Size = System::Drawing::Size(75, 33);
			this->buttonAddLV->TabIndex = 2;
			this->buttonAddLV->Text = L"ADD";
			this->buttonAddLV->UseVisualStyleBackColor = true;
			this->buttonAddLV->Click += gcnew System::EventHandler(this, &Form1::buttonAddLV_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(186, 122);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(117, 20);
			this->label24->TabIndex = 1;
			this->label24->Text = L"Object Space";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::AliceBlue;
			this->tabPage2->Controls->Add(this->numericUpDownAngle);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->listView3);
			this->tabPage2->Controls->Add(this->listView2);
			this->tabPage2->Controls->Add(this->label23);
			this->tabPage2->Controls->Add(this->buttonSave);
			this->tabPage2->Controls->Add(this->buttonUpdate);
			this->tabPage2->Controls->Add(this->buttonReset);
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->numericUpDownMSIV);
			this->tabPage2->Controls->Add(this->numericUpDownOWIV);
			this->tabPage2->Controls->Add(this->numericUpDownOHIV);
			this->tabPage2->Controls->Add(this->buttonAddObjectImageSpace);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->buttonAddRoomImage);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Location = System::Drawing::Point(4, 29);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1900, 1018);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"ImageView";
			// 
			// numericUpDownAngle
			// 
			this->numericUpDownAngle->Location = System::Drawing::Point(110, 793);
			this->numericUpDownAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->numericUpDownAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, System::Int32::MinValue });
			this->numericUpDownAngle->Name = L"numericUpDownAngle";
			this->numericUpDownAngle->Size = System::Drawing::Size(61, 26);
			this->numericUpDownAngle->TabIndex = 23;
			this->numericUpDownAngle->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownAngle_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(199, 792);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(45, 26);
			this->textBox1->TabIndex = 22;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// listView3
			// 
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(110, 376);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(155, 174);
			this->listView3->SmallImageList = this->imageList1;
			this->listView3->TabIndex = 21;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView3_SelectedIndexChanged);
			// 
			// listView2
			// 
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(110, 108);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(155, 186);
			this->listView2->SmallImageList = this->imageList1;
			this->listView2->TabIndex = 20;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView2_SelectedIndexChanged);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(1094, 41);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(178, 25);
			this->label23->TabIndex = 19;
			this->label23->Text = L"Visualization Box";
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(1412, 725);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(112, 35);
			this->buttonSave->TabIndex = 18;
			this->buttonSave->Text = L"Save Image";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->Location = System::Drawing::Point(1172, 725);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(75, 35);
			this->buttonUpdate->TabIndex = 17;
			this->buttonUpdate->Text = L"Update";
			this->buttonUpdate->UseVisualStyleBackColor = true;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &Form1::buttonUpdate_Click);
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(850, 725);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(75, 35);
			this->buttonReset->TabIndex = 16;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Form1::buttonReset_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(715, 108);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(957, 578);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2_MouseDown);
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2_MouseMove);
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox2_MouseUp);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(106, 749);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(107, 20);
			this->label21->TabIndex = 12;
			this->label21->Text = L"Rotate Image";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(114, 666);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(93, 20);
			this->label20->TabIndex = 11;
			this->label20->Text = L"Marker Size";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(114, 623);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(100, 20);
			this->label19->TabIndex = 10;
			this->label19->Text = L"Object Width";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(114, 579);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(106, 20);
			this->label18->TabIndex = 9;
			this->label18->Text = L"Object Height";
			// 
			// numericUpDownMSIV
			// 
			this->numericUpDownMSIV->Location = System::Drawing::Point(339, 660);
			this->numericUpDownMSIV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownMSIV->Name = L"numericUpDownMSIV";
			this->numericUpDownMSIV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownMSIV->TabIndex = 8;
			// 
			// numericUpDownOWIV
			// 
			this->numericUpDownOWIV->Location = System::Drawing::Point(339, 617);
			this->numericUpDownOWIV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownOWIV->Name = L"numericUpDownOWIV";
			this->numericUpDownOWIV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownOWIV->TabIndex = 7;
			// 
			// numericUpDownOHIV
			// 
			this->numericUpDownOHIV->Location = System::Drawing::Point(339, 573);
			this->numericUpDownOHIV->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownOHIV->Name = L"numericUpDownOHIV";
			this->numericUpDownOHIV->Size = System::Drawing::Size(120, 26);
			this->numericUpDownOHIV->TabIndex = 6;
			// 
			// buttonAddObjectImageSpace
			// 
			this->buttonAddObjectImageSpace->Location = System::Drawing::Point(349, 444);
			this->buttonAddObjectImageSpace->Name = L"buttonAddObjectImageSpace";
			this->buttonAddObjectImageSpace->Size = System::Drawing::Size(75, 35);
			this->buttonAddObjectImageSpace->TabIndex = 5;
			this->buttonAddObjectImageSpace->Text = L"ADD";
			this->buttonAddObjectImageSpace->UseVisualStyleBackColor = true;
			this->buttonAddObjectImageSpace->Click += gcnew System::EventHandler(this, &Form1::buttonAddObjectImageSpace_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(181, 328);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(174, 20);
			this->label17->TabIndex = 3;
			this->label17->Text = L"Carpet Image Space";
			// 
			// buttonAddRoomImage
			// 
			this->buttonAddRoomImage->Location = System::Drawing::Point(349, 159);
			this->buttonAddRoomImage->Name = L"buttonAddRoomImage";
			this->buttonAddRoomImage->Size = System::Drawing::Size(75, 35);
			this->buttonAddRoomImage->TabIndex = 2;
			this->buttonAddRoomImage->Text = L"ADD";
			this->buttonAddRoomImage->UseVisualStyleBackColor = true;
			this->buttonAddRoomImage->Click += gcnew System::EventHandler(this, &Form1::buttonAddRoomImage_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(181, 46);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(167, 20);
			this->label16->TabIndex = 0;
			this->label16->Text = L"Room Image Space";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::AliceBlue;
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBoxK2);
			this->tabPage1->Controls->Add(this->textBoxP1);
			this->tabPage1->Controls->Add(this->textBoxP2);
			this->tabPage1->Controls->Add(this->textBoxK3);
			this->tabPage1->Controls->Add(this->textBoxK1);
			this->tabPage1->Controls->Add(this->textBoxFy);
			this->tabPage1->Controls->Add(this->textBoxCx);
			this->tabPage1->Controls->Add(this->textBoxCy);
			this->tabPage1->Controls->Add(this->textBoxSkew);
			this->tabPage1->Controls->Add(this->textBoxFx);
			this->tabPage1->Controls->Add(this->textBoxUpload);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->buttonCalibrate);
			this->tabPage1->Controls->Add(this->numericUpDownWidth);
			this->tabPage1->Controls->Add(this->numericUpDownHeigh);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->buttonImage_Path);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1900, 1018);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Calibration";
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(33, 161);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(202, 245);
			this->listView1->TabIndex = 33;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(892, 45);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(146, 20);
			this->label15->TabIndex = 30;
			this->label15->Text = L"Visualization Box";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1495, 873);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(28, 20);
			this->label10->TabIndex = 29;
			this->label10->Text = L"K3";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1495, 806);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(28, 20);
			this->label11->TabIndex = 28;
			this->label11->Text = L"P2";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1495, 675);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 20);
			this->label12->TabIndex = 27;
			this->label12->Text = L"K2";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(1495, 746);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(28, 20);
			this->label13->TabIndex = 26;
			this->label13->Text = L"P1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(1495, 624);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(28, 20);
			this->label14->TabIndex = 25;
			this->label14->Text = L"K1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1495, 386);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(45, 20);
			this->label9->TabIndex = 24;
			this->label9->Text = L"skew";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1495, 319);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 20);
			this->label8->TabIndex = 23;
			this->label8->Text = L"cy";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1495, 188);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 20);
			this->label7->TabIndex = 22;
			this->label7->Text = L"fy";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1495, 259);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 20);
			this->label6->TabIndex = 21;
			this->label6->Text = L"cx";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1495, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 20);
			this->label5->TabIndex = 20;
			this->label5->Text = L"fx";
			// 
			// textBoxK2
			// 
			this->textBoxK2->Location = System::Drawing::Point(1574, 669);
			this->textBoxK2->Name = L"textBoxK2";
			this->textBoxK2->Size = System::Drawing::Size(235, 26);
			this->textBoxK2->TabIndex = 19;
			// 
			// textBoxP1
			// 
			this->textBoxP1->Location = System::Drawing::Point(1574, 740);
			this->textBoxP1->Name = L"textBoxP1";
			this->textBoxP1->Size = System::Drawing::Size(235, 26);
			this->textBoxP1->TabIndex = 18;
			// 
			// textBoxP2
			// 
			this->textBoxP2->Location = System::Drawing::Point(1574, 800);
			this->textBoxP2->Name = L"textBoxP2";
			this->textBoxP2->Size = System::Drawing::Size(235, 26);
			this->textBoxP2->TabIndex = 17;
			// 
			// textBoxK3
			// 
			this->textBoxK3->Location = System::Drawing::Point(1574, 867);
			this->textBoxK3->Name = L"textBoxK3";
			this->textBoxK3->Size = System::Drawing::Size(235, 26);
			this->textBoxK3->TabIndex = 16;
			// 
			// textBoxK1
			// 
			this->textBoxK1->Location = System::Drawing::Point(1574, 618);
			this->textBoxK1->Name = L"textBoxK1";
			this->textBoxK1->Size = System::Drawing::Size(235, 26);
			this->textBoxK1->TabIndex = 15;
			// 
			// textBoxFy
			// 
			this->textBoxFy->Location = System::Drawing::Point(1574, 182);
			this->textBoxFy->Name = L"textBoxFy";
			this->textBoxFy->Size = System::Drawing::Size(235, 26);
			this->textBoxFy->TabIndex = 14;
			// 
			// textBoxCx
			// 
			this->textBoxCx->Location = System::Drawing::Point(1574, 253);
			this->textBoxCx->Name = L"textBoxCx";
			this->textBoxCx->Size = System::Drawing::Size(235, 26);
			this->textBoxCx->TabIndex = 13;
			// 
			// textBoxCy
			// 
			this->textBoxCy->Location = System::Drawing::Point(1574, 313);
			this->textBoxCy->Name = L"textBoxCy";
			this->textBoxCy->Size = System::Drawing::Size(235, 26);
			this->textBoxCy->TabIndex = 12;
			// 
			// textBoxSkew
			// 
			this->textBoxSkew->Location = System::Drawing::Point(1574, 380);
			this->textBoxSkew->Name = L"textBoxSkew";
			this->textBoxSkew->Size = System::Drawing::Size(235, 26);
			this->textBoxSkew->TabIndex = 11;
			// 
			// textBoxFx
			// 
			this->textBoxFx->Location = System::Drawing::Point(1574, 128);
			this->textBoxFx->Name = L"textBoxFx";
			this->textBoxFx->Size = System::Drawing::Size(235, 26);
			this->textBoxFx->TabIndex = 10;
			// 
			// textBoxUpload
			// 
			this->textBoxUpload->Location = System::Drawing::Point(33, 89);
			this->textBoxUpload->Name = L"textBoxUpload";
			this->textBoxUpload->Size = System::Drawing::Size(202, 26);
			this->textBoxUpload->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(1609, 532);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"dist_Coeffs";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1609, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(124, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Camera Matrix";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(556, 83);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(807, 542);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// buttonCalibrate
			// 
			this->buttonCalibrate->Location = System::Drawing::Point(378, 594);
			this->buttonCalibrate->Name = L"buttonCalibrate";
			this->buttonCalibrate->Size = System::Drawing::Size(110, 31);
			this->buttonCalibrate->TabIndex = 6;
			this->buttonCalibrate->Text = L"calibrate";
			this->buttonCalibrate->UseVisualStyleBackColor = true;
			this->buttonCalibrate->Click += gcnew System::EventHandler(this, &Form1::buttonCalibrate_Click);
			// 
			// numericUpDownWidth
			// 
			this->numericUpDownWidth->Location = System::Drawing::Point(291, 526);
			this->numericUpDownWidth->Name = L"numericUpDownWidth";
			this->numericUpDownWidth->Size = System::Drawing::Size(120, 26);
			this->numericUpDownWidth->TabIndex = 5;
			// 
			// numericUpDownHeigh
			// 
			this->numericUpDownHeigh->Location = System::Drawing::Point(291, 451);
			this->numericUpDownHeigh->Name = L"numericUpDownHeigh";
			this->numericUpDownHeigh->Size = System::Drawing::Size(120, 26);
			this->numericUpDownHeigh->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 526);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"CheckerWidth";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 451);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"CheckerHeight";
			// 
			// buttonImage_Path
			// 
			this->buttonImage_Path->Location = System::Drawing::Point(291, 83);
			this->buttonImage_Path->Name = L"buttonImage_Path";
			this->buttonImage_Path->Size = System::Drawing::Size(120, 38);
			this->buttonImage_Path->TabIndex = 1;
			this->buttonImage_Path->Text = L"image_path";
			this->buttonImage_Path->UseVisualStyleBackColor = true;
			this->buttonImage_Path->Click += gcnew System::EventHandler(this, &Form1::buttonImage_Path_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1908, 1051);
			this->tabControl1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1908, 1050);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownIndexCam))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMSLV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOWLV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOHLV))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownAngle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMSIV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOWIV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownOHIV))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHeigh))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////// Form1 Tab ////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	// Configuration du ListView
	listView1->View = View::Details;
	listView1->Columns->Add("",150);
	listView1->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

	listView2->View = View::Details;
	listView2->Columns->Add("", 150);
	listView2->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

	listView3->View = View::Details;
	listView3->Columns->Add("", 150);
	listView3->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

	listView4->View = View::Details;
	listView4->Columns->Add("", 150);
	listView4->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		     ///////////////////////////////// Calibration Tab ////////////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


private: System::Void buttonImage_Path_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		folderBrowserDialog1->Description = "Sélectionnez un dossier avec des images";

		if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ selectedPath = folderBrowserDialog1->SelectedPath;


			// Recherche des fichiers d'image dans le dossier sélectionné
			array<String^>^ imageExtensions = { ".jpg", ".jpeg", ".png", ".gif", ".bmp",".HEIC" };
			array<String^>^ files = Directory::GetFiles(selectedPath);
			listView1->SmallImageList = imageList1;

			for each (String ^ file in files)
			{
				String^ extension = Path::GetExtension(file)->ToLower();
				if (Array::IndexOf(imageExtensions, extension) != -1)
				{
					imagePaths->Add(file);
					imageList1->Images-> Add(Image::FromFile(file));
					String^ fileName =  Path::GetFileName(file);
					listView1->Items->Add(fileName, imageList1->Images->Count - 1);  // Utilisez l'index de la dernière image ajoutée
				}
			}


			if (imagePaths->Count == 0)
			{
				MessageBox::Show("Erreur : Aucune image trouvée dans le dossier.");
				return;
			}

			if (imagePaths->Count < 10)
			{
				MessageBox::Show("Erreur : Le nombre d'images est inférieur à 10.");
				return;
			}

			if (imagePaths->Count >= 10)
			{
				textBoxUpload->Text = selectedPath;
			}

			// Afficher la première image
			currentImageIndex = 0;
			DisplayCurrentImage();
		}
	}

private: System::Void buttonCalibrate_Click(System::Object^ sender, System::EventArgs^ e) {

	// Obtenez le chemin du dossier à partir du TextBox
	String^ imageFolderPath = textBoxUpload->Text;

	// Obtenez les valeurs des contrôles NumericUpDown
	int heightChess = (int)numericUpDownHeigh->Value;
	int widthChess = (int)numericUpDownWidth->Value;

	// Vérifiez si le chemin du dossier n'est pas vide et que les valeurs des NumericUpDown sont différentes de zéro
	if (!String::IsNullOrEmpty(imageFolderPath) && heightChess > 0 && widthChess > 0) {
		// Convertissez le chemin du dossier en std::string
		msclr::interop::marshal_context context;
		std::string imageFolderPathStd = context.marshal_as<std::string>(imageFolderPath);

		// Appelez la fonction de calibration
		std::vector<cv::Mat> calibrationResult = calibrate_func(imageFolderPathStd, heightChess, widthChess);

		if (calibrationResult.empty())
		{
			MessageBox::Show("Calibration is not possible. Please provide high-quality photos.");
		}

		cv::Mat MatrixCamera = *camMax = calibrationResult[0];
		cv::Mat DistCoeff = *distCoeff = calibrationResult[1];

		for (int i = 0; i < MatrixCamera.rows - 1; i++)
		{
			for (int j = 0; j < MatrixCamera.cols; j++)
			{
				String^ formattedText = MatrixCamera.at<double>(i, j).ToString();
				if (i == 0)
				{
					if (j == 0)
						textBoxFx->Text = formattedText;
					else if (j == 1)
						textBoxSkew->Text = formattedText;
					else if (j == 2)
						textBoxCx->Text = formattedText;

				}
				else
				{
					if (j == 0)
						continue;
					else if (j == 1)
						textBoxFy->Text = formattedText;
					else if (j == 2)
						textBoxCy->Text = formattedText;
				}

			}
		}

		for (int i = 0; i < DistCoeff.rows; i++)
		{
			for (int j = 0; j < DistCoeff.cols; j++) {
				String^ formattedText = DistCoeff.at<double>(i, j).ToString();
				if (j < DistCoeff.cols)
				{
					if (j == 0)
						textBoxK1->Text = formattedText;
					else if (j == 1)
						textBoxK2->Text = formattedText;
					else if (j == 2)
						textBoxP1->Text = formattedText;
					else if (j == 3)
						textBoxP2->Text = formattedText;
					else if (j == 4)
						textBoxK3->Text = formattedText;
				}
			}
		}


		// Afficher un message demandant si l'utilisateur souhaite enregistrer les résultats.
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Calibration is now complete. Do you want to save the results to a file??",
			"Save the results",
			MessageBoxButtons::YesNo);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			// L'utilisateur a choisi d'enregistrer les résultats.

			// Vous pouvez maintenant enregistrer les résultats dans un fichier dans le dossier du programme.
			// Utilisez la classe FileIO ou les fonctionnalités .NET appropriées pour effectuer l'enregistrement.

			std::string output_file = "camera_calibration_results.yml"; // Nom du fichier de sortie

			cv::FileStorage fs(output_file, cv::FileStorage::WRITE);

			// Stockez les données de calibration
			fs << "CameraMatrix" << MatrixCamera;
			fs << "DistortionCoefficients" << DistCoeff;
			fs.release();

			MessageBox::Show("The calibration results have been successfully saved.",
				"Saving successful",
				MessageBoxButtons::OK);
		}
		else {
			// L'utilisateur a choisi de ne pas enregistrer les résultats.
		}

	}
	else
	{
		// Affichez un message d'erreur si les conditions ne sont pas remplies
		MessageBox::Show("Erreur : Veuillez spécifier un chemin d'image valide et des valeurs non nulles dans les contrôles.");
	}
}

private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Vérifiez si un élément est sélectionné
	if (listView1->SelectedIndices->Count > 0)
	{
		// Récupérez le chemin du fichier de l'élément sélectionné
		String^ selectedFilePath = imagePaths[listView1->SelectedIndices[0]];

		// Affichez l'image dans le PictureBox
		pictureBox1->Image = Image::FromFile(selectedFilePath);
	}
}



     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////// ImageView Tab /////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



private: System::Void buttonAddRoomImage_Click(System::Object^ sender, System::EventArgs^ e) {
	// Configurez OpenFileDialog
	openFileDialog1->Filter = "Images|*.jpg;*.jpeg;*.png;*.bmp|All Files|*.*";
	openFileDialog1->Multiselect = true; // Permet la sélection de plusieurs fichiers
	// Définissez l'emplacement de destination dans votre application

	int index = 0;

	// Affichez la boîte de dialogue et attendez la sélection de fichiers
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		// Récupérez la liste des fichiers sélectionnés
		array<String^>^ selectedFiles = openFileDialog1->FileNames;

		// Parcourez les fichiers sélectionnés et copiez-les dans le dossier de destination
		for each (String ^ filePath in selectedFiles) {
			imagePathsListView2->Add(filePath);

			imageList1->Images->Add(Image::FromFile(filePath));
			if (index == 0)
			{
				pictureBox2->Image = Image::FromFile(filePath);
				pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
			}

			String^ fileName = Path::GetFileName(filePath);
			listView2->Items->Add(fileName, imageList1->Images->Count - 1);  // Utilisez l'index de la dernière image ajoutée
			index++;
		}
	}
}

private: System::Void listView2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	msclr::interop::marshal_context context;
	if (listView2->SelectedIndices->Count > 0)
	{
		// Récupérez le chemin du fichier de l'élément sélectionné
		String^ selectedFilePath = imagePathsListView2[listView2->SelectedIndices[0]];
		image_path = selectedFilePath;
		std::string imagepath = context.marshal_as<std::string>(image_path);
		// Affichez l'image dans le PictureBox
		pictureBox2->Image = Image::FromFile(selectedFilePath);
		pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
		if((!camMax->empty() || !distCoeff->empty()))
			if(selected_im_Path != "vide")
				detectEstimMarkerPos(imagepath, marker_size, *camMax, *distCoeff, *rvec, *tvec);
	}
	   }

private: System::Void buttonAddObjectImageSpace_Click(System::Object^ sender, System::EventArgs^ e) {
	// Configurez OpenFileDialog
	openFileDialog1->Filter = "Images|*.jpg;*.jpeg;*.png;*.bmp|All Files|*.*";
	openFileDialog1->Multiselect = true; // Permet la sélection de plusieurs fichiers

	// Affichez la boîte de dialogue et attendez la sélection de fichiers
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Récupérez la liste des fichiers sélectionnés
		array<String^>^ selectedFiles = openFileDialog1->FileNames;

		// Parcourez les fichiers sélectionnés et copiez-les dans le listView
		for each (String ^ filePath in selectedFiles) {
			imagePathsListView3->Add(filePath);
			imageList1->Images->Add(Image::FromFile(filePath));
			String^ fileName = Path::GetFileName(filePath);
			listView3->Items->Add(fileName, imageList1->Images->Count - 1);  // Utilisez l'index de la dernière image ajoutée
		}
	}
}

private: System::Void listView3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listView3->SelectedIndices->Count > 0)
	{
		translation_point->clear();
		msclr::interop::marshal_context context;

		// Récupérez le chemin du fichier image sélectionné dans le ListBox
		selected_im_Path = imagePathsListView3[listView3->SelectedIndices[0]];

		if (image_path == "vide")
		{
			if (listView2->Items->Count > 0)
			{
				image_path = imagePathsListView2[0];
			}
			else
			{
				// La liste est vide, faites quelque chose en conséquence
				MessageBox::Show("Please upload the image of your room containing the ArUco marker");
				pictureBox2->Image = Image::FromFile(selected_im_Path);
				pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				return;
			}

		}

		if (camMax->empty() || distCoeff->empty())
		{
			MessageBox::Show("You need to calibrate your camera");
			alternativ_calib_func();
		}

		// Assurez-vous que le chemin sélectionné est un fichier image (vous pouvez ajouter des vérifications supplémentaires)
		if (System::IO::File::Exists(selected_im_Path) && IsImageFile(selected_im_Path) && !camMax->empty() && !distCoeff->empty() && listView2->Items->Count > 0)
		{

			height = ((float)numericUpDownOHIV->Value) / 100;
			width = ((float)numericUpDownOWIV->Value / 100);
			marker_size = ((float)numericUpDownMSIV->Value / 100);

			std::vector<cv::Point3f>& rec = *rectangle_corners = { {-width / 2, -height / 2, 0},
								   {width / 2, -height / 2, 0},
								   {width / 2, height / 2, 0},
								   {-width / 2,height / 2, 0} };

			if (height == 0.0 || width == 0.0 || marker_size == 0.0)
			{
				MessageBox::Show("Please enter the dimension of the carpet and the marker");
			}
			// Convertissez le chemin du dossier en std::string
			else
			{
				std::string overlay_image = context.marshal_as<std::string>(selected_im_Path);
				std::string imagepath = context.marshal_as<std::string>(image_path);
				cv::Mat cameraMatrix = *camMax;
				cv::Mat DistCoeff = *distCoeff;

				if (rvec->empty() || tvec->empty())
				{
					detectEstimMarkerPos(imagepath, marker_size, cameraMatrix, DistCoeff, *rvec, *tvec);
				}

				*res_overlay = detect_aruco_and_project_image(imagepath, overlay_image,rec, cameraMatrix, DistCoeff, *rvec, *tvec);

				if (res_overlay->empty())
				{
					MessageBox::Show("Unable to process the visualization. Please  make sure the arUco marker is present on the image of your room.");
				}
				else
				{
					// Chargez l'image dans le PictureBox
					DisplayMatInPictureBox(pictureBox2, *res_overlay);

				}

			}

		}
		else
			MessageBox::Show("The selected file is not an image.");
	}
}

private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	translation_point->clear();
	rotation_angle = 0;
	// Récupérez le chemin du fichier image sélectionné dans le ListBox
	if (selected_im_Path == "vide")
	{
		if (listView2->Items->Count > 0)
			selected_im_Path = imagePathsListView3[0]->ToString();
		else
		{
			MessageBox::Show("You haven't uploaded any image in your room image space");
			return;
		}

	}


	if (image_path == "vide")
	{
		if (listView3->Items->Count > 0) {
			image_path = imagePathsListView2[0];
			// Utilisez premierElement comme bon vous semble
		}
		else {
			// La liste est vide, faites quelque chose en conséquence
			MessageBox::Show("You haven't uploaded any image in your object image space");
			return;
		}
	}

	if (camMax->empty() || distCoeff->empty())
	{
		MessageBox::Show("You need to calibrate your camera first.");
		alternativ_calib_func();
	}
	// Assurez-vous que le chemin sélectionné est un fichier image (vous pouvez ajouter des vérifications supplémentaires)
	if (System::IO::File::Exists(selected_im_Path) && IsImageFile(selected_im_Path) && !camMax->empty() && !distCoeff->empty())
	{

		//float height = ((float)numericUpDownOHIV->Value) / 100;
		//float width = ((float)numericUpDownOWIV->Value / 100);
		float marker_size = ((float)numericUpDownMSIV->Value / 100);
		if (height == 0.0 || width == 0.0 || marker_size == 0.0)
		{
			MessageBox::Show("Please enter the dimension of the carpet and the marker");
		}
		// Convertissez le chemin du dossier en std::string
		else
		{
			std::string overlay_image = context.marshal_as<std::string>(selected_im_Path);
			std::string imagepath = context.marshal_as<std::string>(image_path);
			cv::Mat cameraMatrix = *camMax;
			cv::Mat DistCoeff = *distCoeff;

			height = ((float)numericUpDownOHIV->Value) / 100;
			width = ((float)numericUpDownOWIV->Value / 100);
			marker_size = ((float)numericUpDownMSIV->Value / 100);

			*rectangle_corners = { {-width / 2, -height / 2, 0},
								   {width / 2, -height / 2, 0},
								   {width / 2, height / 2, 0},
								   {-width / 2,height / 2, 0} };

			*res_overlay = detect_aruco_and_project_image(imagepath, overlay_image, *rectangle_corners, cameraMatrix, DistCoeff, *rvec, *tvec);

			if (res_overlay->empty())
			{
				MessageBox::Show("An error occured");
			}
			else
			{
				// Chargez l'image dans le PictureBox
				DisplayMatInPictureBox(pictureBox2, *res_overlay);

			}

		}

	}
	else if (listView3->Items->Count == 0)
	{
	        MessageBox::Show("Please verify you have initialized everything with valid values",
					"can't reset",
			MessageBoxButtons::OK);

		// Effacez l'image du PictureBox si le fichier n'est pas une image
		pictureBox2->Image = nullptr;
	}
}

private: System::Void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {

	msclr::interop::marshal_context context;
	// Récupérez le chemin du fichier image sélectionné dans le ListBox

	if (selected_im_Path == "vide")
	{
		if (listView3->Items->Count > 0)
			selected_im_Path = listView3->Items[0]->ToString();
		else
		{
			MessageBox::Show("You haven't uploaded any image in your object image space");
			return;
		}

	}

	if (image_path == "vide")
	{
		if (listView2->Items->Count > 0) {
			image_path = listView2->Items[0]->ToString();
			// Utilisez premierElement comme bon vous semble
		}
		else {
			// La liste est vide, faites quelque chose en conséquence
			MessageBox::Show("You haven't uploaded any image in your room image space");
			return;
		}
	}

	if (camMax->empty() || distCoeff->empty())
	{
		MessageBox::Show("You need to calibrate your camera first.");
		alternativ_calib_func();
	}
	// Assurez-vous que le chemin sélectionné est un fichier image (vous pouvez ajouter des vérifications supplémentaires)
	if (System::IO::File::Exists(selected_im_Path) && IsImageFile(selected_im_Path) && !camMax->empty() && !distCoeff->empty())
	{
		if (height == 0.0 || width == 0.0 || marker_size == 0.0)
		{
			MessageBox::Show("Please enter the dimension of the carpet and the marker");
		}
		// Convertissez le chemin du dossier en std::string
		else
		{
			std::string overlay_image = context.marshal_as<std::string>(selected_im_Path);
			std::string imagepath = context.marshal_as<std::string>(image_path);
			cv::Mat cameraMatrix = *camMax;
			cv::Mat DistCoeff = *distCoeff;
			height = ((float)numericUpDownOHIV->Value) / 100;
			width = ((float)numericUpDownOWIV->Value / 100);

			cv::Point2f delta_tmp(0, 0);

			std::vector<cv::Point3f>& rec = *rectangle_corners = { {-width / 2, -height / 2, 0},
					   {width / 2, -height / 2, 0},
					   {width / 2, height / 2, 0},
					   {-width / 2,height / 2, 0} };

			for (cv::Point2f point : *translation_point)
			{
				delta_tmp.x += point.x;
				delta_tmp.y += point.y;
			}

			translate_3D(delta_tmp.x * 0.001, -1 * delta_tmp.y * 0.001, *rectangle_corners);

			rotateImage3D(rotation_angle, *rectangle_corners);

			*res_overlay = detect_aruco_and_project_image(imagepath, overlay_image, *rectangle_corners, cameraMatrix, DistCoeff, *rvec, *tvec);

			if (res_overlay -> empty())
			{
				MessageBox::Show("An error occured");
			}
			else
			{
				// Chargez l'image dans le PictureBox
				DisplayMatInPictureBox(pictureBox2, *res_overlay);

			}

		}
	}
	else
	{

		if (listView2->Items->Count == 0)
			MessageBox::Show("Please verify you have initialized everything with valid values",
				"can't refresh",
				MessageBoxButtons::OK);

		// Effacez l'image du PictureBox si le fichier n'est pas une image
		pictureBox2->Image = nullptr;

	}
}

private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	if (!res_overlay->empty())
	{
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "Fichiers d'image (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp|Tous les fichiers (*.*)|*.*";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ savePath = saveFileDialog->FileName;

			// Convertissez le chemin du fichier en std::string
			std::string savePathStd = context.marshal_as<std::string>(savePath);

			// Maintenant, vous pouvez enregistrer votre image avec Open
			cv::imwrite(savePathStd, *res_overlay);
			MessageBox::Show("Image successfully saved");
		}
	}

	else {
		MessageBox::Show("No pictures to save");
	}

}

private: System::Void pictureBox2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		mousePressed = false;
	}
}

private: System::Void pictureBox2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		// Vérifier si la souris est enfoncée à l'intérieur du rectangle
		if (IsMouseInsideRectangle(e->X, e->Y))
		{
			*last_mouse_pos = cv::Point2f(e->X, e->Y);
			mousePressed = true;
		}
	}
}

private: System::Void pictureBox2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	msclr::interop::marshal_context context;
	cv::Mat image = cv::imread(context.marshal_as<std::string>(image_path));
	double zoomFactorX = static_cast<double>(pictureBox2->Width) / static_cast<double>(image.cols);
	double zoomFactorY = static_cast<double>(pictureBox2->Height) / static_cast<double>(image.rows);

	if (mousePressed)
	{
		cv::Point2f current_mouse_Pos(e->X, e->Y);
		*delta = current_mouse_Pos - *last_mouse_pos;
		delta->x = static_cast<int>(delta->x / zoomFactorX);
		delta->y = static_cast<int>(delta->y/ zoomFactorY);

		std::string overlay_image = context.marshal_as<std::string>(selected_im_Path);
		std::string imagepath = context.marshal_as<std::string>(image_path);
		cv::Mat cameraMatrix = *camMax;
		cv::Mat DistCoeff = *distCoeff;
		translation_point->push_back(*delta);

		translate_3D(delta->x * 0.001, -1 * delta->y * 0.001, *rectangle_corners);

		*res_overlay = detect_aruco_and_project_image(imagepath, overlay_image, *rectangle_corners, cameraMatrix, DistCoeff, *rvec, *tvec);

		if (res_overlay->empty())
		{
			MessageBox::Show("Unable to process the visualization. Please  make sure...");
		}
		else
		{
			// Chargez l'image dans le PictureBox
			DisplayMatInPictureBox(pictureBox2, *res_overlay);

		}

		*last_mouse_pos = current_mouse_Pos;
	}

}

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		   try {
			   rotation_angle = Convert::ToInt32(textBox1->Text);
		   }
		   catch (FormatException^)
		   {
			   Console::WriteLine("Erreur : la conversion en float a échoué.");
		   }

	   }

private: System::Void numericUpDownAngle_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

	rotation_angle = (float)numericUpDownAngle->Value; // Obtenir la valeur du TrackBar
	textBox1->Text = rotation_angle.ToString() + "°";
	// Afficher l'image pivotée dans votre PictureBox

	msclr::interop::marshal_context context;
	// Récupérez le chemin du fichier image sélectionné dans le ListBox

	if (image_path == "vide")
	{
		if (listView3->Items->Count > 0) {
			image_path = imagePathsListView3[0]->ToString();
			// Utilisez premierElement comme bon vous semble
		}
		else {
			// La liste est vide, faites quelque chose en conséquence
			MessageBox::Show("You haven't uploaded any image in your room image space");
			return;
		}
	}
	// Assurez-vous que le chemin sélectionné est un fichier image (vous pouvez ajouter des vérifications supplémentaires)
	else if (System::IO::File::Exists(selected_im_Path) && IsImageFile(selected_im_Path) && !camMax->empty() && !distCoeff->empty())
	{
		float marker_size = ((float)numericUpDownMSIV->Value / 100);
		if (height == 0.0 || width == 0.0 || marker_size == 0.0)
		{
			MessageBox::Show("Please enter the dimension of the carpet and the marker");
		}
		// Convertissez le chemin du dossier en std::string
		else
		{
			std::string overlay_image = context.marshal_as<std::string>(selected_im_Path);
			std::string imagepath = context.marshal_as<std::string>(image_path);
			cv::Mat cameraMatrix = *camMax;
			cv::Mat DistCoeff = *distCoeff;
			rotateImage3D(rotation_angle, *rectangle_corners);

			*res_overlay = detect_aruco_and_project_image(imagepath, overlay_image, *rectangle_corners, cameraMatrix, DistCoeff, *rvec, *tvec);

			if (res_overlay->empty())
			{
				MessageBox::Show("An error occured");
			}
			else
			{
				// Chargez l'image dans le PictureBox
				DisplayMatInPictureBox(pictureBox2, *res_overlay);

			}

		}

	}
	else {
		// Effacez l'image du PictureBox si le fichier n'est pas une image
		pictureBox2->Image = nullptr;
		MessageBox::Show("You haven't selected any image to overlay");

	}
}



	   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			   ////////////////////////////////// LiveView Tab /////////////////////////////////////////////
	  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



private: System::Void buttonAddLV_Click(System::Object^ sender, System::EventArgs^ e) {
	// Configurez OpenFileDialog
	openFileDialog1->Filter = "Images|*.jpg;*.jpeg;*.png;*.bmp|All Files|*.*";
	openFileDialog1->Multiselect = true; // Permet la sélection de plusieurs fichiers

	// Affichez la boîte de dialogue et attendez la sélection de fichiers
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Récupérez la liste des fichiers sélectionnés
		array<String^>^ selectedFiles = openFileDialog1->FileNames;

		// Parcourez les fichiers sélectionnés et copiez-les dans le listView
		for each (String ^ filePath in selectedFiles) {
			imagePathsListView4->Add(filePath);
			imageList1->Images->Add(Image::FromFile(filePath));
			String^ fileName = Path::GetFileName(filePath);
			listView4->Items->Add(fileName, imageList1->Images->Count - 1);  // Utilisez l'index de la dernière image ajoutée
		}
		pictureBox3->Image = Image::FromFile(selectedFiles[0]);
	}

}

private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	stream = true;
	height = ((float)numericUpDownOHLV->Value) / 100;
	width = ((float)numericUpDownOWLV->Value / 100);
    marker_size = ((float)numericUpDownMSLV->Value / 100);
	IndexCam = (int)numericUpDownIndexCam->Value;

	if (listView4->Items->Count == 0)
	{
		MessageBox::Show("You haven't uploaded any images of the object you want to visualize.",
			"Error",
			MessageBoxButtons::OK);
	}

	if (camMax->empty() || distCoeff->empty())
	{
		MessageBox::Show("You need to calibrate your camera");
		alternativ_calib_func();
	}

	if (height == 0.0 || width == 0.0 || marker_size == 0.0)
	{
		MessageBox::Show("Please enter the dimension of the object you want to visualize and the marker's size. Don't forget to give the right index of your Camera.");
		return;
	}

	// Vérifier si le BackgroundWorker est déjà en cours d'exécution
	ThreadStart^ threadStart = gcnew ThreadStart(this, &Form1::VideoPlayback);
	Thread^ videoThread = gcnew Thread(threadStart);
	videoThread->Start();
}
	  
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {

	rotation_angle = trackBar2->Value;
}

private: System::Void numericUpDownOHLV_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		   height = ((float)numericUpDownOHLV->Value) / 100;
	   }

private: System::Void numericUpDownOWLV_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	width = ((float)numericUpDownOWLV->Value) / 100;
}

private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
		   cancel_loop = true;

		   if (videoThread != nullptr && videoThread->IsAlive)
		   {
			   videoThread->Join();
		   }

		   pictureBox3->Image = nullptr;
	   }

private: System::Void listView4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listView4->SelectedItems->Count > 0)
	{
		overlay = true;
		selected_im_Path = imagePathsListView4[listView4->SelectedIndices[0]]->ToString();
	}
}

	   
	   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	             ////////////////////////////// Functions ///////////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


private: void VideoPlayback()
{
	msclr::interop::marshal_context context;
	height = ((float)numericUpDownOHLV->Value) / 100;
	width = ((float)numericUpDownOWLV->Value / 100);
	float marker_size = ((float)numericUpDownMSLV->Value / 100);

	cap->open(0);

	if (!(*cap).isOpened())
	{
		MessageBox::Show("Make sure your camera is connected");
		cancel_loop = true;
		return;
	}

	do
	{

		if (overlay == false)
		{
			cancel_loop = false;
			*cap >> *res_overlay;
		}
		else
		{
			cancel_loop = false;
			std::string overlay_image_path = context.marshal_as<std::string>(selected_im_Path);
			*res_overlay = detect_aruco_and_project_image_with_video(*cap, overlay_image_path, marker_size, height, width, *camMax, *distCoeff, rotation_angle);

		}

		if (res_overlay->empty())
		{
			MessageBox::Show("No frame received");
			cancel_loop = true;
			break;
		}

		DisplayMatInPictureBox(pictureBox3, *res_overlay);

	} while (cancel_loop == false);
}

private: void UpdatePictureBoxGraphics(PictureBox^ pbOut, Bitmap^ bm) {
	Graphics^ graphics = Graphics::FromHwnd(pbOut->Handle);
	RectangleF rect(0, 0, (float)(pbOut->Width), (float)(pbOut->Height));
	graphics->DrawImage(bm, rect);
	delete graphics;
	delete bm; // Supprimer le bitmap après utilisation
}

       void DisplayCurrentImage()
	   {
		   if (currentImageIndex >= 0 && currentImageIndex < imagePaths->Count)
		   {

			   pictureBox1->Image = Image::FromFile(imagePaths[currentImageIndex]);
			   pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
		   }
	   }

	   std::vector<cv::Mat> calibrate_func(std::string image_folder, int height_chess, int width_chess)
	   {
		   std::vector<cv::String> images;
		   cv::glob(image_folder, images);

		   std::vector<std::vector<cv::Point2f>> imagePoints;
		   std::vector<std::vector<cv::Point3f>> objectPoints;
		   cv::Size imageSize;

		   // Spécifiez les dimensions de l'échiquier (chessboard) utilisé dans les images
		   cv::Size boardSize(height_chess, width_chess); // Par exemple, 6x9 pour un échiquier standard

		   // Préparez les points de l'objet (coordonnées 3D du monde réel)
		   std::vector<cv::Point3f> objp;
		   for (int i = 0; i < boardSize.height; i++) {
			   for (int j = 0; j < boardSize.width; j++) {
				   objp.push_back(cv::Point3f(j, i, 0.0f));
			   }
		   }

		   for (const cv::String& image_file : images) {
			   cv::Mat image = cv::imread(image_file);
			   cv::Mat gray;

			   if (image.empty()) {
				   std::cerr << "Erreur : Impossible de charger l'image " << image_file << std::endl;
				   continue;
			   }

			   if (imageSize == cv::Size()) {
				   imageSize = image.size();
			   }
			   else if (imageSize != image.size()) {
				   std::cerr << "Erreur : Les images doivent avoir la même taille." << std::endl;
				   return std::vector<cv::Mat>();
			   }

			   cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

			   std::vector<cv::Point2f> corners;
			   bool found = cv::findChessboardCorners(gray, boardSize, corners);

			   if (found) {
				   cv::cornerSubPix(gray, corners, cv::Size(11, 11), cv::Size(-1, -1),
					   cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));

				   imagePoints.push_back(corners);
				   objectPoints.push_back(objp);

				   // Dessinez les coins sur l'image
				   cv::drawChessboardCorners(image, boardSize, corners, found);
			   }
			   else
			   {
				   return std::vector<cv::Mat>();
			   }

			   DisplayMatInPictureBox(pictureBox1, image);
		   }


		   // Effectuez la calibration de la caméra
		   cv::Mat cameraMatrix, distCoeffs;
		   std::vector<cv::Mat> rvecs, tvecs;
		   std::vector<cv::Mat> res;

		   cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs);
		   res.push_back(cameraMatrix);
		   res.push_back(distCoeffs);

		   return res;
	   }	  

	   void DisplayMatInPictureBox(PictureBox^ pbOut, cv::Mat matSrc)
	   {
		   cv::Mat matDup(matSrc.rows, (matSrc.cols + 3) / 4 * 4, CV_8UC3);
		   cv::Rect rectSrc(0, 0, matSrc.cols, matSrc.rows);
		   matSrc(rectSrc).copyTo(matDup(rectSrc));

		   IntPtr ptr(matDup.ptr());
		   int iStride = matDup.step;

		   Bitmap^ bm = gcnew Bitmap(matDup.cols, matDup.rows, iStride, Imaging::PixelFormat::Format24bppRgb, ptr);

		   // Encapsulez la mise à jour du PictureBox dans une action
		   UpdatePictureBoxDelegate^ action = gcnew UpdatePictureBoxDelegate(this, &Form1::UpdatePictureBoxGraphics);

		   // Exécutez l'action dans le thread de l'interface utilisateur
		   pbOut->Invoke(action, gcnew array<Object^> {pbOut, bm});

	   }

	   bool IsImageFile(String^ filePath) {
		   array<String^>^ validExtensions = { ".jpg", ".jpeg", ".png", ".bmp", ".gif", ".HEIC"}; // Ajoutez d'autres extensions si nécessaire

		   String^ extension = System::IO::Path::GetExtension(filePath)->ToLower();

		   for each (String ^ validExtension in validExtensions) {
			   if (extension == validExtension) {
				   return true;
			   }
		   }

		   return false;
	   }

	   void detectEstimMarkerPos(const std::string& image_path, float marker_length, cv::Mat cameraMatrix, cv::Mat DistCoeff, std::vector<cv::Vec3d>& rvec, std::vector<cv::Vec3d>& tvec)
	   {
		   // Charger l'image
		   cv::Mat image = cv::imread(image_path);

		   // Détecter les marqueurs ArUco
		   cv::Ptr<cv::aruco::Dictionary> aruco_dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_1000);
		   std::vector<std::vector<cv::Point2f>> corners;
		   std::vector<int> ids;
		   cv::aruco::detectMarkers(image, aruco_dict, corners, ids);

		   if (!ids.empty())
		   {
			   // Estimer la pose du marqueur
			   cv::aruco::estimatePoseSingleMarkers(corners, marker_length, cameraMatrix, DistCoeff, rvec, tvec);
		   }
	   }

	   void rotateImage3D(float rotation_angle, std::vector<cv::Point3f>& rectangle_corner)
	   {
		   // Calculer le centre du rectangle
		   cv::Point2f center(0, 0);
		   for (const cv::Point3f& corner : rectangle_corner)
		   {
			   center.x += corner.x;
			   center.y += corner.y;
		   }
		   center.x /= rectangle_corner.size();
		   center.y /= rectangle_corner.size();

		   // Déplacer le rectangle pour que son centre soit à l'origine
		   for (cv::Point3f& corner : rectangle_corner)
		   {
			   corner.x -= center.x;
			   corner.y -= center.y;
		   }

		   // Appliquer la rotation aux coins du rectangle
		   cv::Mat rotation_matrix = cv::getRotationMatrix2D(cv::Point2f(0, 0), rotation_angle, 1.0);

		   for (cv::Point3f& corner : rectangle_corner)
		   {
			   cv::Mat corner_mat = (cv::Mat_<double>(3, 1) << corner.x, corner.y, 1.0);
			   corner_mat = rotation_matrix * corner_mat;
			   corner = cv::Point3f(corner_mat.at<double>(0, 0), corner_mat.at<double>(1, 0), 0);
		   }

		    // Déplacer le rectangle de nouveau à sa position d'origine
		   for (cv::Point3f& corner : rectangle_corner)
		   {
			   corner.x += center.x;
			   corner.y += center.y;
		   }
	   }

	   cv::Mat detect_aruco_and_project_image(const std::string& image_path,const std::string& overlay_image_path, std::vector<cv::Point3f>& rectangle_corner, cv::Mat cameraMatrix, cv::Mat DistCoeff,std::vector<cv::Vec3d> rvec, std::vector<cv::Vec3d>tvec)
	   {
		   // Charger l'image
		   cv::Mat image = cv::imread(image_path);

		   // Charger l'image à projeter
		   cv::Mat overlay_image = cv::imread(overlay_image_path);


		   if (!rvec.empty() && !tvec.empty())
		   {

				   std::vector<cv::Point2f> image_points;

				   cv::projectPoints(rectangle_corner, rvec, tvec, cameraMatrix, DistCoeff, image_points);

				   *rectangle_corners_image = image_points;

				   // Calculer la transformation homographique
				   std::vector<cv::Point2f> overlay_corners = { {0, 0},
															   {(float)overlay_image.cols, 0},
															   {(float)overlay_image.cols, (float)overlay_image.rows},
															   {0, (float)overlay_image.rows} };

				   cv::Mat homography = cv::findHomography(overlay_corners, image_points);

				   //cv::Mat homography = cv::getPerspectiveTransform(overlay_corners, image_points);

				   // Projeter l'image à l'intérieur du rectangle
				   cv::Mat overlay_warped;
				   cv::warpPerspective(overlay_image, overlay_warped, homography, image.size());
				   cv::Mat mask = overlay_warped > 0;

				   // Fusionner les images
				   overlay_warped.copyTo(image, mask);
			   
			   return image;
		   }
		   else
		   {
			   return cv::Mat();
		   }
	   }

	   cv::Mat detect_aruco_and_project_image_with_video(cv::VideoCapture& cap, const std::string& overlay_image_path, float marker_length, float square_length, float square_height, cv::Mat cameraMatrix, cv::Mat distCoeff, float rotation_angle) {

		   cv::Mat frame;
		   cap >> frame;

		   if (frame.empty()) {
			   return cv::Mat();
		   }
		   // Charger l'image à projeter
		   cv::Mat overlay_image = cv::imread(overlay_image_path);
		   if (overlay_image.empty())
		   {
			   return frame;
		   }

		   // Détecter les marqueurs ArUco
		   cv::Ptr<cv::aruco::Dictionary> aruco_dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_1000);
		   std::vector<std::vector<cv::Point2f>> corners;
		   std::vector<int> ids;
		   cv::aruco::detectMarkers(frame, aruco_dict, corners, ids);

		   if (!ids.empty())
		   {
			   // Estimer la pose du marqueur
			   std::vector<cv::Vec3d> rvecs, tvecs;
			   cv::aruco::estimatePoseSingleMarkers(corners, marker_length, cameraMatrix, distCoeff, rvecs, tvecs);

			   for (size_t i = 0; i < ids.size(); i++) {
				   // Estimer la position du rectangle
				   std::vector<cv::Point3f> rectangle_corners = { {-square_length / 2, -square_height / 2, 0},
																 {square_length / 2, -square_height / 2, 0},
																 {square_length / 2, square_height / 2, 0},
																 {-square_length / 2, square_height / 2, 0} };
				   // Appliquer la rotation aux coins du rectangle
				   cv::Mat rotation_matrix = cv::getRotationMatrix2D(cv::Point2f(0, 0), rotation_angle, 1.0);
				   for (cv::Point3f& corner : rectangle_corners) {
					   cv::Mat corner_mat = (cv::Mat_<double>(3, 1) << corner.x, corner.y, 1.0);
					   corner_mat = rotation_matrix * corner_mat;
					   corner = cv::Point3f(corner_mat.at<double>(0, 0), corner_mat.at<double>(1, 0), 0);
				   }
				   std::vector<cv::Point2f> image_points;
				   cv::projectPoints(rectangle_corners, rvecs[i], tvecs[i], cameraMatrix, distCoeff, image_points);

				   // Calculer la transformation homographique
				   std::vector<cv::Point2f> overlay_corners = { {0, 0},
															   {(float)overlay_image.cols, 0},
															   {(float)overlay_image.cols, (float)overlay_image.rows},
															   {0, (float)overlay_image.rows} };
				   cv::Mat homography = cv::findHomography(overlay_corners, image_points);

				   // Projeter l'image à l'intérieur du rectangle
				   cv::Mat overlay_warped;
				   cv::warpPerspective(overlay_image, overlay_warped, homography, frame.size());
				   cv::Mat mask = overlay_warped > 0;

				   // Fusionner les images
				   overlay_warped.copyTo(frame, mask);
			   }

			   return frame;
		   }
		   else {
			   return frame;
		   }
	   }
	   
	   delegate void UpdatePictureBoxDelegate(PictureBox^ pbOut, Bitmap^ bm);

	   void alternativ_calib_func()
	   {
		   msclr::interop::marshal_context context;
		   // Afficher un message demandant si l'utilisateur souhaite enregistrer les résultats.
		   System::Windows::Forms::DialogResult result = MessageBox::Show(
			   "Do you have a yaml file containing the intrinsic parameters of your camera?",
			   "Any yaml file?",
			   MessageBoxButtons::YesNo);

		   if (result == System::Windows::Forms::DialogResult::Yes) {
			   OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			   openFileDialog->Filter = "Fichiers YAML|*.yml";

			   if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			   {
				   // L'utilisateur a sélectionné un fichier de données de calibration
				   std::string calibrationFilePath = context.marshal_as<std::string>(openFileDialog->FileName);

				   cv::FileStorage fs(calibrationFilePath, cv::FileStorage::READ);

				   if (!fs.isOpened()) {
					   MessageBox::Show("Unable to open the yaml file");
				   }
				   else
				   {

					   // Lecture de la matrice de la caméra
					   fs["CameraMatrix"] >> *camMax;

					   // Lecture des coefficients de distorsion
					   fs["DistortionCoefficients"] >> *distCoeff;

					   fs.release(); // Fermeture du fichier YAML

					   MessageBox::Show("Upload succesfull");
				   }

			   }
			   else
			   {

				   MessageBox::Show("You haven't selected any file.",
					   "Cancel",
					   MessageBoxButtons::OK);
			   }

		   }
		   else
		   {
			   MessageBox::Show("Please go to the calibration Tab and calibrate your camera first.",
				   "Calibration required",
				   MessageBoxButtons::OK);
		   }

	   }

	   void translate_3D(float dx, float dy, std::vector<cv::Point3f>& rectangle_corner)
	   {
		   for (int i = 0; i < rectangle_corner.size(); ++i)
		   {
			   rectangle_corner[i].x += dx;
			   rectangle_corner[i].y += dy;
		   }
	   }

	   bool IsMouseInsideRectangle(int mouseX, int mouseY)
	   {

		   msclr::interop::marshal_context context;
		   cv::Mat image = cv::imread(context.marshal_as<std::string>(image_path));

		   // Convertir les coordonnées de la souris en fonction du facteur de zoom
		   double zoomFactorX = static_cast<double>(pictureBox2->Width) / static_cast<double>(image.cols);
		   double zoomFactorY = static_cast<double>(pictureBox2->Height) / static_cast<double>(image.rows);

		   float mousePosX = static_cast<float>(mouseX / zoomFactorX);
		   float mousePosY = static_cast<float>(mouseY / zoomFactorY);


		   // Utiliser la fonction pointPolygonTest pour vérifier si la souris est à l'intérieur du rectangle
		   double result = cv::pointPolygonTest(*rectangle_corners_image, cv::Point2f(mousePosX, mousePosY), false);

		   // Si le résultat est positif, la souris est à l'intérieur du rectangle
		   return result >= 0;

	   }


};

}
