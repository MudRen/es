#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name( "deer gloves", "¹Ƥ����" );
	add( "id", ({ "gloves" }) );
	set_short( "¹Ƥ����" );
	set_long(
	"����һ˫¹Ƥ�������ף�ͨ��ʩ�����˶���������������Լ��ж���\n"
	);
	set( "unit", "˫" );
        set("material","leather");
	set( "type", "hands" );
	set( "weight", 30 );
	set( "armor_class", 3 );
 	set( "defense_bonus", 3 );
	set("special_defense",(["poison":30 ]));
	set( "value", ({ 240, "silver" }) );
	set( "extra_skills",(["venomlogy":5]) );
}

