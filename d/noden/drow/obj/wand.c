#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "snake eye wand", "����ʯ֮��");
        add( "id", ({ "wand" }) );
        set_short( "����ʯ֮��");
        set_long(
@C_LONG
������������һ��������ʯǶ���ȱ���ͭ�ȣ���̵�����ϸ������ۣ�����
����������ֵ��ǣ��������������ʯ��û��ɢ��ҫ�۵Ĺ�â��������һ�֡���
��������������ɫ��΢�������������С�
C_LONG
                );
        set( "unit", "��" );
        set( "type", "wand" );
   set( "weapon_class", 16 );
        set( "min_damage", 9 );
        set( "max_damage", 15 );
        set( "power_on", 1);
        set( "weight", 45 );
        set( "value", ({ 1000, "silver" }) );

        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "electric" );
        set( "special_damage", 15 );
        set( "special_c_msg", "�������ſ�������һ����⣡");
}
