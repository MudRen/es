#include "../oldcat.h"

inherit ARMOR;

void create()
{
	set_name( "dark shield", "����" );
	add( "id", ({ "shield" }) );
	set_short(  "����" );
	set_long( 
             @LONG
�������������ѧ����ɣ���ɽ��ǰ������ʦ���������ģ�����ʦ��˵����ܲ�
���κ�а��Ĺ�������������ɱ����ħ��Ҫ�ķ��ߡ�
LONG
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "heavy_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "mental":-5 ]) );
	set( "extra_skills",([ "block":5 ]) );     
	set( "weight", 130 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
