#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake armbands", "�߻���");
   add( "id", ({ "armbands" }) );
        set_short( "�߻���" );
        set_long(
@C_LONG
����һ������Ƥ����ɵĻ��ۣ���Ե����ͭƬ��֯���ܵؽ�ϡ�
C_LONG
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "leather" );
   set( "armor_class", 3 );
   set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "poison": 18, "cold": -5 ]) );
        set( "weight", 32 );
        set( "value", ({ 110, "gold" }) );
        set( "no_sale", 1);
}
