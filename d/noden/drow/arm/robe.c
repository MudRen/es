#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("snake skin robe", "����Ƥ����");
   add( "id", ({ "robe" }) );
        set_short( "����Ƥ����" );
        set_long(
@C_LONG
����һ���Ѿ����������Ƥ��ĳ��ۣ�����Ч�ظ���ס������岢
�ұ����˺����Ǻڰ������ֹ��յĴ�������
C_LONG
        );
        set( "unit", "��");
        set( "type", "body" );
        set( "material", "leather" );
        set( "armor_class", 14 );
   set( "defense_bonus", 8 );
        set( "special_defense",
               ([ "poison":6 ]) );
        set( "weight", 130 );
        set( "value", ({ 1000, "silver" }) );
}
