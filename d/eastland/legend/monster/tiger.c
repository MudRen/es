#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(14);
        set_name( "tiger", "�ϻ�" );
        set_short( "�ϻ�" );
        set_long(@C_LONG
��ֻ����������е���è�ģ�������ȴ��ܶࡣ������צ�Ӻ������������ʳ����
Ҫ���ߡ���һ�ַǳ�Σ�յ���ʳ�Զ��
C_LONG
        );
        set("unit","ֻ");
        set_perm_stat( "str", 18 );
        set_perm_stat( "dex", 20 ); 
        set_perm_stat( "int", 12 );
        set_perm_stat( "kar", 18 );
        set_skill( "dodge", 90);
        set("max_hp", 450);
        set("hit_points",450);
        set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        set( "killer", 1);
        set( "c_killer_msg", "ͻȻ�䣬�㿴���ϻ���������������㼱���˹���!!!");
        set( "alignment", -500 );
        set_natural_weapon(40,17,27);
        set_natural_armor(70,1);
        set_c_verbs( ({ "%s���͵���%sһ��ҧȥ", "%sѸ�ٵ�����%s",
                        "%s��������צ��%s������ץȥ"  }) );
        set_c_limbs( ({ "ͷ��", "����", "�Ų�"}) );
}
