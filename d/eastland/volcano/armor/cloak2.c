#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "green cloak", "�̶���" );
	add( "id", ({ "cloak" }) );
	set_short( "�̶���" );
	set_long( 
@LONG
���ǡ����������Ķ����ʵֻ��һ����ɫ�Ĳ��������Ǵӡ�������ʱ�ʹ�����
�ڣ���������һ���������Ѿ���һ�����ԣ����һЩħ���н�ǿ�Ŀ�����
LONG
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "mage");
	set( "armor_class", 5 );
	set( "defense_bonus", 6 );
	set( "extra_skills", ([
	  "black-magic" : 10, "white-magic" : -10, "elemental" : 5, ])
	);
	set( "special_defense", ([
	  "cold" : 30, "electric" : 20, "fire" : -10, ])
    );
	set( "no_sale", 1);
	set( "weight", 40 );
	set( "value", ({ 1000, "silver" }) );
}
