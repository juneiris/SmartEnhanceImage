
// MFCApplication4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



ColorMatrix colormatrix= 
{
	1,	0,	0,	0,	0,
	0,	1,	0,	0,	0,
	0,	0,	1,	0,	0,
	0,	0,	0,	1,	0,
	0,  0,	0,  0,  1
};




// CAboutDlg dialog used for App About



class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication4Dlg dialog



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication4Dlg::IDD, pParent)
	, in_bright1(0)
	, in_contrast(0)
	, in_saturation(0)
	, in_red(0)
	, in_green(0)
	, in_blue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_BRIGHT, m_bright);
	DDX_Control(pDX, IDC_SLIDER_R, m_rvalue);
	DDX_Control(pDX, IDC_SLIDER_G, m_gvalue);
	DDX_Control(pDX, IDC_SLIDER_B, m_bvalue);
	DDX_Control(pDX, IDC_SLIDER_CONTRAST, m_contrast);
	DDX_Control(pDX, IDC_SLIDER1, m_saturation);
	DDX_Control(pDX, IDC_EDIT2, in_bright);
	DDX_Text(pDX, IDC_EDIT2, in_bright1);
	DDX_Text(pDX, IDC_EDIT7, in_contrast);
	DDX_Text(pDX, IDC_EDIT8, in_saturation);
	DDX_Text(pDX, IDC_EDIT3, in_red);
	DDX_Text(pDX, IDC_EDIT4, in_green);
	DDX_Text(pDX, IDC_EDIT5, in_blue);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication4Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BRIGHT, &CMFCApplication4Dlg::OnNMCustomdrawSliderBright)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_R, &CMFCApplication4Dlg::OnNMCustomdrawSliderR)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_G, &CMFCApplication4Dlg::OnNMCustomdrawSliderG)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_B, &CMFCApplication4Dlg::OnNMCustomdrawSliderB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_CONTRAST, &CMFCApplication4Dlg::OnNMCustomdrawSliderContrast)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCApplication4Dlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication4Dlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication4Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT7, &CMFCApplication4Dlg::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CMFCApplication4Dlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication4Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication4Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication4Dlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication4Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication4Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCApplication4Dlg message handlers

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	nWidth = 0;
	nHeight = 0;
	//
	r1=0;
	g1= 0;
	b1= 0;

	r2= 0;
	g2= 0;
	b2= 0;

	r3= 0;
	g3= 0;
	b3= 0;

	rr=0;
	gr=0;
	br=0;


	//relative position
	pos_r=0;
	deltaposr=0;
	pos_g=0;
	deltaposg=0;
	pos_b=0;
	deltaposb=0;

	posbright=0;
	deltaposbright=0;


	deltaBright=0;
	deltaContrast=0;
	f1=0;
	f2=0;
	f3=0;
	fR=0;
	fG=0;
	fB=0;
	sum=0;

	//picture pointer initialization
	m_image=NULL;
	m_image1=NULL;
	m_imagebright=NULL;
	m_imagesaturation=NULL;
	m_imager=NULL;
	m_imageg=NULL;
	m_imageb=NULL;


	//slider initialization
	m_bright.SetRange(-100,100);
	m_bright.SetPos(0);
	m_bright.SetTicFreq(5);

	m_contrast.SetRange(-255,255);
	m_contrast.SetPos(0);
	m_contrast.SetTicFreq(5);

	m_saturation.SetRange(-150,150);
	m_saturation.SetPos(0);
	m_saturation.SetTicFreq(5);


	m_rvalue.SetRange(-100,100);
	m_rvalue.SetPos(0);
	m_rvalue.SetTicFreq(1);

	m_gvalue.SetRange(-100,100);
	m_gvalue.SetPos(0);
	m_gvalue.SetTicFreq(1);

	m_bvalue.SetRange(-100,100);
	m_bvalue.SetPos(0);
	m_bvalue.SetTicFreq(1);




	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	TCHAR szFilter[] = _T("Bmp Image File(*.bmp)|*.bmp|BMP(*.bmp)|*.bmp|JPG Files(*.jpg)|*.jpg|JPEG(*.jpg)|*.jpg||");
	CFileDialog fileDlg(TRUE, _T("bmp"),NULL,0,szFilter,this);
	//CReadImgFile fileDlg(TRUE, NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_EXPLORER|OFN_ENABLETEMPLATE,szFilter);
	CString strFilePath;

	if(IDOK ==fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1,strFilePath);

		//load bmp image
		BmpName = strFilePath;
		EntName = fileDlg.GetFileExt();
		EntName.MakeLower();
		/*if(EntName == ("bmp"||"jpg"))
		{*/
			CDC* pDC = GetDC();
			Graphics graph(pDC->GetSafeHdc());

			//get window size
			CRect winRect;
			GetClientRect(winRect);

			int winWidth = winRect.Width()-350;
			int winHeight = winRect.Height();

			m_image=Bitmap::FromFile(BmpName.AllocSysString());
			m_imagebright=Bitmap::FromFile(BmpName.AllocSysString());
			m_imagesaturation=Bitmap::FromFile(BmpName.AllocSysString());
			
			m_imager=Bitmap::FromFile(BmpName.AllocSysString());
			m_imageg=Bitmap::FromFile(BmpName.AllocSysString());
			m_imageb=Bitmap::FromFile(BmpName.AllocSysString());
			

			
			//get image size
			nWidth = m_image->GetWidth();
			nHeight = m_image->GetHeight();
			Bitmap imagebmp(nWidth,nHeight);

			if(nWidth>nHeight)
			{
				rWidth = winWidth;
				rHeight = nHeight*winWidth/nWidth;
				graph.DrawImage(m_image,0,0,rWidth,rHeight);
			
			}
			else
			{
				rWidth =nWidth*winHeight/nHeight;
				rHeight = winHeight;
				graph.DrawImage(m_image,0,0,rWidth,rHeight);
			
			}
				
			ReleaseDC(pDC);
		/*}*/

	
	}
}


int CMFCApplication4Dlg::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num=0;
	UINT size=0;

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;

	GetImageEncoders(num,size,pImageCodecInfo);

	for(UINT j=0; j<num; ++j)
	{
		if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	}

	free(pImageCodecInfo);
	return -1;

}


void CMFCApplication4Dlg::OnNMCustomdrawSliderBright(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int posb = m_bright.GetPos();
	SetDlgItemInt(IDC_EDIT2,posb);
	//extern CString BmpName;
	ChangeImageBrightness(BmpName,posb);
	deltaposbright=posbright-posb;
	//ChangeImageBrightness1(-deltaposbright);
	posbright=posb;


	//ChangeImageBrightness1(posb);
}





void CMFCApplication4Dlg::ChangeImageBrightness(CString& imagepath,int brightness)
{
	
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);


	//Graphics graph(m_image);
//	Graphics graph(&bitmap);


	REAL f = brightness/255.0f;
	/*if(f>=0)
		f1= 1/(1-f)-1;
	else*/
		f1=f;

	deltaBright=f1*f2;

	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;


	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);

	/*HDC hDC=::GetDC(m_hWnd);
	Effect(hDC);
	::ReleaseDC(m_hWnd,hDC);*/
}

void CMFCApplication4Dlg::ChangeImageBrightness1(int brightness)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());
	
	//m_imagebright=Bitmap::FromFile(BmpName.AllocSysString());
	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	int grey;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{
			
			m_imagebright->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
			grey=0.299*R+0.587*G+0.114*B;
		
			//if((255>R>=200)&&(255>G>=200)&&(255>B>=200))
			if(255>=grey>=200)
			{
				R=R+0.15*brightness;
				G=G+0.15*brightness;
				B=B+0.15*brightness;
			}
			//else if((200>R>=160)&&(255>G>=160)&&(255>B>=160))
			else if(200>grey>=160)
			{
				R=R+0.25*brightness;
				G=G+0.25*brightness;
				B=B+0.25*brightness;
			}
			/*else if(70>=grey>0)
			{
				R=R+0.25*brightness;
				G=G+0.25*brightness;
				B=B+0.25*brightness;
					
			}
			else if(100>=grey>70)
			{
				R=R+0.35*brightness;
				G=G+0.35*brightness;
				B=B+0.35*brightness;
					
			}*/
			else
			{
				R=R+0.4*brightness;
				G=G+0.4*brightness;
				B=B+0.4*brightness;
			}
			
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);
				m_imagesaturation->SetPixel(i,j,colortemp);
				m_imager->SetPixel(i,j,colortemp);
				m_imageg->SetPixel(i,j,colortemp);
				m_imageb->SetPixel(i,j,colortemp);

				
		}
	}

	//m_image=m_imagebright;


	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::OnNMCustomdrawSliderContrast(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int posc = m_contrast.GetPos();
	SetDlgItemInt(IDC_EDIT7,posc);
	//extern CString BmpName;
	ChangeImageContrast(BmpName,posc);
}


void CMFCApplication4Dlg::ChangeImageContrast(CString& imagepath,int contrast)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);

//	Graphics graph(&bitmap);


	REAL f = 0.0f;  //duibidu

	if (contrast >= 0)
		//f = (contrast + 10.0f)/10.0f;
		f2 = (255 + contrast)/255.0f;
	else
		f2 = (255 + contrast)/255.0f;

	deltaContrast=0.5*f2*(1-f2);



	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;


	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);

}




void CMFCApplication4Dlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	int poss = m_saturation.GetPos();
	SetDlgItemInt(IDC_EDIT8,poss);
	ChangeImageSaturation(BmpName,poss);
	//ChangeImageSaturation1(poss);
}



void CMFCApplication4Dlg::swapRGB(double &a, double &b)
{
	a += b;
	b = a-b;
	a -= b;
}

void CMFCApplication4Dlg::ChangeImageSaturation(CString& imagepath, int saturation)
{
	//Color color,colortemp;
	//double colorr,colorg,colorb;
	//double max=0,min=0,c=0;
	//double value=0,S=0,L=0,delta=0;
	//double alpha=0;

	//CDC* pDC = GetDC();
	//Graphics graph(pDC-> GetSafeHdc());

	//Rect rect(0,0,rWidth,rHeight);
	//
	//Bitmap bitmap(rWidth,rHeight);
	//Bitmap image(BmpName);
	//int poss = m_saturation.GetPos();
	//saturation = poss;
	//saturation=saturation/255;
	////saturation = 150;

	//int i=0,j=0;
	//for(i=0;i<nWidth;i++)
	//{
	//	for(j=0;j<nHeight;j++)
	//	{
	//		//m_image->GetPixel(i,j,&color);
	//		image.GetPixel(i,j,&color);
	//		colorr = color.GetRed();
	//		colorg = color.GetGreen();
	//		colorb = color.GetBlue();

	//		max=colorr;
	//		min=colorg;
	//		c=colorb;
	//		if(max<c)
	//			swapRGB(max,c);
	//		if(max<min)
	//			swapRGB(max,min);
	//		if(min>c)
	//			swapRGB(min,c);
	//		delta=(max-min)/255;

	//		//delta=0,S=0
	//		if(delta==0)
	//			return;
	//		value=(max+min)/255;
	//		L=value/2;

	//		if(L<0.5)
	//			S=delta/value;
	//		else
	//			S=delta/(2-value);

	//		

	//		if(saturation>=0)
	//		{
	//			alpha = saturation + S >= 1? S:1-saturation;
	//			alpha = 1/alpha-1;

	//			colorr = colorr + (colorr - L*255)*alpha;
	//			colorg = colorg + (colorg - L*255)*alpha;
	//			colorb = colorb + (colorb - L*255)*alpha;
	//		}
	//		else
	//		{
	//			alpha = saturation;

	//			colorr = L*255 + (colorr-L*255)*(1+alpha);
	//			colorg = L*255 + (colorg-L*255)*(1+alpha);
	//			colorb = L*255 + (colorb-L*255)*(1+alpha);
	//		}

	//		colortemp.SetValue(color.MakeARGB(255,colorr,colorg,colorb));
	//		//m_image->SetPixel(i,j,colortemp);
	//		image.SetPixel(i,j,colortemp);

	//	}
	//}

	//graph.DrawImage(&image,rect,0,0,nWidth,nHeight,UnitPixel);

	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);


	//Graphics graph(m_image);
//	Graphics graph(&bitmap);


	REAL f = 0.0f;
	if(saturation>=0)
	{
		f3 = (255 + saturation*3)/255.0f;
	}
	else
		f3 = (255 + saturation)/255.0f;
	
	fR=(1.0f-f3)*RWGT ;
	fG=(1.0f-f3)*GWGT;
	fB=(1.0f-f3)*BWGT;
	

	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;
	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}



void CMFCApplication4Dlg::ChangeImageSaturation1(int saturation)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());

	
	Rect rect(0,0,rWidth,rHeight);
	
	int i,j;
	Color color,colortemp;
	int R,G,B;
	ARGB argb;

	float max=0,min=0,c=0;
	float value=0,S=0,L=0,delta=0;
	float alpha=0;


	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_imagesaturation->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			if((R>=G)&&(R>=B))
			{
				max=R;
				if(G>=B)
					min=B;
				else
					min=G;
			}
			else if((G>=R)&&(G>=B))
			{
				max=G;
				if(R>=B)
					min=B;
				else
					min=R;
			}
			else if((B>=R)&&(B>=G))
			{
				max=B;
				if(R>=G)
					min=G;
				else
					min=R;
			}

			delta=(max-min)/255;

			//delta=0,S=0
			if(delta!=0)
				
			{
				value=(max+min)/255;
				L=value/2;

				if(L<0.5)
					S=delta/value;
				else
					S=delta/(2-value);


				if(saturation>=0)
				{
					alpha = saturation + S >= 1? S:1-saturation;
					alpha = 1/alpha-1;

					R = R + (R - L*255)*alpha;
					G = G + (G - L*255)*alpha;
					B = B + (B - L*255)*alpha;
				}
				else
				{
					alpha = saturation;

					R = L*255 + (R-L*255)*(1+alpha);
					G = L*255 + (G-L*255)*(1+alpha);
					B = L*255 + (B-L*255)*(1+alpha);
				}
			
			
			}

			
			
			if(R>=255)
				R=255;
			else if(R<=0)
				R=0;
				
				
			if(G>=255)
				G=255;
			else if(G<=0)
				G=0;
				
			if(B>=255)
				B=255;
			else if(B<=0)
				B=0;
				
	
			colortemp.SetValue(color.MakeARGB(255,R,G,B));
			m_image->SetPixel(i,j,colortemp);

				
		}
		
	}



	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}



void CMFCApplication4Dlg::OnNMCustomdrawSliderR(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	int pos_rvalue = m_rvalue.GetPos();
	SetDlgItemInt(IDC_EDIT3,pos_rvalue);
	if(pos_rvalue == 0)
		ColorBalanceR1(0);
	deltaposr=pos_r-pos_rvalue;
	ColorBalanceR1(-deltaposr);
	pos_r=pos_rvalue;
	//ColorBalanceR1(pos_rvalue);

	
}


void CMFCApplication4Dlg::ColorBalanceR(int colorbalancer)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);

	//Graphics graph(&bitmap);
	//r= 255/255.0f;
	g1= 80/255.0f;
	b1= 80/255.0f;

	REAL f = (0.4*colorbalancer+40)/255.0f;
	
	r1=f-0.157;
	g1=g1-f-0.157;
	b1=b1-f-0.157;


	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;

	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);

	
	
}


void CMFCApplication4Dlg::ColorBalanceR1(int colorbalancer)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());

	//m_imager=m_image;
	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R,G,B;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			/*if((R>G)&&(R>B))
			{
			*/	if((255>B>=200)&&(255>G>=200)&&(255>R>=200))
				{
					R=R+0.15*colorbalancer;
					G=G-0.15*colorbalancer;
					B=B-0.15*colorbalancer;
				}
				else if((200>B>=160)&&(255>G>=160)&&(200>R>=160))
				{
					R=R+0.2*colorbalancer;
					G=G-0.2*colorbalancer;
					B=B-0.2*colorbalancer;
				}
				else if((50>=R>0)&&(50>=G>0)&&(50>=B>0))
				{
					R=R+0.3*colorbalancer;
					G=G-0.3*colorbalancer;
					B=B-0.3*colorbalancer;
				}
				else
				{
					R=R+0.35*colorbalancer;
					G=G-0.35*colorbalancer;
					B=B-0.35*colorbalancer;
				}
			/*	
			}
			
			else
			{
				R=R+0.25*colorbalancer;
				G=G-0.25*colorbalancer;
				B=B-0.25*colorbalancer;
			}*/
			
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);
				/*m_imagebright->SetPixel(i,j,colortemp);
				m_imageg->SetPixel(i,j,colortemp);
				m_imageb->SetPixel(i,j,colortemp);*/

				
		}
	}



	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}


void CMFCApplication4Dlg::OnNMCustomdrawSliderG(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	int pos_gvalue = m_gvalue.GetPos();
	SetDlgItemInt(IDC_EDIT4,pos_gvalue);
	if(pos_gvalue == 0)
		ColorBalanceG1(0);
	deltaposg=pos_g-pos_gvalue;
	ColorBalanceG1(-deltaposg);
	pos_g=pos_gvalue;
	//ColorBalanceG(pos_gvalue);
	
}


void CMFCApplication4Dlg::ColorBalanceG(int colorbalanceg)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);

//	Graphics graph(&bitmap);
	r2= 100/255.0f;
	b2= 100/255.0f;

	REAL f =  (0.5*colorbalanceg+50)/255.0f;
	g2=f-0.195;
	r2=r2-f-0.195;
	b2=b2-f-0.195;

	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;
	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::ColorBalanceG1(int colorbalanceg)
{
	
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			if((255>R>=200)&&(255>G>=200)&&(255>B>=200))
			{
				R=R-0.1*colorbalanceg;
				G=G+0.1*colorbalanceg;
				B=B-0.1*colorbalanceg;
			}
			else if((200>R>=160)&&(255>G>=160)&&(255>B>=160))
			{
				R=R-0.15*colorbalanceg;
				G=G+0.15*colorbalanceg;
				B=B-0.15*colorbalanceg;
			}
			else if((50>=R>0)&&(50>=G>0)&&(50>=B>0))
			{
				R=R-0.3*colorbalanceg;
				G=G+0.3*colorbalanceg;
				B=B-0.3*colorbalanceg;
					
			}
			else
			{
				R=R-0.35*colorbalanceg;
				G=G+0.35*colorbalanceg;
				B=B-0.35*colorbalanceg;
			}
			
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::OnNMCustomdrawSliderB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	//@TN
		//*pResult = 0;
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int pos_bvalue = m_bvalue.GetPos();
	SetDlgItemInt(IDC_EDIT5,pos_bvalue);
	if(pos_bvalue == 0)
		ColorBalanceB1(0);
	deltaposb=pos_b-pos_bvalue;
	ColorBalanceB1(-deltaposb);
	pos_b=pos_bvalue;
	//ColorBalanceB(pos_bvalue);
	
}


void CMFCApplication4Dlg::ColorBalanceB(int colorbalanceb)
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	
	Bitmap bitmap(rWidth,rHeight);

//	Graphics graph(&bitmap);
	r3= 100/255.0f;
	g3= 100/255.0f;

	REAL f =  (0.5*colorbalanceb+50)/255.0f;
	
	b3=f-0.195;
	r3=r3-f-0.195;
	g3=g3-f-0.195;


	colormatrix.m[0][0]=f2*(fR+f3);
	colormatrix.m[0][1]=colormatrix.m[0][2]=f2*fR;
	colormatrix.m[1][0]=colormatrix.m[1][2]=f2*fG;
	colormatrix.m[1][1]=f2*(fG+f3);
	colormatrix.m[2][0]=colormatrix.m[2][1]=f2*fB;
	colormatrix.m[2][2]=f2*(fG+f3);
	colormatrix.m[4][0]=deltaBright+deltaContrast+r1+r2+r3;
	colormatrix.m[4][1]=deltaBright+deltaContrast+g1+g2+g3;
	colormatrix.m[4][2]=deltaBright+deltaContrast+b1+b2+b3;

	/*ColorMatrix colormatrix =
	{
		f2*(fR+f3),f2*fR,f2*fR,0,0,
		f2*fG,f2*(fG+f3),f2*fG,0,0,
		f2*fB,f2*fB,f2*(fG+f3),0,0,
		0,0,0,1,0,
		deltaBright+deltaContrast+r1+r2+r3,deltaBright+deltaContrast+g1+g2+g3,deltaBright+deltaContrast+b1+b2+b3,0,1
	};*/

	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::ColorBalanceB1(int colorbalanceb)
{
	
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			if((255>R>=200)&&(255>G>=200)&&(255>B>=200))
			{
				R=R-0.1*colorbalanceb;
				G=G-0.1*colorbalanceb;
				B=B+0.1*colorbalanceb;
			}
			else if((200>R>=160)&&(255>G>=160)&&(255>B>=160))
			{
				R=R-0.15*colorbalanceb;
				G=G-0.15*colorbalanceb;
				B=B+0.15*colorbalanceb;
			}
			else if((50>=R>0)&&(50>=G>0)&&(50>=B>0))
			{
				R=R-0.3*colorbalanceb;
				G=G-0.3*colorbalanceb;
				B=B+0.3*colorbalanceb;
					
			}
			else
			{
				R=R-0.35*colorbalanceb;
				G=G-0.35*colorbalanceb;
				B=B+0.35*colorbalanceb;
			}
			
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}





void CMFCApplication4Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	/*ChangeImageBrightness(BmpName,0);
	ChangeImageContrast(BmpName,0);
	ChangeImageSaturation(BmpName,0);
	ColorBalanceR1(0);
	ColorBalanceG1(0);
	ColorBalanceB1(0);*/
	CDC* pDC=GetDC();
	Graphics graph(pDC->GetSafeHdc());
	m_image=Bitmap::FromFile(BmpName.AllocSysString());
	graph.DrawImage(m_image,0,0,rWidth,rHeight);
}




void  CMFCApplication4Dlg::curvewarm()
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			/*R=-0.00002165*R*R*R+0.008141*R*R+0.3427*R-2.529;
			G=-0.00002165*G*G*G+0.008141*G*G+0.3427*G-2.529;
			B=-0.00002165*B*B*B+0.008141*B*B+0.3427*B-2.529;*/
			R=-0.00001992*R*R*R+0.007607*R*R+0.3551*R+0.06618;
			G=-0.00001992*G*G*G+0.007607*G*G+0.3551*G+0.06618;
			//B=-0.00001992*B*B*B+0.007607*B*B+0.3551*B+0.06618;
			//R=0.000000104*R*R*R*R-0.00007322*R*R*R+0.01526*R*R+0.1657*R-5.678;
			//G=0.000000104*G*G*G*G-0.00007322*G*G*G+0.01526*G*G+0.1657*G-5.678;
			//B=0.000000104*B*B*B*B-0.00007322*B*B*B+0.01526*B*B+0.1657*B-5.678;
				
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}


void CMFCApplication4Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	
	//ChangeImageBrightness(BmpName,10);
	ChangeImageSaturation(BmpName,40);
	ChangeImageBrightness1(15);
	ChangeImageContrast(BmpName,10);
	curvewarm();
	
	//ColorBalanceR1(17);
	//ColorBalanceG1(0);
	ColorBalanceB1(-5);
}


void  CMFCApplication4Dlg::curveold()
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			//R=-0.00002165*R*R*R+0.008141*R*R+0.3427*R-2.529;
			G=-0.00002165*G*G*G+0.008141*G*G+0.3427*G-2.529;
			B=-0.00002165*B*B*B+0.008141*B*B+0.3427*B-2.529;
			//R=-0.00001992*R*R*R+0.007607*R*R+0.3551*R+0.06618;
			//G=-0.00001992*G*G*G+0.007607*G*G+0.3551*G+0.06618;
			//B=-0.00001992*B*B*B+0.007607*B*B+0.3551*B+0.06618;
			//R=0.000000104*R*R*R*R-0.00007322*R*R*R+0.01526*R*R+0.1657*R-5.678;
			//G=0.000000104*G*G*G*G-0.00007322*G*G*G+0.01526*G*G+0.1657*G-5.678;
			//B=0.000000104*B*B*B*B-0.00007322*B*B*B+0.01526*B*B+0.1657*B-5.678;
				
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	ChangeImageSaturation(BmpName,30);
	
	//ChangeImageContrast(BmpName,10);
	
	//ColorBalanceR1(5);
	//ColorBalanceG1(-5);
	//ColorBalanceB1(-20);
	curveold();
	//ChangeImageBrightness1(10);

	
}



void  CMFCApplication4Dlg::curvecold()
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			/*R=-0.00002165*R*R*R+0.008141*R*R+0.3427*R-2.529;
			G=-0.00002165*G*G*G+0.008141*G*G+0.3427*G-2.529;
			B=-0.00002165*B*B*B+0.008141*B*B+0.3427*B-2.529;*/
			R=-0.00001992*R*R*R+0.007607*R*R+0.3551*R+0.06618;
			//G=-0.00001992*G*G*G+0.007607*G*G+0.3551*G+0.06618;
			B=-0.00001992*B*B*B+0.007607*B*B+0.3551*B+0.06618;
			//R=0.000000104*R*R*R*R-0.00007322*R*R*R+0.01526*R*R+0.1657*R-5.678;
			//G=0.000000104*G*G*G*G-0.00007322*G*G*G+0.01526*G*G+0.1657*G-5.678;
			//B=0.000000104*B*B*B*B-0.00007322*B*B*B+0.01526*B*B+0.1657*B-5.678;
				
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}

void CMFCApplication4Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	ChangeImageBrightness1(40);
	//ChangeImageContrast(BmpName,15);
	ChangeImageSaturation(BmpName,-20);
	//ColorBalanceR1(-5);
	ColorBalanceG1(5);
	ColorBalanceB1(10);
	curvecold();
}


void CMFCApplication4Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

//#1015c

	// TODO:  Add your control notification handler code here
	in_bright1=GetDlgItemInt(IDC_EDIT2);
	m_bright.SetPos(in_bright1);
}


void CMFCApplication4Dlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.



	// TODO:  Add your control notification handler code here
	in_contrast=GetDlgItemInt(IDC_EDIT7);
	m_contrast.SetPos(in_contrast);
}


void CMFCApplication4Dlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.



	// TODO:  Add your control notification handler code here
	in_saturation=GetDlgItemInt(IDC_EDIT8);
	m_saturation.SetPos(in_saturation);
}


void CMFCApplication4Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  Add your control notification handler code here
	in_red=GetDlgItemInt(IDC_EDIT3);
	m_rvalue.SetPos(in_red);
}


void CMFCApplication4Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	in_green=GetDlgItemInt(IDC_EDIT4);
	m_gvalue.SetPos(in_green);
}


void CMFCApplication4Dlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  Add your control notification handler code here
	in_blue=GetDlgItemInt(IDC_EDIT5);
	m_bvalue.SetPos(in_blue);
}

void  CMFCApplication4Dlg::curvenormal()
{
	CDC* pDC = GetDC();
	Graphics graph(pDC->GetSafeHdc());


	Rect rect(0,0,rWidth,rHeight);
	//colorbalancer=40;
	//REAL f = 0.4*colorbalancer+40;
	int i,j;
	Color color,colortemp;
	REAL R=0,G=0,B=0;
	ARGB argb;

	for(i=0;i<nWidth;i++)
	{
		for(j=0;j<nHeight;j++)
		{

			m_image->GetPixel(i,j,&color);
			argb=color.GetValue();

			R=color.GetR();
			G=color.GetG();
			B=color.GetB();
		
			/*R=-0.00002165*R*R*R+0.008141*R*R+0.3427*R-2.529;
			G=-0.00002165*G*G*G+0.008141*G*G+0.3427*G-2.529;
			B=-0.00002165*B*B*B+0.008141*B*B+0.3427*B-2.529;*/
			R=-0.00001992*R*R*R+0.007607*R*R+0.3551*R+0.06618;
			G=-0.00001992*G*G*G+0.007607*G*G+0.3551*G+0.06618;
			B=-0.00001992*B*B*B+0.007607*B*B+0.3551*B+0.06618;
			/*R=0.000000104*R*R*R*R-0.00007322*R*R*R+0.01526*R*R+0.1657*R-5.678;
			G=0.000000104*G*G*G*G-0.00007322*G*G*G+0.01526*G*G+0.1657*G-5.678;
			B=0.000000104*B*B*B*B-0.00007322*B*B*B+0.01526*B*B+0.1657*B-5.678;*/
				
			
				if(R>=255)
					R=255;
				else if(R<=0)
					R=0;
				
				
				if(G>=255)
					G=255;
				else if(G<=0)
					G=0;
				
				if(B>=255)
					B=255;
				else if(B<=0)
					B=0;
				
	
			
				colortemp.SetValue(color.MakeARGB(255,R,G,B));
				m_image->SetPixel(i,j,colortemp);

				
		}
	}




	ImageAttributes imageAttr;
	imageAttr.SetColorMatrix(&colormatrix);

	//draw new brightness changed image with the color matrix
	graph.DrawImage(m_image,rect,0,0,nWidth,nHeight,UnitPixel,&imageAttr);
}
void CMFCApplication4Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	//curve();
	//ChangeImageSaturation(BmpName,50);
	
	curvenormal();
	ChangeImageSaturation(BmpName,60);
	//ChangeImageContrast(BmpName,-10);
	ChangeImageBrightness1(10);
	//ColorBalanceR1(5);

}


void CMFCApplication4Dlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	
	CLSID encoderClsid;
	GetEncoderClsid(L"image/bmp",&encoderClsid);
	m_image->Save(L"C:\\Users\\xuchuwen\\Desktop\\process.bmp",&encoderClsid,NULL);
}
