#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("platinum necklace", "�׽�����");
add( "id", ({ "necklace" }) );
	set_short( "�׽�����" );
        set_long(
@C_LONG
�����׽������������ֵ��쳣�����ά�͸����ܵ�˿��ʮ��������
�����춶��칤��ϸ�壬�������ܵ�˿��ϲ����װ��Ʒ��
C_LONG
        );
	set( "unit", "��");
        set( "type", "misc" );
	set( "material", "light_metal" );
   set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
        set( "weight", 40 );
   set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1);
}
