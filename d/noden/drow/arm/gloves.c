#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("snake gloves", "��������");
   add( "id", ({ "gloves" }) );
	set_short( "��������" );
        set_long(
@C_LONG
����һ˫����Ƥ�����Ƶ����ף���������������·�����о��ѵ���
���ԣ����ʺ��κγߴ�����������
C_LONG
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "material", "leather" );
   set( "armor_class", 4 );
   set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
	set( "weight", 25 );
	set( "value", ({ 180, "gold" }) );
}
