#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "archmaster robe", "���ʦ��" );
	add( "id", ({ "robe", }) );
	set_short( "���ʦ��");
	set_long( 
@C_LONG
���Ƕ����ʵ۴͸����ʦ�ĳ��ۣ���˵���ù�ʱ����ĳ������������������
���Ƴɣ��йɰ����Ĺ�â��
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 55 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 38 );
	set( "defense_bonus", 5 );
	set( "special_defense" ,
	      ([ "all": 20, "none":10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
