#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Bracer","��ɫ����" );
	add( "id",({ "bracer" }) );
	set_short( "��ɫ����" );
	set_long(@LONG
	����һ����ҫ����ɫ��â�Ļ���
LONG
           	);
	set( "unit","��" );
	set( "weight",45 );
	set( "type","hands" );
	set( "material","light_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 470,"silver" }) );
}
