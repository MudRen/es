
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Swallow Sword", "����֮��" );
        add( "id",({ "swallow","sword" }) );
        set_short( "Swallow Sword", "����֮��" );
        set_long(@AAA
��һ�����������½�ʿ ���Ҿ� ���佣����˵�Ҿ����ô˽�
ն����еķ��࣬�ʴ˽��д�����
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 37 );
        set( "weight", 130 );
        set( "value", ({ 1720, "silver" }) );
}
