#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Five-Color In", "��ɫӡ" );
	add( "id", ({ "shield","in" }) );
	set_short( "��ɫӡ" );
	set_long( 
@C_LONG
����һ��Ư����ӡʯ��������ҫ��������ɫ�Ĺ�â���졢�̡������ס���ɫ�Ĺ��
������˸��������Ŀ��Ͼ����
C_LONG
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "stone");
	set( "armor_class", 8 );
	set( "defense_bonus", 6 );
	set( "special_defense",
	     ([ "none":5, "evil":5 ]) );
	set( "extra_skills",([ "block":7 ]) );     
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 4750, "silver" }) );
}
