#include "capital.h"
QString g_strDigit[] = {QString::fromLocal8Bit("零"), QString::fromLocal8Bit("壹"), QString::fromLocal8Bit("贰"), QString::fromLocal8Bit("叁"), QString::fromLocal8Bit("肆"), QString::fromLocal8Bit("伍"), QString::fromLocal8Bit("陆"), QString::fromLocal8Bit("柒"), QString::fromLocal8Bit("捌"),QString::fromLocal8Bit("玖")};

QString g_strUnit[] = {QString::fromLocal8Bit("圆"), QString::fromLocal8Bit("拾"), QString::fromLocal8Bit("佰"), QString::fromLocal8Bit("仟"), QString::fromLocal8Bit("万"), QString::fromLocal8Bit("拾"),QString::fromLocal8Bit("佰"),QString::fromLocal8Bit("仟"), QString::fromLocal8Bit("亿"), 
	QString::fromLocal8Bit("拾"), QString::fromLocal8Bit("佰"), QString::fromLocal8Bit("仟"), QString::fromLocal8Bit("万"), QString::fromLocal8Bit("拾"), QString::fromLocal8Bit("佰")};

QString g_strUnit2[] = {QString::fromLocal8Bit("角"), QString::fromLocal8Bit("分")};

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
    char *pcDecimal     = NULL; //保存小数部分字符
    char czNumber[MAX]  = {0};  //保存完整数字部分字符
    QString strResult;



    //判断是否为小数
    if (money < 0)
    {
        strResult = QString::fromLocal8Bit("不支持读负数");   
        return strResult;   
    }

    //将数字转为数字字符串，利用sprintf_s的正则转换
    sprintf_s(czNumber, MAX, "%.15lg", money);
    printf("[No.0]%s\n", czNumber); 

    //如果数字是太大或太小的数，因为已经转为科学计数，所以会含有e字符
    p = strchr(czNumber,'e');  
    if (NULL!=p) 
    {
        strResult = QString::fromLocal8Bit("不支持读太大或太小的数");
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


    //把strResult中的所有"零零"子串替换为"零"
    while (1)
    {
        ret = ReplaceSubStr(strResult.toStdString(), "零零","零");
        if (ret < 0)
        {
            break;
        }
    }


    ReplaceSubStr(strResult.toStdString(), "零亿", "亿");
    ReplaceSubStr(strResult.toStdString(),"零万", "万");
    if (strResult != QString::fromLocal8Bit("零圆"))    //如果整数部分全为0，则不要去除元单位前面的零
    {
        ReplaceSubStr(strResult.toStdString(), "零圆","圆");
    }
    

    //小数精确到两位数，即精确到单位分
    if (NULL != pcDecimal) 
    {
        //如果小数部分有数值而整数部分为0，则删除字符串中的零元
        if (strResult == QString::fromLocal8Bit("零圆"))
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
