#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "magical robe", "ħ������" );
	add( "id", ({ "robe" }) );
	set_short( "ħ������" );
	set_long( @C_LONG
    Ī�Ǵ����ϵ�ħ��ʦ��ϲ�����ĳ���, ��˵����һЩħ����
C_LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 4 );
	set( "special_defense",
	      ([ "magic":5, "fire":-3 ]) ); 
        set( "weight", 50 );
	set( "value", ({ 1500, "silver" }) );
}
