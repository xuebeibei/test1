#include "capital.h"
QString g_strDigit[] = {QString::fromLocal8Bit("��"), QString::fromLocal8Bit("Ҽ"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("½"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("��"),QString::fromLocal8Bit("��")};

QString g_strUnit[] = {QString::fromLocal8Bit("Բ"), QString::fromLocal8Bit("ʰ"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("Ǫ"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("ʰ"),QString::fromLocal8Bit("��"),QString::fromLocal8Bit("Ǫ"), QString::fromLocal8Bit("��"), 
	QString::fromLocal8Bit("ʰ"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("Ǫ"), QString::fromLocal8Bit("��"), QString::fromLocal8Bit("ʰ"), QString::fromLocal8Bit("��")};

QString g_strUnit2[] = {QString::fromLocal8Bit("��"), QString::fromLocal8Bit("��")};

Capital::Capital()
{

}
int Capital:: ReplaceSubStr(std::string &strOrig, std::string strSub, std::string strReplace)
{
    int pos = (int)(strOrig.find(strSub));
    int length = (int)strSub.length();
    
    if (pos >= 0)
    {
        strOrig.replace(pos, length, strReplace);
        return 0;
    }
    
    return -1;
}
QString Capital::NumToChineseStr(double money)
{
    int i               = 0;
    int ret             = 0;
    int length          = 0;
    char *p             = NULL;
    char *pcDecimal     = NULL; //����С�������ַ�
    char czNumber[MAX]  = {0};  //�����������ֲ����ַ�
    QString strResult;



    //�ж��Ƿ�ΪС��
    if (money < 0)
    {
        strResult = QString::fromLocal8Bit("��֧�ֶ�����");   
        return strResult;   
    }

    //������תΪ�����ַ���������sprintf_s������ת��
    sprintf_s(czNumber, MAX, "%.15lg", money);
    printf("[No.0]%s\n", czNumber); 

    //���������̫���̫С��������Ϊ�Ѿ�תΪ��ѧ���������ԻẬ��e�ַ�
    p = strchr(czNumber,'e');  
    if (NULL!=p) 
    {
        strResult = QString::fromLocal8Bit("��֧�ֶ�̫���̫С����");
        return strResult;
    }
    
    p = strchr(czNumber, '.');  
    if (NULL != p) 
    {       
        p[0] = 0;    
        pcDecimal = p + 1;   
    }    
    length = (int)strlen(czNumber);  
    
    for (i = 0; i<length; i++) 
    {        
        if ('0' == czNumber[i] && 0 != ((length-1-i) % 4))
        {
            strResult += g_strDigit[czNumber[i] - '0'];
        } 
        else 
        {
            strResult += g_strDigit[czNumber[i] - '0'] + g_strUnit[length-1-i];
        }   
    }


    //��strResult�е�����"����"�Ӵ��滻Ϊ"��"
    while (1)
    {
        ret = ReplaceSubStr(strResult.toStdString(), "����","��");
        if (ret < 0)
        {
            break;
        }
    }


    ReplaceSubStr(strResult.toStdString(), "����", "��");
    ReplaceSubStr(strResult.toStdString(),"����", "��");
    if (strResult != QString::fromLocal8Bit("��Բ"))    //�����������ȫΪ0����Ҫȥ��Ԫ��λǰ�����
    {
        ReplaceSubStr(strResult.toStdString(), "��Բ","Բ");
    }
    

    //С����ȷ����λ��������ȷ����λ��
    if (NULL != pcDecimal) 
    {
        //���С����������ֵ����������Ϊ0����ɾ���ַ����е���Ԫ
        if (strResult == QString::fromLocal8Bit("��Բ"))
        {
            strResult.clear();
        }
        i = 0;
        while (1) 
        {           
            if (0 == pcDecimal[i] || i >= 2) 
                break;   
            strResult += g_strDigit[pcDecimal[i] - '0'] + g_strUnit2[i];
            i++;      
        }   
    }
    
    return strResult;
}
