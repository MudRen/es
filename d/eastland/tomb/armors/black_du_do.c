#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black du-do", "�ڶǶ�" );
	add( "id", ({ "du-do","do" }) );
	set_short( "�ڶǶ�");
	set_long( 
@C_LONG
����һ����ɫ�ĶǶ������滭��һֻ���������롣��Ȼ�����������е��Ц����
��ȴ���ṩ�൱�õı�����
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 3 );
	set( "special_defense" ,
	      ([ "divine": -5,"evil":10 ]) );
	set( "extra_skills", ([ "runes" :10 ]) );
	set( "value", ({ 1200, "silver" }) );
}
