#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "cockroach", "���" );
        set_short( "���" );
        set_long(
                "һֻ��룬������ö��ġ�\n"
        );
        set_perm_stat("dex", 5 );
        set_perm_stat("str", 1 );
        set( "alignment" , -100 );
        set_c_verbs( ({ "%s������%sҧ��" }) );
        set_c_limbs( ({ "ͷ��", "����","����" }) );
 
        set( "unit", "ֻ" );
        set( "natural_armor_class", 8 );
        set( "max_hp", 20 );
        set( "hit_points", 20 );
 
        set( "exp_reward", 60 );
 
        set( "chat_chance", 15 );
        set( "chat_output", ({
        "����Լ�����ٶ��ڽ���(corner)��������ȥ����ֻ���ǻ�ѽ��ѽ�أ��ֶ��ĵ�...\n"
        }) );
}
