#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson robe", "�ʺ�ɫ����" );
	set_short( "�ʺ�ɫ����" );
	set_long(@CLONG
����һ�����ʺ�ɫ�������ɵĻ��ۣ��ڻ��۵ı��滭������������\n"
���ţ�������ʮ�ֹ��� ....\n"
CLONG
         	);
	add("id",({"robe"}));
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 4 );
    set( "special_defense",
          ([ "evil":5, "mental":-3, "divine":-5 ]) );
	set( "weight", 90 );
	set( "value", ({ 470, "silver" }) );
}
