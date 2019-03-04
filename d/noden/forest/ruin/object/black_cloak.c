#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black cloak", "�ڶ���" );
	add( "id", ({ "cloak" }) );
	set_short( "�ڶ���" );
	set_long( @C_LONG
ڤ��ħ��ʿ��ħ��춴����ĺ�ɫ����������������ã���ȴɢ����һ��а��
����������˵�ֿܵ����ֺ�ħ���Ĺ�����
C_LONG
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "mage");
	set( "armor_class", 8 );
	set( "defense_bonus", 6 );
	set( "extra_stats", ([
	"int" : 3, "pie" : -5, "con" : -4, ])
	);
	set( "extra_skills", ([
	  "black-magic" : 10, "white-magic" : -10, "elemental" : 5, ])
	);
	set( "special_defense", ([
	  "cold" : 30, "electric" : 20, "fire" : -10, ])
    );
	set( "no_sale", 1);
	set( "weight", 40 );
	set( "value", ({ 5, "silver" }) );
}
