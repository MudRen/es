#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's ring", "��ʦ���" );
	add( "id", ({ "ring" }) );
	set_short( "a wizard's ring", "��ʦ���" );
	set_long( @LONG
	This ring is used by wizard Rashudi. It is made by magical ruby and 
spreads a wanderful power of magic.
LONG
    , @C_LONG
	ħ��ʿ���޵���ϲ���Ľ�ָ������ñ�����ħ���ĺ챦ʯ�Ƴɣ�ɢ����һ�ɲ��ɵ�
����ħ������˵ӵ�еֿ�����ħ����������
C_LONG
	);
	set( "unit", "ֻ" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 10 );
	set( "special_defense", 
	     ([ "poison":5, "magic":10 ]) );
	set( "extra_skills", ([ "black-magic":10 ]) );      
	set( "weight", 5 );
	set( "no_sale", 1);
	set( "value", ({ 6000, "silver" }) );
}
