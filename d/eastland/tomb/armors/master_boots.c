#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "master boots", "��ʦѥ" );
	add( "id", ({ "boots", }) );
	set_short( "��ʦѥ" );
	set_long( 
@C_TOPIC
һ˫��˵��������ɽ  ����ʦʩ������ѥ�ӣ��������벻����\��\Ч\��
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 8 );
	set( "defense_bonus", 2 );
	set( "special_defense", 
	     ([ "divine":15, "none":15 ]) );
	set( "weight", 20 );
	set( "no_sale", 1);
	set( "value", ({ 3700, "silver" }) );
}
