#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white du-do", "�׶Ƕ�" );
	add( "id", ({ "du-do","do" }) );
	set_short( "�׶Ƕ�");
	set_long( 
@C_LONG
����һ����ɫ�ĶǶ��������и����Ľ���--����������Ȼ�����������е��Ц����
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
	      ([ "divine": 10,"evil":-5 ]) );
	set( "value", ({ 1200, "silver" }) );
}
