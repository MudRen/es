#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring", "�������" );
	add( "id", ({ "ring","blue" }) );
	set_short( "love ring", "�������" );
	set_long(@C_LONG
һֻ������ɫ��â�Ľ�ָ���������ƺ��е㲻Ѱ����������������е�����
����ʧΪһ����ʾ��������
C_LONG
	);
	set( "unit", "ֻ" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 6 );
	set( "special_defense", 
	     ([ "fire":2 ]) );      
	set( "weight", 5 );
	set( "value", ({ 2500, "silver" }) );
}
