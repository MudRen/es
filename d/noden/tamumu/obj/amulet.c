#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "amulet of Cybilas", "�����" );
	add( "id", ({ "amulet" }) );
	set_short( "������˹�����" );
	set_long(@C_LONG
������������˸��һ��һ����ɫ�İ׹⣬���������ҫ�۵����ǣ����㽫��
�������е�ʱ�򣬿��Ըо���������ů��
C_LONG
        );
	set( "type", "misc" );
	set( "material" ,"element");
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", 
	      ([ "acid":5, "fire":5, "evil":-2 ]) );
	set( "weight", 15 );
	set( "value", ({ 205, "gold" }) );
}
