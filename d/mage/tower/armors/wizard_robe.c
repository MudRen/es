#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's robe", "��ʦħ��" );
	add( "id", ({ "robe", }) );
	set_short( "a wizard's robe", "��ʦħ��");
	set_long( @LONG
	This robe is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	����ħ��ʿ���޵۹�춴����ķ�װ����Ҫ����ֻ������ͨ�Ĳ�֯�ɣ�������ӵ��
����������֮��ķ���������˵���ֿܵ�����ħ����
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 45 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 35 );
	set( "defense_bonus", 10 );
	set( "special_defense" ,
	      ([ "evil": 10, "none":2 ]) );
	set( "extra_skills", ([ "magic-shield" :10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
