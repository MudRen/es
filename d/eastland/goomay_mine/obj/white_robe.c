#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white robe", "����" );
	add( "id", ({ "robe", }) );
	set_short( "����");
	set_long(@C_LONG
	һ�������Ͼ�İ�ɫ���ӣ�����������������ʥ���ԣ�ʹ�˾���ֻҪ
	������������ӵ��ˣ�������һ�������ĺ��ˣ����а���ħ��Ҳ\����
	Щ\��\�ı���������	
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 24 );
	set( "defense_bonus", 9 );
	set( "special_defense" ,
	      ([ "evil": 5 ]) );
	set( "value", ({ 2000, "silver" }) );
}
