
// MFCApplication4Dlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCApplication4Dlg dialog
class CMFCApplication4Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	CString BmpName;
	CString EntName;
	int nWidth;
	int nHeight;
	int rWidth;
	int rHeight;


	ColorMatrix m_colormatrix;

	Bitmap* m_image;
	Bitmap* m_image1;
	Bitmap* m_imagebright;
	Bitmap* m_imagesaturation;
	Bitmap* m_imager;
	Bitmap* m_imageg;
	Bitmap* m_imageb;



	//BRIGHT AND CONTRAST AND saturatiON
	REAL deltaBright;
	REAL deltaContrast;
	REAL f1,f2,f3;
	REAL fR,fG,fB;
	REAL sum;

	int posbright;
	int deltaposbright;

	//color balance
	REAL r1;
	REAL g1;
	REAL b1;

	REAL r2;
	REAL g2;
	REAL b2;

	REAL r3;
	REAL g3;
	REAL b3;

	//relative position
	int pos_r;
	int deltaposr;
	int pos_g;
	int deltaposg;
	int pos_b;
	int deltaposb;

	REAL rr,gr,br;




	CSliderCtrl m_bright;
	afx_msg void OnNMCustomdrawSliderBright(NMHDR *pNMHDR, LRESULT *pResult);
	
	int GetEncoderClsid(const WCHAR* format, CLSID* pClisid);
	void ChangeImageBrightness(CString& imagepath, int brightness);
	void ChangeImageBrightness1(int brightness);
	void ChangeImageContrast(CString& imagepath, int contrast);
	void ChangeImageSaturation(CString& imagepath, int saturation);
	void ChangeImageSaturation1(int saturation);
	
	
	void curvenormal();
	void curvewarm();
	void curvecold();
	void curveold();


	void ColorBalanceR(int colorbalancer);
	void ColorBalanceR1(int colorbalancer);
	void ColorBalanceG(int colorbalanceg);
	void ColorBalanceG1(int colorbalanceg);
	void ColorBalanceB(int colorbalanceb);
	void ColorBalanceB1(int colorbalanceb);

	void swapRGB(double &a, double &b);

	void Effect(HDC hDC);
	//void WinClear();
	CSliderCtrl m_rvalue;
	afx_msg void OnNMCustomdrawSliderR(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_gvalue;
	CSliderCtrl m_bvalue;
	afx_msg void OnNMCustomdrawSliderG(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderB(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_contrast;
	afx_msg void OnNMCustomdrawSliderContrast(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_saturation;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CEdit in_bright;
	afx_msg void OnEnChangeEdit2();
	int in_bright1;
	int in_contrast;
	afx_msg void OnEnChangeEdit7();
	int in_saturation;
	afx_msg void OnEnChangeEdit8();
	int in_red;
	afx_msg void OnEnChangeEdit3();
	int in_green;
	afx_msg void OnEnChangeEdit4();
	int in_blue;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
