
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "sound_blade", "������" );
        add( "id",({ "bladed","sword","sound_sword" }) );
        set_short( "sound_blade", "������" );
        set_long(@AAA
����һ�ѽ����ҳ����ձ���,�ڽ��ɴ�����һ������,��ʾ������ʿ
�ӳ�Լ�޵��䵶
AAA
        );
        set( "unit", "��");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 38 );
        set( "nosecond",0);
        set( "weight", 150 );
        set( "value", ({ 100, "gold" }) );
}



