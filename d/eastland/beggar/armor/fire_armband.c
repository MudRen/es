#include "../dony.h"

inherit ARMOR;
void create()
{
     set_name( "fire armband","���ƻ���" );
     add( "id",({ "armband" }) );
     set_short( "���ƻ���" );
     set_long(@C_LONG
����һ�����л���ò�ıۻ�������Ļ��������һƬƬ�ĸ���,����Χ�Ƶ�������
Ϊ���͡�������,�����������һ֧���ƴ�������Ļ���, �������˻����ޱ�����
ò��
C_LONG
     );
     set( "unit","˫" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 620,"silver" }) );
}