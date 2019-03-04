#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's cloak", "��ʦ����" );
	add( "id", ({ "cloak" }) );
	set_short( "a wizard's cloak", "��ʦ����" );
	set_long( @LONG
	This cloak is used by wizard Rashudi. It is made by magical cloth and 
spreads a wanderful power of magic.
LONG
    , @C_LONG
	ħ��ʿ���޵۹�춴����Ķ������ñ�����ħ���Ĳ�֯�ɣ�ɢ����һ�ɲ��ɵ�
����ħ������˵ӵ�еֿ�����ħ����������
C_LONG
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 10 );
	set( "special_defense",
          ([ "electric":5, "energy":5, "mental":10 ]) );
    set( "extra_skill", ([ "elemental":10 ]) );     
	set( "weight", 30 );
	set( "no_sale", 1);
	set( "value", ({ 5800, "silver" }) );
}
